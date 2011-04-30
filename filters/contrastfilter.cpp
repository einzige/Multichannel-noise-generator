#include "contrastfilter.h"
#include "../helpers/color.h"
#include "../ifilter.h"

ContrastFilter::ContrastFilter(int diff)
{
    setDiff(diff);
}

void ContrastFilter::setDiff(int diff)
{
    this->diff = diff;
}

int ContrastFilter::getDiff()
{
    return diff;
}

QImage ContrastFilter::apply(QImage img) const
{
    return changeContrast(img, diff);
}
