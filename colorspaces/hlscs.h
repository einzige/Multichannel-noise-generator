#ifndef HLSCS_H
#define HLSCS_H

#include "../filters/huefilter.h"
#include "../filters/saturationfilter.h"
#include "../filters/lightnessfilter.h"

#include "../colorspace.h"

class HSLCS : public ColorSpace
{
public:
    HSLCS(ColorSpace::Identifier = ColorSpace::HLS);
    QImage restore();
};

#endif // HLSCS_H
