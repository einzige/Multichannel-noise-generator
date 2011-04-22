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
    void grayscale();
    void restoreImage();
    void rateChanged(int);
    void channelChanged(QString);
    void showHist();
    void imageLoaded(const QImage &img);
    void applyImpulseNoise(int blackRate);
    void applyAdditionalNoise(int maxDiff);
    void applyMultiNoise(int coef);
    void applyBrightness(int diff);
    void applyContrast(int diff);
    void inverse();
public slots:
    void loadImage();
    void displayImage(const QImage &img);

protected:
    void changeEvent(QEvent *e);

private:
    Ui::MainWindow *ui;
    QImage          sourceImage;
    QLabel*         imageLabel;

private slots:
    void on_applyBrightnessButton_clicked();
    void on_applyMultiButton_clicked();
    void on_applyAdditButton_clicked();
    void on_channelsBox_currentIndexChanged(QString );
    void on_applyImpulseButton_clicked();
};

#endif // MAINWINDOW_H
