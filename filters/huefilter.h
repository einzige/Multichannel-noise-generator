#ifndef HUEFILTER_H
#define HUEFILTER_H

#include "../ifilter.h"

class HueFilter : public IFilter
{
public:
    QImage apply(QImage) const;
};

#endif // HUEFILTER_H
