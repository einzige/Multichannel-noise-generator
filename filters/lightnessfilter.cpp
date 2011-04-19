#include "lightnessfilter.h"

QImage LightnessFilter::Apply(QImage img) const
{
    for (int x = 0; x < img.width(); x++)
        for(int y = 0; y < img.height(); y++)
        {
            int l = QColor(img.pixel(x, y)).lightness();
            img.setPixel(x, y, QColor(l, l, l, 255).rgba());
        }

    return img;
}
