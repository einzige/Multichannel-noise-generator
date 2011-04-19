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

    NoiseModel* mModel;
    QList<IView*> mViewList;

public slots:
    void restoreImage();
    void applyImpulseFilter(Channel::Identifier, int);
    void loadImage(const QImage&);
};

#endif // NOISEPRESENTER_H
