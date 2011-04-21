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

    QImage getSourceImage();
    QImage getImage();
    QImage getChannelImage(Channel::Identifier);

    void   applyFilter(IFilter*);
    void   applyFilter(IFilter*, Channel::Identifier);

    void   setImage(const QImage&, bool replaceSource = false);
    void   resetImage();

    void   addColorSpace(ColorSpace cs);

protected:
    ColorSpace*  getCSByChannel(Channel::Identifier);

    QHash<ColorSpace::Identifier, ColorSpace> colorSpaces;

    QImage sourceImage;
    QImage image;
};

#endif // MODEL_H
