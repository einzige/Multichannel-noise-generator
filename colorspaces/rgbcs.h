#ifndef RGBCS_H
#define RGBCS_H

#include "../filters/redfilter.h"
#include "../filters/greenfilter.h"
#include "../filters/bluefilter.h"

#include "../colorspace.h"

class RGBCS : public ColorSpace
{
public:
    RGBCS(ColorSpace::Identifier = ColorSpace::RGB);
    QImage restore();
};

#endif // RGBCS_H
