#include "huefilter.h"
#include <QDebug>
#include "../helpers/color.h"

QImage HueFilter::Apply(QImage img) const
{
    for (int x = 0; x < img.width(); x++)
        for(int y = 0; y < img.height(); y++)
        {
            int h = QColor(img.pixel(x, y)).hue();
            img.setPixel(x, y, assertRGBColor(h,h,h).rgba());
        }

    return img;
}
