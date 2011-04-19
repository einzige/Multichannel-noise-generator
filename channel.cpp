#include "channel.h"
#include "filters/redfilter.h"
#include <assert.h>

Channel::Channel(){}

Channel::Channel(Channel::Identifier id, IFilter* f)
{
    mFilter = f;
    mIdentifier = id;
}

Channel::Channel(Channel::Identifier id, IFilter *f, const QImage &img)
{
    mFilter = f;
    mIdentifier = id;
    mImage = mFilter->Apply(img); // FIXME: dry
}

IFilter* Channel::GetFilter()
{
    return mFilter;
}

Channel::Identifier Channel::GetID() const
{
    return mIdentifier;
}

void Channel::FetchFrom(const QImage& img)
{
    mImage = mFilter->Apply(img);
}

QImage Channel::GetImage()
{
    return mImage;
}

void Channel::ApplyFilter(IFilter *f)
{
    mImage = f->Apply(mImage);
}
