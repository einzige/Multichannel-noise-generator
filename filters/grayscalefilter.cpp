#include "grayscalefilter.h"

QImage GrayscaleFilter::apply(QImage img) const
{
    for (int x = 0; x < img.width(); x++)
        for(int y = 0; y < img.height(); y++){
            QColor col(img.pixel(x,y));

            int red   =  col.red();
            int green =  col.green();
            int blue  =  col.blue();

            int gcol  = (red * 0.35) + (green * 0.54) + (blue * 0.11);

            img.setPixel(x, y, QColor(gcol, gcol, gcol, 255).rgba());
        }
    return img;
}
