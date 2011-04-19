#ifndef IFILTER_H
#define IFILTER_H

#include <QImage>
#include <QColor>
#include <QMessageBox>

class IFilter
{
public:
    virtual QImage Apply(QImage) const;
};

#endif // IFILTER_H
