#ifndef MEDIANCONVOLUTION_H
#define MEDIANCONVOLUTION_H

#include "../ifilter.h"

class MedianConvolution : public IMaskFilter
{
public:
    MedianConvolution(IMaskFilter);
    QImage apply(QImage) const;

    static QImage convolve(QImage img,
                           QHash<int, QList<float> > mask,
                           int filter_offset = 0, float filter_div = 1.);
};


#endif // MEDIANCONVOLUTION_H
