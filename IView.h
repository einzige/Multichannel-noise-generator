#ifndef IVIEW_H
#define IVIEW_H

#include "channel.h"

class IView
{
public: // signals
    virtual void ApplyImpulseNoise(Channel::Identifier channel, int blackRate) = 0;
    //virtual void ApplyAdditionalNoise(Channel::Identifier, int rate, int maxMinus, int maxPlus) = 0;
    //virtual void ApplyMultiNoise(Channel::Identifier, int rate, int multiplier) = 0;
    virtual void RestoreImage() = 0;
    //virtual void ShowOriginal() = 0;
    //virtual void ChangeChannel() = 0;
    virtual void ImageLoaded(const QImage& img) = 0;

public: // slots
    //virtual void SetLastOperationTicks(int ticks) = 0;
    virtual void DisplayImage(const QImage& img) = 0;
};

#endif // IVIEW_H
