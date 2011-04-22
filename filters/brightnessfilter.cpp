#include "brightnessfilter.h"
#include "../helpers/color.h"
#include "../ifilter.h"

BrightnessFilter::BrightnessFilter(int diff) {
    setDiff(diff);
}

void BrightnessFilter::setDiff(int diff) {
    this->diff = diff;
}

int BrightnessFilter::getDiff(){
    return diff;
}

QImage BrightnessFilter::apply(QImage img) const {
    /*for(int x = 0; x < img.width(); x++)
        for(int y = 0; y < img.height(); y++)
            img.setPixel(x,y, assertRGBColor(QColor(img.pixel(x,y)).red()   + diff,
                                             QColor(img.pixel(x,y)).green() + diff,
                                             QColor(img.pixel(x,y)).blue()  + diff).rgba());
    return img;*/
    return changeBrightness(img, diff);
}
