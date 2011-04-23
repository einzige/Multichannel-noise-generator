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
    void applyAdditionalNoise(int maxDiff);
    void applyMultiNoise(int coef);
    void applyGrayscaleFilter();
    void applyBrightnessFilter(int diff);
    void applyContrastFilter(int diff);
    void applyGammaFilter(int diff);
    void applyInverseFilter();
    void applyEqualizeFilter();

    QImage hist();

    void setRate(int rate);
    void setCurrentChannel(Channel::Identifier channel);

protected:
    void reset();

    int                 rate;
    Channel::Identifier currentChannel;
};

#endif // NOISEMODEL_H
