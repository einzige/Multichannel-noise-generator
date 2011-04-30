#include "redfilter.h"

QImage RedFilter::apply(QImage img) const
{
    for (int x = 0; x < img.width(); x++)
        for(int y = 0; y < img.height(); y++) {
            uint val = QColor(img.pixel(x, y)).red();
            img.setPixel(x, y, QColor(val, val, val, 255).rgba());
        }
    return img;
}
