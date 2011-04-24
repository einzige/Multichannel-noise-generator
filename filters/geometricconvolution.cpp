#include "geometricconvolution.h"
#include "math.h"
#include "QDebug"

using namespace std;

GeometricConvolution::GeometricConvolution(IMaskFilter f) : IMaskFilter(mask = f.getMask())
{}

QImage GeometricConvolution::apply(QImage img) const
{
    qDebug() << "Applying geo";
    return GeometricConvolution::convolve(img, mask, offset);
}

// static
QImage GeometricConvolution::convolve(QImage img,
                                      QHash<int, QList<float> > mask,
                                      int filter_offset, float filter_div)
{
    int xfilter_size = mask[0].count();
    int yfilter_size = mask.count();

    int mfilter_size = xfilter_size * yfilter_size;

    for (int y = 0; y < img.height(); ++y)
    {
        for (int x = 0; x < img.width(); ++x)
        {
            float new_r, new_g, new_b;
            new_r = new_g = new_b = 1;

            for (int j = 0; j < yfilter_size; j++)
            {
                int yv = min(max(y - 1 + j, 0), img.height() - 1);

                for (int i = 0; i < xfilter_size; i++)
                {
                    int xv = min(max(x-1 + i, 0), img.width() - 1);

                    QColor c(img.pixel(xv, yv));

                    float m = mask[j][i];
                    new_r *= c.red()   * m;
                    new_g *= c.green() * m;
                    new_b *= c.blue()  * m;
                }
            }

            new_r = pow(new_r/filter_div, 1./mfilter_size) + filter_offset;
            new_g = pow(new_g/filter_div, 1./mfilter_size) + filter_offset;
            new_b = pow(new_b/filter_div, 1./mfilter_size) + filter_offset;

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
