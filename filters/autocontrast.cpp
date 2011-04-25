#include "autocontrast.h"
#include "math.h"
#include "QDebug"

AutoContrast::AutoContrast(int min, int max)
{
    this->min = min;
    this->max = max;
}

int AutoContrast::getMin(){return min;}
int AutoContrast::getMax(){return max;}

void AutoContrast::setMin(int min){this->min = min;}
void AutoContrast::setMax(int max){this->max = max;}

#define NSLICES 50

QImage AutoContrast::apply(QImage img) const
{
    QImage res(img.width(), img.height(), QImage::Format_ARGB32);

    int nslices = NSLICES;

    int xfilter_size = (float)(img.width())  / nslices;
    int yfilter_size = (float)(img.height()) / nslices;

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

            float fmin = 255;
            float fmax = 0;

            for (int j = 0; j < yfilter_size; j++)
            {
                int yv = std::min(std::max(y - yradius + j, 0), img.height() - yradius);

                for (int i = 0; i < xfilter_size; i++)
                {
                    int xv = std::min(std::max(x-xradius + i, 0), img.width() - xradius);

                    int l = QColor(img.pixel(xv, yv)).lightness();

                    if (fmin > l) fmin = l;
                    // else ?
                    if (fmax < l) fmax = l;
                }
            }

            float z = fmax - fmin;
            float a = (max - min) / z;
            float b = (min*fmax - max*fmin) / z;

            QColor c(img.pixel(c_pixel_x, c_pixel_y));
            int g = a*c.lightness() + b;

            res.setPixel(c_pixel_x,
                         c_pixel_y,
                         QColor::fromHsl(c.hue(),
                                         c.saturation(),
                                         std::max(std::min(g, 255), 0),
                                         255).rgba());
        }
    }
    return res;
}

/* TRUE REALIZATION:
    int slice_size = 300;
    if (img.width() < slice_size || img.height() < slice_size)
        return img;

    int xnslices = img.width() / slice_size;
    int ynslices = img.width() / slice_size;

    int xstep = (float)(img.width())  / xnslices;
    int ystep = (float)(img.height()) / ynslices;

    //int fmin[xnslices][ynslices] = {{255, 255, 255}};
    //int fmax[xnslices][ynslices] = {{0, 0, 0}};

    int **fmin = AllocateDynamicArray<int>(xnslices,ynslices);
    int **fmax = AllocateDynamicArray<int>(xnslices,ynslices);

    // Fill min, max
    for (int xi = 0; xi < xnslices; xi++)
        for (int yi = 0; yi < ynslices; yi++) {
            fmin[xi][yi] = 0;
            fmax[xi][yi] = 255;
        }

    for (int xi = 0; xi < xnslices; xi++)
        for (int yi = 0; yi < ynslices; yi++)
            for (int x = xi*xstep; x < xstep + xi*xstep; x++)
                for (int y = yi*ystep; y < ystep + yi*ystep; y++) {
                    // Get Fminm, Fmax
                    int l = QColor(img.pixel(x, y)).lightness();

                    if (fmin[xi][yi] > l)
                        fmin[xi][yi] = l;
                    else if (fmax[xi][yi] < l)
                        fmax[xi][yi] = l;
                }

    // Now we set pixels
    for (int xi = 0; xi < xnslices; xi++)
        for (int yi = 0; yi < ynslices; yi++) {

            float a =    ((float)(max - min))
                    / //______________________________
                    (fmax[xi][yi] - fmin[xi][yi]);

            float b = ((float)(min*fmax[xi][yi] - max*fmin[xi][yi]))
                    / //______________________________________________
                    (fmax[xi][yi] - fmin[xi][yi]);

            for (int x = xi*xstep; x < xstep + xi*xstep; x++)
                for (int y = yi*ystep; y < ystep + yi*ystep; y++) {
                    QColor c(img.pixel(x, y));

                    int f = c.lightness();
                    int g = a*f + b;

                    img.setPixel(x,y, QColor::fromHsl(c.hue(), c.saturation(), g, 255).rgba());
                }
        }

    return img;

  */
