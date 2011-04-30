#ifndef TWODCLEAN_H
#define TWODCLEAN_H

#include "../ifilter.h"

class TwoDClean : public IMaskFilter
{
protected:
    int threshold;

public:
           TwoDClean(IMaskFilter f);

    QImage apply(QImage) const;

    void   setThreshold(int threshold);
    int    getThreshold();
};

#endif // TWODCLEAN_H
