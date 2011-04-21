#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QImage>
#include <QLabel>
#include "../IView.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow, public IView {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

signals:
    void RestoreImage();
    void RateChanged(int);
    void ImageLoaded(const QImage &img);
    void ApplyImpulseNoise(Channel::Identifier channel, int blackRate);
public slots:
    void loadImage();
    void DisplayImage(const QImage &img);

protected:
    void changeEvent(QEvent *e);

private:
    Ui::MainWindow *ui;
    QImage          mSourceImage;
    QLabel*         mImageLabel;

private slots:
    void on_applyImpulseButton_clicked();
};

#endif // MAINWINDOW_H
