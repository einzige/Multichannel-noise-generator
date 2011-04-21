#include "noisemodel.h"
#include "filters/impulsenoise.h"
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

void NoiseModel::setRate(int rate) {
    this->rate = rate;
}

void NoiseModel::setCurrentChannel(Channel::Identifier channel) {
    this->currentChannel = channel;
}

#include "filters/grayscalefilter.h"

void NoiseModel::applyGrayscaleFilter()
{
    GrayscaleFilter *f = new GrayscaleFilter();
    applyFilter(f);
    /*QImage res = this->image;

    RGBCS cs = (RGBCS&)(this->colorSpaces[ColorSpace::RGB]);

    QImage r(cs.getChannelImage(Channel::R));
    QImage g(cs.getChannelImage(Channel::G));
    QImage b(cs.getChannelImage(Channel::B));

    for(int x = 0; x < res.width(); x++)
        for(int y = 0; y < res.height(); y++) {
            int red   =  QColor(r.pixel(x,y)).red();
            int green =  QColor(g.pixel(x,y)).green();
            int blue  =  QColor(b.pixel(x,y)).blue();

            int col   = ((red * 0.35) + (green * 0.54) + (blue * 0.11));
            res.setPixel(x, y, QColor(col, col, col, 255).rgba());
        }
    */

    //return res;
}
