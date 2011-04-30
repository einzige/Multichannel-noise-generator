#ifndef LAPLASIAN_H
#define LAPLASIAN_H

#include "../ifilter.h"

class AdditionalConvolution : public IMaskFilter
{
public:
    AdditionalConvolution(IMaskFilter);
    QImage apply(QImage) const;
};

#endif // LAPLASIAN_H
