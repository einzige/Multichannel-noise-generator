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
    void imageLoaded(const QImage &img);
    void applyImpulseNoise(Channel::Identifier channel, int blackRate);
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
    void on_channelsBox_currentIndexChanged(QString );
    void on_channelsBox_textChanged(QString );
    void on_applyImpulseButton_clicked();
};

#endif // MAINWINDOW_H
