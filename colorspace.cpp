#include "colorspace.h"

QImage ColorSpace::Restore() { return QImage(); } // as a pseudo-virtual

ColorSpace::ColorSpace(){}

ColorSpace::ColorSpace(ColorSpace::Identifier id)
{
    mId = id;
}

void ColorSpace::SetImage(const QImage& img)
{
    foreach(Channel::Identifier cid, mChannels.keys())
    {
        mChannels[cid].FetchFrom(img);
    }
}

void ColorSpace::AddChannel(const Channel &c)
{
    mChannels[c.GetID()] = c;
}

bool ColorSpace::ContainsChannel(Channel::Identifier cid)
{
    return mChannels.contains(cid);
}

QImage ColorSpace::GetChannelImage(Channel::Identifier id)
{
    return mChannels[id].GetImage();
}

void ColorSpace::ApplyFilter(IFilter *f, Channel::Identifier id)
{
    mChannels[id].ApplyFilter(f);
}

ColorSpace::Identifier ColorSpace::GetId(){ return mId; }
