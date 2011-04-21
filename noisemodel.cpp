#include "noisemodel.h"
#include "filters/impulsenoise.h"
#include "filters/additivenoise.h"
#include "filters/grayscalefilter.h"

#include <QDebug>

void NoiseModel::reset()
{
    currentChannel = Channel::UNDEFINED;
    rate = 1;
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

    qDebug() << "NoiseFilter applied";
}

void NoiseModel::applyAdditionalNoise(int maxDiff)
{
    AdditiveNoise *f = new AdditiveNoise(rate, maxDiff, maxDiff);
    applyFilter(f, this->currentChannel);

    qDebug() << "AdditiveFilter applied";
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
