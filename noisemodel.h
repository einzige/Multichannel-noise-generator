#ifndef NOISEMODEL_H
#define NOISEMODEL_H

#include "model.h"
#include "colorspaces/rgbcs.h"
#include "colorspaces/hlscs.h"

#include "filters/huefilter.h"
#include "filters/saturationfilter.h"
#include "filters/lightnessfilter.h"

#include "filters/additivenoise.h"
#include "filters/multinoise.h"
#include "filters/impulsenoise.h"


class NoiseModel : public Model
{
public:
    NoiseModel();
    NoiseModel(const QImage&);

    void applyImpulseNoise(int blackRate);

protected:
    void reset();

    int                 mRate;
    Channel::Identifier mCurrentChannel;
};

#endif // NOISEMODEL_H
