#include "medianconvolution.h"
#include "math.h"
#include "QDebug"

using namespace std;

MedianConvolution::MedianConvolution(IMaskFilter f) : IMaskFilter(f.getMask(), f.getOffset())
{//mask = f.getMask(), offset = f.getOffset()
    qDebug() << "At median::constructor";
}

QImage MedianConvolution::apply(QImage img) const
{
    qDebug() << "Applying median";
    return MedianConvolution::convolve(img, mask, offset);
}

// static
QImage MedianConvolution::convolve(QImage img,
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
            QList<float> r;
            QList<float> g;
            QList<float> b;

            for (int j = 0; j < yfilter_size; j++)
            {
                int yv = min(max(y - 1 + j, 0), img.height() - 1);

                for (int i = 0; i < xfilter_size; i++)
                {
                    int xv = min(max(x-1 + i, 0), img.width() - 1);

                    QColor c(img.pixel(xv, yv));
                    r << c.red()   * mask[j][i];
                    g << c.green() * mask[j][i];
                    b << c.blue()  * mask[j][i];
                }
            }

            qSort(r); qSort(g); qSort(b);
            int new_r = r.at(mfilter_size / 2) / filter_div + filter_offset;
            int new_g = g.at(mfilter_size / 2) / filter_div + filter_offset;
            int new_b = b.at(mfilter_size / 2) / filter_div + filter_offset;

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
