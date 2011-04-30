#include "model.h"

#include <QColor>

#include "filters/redfilter.h"
#include "filters/greenfilter.h"
#include "filters/bluefilter.h"
#include "filters/huefilter.h"
#include "filters/saturationfilter.h"
#include "filters/lightnessfilter.h"
#include "filters/multinoise.h"

#include "colorspaces/hlscs.h"
#include "colorspaces/rgbcs.h"

#include <assert.h>

Model::Model(){ ticks = 0; }
Model::Model(const QImage& img)
{
    ticks = 0;
    setImage(img);
}

int Model::getTicks() {
    return ticks;
}

void Model::setImage(const QImage& img, bool replaceSource)
{
    if(sourceImage.isNull() || replaceSource)
        sourceImage = img;

    this->image = img;

    // each colorspace needs to recalc channels
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
    QTime t;
    t.start();

    if(channel_id == Channel::UNDEFINED) {
        applyFilter(f);
    } else {
        ColorSpace* cs = getCSByChannel(channel_id);

        // apply filter to the given channel
        cs->applyFilter(f, channel_id);

        // restore image by the new channel data
        if(cs->getId() == ColorSpace::HLS)
            setImage(((HSLCS*)cs)->restore());
        else
            if(cs->getId() == ColorSpace::RGB)
                setImage(((RGBCS*)cs)->restore());
    }
    ticks = t.elapsed();
}

QImage Model::getChannelImage(Channel::Identifier id)
{
    if(id == Channel::UNDEFINED) return getImage();

    return getCSByChannel(id)->getChannelImage(id);
}

ColorSpace* Model::getCSByChannel(Channel::Identifier id)
{
    foreach(ColorSpace::Identifier csid, colorSpaces.keys())
    {
        if(colorSpaces[csid].containsChannel(id)) return &colorSpaces[csid];
    }

    return NULL;
}
