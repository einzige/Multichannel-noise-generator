#include "hlscs.h"

HLSCS::HLSCS(ColorSpace::Identifier id) : ColorSpace(id)
{
    AddChannel(Channel(Channel::H, new HueFilter()));
    AddChannel(Channel(Channel::L, new LightnessFilter()));
    AddChannel(Channel(Channel::S, new SaturationFilter()));
}

QImage HLSCS::restore()
{
    QImage h(mChannels[Channel::H].GetImage());
    QImage l(mChannels[Channel::L].GetImage());
    QImage s(mChannels[Channel::S].GetImage());

    int w    = h.width();
    int hh   = h.height();
    QImage::Format f = h.format();

    QImage res(w, hh, f);

    for(int x = 0; x < w; x++)
        for(int y = 0; y < hh; y++)
            res.setPixel(x, y, QColor::fromHsl(
                                        QColor(h.pixel(x,y)).hue(),
                                        QColor(s.pixel(x,y)).saturation(),
                                        QColor(l.pixel(x,y)).lightness()
                                      ).rgba());
    return res;
}
