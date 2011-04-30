#ifndef YUVCS_H
#define YUVCS_H

#include "../colorspace.h"
#include "../filters/yfilter.h"
#include "../filters/ufilter.h"
#include "../filters/vfilter.h"

class YUVCS : public ColorSpace
{
public:
    YUVCS(ColorSpace::Identifier = ColorSpace::YUV);

    QImage restore();
};

#endif // YUVCS_H
