#include "noisemodel.h"
#include "filters/impulsenoise.h"
#include "filters/additivenoise.h"
#include "filters/multinoise.h"
#include "filters/grayscalefilter.h"
#include "filters/hist.h"
#include "filters/brightnessfilter.h"
#include "filters/contrastfilter.h"
#include "filters/invertfilter.h"
#include "filters/equalize.h"
#include "filters/exp.h"
#include "filters/autolevels.h"
#include "filters/autocontrast.h"

#include <QDebug>

void NoiseModel::reset()
{
    currentChannel = Channel::UNDEFINED;
    rate  = 1;
}

NoiseModel::NoiseModel() : Model()
{
    reset();
    addColorSpace(RGBCS());
    addColorSpace(HLSCS());
}

// FIXME to call parent class Model
//
NoiseModel::NoiseModel(const QImage &img)
{
    reset();
    addColorSpace(RGBCS());
    addColorSpace(HLSCS());

    setImage(img);
}

void NoiseModel::applyImpulseNoise(int blackRate)
{
    ImpulseNoise *f = new ImpulseNoise(rate, blackRate);
    f->setRate(rate);
    applyFilter(f, this->currentChannel);
}

void NoiseModel::applyAdditionalNoise(int maxDiff)
{
    AdditiveNoise *f = new AdditiveNoise(rate, maxDiff, maxDiff);
    applyFilter(f, this->currentChannel);
}

void NoiseModel::applyMultiNoise(int coef)
{
    MultiNoise *f = new MultiNoise(rate, coef);
    applyFilter(f, this->currentChannel);
}

void NoiseModel::setRate(int rate) {
    this->rate = rate;
}

void NoiseModel::setCurrentChannel(Channel::Identifier channel) {
    this->currentChannel = channel;
}


void NoiseModel::applyGrayscaleFilter()
{
    GrayscaleFilter *f = new GrayscaleFilter();
    applyFilter(f);
}

void NoiseModel::applyInverseFilter()
{
    InvertFilter *f = new InvertFilter();
    applyFilter(f, this->currentChannel);
}

void NoiseModel::applyEqualizeFilter()
{
    EqualizeFilter *f = new EqualizeFilter();
    applyFilter(f, this->currentChannel);
}

void NoiseModel::applyBrightnessFilter(int diff)
{
    BrightnessFilter *f = new BrightnessFilter(diff);
    applyFilter(f, this->currentChannel);
}

void NoiseModel::applyContrastFilter(int diff)
{
    ContrastFilter *f = new ContrastFilter(diff);
    applyFilter(f, this->currentChannel);
}

void NoiseModel::applyGammaFilter(int diff)
{
    ExpFilter *f = new ExpFilter(diff);
    applyFilter(f, this->currentChannel);
}

void NoiseModel::applyAutoLevelsFilter(int min, int max)
{
    Autolevels *f = new Autolevels(min, max);
    applyFilter(f, this->currentChannel);
}

void NoiseModel::applyAutoContrastFilter(int min, int max)
{
    AutoContrast *f = new AutoContrast(min, max);
    applyFilter(f, this->currentChannel);
}

QImage NoiseModel::hist()
{
    HistFilter *f = new HistFilter();
    return f->apply(getChannelImage(this->currentChannel));
}
