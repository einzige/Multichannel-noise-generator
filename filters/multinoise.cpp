#include "multinoise.h"
#include <math.h>
#include <QDebug>

MultiNoise::MultiNoise(unsigned int rate, float multiplier) : INoise(rate)
{
    mMuiltiplier = multiplier;
}

QImage MultiNoise::Apply(QImage img) const
{
    float w = img.width();
    float h = img.height();

    int r = floor(w * h * mRate/100);

    for (int i = 0; i < r; i++)
    {
        QPoint p(rand() % (int)w, rand() % (int)h);

        QColor c(img.pixel(p));

        int r = floor(c.red()   * mMuiltiplier);
        int g = floor(c.green() * mMuiltiplier);
        int b = floor(c.blue()  * mMuiltiplier);

        img.setPixel(p, assertRGBColor(r, g, b).rgba());
    }

    return img;
}
