#include "noisepresenter.h"
#include <QDebug>

NoisePresenter::NoisePresenter(QObject *parent) : QObject(parent), mModel(new NoiseModel)
{}

void NoisePresenter::applyImpulseFilter(Channel::Identifier, int blackRate)
{
    mModel->applyImpulseNoise(blackRate);
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

    QObject::connect(view_obj, SIGNAL(ApplyImpulseNoise (Channel::Identifier, int)),
                     this,       SLOT(applyImpulseFilter(Channel::Identifier, int)));
}

void NoisePresenter::loadImage(const QImage &img)
{
    mModel->SetImage(img);
}

void NoisePresenter::restoreImage()
{
    qDebug() << "----RESTORING----";

    IView *view = dynamic_cast<IView*>(sender());
    mModel->ResetImage();

    view->DisplayImage(mModel->GetImage());
}
