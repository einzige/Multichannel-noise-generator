#ifndef LIGHTNESSFILTER_H
#define LIGHTNESSFILTER_H

#include "../ifilter.h"

class LightnessFilter : public IFilter
{
public:
    QImage Apply(QImage) const;
};

#endif // LIGHTNESSFILTER_H
