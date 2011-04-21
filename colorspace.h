#ifndef COLORSPACE_H
#define COLORSPACE_H

#include "channel.h"
#include "ifilter.h"
#include <QHash>

class ColorSpace
{
public:
    enum Identifier { RGB, HLS };

    ColorSpace();
    ColorSpace(ColorSpace::Identifier);
    ColorSpace(ColorSpace::Identifier, QList<Channel>);

            void   AddChannel(const Channel&);
            bool   ContainsChannel(Channel::Identifier);
            QImage GetChannelImage(Channel::Identifier);
    virtual QImage Restore();

            void   SetInactual();
            void   SetActual();
            void   ApplyFilter(IFilter*, Channel::Identifier);

            void   SetImage(const QImage& img);

            ColorSpace::Identifier GetId();

protected:
    QHash<Channel::Identifier, Channel> channels;
    ColorSpace::Identifier              _id;
    bool                                actual;
};

#endif // COLORSPACE_H
