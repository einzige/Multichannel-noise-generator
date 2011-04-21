#include "inoise.h"
#include "assert.h"

INoise::INoise(unsigned int rate = 10)
{
    setRate(rate);
}

void INoise::setRate(unsigned int rate)
{
    assert(rate > 0 && rate < 101);
    this->rate = rate;
}
