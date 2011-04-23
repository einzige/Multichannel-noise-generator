#include "exp.h"
#include "../helpers/color.h"
#include "../ifilter.h"

ExpFilter::ExpFilter(int diff) {
    setDiff(diff);
}

void ExpFilter::setDiff(int diff) {
    this->diff = diff;
}

int ExpFilter::getDiff(){
    return diff;
}

QImage ExpFilter::apply(QImage img) const
{
    return changeGamma(img, diff);
}
