#ifndef LIGHTNESSFILTER_H
#define LIGHTNESSFILTER_H

#include "../ifilter.h"

class LightnessFilter : public IFilter
{
public:
    QImage apply(QImage) const;
};

#endif // LIGHTNESSFILTER_H
