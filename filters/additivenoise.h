#ifndef ADDITIVENOISE_H
#define ADDITIVENOISE_H

#include "../inoise.h"

class AdditiveNoise : public INoise
{
public:
    AdditiveNoise(unsigned int rate     = 40,
                  unsigned int maxMinus = 20,
                  unsigned int maxPlus  = 20);

    QImage apply(QImage) const;

private:
    unsigned int maxMinus;
    unsigned int maxPlus;
};

#endif // ADDITIVENOISE_H
