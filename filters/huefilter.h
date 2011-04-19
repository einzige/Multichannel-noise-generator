#ifndef HUEFILTER_H
#define HUEFILTER_H

#include "../ifilter.h"

class HueFilter : public IFilter
{
public:
    QImage Apply(QImage) const;
};

#endif // HUEFILTER_H
