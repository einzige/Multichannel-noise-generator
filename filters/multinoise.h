#ifndef MULTINOISE_H
#define MULTINOISE_H

#include "../inoise.h"
#include "../helpers/definions.h"
#include "../helpers/color.h"

class MultiNoise : public INoise
{
public:
    MultiNoise(unsigned int rate = 100, float multiplier = 0.9);
    QImage apply(QImage) const;

private:
    float multiplier;
};

#endif // MULTINOISE_H
