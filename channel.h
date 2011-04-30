#ifndef CHANNEL_H
#define CHANNEL_H

#include "ifilter.h"
#include <QString>

class Channel
{
public:
    enum Identifier { RGB_R=0, RGB_G,  RGB_B,
                      HSL_H,   HSL_S,  HSL_L,
                      HSV_H,   HSV_S,  HSV_V,
                      YUV_Y,   YUV_U,  YUV_V,
                      CMYK_C,  CMYK_M, SMYK_Y, SMYK_K,
                      UNDEFINED };

    Channel();
    Channel(Channel::Identifier, IFilter*);
    Channel(Channel::Identifier, IFilter*, const QImage&);

    IFilter*   getFilter();
    Identifier getID() const;
    void       fetchFrom(const QImage&);
    QImage     getImage();
    void       applyFilter(IFilter*);

    static Channel::Identifier getChannelByName(const QString& name);

private:
    IFilter*   filter;
    Identifier identifier;
    QImage     image;
};

#endif // CHANNEL_H
