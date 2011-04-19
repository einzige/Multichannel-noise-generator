#include "bluefilter.h"

QImage BlueFilter::Apply(QImage img) const
{
    for (int x = 0; x < img.width(); x++)
        for(int y = 0; y < img.height(); y++)
            img.setPixel(x, y, QColor(0, 0, QColor(img.pixel(x, y)).blue(), 255).rgba());
    return img;
}
