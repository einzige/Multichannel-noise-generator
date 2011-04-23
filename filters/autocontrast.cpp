#include "autocontrast.h"

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

QImage AutoContrast::apply(QImage img) const {
    int nslices = NSLICES;

    int xstep = (float)(img.width())  / nslices;
    int ystep = (float)(img.height()) / nslices;

    int fmin[NSLICES][NSLICES] = {{255, 255, 255}};
    int fmax[NSLICES][NSLICES] = {{0, 0, 0}};

    for (int xi = 0; xi < nslices; xi++)
        for (int yi = 0; yi < nslices; yi++)
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
    for (int xi = 0; xi < nslices; xi++)
        for (int yi = 0; yi < nslices; yi++) {

            float z = fmax[xi][yi] - fmin[xi][yi];
            float a = (max - min) / z;
            float b = (min*fmax[xi][yi] - max*fmin[xi][yi]) / z;

            for (int x = xi*xstep; x < xstep + xi*xstep; x++)
                for (int y = yi*ystep; y < ystep + yi*ystep; y++) {
                    QColor c(img.pixel(x, y));

                    int f = c.lightness();
                    int g = a*f + b;

                    img.setPixel(x,y, QColor::fromHsl(c.hue(), c.saturation(), g, 255).rgba());
                }
        }

    return img;
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
