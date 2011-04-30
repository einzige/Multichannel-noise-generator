#ifndef AUTOLEVELS_H
#define AUTOLEVELS_H

#include "../ifilter.h"

class Autolevels : public IFilter
{
    int max;
    int min;

public:
    Autolevels(int min, int max);

    void setMin(int min);
    void setMax(int max);

    int getMin();
    int getMax();

    QImage apply(QImage) const;
};

#endif // AUTOLEVELS_H
