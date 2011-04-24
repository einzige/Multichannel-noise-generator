#include "twodclean.h"
#include "math.h"
#include <QDebug>

using namespace std;

TwoDClean::TwoDClean(IMaskFilter f) : IMaskFilter(f.getMask(), f.getOffset())
{ threshold = 20; }

void TwoDClean::setThreshold(int threshold){
    this->threshold = threshold;
}

int TwoDClean::getThreshold(){
    return threshold;
}

QImage TwoDClean::apply(QImage img) const
{
    QImage res(img);
    qDebug() << "At 2dClean::apply";

    int xfilter_size = mask[0].count();
    int yfilter_size = mask.count();

    int xradius = xfilter_size / 2;
    int yradius = yfilter_size / 2;

    for (int y = 0; y < img.height(); ++y)
    {
        for (int x = 0; x < img.width(); ++x)
        {
            int c_pixel_x = x + xradius;
            int c_pixel_y = y + yradius;

            if (c_pixel_x >= img.width() || c_pixel_y >= img.height())
                continue;

            float new_r,  new_g,  new_b;
                  new_r = new_g = new_b = 0;

            int r_count,  g_count,  b_count;
                r_count = g_count = b_count = 0;

            QColor c_color(img.pixel(c_pixel_x, c_pixel_y));

            for (int j = 0; j < yfilter_size; j++)
            {
                int yv = min(max(y-yradius + j, 0), img.height() - yradius);

                for (int i = 0; i < xfilter_size; i++)
                {
                    int xv = min(max(x-xradius + i, 0), img.width() - xradius);

                    if(xv == c_pixel_x && yv == c_pixel_y) // ?
                        continue;

                    QColor c(img.pixel(xv, yv));

                    int r = c.red();
                    int g = c.green();
                    int b = c.blue();

                    float m = mask[j][i];

                    if(abs(c_color.red() - r) < threshold) {
                        new_r += r * m;
                        r_count++;
                    }
                    if(abs(c_color.blue() - b) < threshold) {
                        new_b += b * m;
                        b_count++;
                    }
                    if(abs(c_color.green() - g) < threshold) {
                        new_g += g * m;
                        g_count++;
                    }
                }
            }

            if (r_count)
                new_r = (float)new_r/r_count + offset;
            if (g_count)
                new_g = (float)new_g/g_count + offset;
            if (b_count)
                new_b = (float)new_b/b_count + offset;

            new_r = (new_r > 255) ? 255 : ((new_r < 0) ? 0:new_r);
            new_g = (new_g > 255) ? 255 : ((new_g < 0) ? 0:new_g);
            new_b = (new_b > 255) ? 255 : ((new_b < 0) ? 0:new_b);

            res.setPixel(c_pixel_x, c_pixel_y, QColor((int)new_r,
                                                      (int)new_g,
                                                      (int)new_b, 255).rgb());
        }
    }
    return res;
}
