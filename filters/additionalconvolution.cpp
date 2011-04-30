#include "additionalconvolution.h"
#include "averageconvolution.h"
#include "../helpers/color.h"

#include <QDebug>

AdditionalConvolution::AdditionalConvolution(IMaskFilter f) : IMaskFilter(f.getMask(), f.getOffset())
{}

QImage AdditionalConvolution::apply(QImage img) const
{
    qDebug() << "Applying laplasian";
    QImage laplas = AverageConvolution::convolve(img, mask, offset);

    for(int x = 0; x < img.width(); x++)
        for(int y = 0; y < img.height(); y++)
        {
            QColor src_c(img.pixel(x,y));
            QColor dst_c(laplas.pixel(x,y));

            int r = src_c.red() + dst_c.red();
            int b = src_c.blue() + dst_c.blue();
            int g = src_c.green() + dst_c.green();

            img.setPixel(x, y, assertRGBColor(r,g,b).rgba());
        }

    return img;
}
