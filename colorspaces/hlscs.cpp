#include "hlscs.h"

HSLCS::HSLCS(ColorSpace::Identifier id) : ColorSpace(id)
{
    addChannel(Channel(Channel::H, new HueFilter()));
    addChannel(Channel(Channel::L, new LightnessFilter()));
    addChannel(Channel(Channel::S, new SaturationFilter()));
}

QImage HSLCS::restore()
{
    QImage h(channels[Channel::H].getImage());
    QImage l(channels[Channel::L].getImage());
    QImage s(channels[Channel::S].getImage());

    int w    = h.width();
    int hh   = h.height();
    QImage::Format f = h.format();

    QImage res(w, hh, f);

    for(int x = 0; x < w; x++)
        for(int y = 0; y < hh; y++)
            res.setPixel(x, y, QColor::fromHsl(
                                        QColor(h.pixel(x,y)).lightness(),
                                        QColor(s.pixel(x,y)).lightness(),
                                        QColor(l.pixel(x,y)).lightness()
                                      ).rgba());
    return res;
}
