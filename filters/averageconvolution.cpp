#include "averageconvolution.h"
#include "math.h"
#include <QDebug>

using namespace std;

AverageConvolution::AverageConvolution(IMaskFilter f) : IMaskFilter(mask = f.getMask())
{}

QImage AverageConvolution::apply(QImage img) const
{
    int filter_div    = 1;
    int filter_offset = 0;
    int filter_size   = mask[0].count();

    for (int y = 0; y < img.height(); ++y)
    {
        for (int x = 0; x < img.width(); ++x)
        {
            float new_r, new_g, new_b;
            new_r = new_g = new_b = 0;

            for (int j = 0; j < filter_size; j++)
            {
                int yv = min(max(y - 1 + j, 0), img.height() - 1);

                for (int i = 0; i < filter_size; i++)
                {
                    int xv = min(max(x-1 + i, 0), img.width() - 1);

                    QColor c(img.pixel(xv, yv));

                    new_r += c.red()   * mask[j][i];
                    new_g += c.green() * mask[j][i];
                    new_b += c.blue()  * mask[j][i];

                    //qDebug() << new_r << new_g << new_b;
                }
            }

            new_r = (new_r/filter_div) + filter_offset;
            new_g = (new_g/filter_div) + filter_offset;
            new_b = (new_b/filter_div) + filter_offset;

            new_r = (new_r > 255) ? 255 : ((new_r < 0) ? 0:new_r);
            new_g = (new_g > 255) ? 255 : ((new_g < 0) ? 0:new_g);
            new_b = (new_b > 255) ? 255 : ((new_b < 0) ? 0:new_b);

            img.setPixel(x, y, QColor((int)new_r,
                                      (int)new_g,
                                      (int)new_b, 255).rgb());
        }
    }
    return img;
}


/* static */ /*QImage
ProcessingModel::ConvolveFilter(QImage img, int* filter, const int& filter_size,
                                                         const int& filter_div,
                                                         const int& filter_offset)
{
    for (int y = 0; y < img.height(); ++y)
    {
        for (int x = 0; x < img.width(); ++x)
        {
            float new_r, new_g, new_b;
            new_r = new_g = new_b = 0;

            for (int j = 0; j < filter_size; j++)
            {
                int yv = min(max(y - 1 + j, 0), img.height() - 1);
                for (int i = 0; i < filter_size; i++)
                {
                    QPoint pixel(min(max(x-1 + i, 0), img.width() - 1), yv);
                    QRgb rgb = img.pixel(pixel);
                    new_r += ((rgb >> 16) & 0xFF) * (filter+j)[i];
                    new_g += ((rgb >> 8) & 0xFF)  * (filter+j)[i];
                    new_b += (rgb & 0xFF)         * (filter+j)[i];
                }
            }

            new_r = (new_r/filter_div) + filter_offset;
            new_g = (new_g/filter_div) + filter_offset;
            new_b = (new_b/filter_div) + filter_offset;

            new_r = (new_r > 255) ? 255 : ((new_r < 0) ? 0:new_r);
            new_g = (new_g > 255) ? 255 : ((new_g < 0) ? 0:new_g);
            new_b = (new_b > 255) ? 255 : ((new_b < 0) ? 0:new_b);

            QColor new_pxl = QColor((int)new_r, (int)new_g, (int)new_b, 255);
            img.setPixel(x, y, new_pxl.rgb());
        }
    }

    return img;
}*/
