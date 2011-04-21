#ifndef BLUEFILTER_H
#define BLUEFILTER_H

#include "../ifilter.h"

class BlueFilter : public IFilter
{
public:
    QImage apply(QImage) const;
};

#endif // BLUEFILTER_H
