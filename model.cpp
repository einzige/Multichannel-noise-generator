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
    SetImage(img);
}

void Model::SetImage(const QImage& img)
{
    if(mSourceImage.isNull())
        mSourceImage = img;

    mImage = img;

    // each colorspace needs to recalc channels
    //
    foreach (ColorSpace::Identifier csid, mColorSpaces.keys())
    {
        mColorSpaces[csid].SetImage(img);
    }
}

void Model::AddColorSpace(ColorSpace cs)
{
    mColorSpaces[cs.GetId()] = cs;
    mColorSpaces[cs.GetId()].SetImage(mImage);
}

QImage Model::GetSourceImage()      { return mSourceImage; }
QImage Model::GetImage()            { return mImage;       }

void Model::ResetImage()            { SetImage(mSourceImage);     }
void Model::ApplyFilter(IFilter* f) { SetImage(f->Apply(mImage)); }


void Model::ApplyFilter(IFilter* f, Channel::Identifier channel_id)
{
    if(channel_id == Channel::UNDEFINED)
    {
        ApplyFilter(f, channel_id);
        return;
    }

    ColorSpace* cs = GetCSByChannel(channel_id);

    // apply filter to the given channel
    cs->ApplyFilter(f, channel_id);

    // restore image by the new channel data
    SetImage(cs->Restore());
}

QImage Model::GetChannelImage(Channel::Identifier id)
{
    return GetCSByChannel(id)->GetChannelImage(id);
}

ColorSpace* Model::GetCSByChannel(Channel::Identifier id)
{
    foreach(ColorSpace::Identifier csid, mColorSpaces.keys())
        if(mColorSpaces[csid].ContainsChannel(id)) return &mColorSpaces[csid];

    return NULL;
}
