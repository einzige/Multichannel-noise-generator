#ifndef AUTOCONTRAST_H
#define AUTOCONTRAST_H

#include "../ifilter.h"

class AutoContrast : public IFilter
{
    int min;
    int max;
public:
    AutoContrast(int min, int max);

    void setMin(int);
    void setMax(int);

    int getMin();
    int getMax();

    QImage apply(QImage) const;
};

#endif // AUTOCONTRAST_H
