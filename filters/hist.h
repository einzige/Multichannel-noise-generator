#ifndef HIST_H
#define HIST_H

#include "../ifilter.h"

class HistFilter : public IFilter
{
public:
    QImage apply(QImage) const;
};

#endif // HIST_H
