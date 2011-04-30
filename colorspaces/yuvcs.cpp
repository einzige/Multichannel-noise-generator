#include "yuvcs.h"

YUVCS::YUVCS(ColorSpace::Identifier id) : ColorSpace(id)
{
    addChannel(Channel(Channel::YUV_Y, new YFilter()));
    addChannel(Channel(Channel::YUV_U, new UFilter()));
    addChannel(Channel(Channel::YUV_V, new VFilter()));
}

QImage YUVCS::restore()
{
    QImage yy(channels[Channel::YUV_Y].getImage());
    QImage u(channels[Channel::YUV_U].getImage());
    QImage v(channels[Channel::YUV_V].getImage());

    int w = yy.width();
    int h = yy.height();

    QImage res(w, h, QImage::Format_ARGB32);

    for(int x = 0; x < w; x++)
        for(int y = 0; y < h; y++)
            res.setPixel(x, y, QColor( QColor(yy.pixel(x,y)).lightness(),
                                       QColor(u.pixel(x,y)).lightness(),
                                       QColor(v.pixel(x,y)).lightness()
                                      ).rgba());
    return res;
}
