#ifndef BRIGHTNESSFILTER_H
#define BRIGHTNESSFILTER_H

#include "../ifilter.h"

class BrightnessFilter : public IFilter
{
public:
    BrightnessFilter(int diff);
    QImage apply(QImage) const;

    void setDiff(int diff);
    int  getDiff();
private:
    int diff;
};

#endif // BRIGHTNESSFILTER_H
