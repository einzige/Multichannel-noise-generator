#include "rgbcs.h"

RGBCS::RGBCS(ColorSpace::Identifier id) : ColorSpace(id)
{
    addChannel(Channel(Channel::R, new RedFilter()));
    addChannel(Channel(Channel::G, new GreenFilter()));
    addChannel(Channel(Channel::B, new BlueFilter()));
}

QImage RGBCS::restore()
{
    QImage r(channels[Channel::R].getImage());
    QImage g(channels[Channel::G].getImage());
    QImage b(channels[Channel::B].getImage());

    int w    = r.width();
    int h    = r.height();
    QImage::Format f = r.format();

    QImage res(w, h, f);

    for(int x = 0; x < w; x++)
        for(int y = 0; y < h; y++)
            res.setPixel(x, y, QColor(
                                        QColor(r.pixel(x,y)).red(),
                                        QColor(g.pixel(x,y)).green(),
                                        QColor(b.pixel(x,y)).blue()
                                      ).rgba());
    return res;
}
