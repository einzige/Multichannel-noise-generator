#ifndef CONTRASTFILTER_H
#define CONTRASTFILTER_H

#include "../ifilter.h"

class ContrastFilter : public IFilter
{
public:
    ContrastFilter(int diff);
    QImage apply(QImage) const;

    void setDiff(int diff);
    int  getDiff();
private:
    int diff;
};

#endif // CONTRASTFILTER_H
