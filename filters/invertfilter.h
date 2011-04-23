#ifndef INVERTFILTER_H
#define INVERTFILTER_H

#include "../ifilter.h"

class InvertFilter : public IFilter
{
public:
    QImage apply(QImage) const;
};

#endif // INVERTFILTER_H
