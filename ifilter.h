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
    QHash< int, QList<float> > mask; // MAT_X

public:
    IMaskFilter(QHash< int, QList<float> > mask);

    static QHash< int, QList<float> > parseMask(QString s);
    static IMaskFilter fromStr(const QString& s);

    void setMask(const QHash< int, QList<float> >& mask);
    QHash< int, QList<float> > getMask();
};

QImage changeContrast( const QImage& image, int contrast );
QImage changeBrightness( const QImage& image, int brightness );
QImage changeGamma(const QImage& image, int gamma);

#endif // IFILTER_H
