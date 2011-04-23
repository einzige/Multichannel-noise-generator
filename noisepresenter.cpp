#include "noisepresenter.h"
#include <QDebug>

NoisePresenter::NoisePresenter(QObject *parent) : QObject(parent), model(new NoiseModel)
{}

void NoisePresenter::setChannel(QString channelName)
{
    Channel::Identifier channel = Channel::getChannelByName(channelName);

    model->setCurrentChannel(channel);

    IView *view = dynamic_cast<IView*>(sender());
    view->displayImage(model->getChannelImage(channel));

    qDebug() << "channel changed";
}

void NoisePresenter::setRate(int rate) {
    model->setRate(rate);
}

void NoisePresenter::applyImpulseNoise(int blackRate)
{
    model->applyImpulseNoise(blackRate);
    IView *view = dynamic_cast<IView*>(sender());

    refreshView(view);
}

void NoisePresenter::applyAdditionalNoise(int maxDiff)
{
    model->applyAdditionalNoise(maxDiff);
    IView *view = dynamic_cast<IView*>(sender());

    refreshView(view);
}

void NoisePresenter::applyMultiNoise(int coef)
{
    model->applyMultiNoise(coef);
    IView *view = dynamic_cast<IView*>(sender());

    refreshView(view);
}

void NoisePresenter::appendView(IView *v)
{
    if(viewList.contains(v)) return;

    viewList.append(v);

    QObject *view_obj = dynamic_cast<QObject*>(v);

    QObject::connect(view_obj, SIGNAL(restoreImage()),
                     this,       SLOT(restoreImage()));

    QObject::connect(view_obj, SIGNAL(showHist()),
                     this,       SLOT(showHist()));

    QObject::connect(view_obj, SIGNAL(grayscale()),
                     this,       SLOT(grayscale()));

    QObject::connect(view_obj, SIGNAL(inverse()),
                     this,       SLOT(inverse()));

    QObject::connect(view_obj, SIGNAL(equalize()),
                     this,       SLOT(equalize()));

    QObject::connect(view_obj, SIGNAL(imageLoaded(const QImage&)),
                     this,       SLOT(loadImage  (const QImage&)));

    QObject::connect(view_obj, SIGNAL(channelChanged(QString)),
                     this,       SLOT(setChannel(QString)));

    QObject::connect(view_obj, SIGNAL(rateChanged(int)),
                     this,       SLOT(setRate(int)));

    QObject::connect(view_obj, SIGNAL(applyImpulseNoise(int)),
                     this,       SLOT(applyImpulseNoise(int)));

    QObject::connect(view_obj, SIGNAL(applyAdditionalNoise(int)),
                     this,       SLOT(applyAdditionalNoise(int)));

    QObject::connect(view_obj, SIGNAL(applyMultiNoise(int)),
                     this,       SLOT(applyMultiNoise(int)));

    QObject::connect(view_obj, SIGNAL(applyBrightness(int)),
                     this,       SLOT(applyBrightnessFilter(int)));

    QObject::connect(view_obj, SIGNAL(applyContrast(int)),
                     this,       SLOT(applyContrastFilter(int)));

    QObject::connect(view_obj, SIGNAL(applyGamma(int)),
                     this,       SLOT(applyGamma(int)));
}

void NoisePresenter::applyGamma(int diff) {
    model->applyGammaFilter(diff);

    IView *view = dynamic_cast<IView*>(sender());
    refreshView(view);
}

void NoisePresenter::applyBrightnessFilter(int diff) {
    model->applyBrightnessFilter(diff);

    IView *view = dynamic_cast<IView*>(sender());
    refreshView(view);
}

void NoisePresenter::applyContrastFilter(int diff) {
    model->applyContrastFilter(diff);

    IView *view = dynamic_cast<IView*>(sender());
    refreshView(view);
}

void NoisePresenter::showHist()
{
    IView *view = dynamic_cast<IView*>(sender());
    view->displayImage(model->hist());
}

void NoisePresenter::grayscale()
{
    model->applyGrayscaleFilter();
    IView *view = dynamic_cast<IView*>(sender());
    refreshView(view);
}

void NoisePresenter::inverse()
{
    model->applyInverseFilter();
    IView *view = dynamic_cast<IView*>(sender());
    refreshView(view);
}

void NoisePresenter::equalize()
{
    model->applyEqualizeFilter();
    IView *view = dynamic_cast<IView*>(sender());
    refreshView(view);
}

void NoisePresenter::loadImage(const QImage &img)
{
    model->setImage(img, true);
    refreshView();
}

void NoisePresenter::refreshView(IView *v) const {
    v->displayImage(model->getImage());
}

void NoisePresenter::refreshView() const
{
    for (QList<IView*>::const_iterator it = viewList.constBegin();
    it != viewList.constEnd(); ++it) {
        refreshView(*it);
    }
}

void NoisePresenter::restoreImage()
{
    qDebug() << "----RESTORING----";
    model->resetImage();

    IView *view = dynamic_cast<IView*>(sender());
    refreshView(view);
}
