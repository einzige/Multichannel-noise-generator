#include "lightness.h"

void LightnessFilter::Apply(QImage *img)
{
    QImage cp = img->copy(null);

    for (int x = 0; x < cp.width(); x++)
        for(int y = 0; y < cp.height(); y++)
            img->setPixel(x, y, QColor(cp.pixel(x, y)).red());
}
