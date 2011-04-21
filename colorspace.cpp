#include "colorspace.h"

QImage ColorSpace::restore() { return channels[Channel::R].getImage(); } // as a pseudo-virtual// FIXME!!!

ColorSpace::ColorSpace(){}

ColorSpace::ColorSpace(ColorSpace::Identifier id)
{
    this->id = id;
}

void ColorSpace::setImage(const QImage& img)
{
    foreach(Channel::Identifier cid, channels.keys())
    {
        channels[cid].fetchFrom(img);
    }
}

void ColorSpace::addChannel(const Channel &c)
{
    channels[c.getID()] = c;
}

bool ColorSpace::containsChannel(Channel::Identifier cid)
{
    return channels.contains(cid);
}

QImage ColorSpace::getChannelImage(Channel::Identifier id)
{
    return channels[id].getImage();
}

void ColorSpace::applyFilter(IFilter *f, Channel::Identifier id)
{
    channels[id].applyFilter(f);
}

ColorSpace::Identifier ColorSpace::getId(){ return id; }
