#ifndef GRAYSCALEFILTER_H
#define GRAYSCALEFILTER_H

#include "../ifilter.h"

class GrayscaleFilter : public IFilter
{
public:
    QImage apply(QImage) const;
};

#endif // GRAYSCALEFILTER_H
