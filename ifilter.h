#ifndef IFILTER_H
#define IFILTER_H

#include <QImage>
#include <QColor>
#include <QMessageBox>

class IFilter
{
public:
    virtual QImage apply(QImage) const;
};

QImage changeContrast( const QImage& image, int contrast );
QImage changeBrightness( const QImage& image, int brightness );
QImage changeGamma(const QImage& image, int gamma);

#endif // IFILTER_H
