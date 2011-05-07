#ifndef NOISEMODEL_H
#define NOISEMODEL_H

#include "model.h"
#include "colorspaces/rgbcs.h"
#include "colorspaces/hlscs.h"
#include "colorspaces/yuvcs.h"

#include "filters/huefilter.h"
#include "filters/saturationfilter.h"
#include "filters/lightnessfilter.h"

#include "filters/additivenoise.h"
#include "filters/multinoise.h"
#include "filters/impulsenoise.h"


class NoiseModel : public Model
{
    void init();
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
    void applyAutoLevelsFilter(int min, int max);
    void applyAutoContrastFilter(int min, int max);
    void applyAverageConvolution(const QString &);
    void applyGeometricConvolution(const QString &);
    void applyMedianConvolution(const QString &);
    void applyAdditionalConvolution(const QString &);
    void apply2DCleaner(const QString& mask, int threshold);

    QImage hist();

    void setRate(int rate);
    void setFilterOffset(int offset);
    void setCurrentChannel(Channel::Identifier channel);
    void setDelta(float);
    void setMSAD(float);

    float getDelta();
    float getMSAD();

    float recalcDelta();
    float recalcMSAD();

protected:
    void reset();

    float msad;
    float delta;
    int rate;
    int filter_offset;
    Channel::Identifier currentChannel;
};

#endif // NOISEMODEL_H
