#ifndef IVIEW_H
#define IVIEW_H

#include "channel.h"

class IView
{
public: // signals
    virtual void applyImpulseNoise(int blackRate) = 0;
    virtual void applyAdditionalNoise(int maxDiff) = 0;
    virtual void applyMultiNoise(int coef) = 0;

    virtual void restoreImage() = 0;
    virtual void setTicks(int ticks) = 0;
    //virtual void ShowOriginal() = 0;
    //virtual void ChangeChannel() = 0;
    virtual void imageLoaded(const QImage& img) = 0;

    virtual void setMSAD(float msad) = 0;
    virtual void setDELTA(float delta) = 0;

public: // slots
    //virtual void SetLastOperationTicks(int ticks) = 0;
    virtual void displayImage(const QImage& img) = 0;
};

#endif // IVIEW_H
