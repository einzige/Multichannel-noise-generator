#include "invertfilter.h"

QImage InvertFilter::apply(QImage img) const
{
    img.invertPixels();
    return img;
}

