#include "color.h"

QColor assertRGBColor(int r, int g, int b, int a)
{
    r = r > 255 ? 255 : r;
    g = g > 255 ? 255 : g;
    b = b > 255 ? 255 : b;
    a = a > 255 ? 255 : a;

    r = r < 0 ? 0 : r;
    g = g < 0 ? 0 : g;
    b = b < 0 ? 0 : b;
    a = a < 0 ? 0 : a;

    return QColor(r, g, b, a);
}
