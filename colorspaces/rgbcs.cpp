#include "rgbcs.h"

RGBCS::RGBCS(ColorSpace::Identifier id) : ColorSpace(id)
{
    AddChannel(Channel(Channel::R, new RedFilter()));
    AddChannel(Channel(Channel::G, new GreenFilter()));
    AddChannel(Channel(Channel::B, new BlueFilter()));
}

QImage RGBCS::restore()
{
    QImage r(mChannels[Channel::R].GetImage());
    QImage g(mChannels[Channel::G].GetImage());
    QImage b(mChannels[Channel::B].GetImage());

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
