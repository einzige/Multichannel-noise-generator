#include "additivenoise.h"
#include "math.h"
#include <QDebug>
#include "../helpers/color.h"

AdditiveNoise::AdditiveNoise(unsigned int rate,
                             unsigned int maxMinus,
                             unsigned int maxPlus) : INoise(rate)
{
    mMaxMinus = maxMinus;
    mMaxPlus  = maxPlus;
}

QImage AdditiveNoise::Apply(QImage img) const
{
    float w = img.width();
    float h = img.height();

    int r = floor(w * h * mRate/100);

    for (int i = 0; i < r; i++)
    {
        QPoint p(rand() % (int)w, rand() % (int)h);

        int diff = (rand() % 2) ? -mMaxMinus : mMaxPlus;
        QColor c(img.pixel(p));

        int r = c.red()   + diff;
        int g = c.green() + diff;
        int b = c.blue()  + diff;

        img.setPixel(p, assertRGBColor(r, g, b).rgba());
    }

    return img;
}
