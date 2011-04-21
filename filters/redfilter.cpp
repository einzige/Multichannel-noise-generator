#include "redfilter.h"

QImage RedFilter::apply(QImage img) const
{
    for (int x = 0; x < img.width(); x++)
        for(int y = 0; y < img.height(); y++)
            img.setPixel(x, y, QColor(QColor(img.pixel(x, y)).red(), 0, 0, 255).rgba());
    return img;
}
