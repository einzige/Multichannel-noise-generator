#ifndef YFILTER_H
#define YFILTER_H

#include "../ifilter.h"

class YFilter : public IFilter
{
public:
    QImage apply(QImage) const;
};

#endif // YFILTER_H
