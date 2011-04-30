#include "ufilter.h"

QImage UFilter::apply(QImage img) const
{
    for (int x = 0; x < img.width(); x++)
        for(int y = 0; y < img.height(); y++) {
            QColor c(img.pixel(x, y));

            int val = -0.147*c.red()
                      -0.289*c.green()
                      +0.436*c.blue();

            img.setPixel(x, y, QColor(val, val, val, 255).rgba());
        }
    return img;
}
