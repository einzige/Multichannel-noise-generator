#ifndef NOISEPRESENTER_H
#define NOISEPRESENTER_H

#include <QObject>
#include "noisemodel.h"
#include "IView.h"

class IView;
template <typename T> class QList;

class NoisePresenter : public QObject
{
    Q_OBJECT

public:
    explicit NoisePresenter(QObject *parent = 0);
    void appendView(IView *v);

private:
    void refreshView() const;
    void refreshView(IView* v) const;

    NoiseModel* model;
    QList<IView*> viewList;

public slots:
    void grayscale();
    void inverse();
    void equalize();
    void setRate(int);
    void setFilterOffset(int);
    void restoreImage();
    void applyImpulseNoise(int);
    void applyAdditionalNoise(int);
    void applyBrightnessFilter(int);
    void applyContrastFilter(int);
    void applyGamma(int);
    void applyAutoLevels(int, int);
    void applyAutoContrast(int, int);

    void applyAverageConvolution(QString);
    void applyGeometricConvolution(QString);
    void applyMedianConvolution(QString);
    void applyAdditionalConvolution(QString);

    void apply2DCleaner(QString, int);

    void applyMultiNoise(int);
    void loadImage(const QImage&);
    void setChannel(QString channelName);
    void showHist();

    void calcMSAD();
    void calcDelta();
};

#endif // NOISEPRESENTER_H
