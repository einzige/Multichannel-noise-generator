#ifndef UFILTER_H
#define UFILTER_H

#include "../ifilter.h"

class UFilter : public IFilter
{
public:
    QImage apply(QImage) const;
};

#endif // UFILTER_H
