#ifndef INOISE_H
#define INOISE_H

#include "ifilter.h"

class INoise : public IFilter
{
public:
    INoise(unsigned int);

    void setRate(unsigned int);

protected:
    unsigned int mRate;
};

#endif // INOISE_H
