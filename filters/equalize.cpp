#include "equalize.h"
#include "math.h"
#include <QHash>
#include <QDebug>

QImage EqualizeFilter::apply(QImage img) const
{
    int hist[255] = {0};
    int min = 256;

    for (int x = 0; x < img.width(); x++)
    {
        for(int y = 0; y < img.height(); y++)
        {
            int l = QColor(img.pixel(x,y)).lightness();
            hist[l] += 1;
            if (hist[l] < min) min = hist[l];
        }
    }

    int pixnum = (img.width() * img.height());

    int cdf[255] = {0};
    for(int i = 0; i < 255; i++)
        for(int j = 0; j < i; j++) cdf[i] += hist[j];

    float alpha = 255.f / pixnum;
    for (int x = 0; x < img.width(); x++)
    {
        for(int y = 0; y < img.height(); y++)
        {
            QColor c(img.pixel(x,y));

            int l   = c.lightness();
            int fix = (int)round(cdf[l] * alpha);

            img.setPixel(x,y, QColor::fromHsl(c.hue(), c.saturation(), fix ? fix : l, 255).rgba());
        }
    }
    return img;
}
