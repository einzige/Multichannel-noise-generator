#ifndef SATURATIONFILTER_H
#define SATURATIONFILTER_H

#include "../ifilter.h"

class SaturationFilter : public IFilter
{
public:
    QImage Apply(QImage) const; // FIXME: remove me
};

#endif // SATURATIONFILTER_H
