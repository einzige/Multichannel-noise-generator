#include "vfilter.h"

// http://www.couleur.org/index.php?page=transformations

QImage VFilter::apply(QImage img) const
{
    for (int x = 0; x < img.width(); x++)
        for(int y = 0; y < img.height(); y++) {
            QColor c(img.pixel(x, y));

            int val = 0.615*c.red()
                     -0.515*c.green()
                     +0.100*c.blue();

            img.setPixel(x, y, QColor(val, val, val, 255).rgba());
        }
    return img;
}
