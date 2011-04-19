#ifndef REDFILTER_H
#define REDFILTER_H

#include "../ifilter.h"

class RedFilter : public IFilter
{
public:
    QImage Apply(QImage) const;
};

#endif // REDFILTER_H
