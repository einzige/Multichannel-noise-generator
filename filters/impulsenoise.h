#ifndef IMPULSENOISE_H
#define IMPULSENOISE_H

#include "../inoise.h"

class ImpulseNoise : public INoise
{
public:
    ImpulseNoise(unsigned int rate = 2, unsigned int blackRate = 50);
    QImage Apply(QImage) const;

private:
    unsigned int mBlackRate;
};

#endif // IMPULSENOISE_H
