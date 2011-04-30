#include "channel.h"
#include "filters/redfilter.h"
#include <assert.h>

Channel::Channel(){}

Channel::Channel(Channel::Identifier id, IFilter* f)
{
    filter = f;
    identifier = id;
}

Channel::Channel(Channel::Identifier id, IFilter *f, const QImage &img)
{
    filter = f;
    identifier = id;
    image = filter->apply(img); // FIXME: dry
}

IFilter* Channel::getFilter()
{
    return filter;
}

Channel::Identifier Channel::getID() const
{
    return identifier;
}

void Channel::fetchFrom(const QImage& img)
{
    image = filter->apply(img);
}

QImage Channel::getImage()
{
    return image;
}

void Channel::applyFilter(IFilter *f)
{
    image = f->apply(image);
}

Channel::Identifier Channel::getChannelByName(const QString &name) {
    if(name == "Красный")      return Channel::RGB_R;
    if(name == "Зеленый")      return Channel::RGB_G;
    if(name == "Синий")        return Channel::RGB_B;
    if(name == "Оттенок")      return Channel::HSL_H;
    if(name == "Насыщенность") return Channel::HSL_S;
    if(name == "Светлость")    return Channel::HSL_L;
    /*if(name == "Y")            return Channel::YUV_Y;
    if(name == "U")            return Channel::YUV_U;
    if(name == "V")            return Channel::YUV_V;
    if(name == "M")            return Channel::CMYK_M;
    if(name == "K")            return Channel::SMYK_K;
    if(name == "C")            return Channel::CMYK_C;*/

    return Channel::UNDEFINED;
}
