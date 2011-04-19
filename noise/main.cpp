#include <QtGui/QApplication>
#include "mainwindow.h"
#include <QTextCodec>

#include "../noisepresenter.h"

void initTextCodecs(const char *codecName)
{
    QTextCodec *codec = QTextCodec::codecForName(codecName);
    QTextCodec::setCodecForCStrings(codec);
    QTextCodec::setCodecForLocale(codec);
    QTextCodec::setCodecForTr(codec);
}

int main(int argc, char *argv[])
{
    initTextCodecs("UTF-8");
    QApplication a(argc, argv);
    MainWindow w;

    NoisePresenter np;
    np.appendView(&w);

    w.show();
    return a.exec();
}
