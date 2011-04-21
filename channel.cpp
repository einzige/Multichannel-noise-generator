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
    if(name == "Красный")      return Channel::R;
    if(name == "Зеленый")      return Channel::G;
    if(name == "Синий")        return Channel::B;
    if(name == "Оттенок")      return Channel::H;
    if(name == "Насыщенность") return Channel::S;
    if(name == "Светлость")    return Channel::L;

    return Channel::UNDEFINED;
}
