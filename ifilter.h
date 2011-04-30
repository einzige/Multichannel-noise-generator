#ifndef IFILTER_H
#define IFILTER_H

#include <QImage>
#include <QColor>
#include <QMessageBox>
#include <QHash>

class IFilter
{
public:
    virtual QImage apply(QImage) const;
};


// Mask filter defined by mat[n][m]
//
class IMaskFilter : public IFilter
{
protected:
    int offset;
    QHash< int, QList<float> > mask; // MAT_X

public:
                                      IMaskFilter(QHash< int, QList<float> > mask, int offset = 0);

    static QHash< int, QList<float> > parseMask(QString s);
    static IMaskFilter                fromStr(const QString& s);

    static QImage                     convolve(QImage img,
                                               QHash< int, QList<float> > mask,
                                               int filter_offset = 0, float filter_div = 1.);

    void                              setMask(const QHash< int, QList<float> >& mask);
    void                              setOffset(int);

    QHash< int, QList<float> >        getMask();
    int                               getOffset();
};

QImage changeContrast( const QImage& image, int contrast );
QImage changeBrightness( const QImage& image, int brightness );
QImage changeGamma(const QImage& image, int gamma);

#endif // IFILTER_H
