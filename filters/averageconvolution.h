#ifndef AVERAGECONVOLUTION_H
#define AVERAGECONVOLUTION_H

#include "../ifilter.h"

class AverageConvolution : public IMaskFilter
{
public:
    AverageConvolution(IMaskFilter);
    QImage apply(QImage) const;
};

#endif // AVERAGECONVOLUTION_H
