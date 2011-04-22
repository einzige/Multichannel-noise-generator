#ifndef EQUALIZE_H
#define EQUALIZE_H

#include "../ifilter.h"

class EqualizeFilter : public IFilter
{
public:
    QImage apply(QImage) const;
};

#endif // EQUALIZE_H
