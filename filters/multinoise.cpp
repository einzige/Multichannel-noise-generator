#include "multinoise.h"
#include <math.h>
#include <QDebug>

MultiNoise::MultiNoise(unsigned int rate, float multiplier) : INoise(rate)
{
    this->multiplier = multiplier;
}

QImage MultiNoise::apply(QImage img) const
{
    float w = img.width();
    float h = img.height();

    int r = floor(w * h * rate/100);

    for (int i = 0; i < r; i++)
    {
        QPoint p(rand() % (int)w, rand() % (int)h);

        QColor c(img.pixel(p));

        int r = floor(c.red()   * multiplier);
        int g = floor(c.green() * multiplier);
        int b = floor(c.blue()  * multiplier);

        img.setPixel(p, assertRGBColor(r, g, b).rgba());
    }

    return img;
}
