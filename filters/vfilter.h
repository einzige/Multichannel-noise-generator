#ifndef VFILTER_H
#define VFILTER_H

#include "../ifilter.h"

class VFilter : public IFilter
{
public:
    QImage apply(QImage) const;
};


#endif // VFILTER_H
