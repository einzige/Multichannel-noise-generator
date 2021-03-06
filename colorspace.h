#ifndef COLORSPACE_H
#define COLORSPACE_H

#include "channel.h"
#include "ifilter.h"
#include <QHash>

class ColorSpace
{
public:
    enum Identifier { RGB, HLS, YUV, SMYK, HSV };

    ColorSpace();
    ColorSpace(ColorSpace::Identifier);
    ColorSpace(ColorSpace::Identifier, QList<Channel>);

            void   addChannel(const Channel&);
            bool   containsChannel(Channel::Identifier);
            QImage getChannelImage(Channel::Identifier);
    //virtual
            QImage restore();

            void   setInactual();
            void   setActual();
            void   applyFilter(IFilter*, Channel::Identifier);

            void   setImage(const QImage& img);

            ColorSpace::Identifier getId();

protected:
    QHash<Channel::Identifier, Channel> channels;
    ColorSpace::Identifier              id;
    bool                                actual;
};

#endif // COLORSPACE_H
