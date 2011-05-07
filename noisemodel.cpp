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

#include "math.h"
using namespace std;


void NoiseModel::reset()
{
    currentChannel = Channel::UNDEFINED;
    rate  = 1;
    filter_offset = 0;
    msad = 0;
    delta = 0;
}

void NoiseModel::setMSAD(float m) {
    msad = m;
}

void NoiseModel::setDelta(float d) {
    delta = d;
}

float NoiseModel::getDelta() {
    return delta;
}

float NoiseModel::getMSAD() {
    return msad;
}

float NoiseModel::recalcDelta() {
    float w = this->sourceImage.width();
    float h = this->sourceImage.height();

    float sum = 0;
    for(int x = 0; x < w; x++)
        for(int y = 0; y < h; y++)
            sum += QColor(image.pixel(x,y)).lightness() - QColor(sourceImage.pixel(x,y)).lightness();

    delta = sum / (w * h);

    return delta;
}

float NoiseModel::recalcMSAD() {
    float w = this->sourceImage.width();
    float h = this->sourceImage.height();

    float sum = 0;
    for(int x = 0; x < w; x++)
        for(int y = 0; y < h; y++)
            sum += fabs(QColor(image.pixel(x,y)).lightness() - QColor(sourceImage.pixel(x,y)).lightness());

    msad = sum / (w * h);
    return msad;
}

void NoiseModel::init()
{
    reset();
    addColorSpace(RGBCS());
    addColorSpace(HSLCS());
    //addColorSpace(YUVCS());
}

NoiseModel::NoiseModel() : Model()
{
    init();
}

// FIXME to call parent class Model
//
NoiseModel::NoiseModel(const QImage &img)
{
    init();
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
