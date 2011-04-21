#include "saturationfilter.h"

QImage SaturationFilter::apply(QImage img) const
{
    for (int x = 0; x < img.width(); x++)
        for(int y = 0; y < img.height(); y++)
        {
            int s = QColor(img.pixel(x, y)).saturation();
            img.setPixel(x, y, QColor(s, s, s, 255).rgba());
        }
    return img;
}
