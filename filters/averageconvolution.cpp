#include "averageconvolution.h"
#include "math.h"
#include <QDebug>

using namespace std;

AverageConvolution::AverageConvolution(IMaskFilter f) : IMaskFilter(mask = f.getMask(), offset = f.getOffset())
{}

QImage AverageConvolution::apply(QImage img) const
{
    qDebug() << "Averaging::APPLY";
    float filter_div = 0;
    foreach(QList<float> row, mask)
        foreach(float weight, row)
            filter_div += abs(weight); // fixme

    return AverageConvolution::convolve(img, mask, offset, filter_div);
}
