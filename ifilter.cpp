#include "ifilter.h"

QImage IFilter::apply(QImage img) const
{ return img; }

// =============================
//
// IMaskFilter
//
// =============================

#include <QRegExp>
#include <QStringList>
#include <QDebug>
#include "math.h"

using namespace std;

#define WEIGHTS_DELIMETER " "

IMaskFilter::IMaskFilter(QHash< int, QList<float> > mask, int offset) {
    this->mask   = mask;
    this->offset = offset;
    qDebug() << "here";
}

void IMaskFilter::setMask(const QHash<int, QList<float> >& mask) {
    this->mask = mask;
}

void IMaskFilter::setOffset(int offset){
    qDebug() << "SET OFFSET: " << offset;
    this->offset = offset;
}

QHash< int, QList<float> > IMaskFilter::getMask() {
    return mask;
}
int IMaskFilter::getOffset(){
    return offset;
}

// static
QImage IMaskFilter::convolve(QImage img, QHash< int, QList<float> > mask, int filter_offset, float filter_div)
{
    QImage res(img);
    int xfilter_size = mask[0].count();
    int yfilter_size = mask.count();

    int xradius = xfilter_size / 2;
    int yradius = yfilter_size / 2;

    for (int y = 0; y < img.height(); ++y)
    {
        for (int x = 0; x < img.width(); ++x)
        {
            int c_pixel_x = x + xradius;
            int c_pixel_y = y + yradius;

            if (c_pixel_x >= img.width() || c_pixel_y >= img.height())
                continue;

            float new_r, new_g, new_b;
            new_r = new_g = new_b = 0;

            for (int j = 0; j < yfilter_size; j++)
            {
                int yv = min(max(y - yradius + j, 0), img.height() - yradius);

                for (int i = 0; i < xfilter_size; i++)
                {
                    int xv = min(max(x-xradius + i, 0), img.width() - xradius);

                    QColor c(img.pixel(xv, yv));

                    new_r += c.red()   * mask[j][i];
                    new_g += c.green() * mask[j][i];
                    new_b += c.blue()  * mask[j][i];
                }
            }

            new_r = (new_r/filter_div) + filter_offset;
            new_g = (new_g/filter_div) + filter_offset;
            new_b = (new_b/filter_div) + filter_offset;

            new_r = (new_r > 255) ? 255 : ((new_r < 0) ? 0:new_r);
            new_g = (new_g > 255) ? 255 : ((new_g < 0) ? 0:new_g);
            new_b = (new_b > 255) ? 255 : ((new_b < 0) ? 0:new_b);



            res.setPixel(c_pixel_x, c_pixel_y, QColor((int)new_r,
                                      (int)new_g,
                                      (int)new_b, 255).rgb());
        }
    }
    return res;
}

// static
IMaskFilter IMaskFilter::fromStr(const QString &s)
{
    return IMaskFilter(IMaskFilter::parseMask(s));
}
// static
QHash< int, QList<float> > IMaskFilter::parseMask(QString s)
{
    s = s.replace(QRegExp("[ \t]+"), WEIGHTS_DELIMETER)
         .replace("\r", "")
         .replace(QRegExp("\\s*\n\\s*"), "\n")
         .replace(QRegExp("^\\s*"), "")
         .replace(QRegExp("\\s*$"), "")
         .replace(QRegExp("^$"), "");

    QHash< int, QList<float> > mask;
    QStringList lines = s.split("\n");

    qDebug() << "lines: " << lines;

    for(int i = 0; i < lines.count(); i++)
    {
        QStringList weights = lines[i].split(WEIGHTS_DELIMETER);

        QList<float> line;
        foreach(QString ws, weights)
            line.push_back(ws.toFloat());
        mask[i] = line;
    }
    qDebug() << "mask" << mask;

    return mask;
}

// ========================================
//
// ADDITIONAL FUNCTIONS: FIXME: cleanup all
//
// ========================================

#include <QImage>
#include "math.h"

template<class T>
inline const T& kClamp( const T& x, const T& low, const T& high )
{
    if      ( x < low )  return low;
    else if ( high < x ) return high;
    else                 return x;
}

inline int changeBrightness( int value, int brightness )
{
    return kClamp( value + brightness * 255 / 100, 0, 255 );
}

inline int changeContrast( int value, int contrast )
{
    return kClamp((( value - 127 ) * contrast / 100 ) + 127, 0, 255 );
}

inline int changeGamma( int value, int gamma )
{
    return kClamp( int( pow( value / 255.0, 100.0 / gamma ) * 255 ), 0, 255 );
}

inline int changeUsingTable( int value, const int table[] )
{
    return table[ value ];
}

template< int operation( int, int ) >
static
        QImage changeImage( const QImage& image, int value )
{
    QImage im = image;
    im.detach();
    if( im.numColors() == 0 ) /* truecolor */
    {
        if( im.format() != QImage::Format_RGB32 ) /* just in case */
            im = im.convertToFormat( QImage::Format_RGB32 );
        int table[ 256 ];
        for( int i = 0;
             i < 256;
             ++i )
            table[ i ] = operation( i, value );
        if( im.hasAlphaChannel() )
        {
            for( int y = 0;
                 y < im.height();
                 ++y )
            {
                QRgb* line = reinterpret_cast< QRgb* >( im.scanLine( y ));
                for( int x = 0;
                     x < im.width();
                     ++x )
                    line[ x ] = qRgba( changeUsingTable( qRed( line[ x ] ), table ),
                                       changeUsingTable( qGreen( line[ x ] ), table ),
                                       changeUsingTable( qBlue( line[ x ] ), table ),
                                       changeUsingTable( qAlpha( line[ x ] ), table ));
            }
        }
        else
        {
            for( int y = 0;
                 y < im.height();
                 ++y )
            {
                QRgb* line = reinterpret_cast< QRgb* >( im.scanLine( y ));
                for( int x = 0;
                     x < im.width();
                     ++x )
                    line[ x ] = qRgb( changeUsingTable( qRed( line[ x ] ), table ),
                                      changeUsingTable( qGreen( line[ x ] ), table ),
                                      changeUsingTable( qBlue( line[ x ] ), table ));
            }
        }
    }
    else
    {
        QVector<QRgb> colors = im.colorTable();
        for( int i = 0;
             i < im.numColors();
             ++i )
            colors[ i ] = qRgb( operation( qRed( colors[ i ] ), value ),
                                operation( qGreen( colors[ i ] ), value ),
                                operation( qBlue( colors[ i ] ), value ));
    }
    return im;
}


// brightness is multiplied by 100 in order to avoid floating point numbers
QImage changeBrightness( const QImage& image, int brightness )
{
    if( brightness == 0 ) // no change
        return image;
    return changeImage< changeBrightness >( image, brightness );
}


// contrast is multiplied by 100 in order to avoid floating point numbers
QImage changeContrast( const QImage& image, int contrast )
{
    if( contrast == 100 ) // no change
        return image;
    return changeImage< changeContrast >( image, contrast );
}

// gamma is multiplied by 100 in order to avoid floating point numbers
QImage changeGamma( const QImage& image, int gamma )
{
    if( gamma == 100 ) // no change
        return image;
    return changeImage< changeGamma >( image, gamma );
}
