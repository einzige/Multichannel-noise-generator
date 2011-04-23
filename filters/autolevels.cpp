#include "autolevels.h"

Autolevels::Autolevels(int min = 20, int max = 230){
    this->min = min;
    this->max = max;
}

int Autolevels::getMax() {
    return max;
}

int Autolevels::getMin() {
    return min;
}

QImage Autolevels::apply(QImage img) const
{
    /* http://www.faqs.org/qa/qa-2555.html

       "Comparing Auto Contrast and Auto Levels may further clarify how Auto Contrast affects your images.
        Auto Levels corrects images with an overall color cast.
        To do this, it analyzes each channel individually and maps the pixels with the lowest values to 0
        and the highest values to 255. The new Auto Contrast command, on the other hand, adjusts poor image
        contrast based on pixel luminosity, which it calculates based on a weighted average of the RGB
        values (remember, you asked!).
      */

    for (int x = 0; x < img.width(); x++)
    {
        for (int y = 0; y < img.height(); y++)
        {
            QColor c(img.pixel(x,y));
            int l = c.lightness();

            if (l < min) {
                img.setPixel(x,y, QColor::fromHsl(c.hue(), c.saturation(), 0, 255).rgba());
            } else if (l > max) {
                img.setPixel(x,y, QColor::fromHsl(c.hue(), c.saturation(), 255, 255).rgba());
            }
        }
    }
    return img;
}
