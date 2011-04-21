#include "noisemodel.h"
#include "filters/impulsenoise.h"
#include <QDebug>

void NoiseModel::reset()
{
    mCurrentChannel = Channel::UNDEFINED;
    mRate = 0;
}

NoiseModel::NoiseModel() : Model()
{ reset(); }

// FIXME to call parent class Model
//
NoiseModel::NoiseModel(const QImage &img)
{
    reset();

    AddColorSpace(RGBCS());
    AddColorSpace(HLSCS());

    SetImage(img);
}

void NoiseModel::applyImpulseNoise(int blackRate)
{
    ImpulseNoise *f = new ImpulseNoise(mRate, blackRate);
    f->setRate(mRate);
    ApplyFilter(f);

    qDebug() << "NoiseFilter applied";
}

void NoiseModel::setRate(int rate) {
    mRate = rate;
}
