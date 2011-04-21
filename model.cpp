#include "model.h"

#include <QColor>

#include "filters/redfilter.h"
#include "filters/greenfilter.h"
#include "filters/bluefilter.h"
#include "filters/huefilter.h"
#include "filters/saturationfilter.h"
#include "filters/lightnessfilter.h"
#include "filters/multinoise.h"

#include <assert.h>

Model::Model(){}
Model::Model(const QImage& img)
{
    setImage(img);
}

void Model::setImage(const QImage& img)
{
    if(sourceImage.isNull())
        sourceImage = img;

    this->image = img;

    // each colorspace needs to recalc channels
    //
    foreach (ColorSpace::Identifier csid, colorSpaces.keys())
    {
        colorSpaces[csid].setImage(img);
    }
}

void Model::addColorSpace(ColorSpace cs)
{
    colorSpaces[cs.getId()] = cs;
    colorSpaces[cs.getId()].setImage(image);
}

QImage Model::getSourceImage()      { return sourceImage; }
QImage Model::getImage()            { return image;       }

void Model::resetImage()            { setImage(sourceImage);     }
void Model::applyFilter(IFilter* f) { setImage(f->apply(image)); }


void Model::applyFilter(IFilter* f, Channel::Identifier channel_id)
{
    if(channel_id == Channel::UNDEFINED)
    {
        applyFilter(f, channel_id);
        return;
    }

    ColorSpace* cs = getCSByChannel(channel_id);

    // apply filter to the given channel
    cs->applyFilter(f, channel_id);

    // restore image by the new channel data
    setImage(cs->restore());
}

QImage Model::getChannelImage(Channel::Identifier id)
{
    return getCSByChannel(id)->getChannelImage(id);
}

ColorSpace* Model::getCSByChannel(Channel::Identifier id)
{
    foreach(ColorSpace::Identifier csid, colorSpaces.keys())
        if(colorSpaces[csid].containsChannel(id)) return &colorSpaces[csid];

    return NULL;
}
