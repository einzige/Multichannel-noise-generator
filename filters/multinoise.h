#ifndef MULTINOISE_H
#define MULTINOISE_H

#include "../inoise.h"
#include "../helpers/definions.h"
#include "../helpers/color.h"

class MultiNoise : public INoise
{
public:
    MultiNoise(unsigned int rate = 100, float multiplier = 0.9);
    QImage Apply(QImage) const;

private:
    float mMuiltiplier;
};

#endif // MULTINOISE_H
