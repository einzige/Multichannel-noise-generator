#ifndef GEOMETRICCONVOLUTION_H
#define GEOMETRICCONVOLUTION_H

#include "../ifilter.h"

class GeometricConvolution : public IMaskFilter
{
public:
    GeometricConvolution(IMaskFilter);
    QImage apply(QImage) const;

    static QImage convolve(QImage img,
                           QHash<int, QList<float> > mask,
                           int filter_offset = 0, float filter_div = 1.);
};

#endif // GEOMETRICCONVOLUTION_H
