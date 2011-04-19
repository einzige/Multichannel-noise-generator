#ifndef MODEL_H
#define MODEL_H

#include <QImage>
#include <QList>

#include "ifilter.h"
#include "colorspace.h"

class Model
{
public:
    Model();
    Model(const QImage&);

    QImage GetSourceImage();
    QImage GetImage();
    QImage GetChannelImage(Channel::Identifier);

    void   ApplyFilter(IFilter*);
    void   ApplyFilter(IFilter*, Channel::Identifier);

    void   SetImage(const QImage&);
    void   ResetImage();

    void   AddColorSpace(ColorSpace cs);

protected:
    ColorSpace*  GetCSByChannel(Channel::Identifier);

    QHash<ColorSpace::Identifier, ColorSpace> mColorSpaces;

    QImage mSourceImage;
    QImage mImage;
};

#endif // MODEL_H
