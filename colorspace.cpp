#include "colorspace.h"

QImage ColorSpace::Restore() { return QImage(); } // as a pseudo-virtual

ColorSpace::ColorSpace(){}

ColorSpace::ColorSpace(ColorSpace::Identifier id)
{
    _id = id;
}

void ColorSpace::SetImage(const QImage& img)
{
    foreach(Channel::Identifier cid, channels.keys())
    {
        channels[cid].FetchFrom(img);
    }
}

void ColorSpace::AddChannel(const Channel &c)
{
    channels[c.GetID()] = c;
}

bool ColorSpace::ContainsChannel(Channel::Identifier cid)
{
    return channels.contains(cid);
}

QImage ColorSpace::GetChannelImage(Channel::Identifier id)
{
    return channels[id].GetImage();
}

void ColorSpace::ApplyFilter(IFilter *f, Channel::Identifier id)
{
    channels[id].ApplyFilter(f);
}

ColorSpace::Identifier ColorSpace::GetId(){ return _id; }
