#ifndef GREENFILTER_H
#define GREENFILTER_H

#include "../ifilter.h"

class GreenFilter : public IFilter
{
public:
    QImage Apply(QImage) const;
};

#endif // GREENFILTER_H
