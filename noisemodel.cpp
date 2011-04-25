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
#include "filters/averageconvolution.h"
#include "filters/geometricconvolution.h"
#include "filters/medianconvolution.h"
#include "filters/twodclean.h"
#include "filters/additionalconvolution.h"

#include <QDebug>

void NoiseModel::reset()
{
    currentChannel = Channel::UNDEFINED;
    rate  = 1;
    filter_offset = 0;
}

NoiseModel::NoiseModel() : Model()
{
    reset();
    addColorSpace(RGBCS());
    addColorSpace(HSLCS());
}

// FIXME to call parent class Model
//
NoiseModel::NoiseModel(const QImage &img)
{
    reset();
    addColorSpace(RGBCS());
    addColorSpace(HSLCS());

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

void NoiseModel::setFilterOffset(int offset){
    this->filter_offset = offset;
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

void NoiseModel::applyAverageConvolution(const QString &s)
{
    AverageConvolution f = AverageConvolution::fromStr(s);
    f.setOffset(this->filter_offset);
    applyFilter(&f, this->currentChannel);
}

void NoiseModel::applyGeometricConvolution(const QString &s)
{
    qDebug() << "NoiseMode::applying geo convolution";
    GeometricConvolution f = GeometricConvolution::fromStr(s);
    f.setOffset(this->filter_offset);
    applyFilter(&f, this->currentChannel);
}

void NoiseModel::applyMedianConvolution(const QString &s)
{
    qDebug() << "NoiseMode::applying median convolution";
    MedianConvolution f = MedianConvolution::fromStr(s);
    f.setOffset(this->filter_offset);
    qDebug() << "Before apply_filter";
    applyFilter(&f, this->currentChannel);
}

void NoiseModel::applyAdditionalConvolution(const QString &s)
{
    qDebug() << "NoiseModel::applying additional convolution";
    AdditionalConvolution f = AdditionalConvolution::fromStr(s);
    f.setOffset(this->filter_offset);;
    applyFilter(&f, this->currentChannel);
}

void NoiseModel::apply2DCleaner(const QString &mask, int threshold){
    TwoDClean f = TwoDClean::fromStr(mask);
    f.setOffset(this->filter_offset);
    f.setThreshold(threshold);

    qDebug() << threshold << " = THRESHOLD";

    applyFilter(&f, this->currentChannel);
}

QImage NoiseModel::hist()
{
    HistFilter *f = new HistFilter();
    return f->apply(getChannelImage(this->currentChannel));
}
