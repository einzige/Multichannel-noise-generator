#include "hist.h"
#include <qdebug.h>

QImage HistFilter::apply(QImage img) const
{
    int map[255] = {0};
    int max = 0;

    for (int x = 0; x < img.width(); x++)
    {
        for(int y = 0; y < img.height(); y++)
        {
            int s = QColor(img.pixel(x,y)).lightness();
            map[s] += 1;
            if (map[s] > max) max = map[s];
        }
    }

    QImage res(255, max + 1, QImage::Format_ARGB32);
    res.fill(0);

    qDebug() << max;

    for(int x = 0; x < res.width(); x++)
        for(int y = 0; y < map[x]; y++)
            res.setPixel(x,y, QColor(0,255,255).rgb());

    return res.mirrored(false, true).scaled(800, 600);
}
