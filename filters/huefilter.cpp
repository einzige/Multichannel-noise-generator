#include "huefilter.h"
#include <QDebug>
#include "../helpers/color.h"

QImage HueFilter::apply(QImage img) const
{
    for (int x = 0; x < img.width(); x++)
        for(int y = 0; y < img.height(); y++)
        {
            int h = QColor(img.pixel(x, y)).hue() * 255 / 359;
            img.setPixel(x, y, QColor(h,h,h, 255).rgba());
        }

    return img;
}
