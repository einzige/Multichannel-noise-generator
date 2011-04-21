#include "impulsenoise.h"
#include <assert.h>
#include <math.h>
#include <QDebug>
#include "../helpers/definions.h"

ImpulseNoise::ImpulseNoise(unsigned int rate, unsigned int blackRate) : INoise(rate)
{
    assert(blackRate < 101);
    this->blackRate = blackRate;
}

QImage ImpulseNoise::apply(QImage img) const
{
    float w = img.width();
    float h = img.height();

    int r = floor(w * h * rate/100);

    for (int i = 0; i < r; i++)
    {
        QPoint p(rand() % (int)w, rand() % (int)h);

        int c = uint(rand() % 100) < blackRate ? 0 : 255;

        img.setPixel(p, QColor(c, c, c, 255).rgba());
    }

    return img;
}
