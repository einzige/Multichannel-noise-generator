#include "noisepresenter.h"
#include <QDebug>

NoisePresenter::NoisePresenter(QObject *parent) : QObject(parent), mModel(new NoiseModel)
{}

void NoisePresenter::setRate(int rate) {
    mModel->setRate(rate);
}

void NoisePresenter::applyImpulseFilter(Channel::Identifier, int blackRate)
{
    qDebug() << blackRate;
    mModel->applyImpulseNoise(blackRate);
    IView *view = dynamic_cast<IView*>(sender());

    refreshView(view);
}

void NoisePresenter::appendView(IView *v)
{
    if(mViewList.contains(v)) return;

    mViewList.append(v);

    QObject *view_obj = dynamic_cast<QObject*>(v);

    QObject::connect(view_obj, SIGNAL(RestoreImage()),
                     this,       SLOT(restoreImage()));

    QObject::connect(view_obj, SIGNAL(ImageLoaded(const QImage&)),
                     this,       SLOT(loadImage  (const QImage&)));

    QObject::connect(view_obj, SIGNAL(RateChanged(int)),
                     this,       SLOT(setRate(int)));

    QObject::connect(view_obj, SIGNAL(ApplyImpulseNoise (Channel::Identifier, int)),
                     this,       SLOT(applyImpulseFilter(Channel::Identifier, int)));
}

void NoisePresenter::loadImage(const QImage &img)
{
    mModel->SetImage(img);
    refreshView();
}

void NoisePresenter::refreshView(IView *v) const {
    v->DisplayImage(mModel->GetImage());
}

void NoisePresenter::refreshView() const
{
    for (QList<IView*>::const_iterator it = mViewList.constBegin();
    it != mViewList.constEnd(); ++it) {
        refreshView(*it);
    }
}

void NoisePresenter::restoreImage()
{
    qDebug() << "----RESTORING----";
    mModel->ResetImage();

    IView *view = dynamic_cast<IView*>(sender());
    refreshView(view);
}
