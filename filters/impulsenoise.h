#ifndef IMPULSENOISE_H
#define IMPULSENOISE_H

#include "../inoise.h"

class ImpulseNoise : public INoise
{
public:
    ImpulseNoise(unsigned int rate = 2, unsigned int blackRate = 50);
    QImage apply(QImage) const;

private:
    unsigned int blackRate;
};

#endif // IMPULSENOISE_H
