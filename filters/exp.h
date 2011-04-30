#ifndef EXP_H
#define EXP_H

#include "../ifilter.h"

class ExpFilter : public IFilter
{
public:
    ExpFilter(int diff);
    QImage apply(QImage) const;

    void setDiff(int diff);
    int  getDiff();
private:
    int diff;
};

#endif // EXP_H
