#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QString>
#include <QFileDialog>
#include <QMessageBox>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // canvas
    imageLabel = new QLabel("Загрузите изображение");
    imageLabel->setBackgroundRole(QPalette::Dark);

    ui->scrollArea->setWidget(imageLabel);

    imageLabel->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    imageLabel->setBackgroundRole(QPalette::Base);

    // layouts
    ui->centralWidget->setLayout(ui->mainLayout);
    ui->scrollArea->setBackgroundRole(QPalette::Dark);

    //ui->toolsFrame->setLayout(ui->toolsLayout);
    ui->toolsDock->setWidget(ui->toolsScrollArea);
    ui->toolsLayout->setMargin(10);
    ui->toolsScrollAreaContent->setLayout(ui->toolsLayout);
    //ui->toolsScrollArea->setWidget(ui->toolsFrame);


    ui->multiTab->setLayout(ui->multiLayout);
    ui->multiLayout->setMargin(10);

    ui->additTab->setLayout(ui->additLayout);
    ui->additLayout->setMargin(10);

    ui->impulseTab->setLayout(ui->impulseLayout);
    ui->impulseLayout->setMargin(10);

    // signals & slots
    connect(ui->loadButton, SIGNAL(clicked()), this, SLOT(loadImage()));

    connect(ui->showProcessedButton, SIGNAL(clicked()), this, SIGNAL(restoreImage()));
    connect(ui->noiseDial, SIGNAL(valueChanged(int)),   this, SIGNAL(rateChanged(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void MainWindow::loadImage()
{
    QString file_name = QFileDialog::getOpenFileName(this, tr("Open File"), QDir::currentPath());

    if ( ! file_name.isEmpty())
    {
        sourceImage = QImage(file_name);
        if (sourceImage.isNull())
        {
            QMessageBox::information(this, tr("Image Viewer"), tr("Cannot load %1.").arg(file_name));
            return;
        }
        if (sourceImage.width() > 800)
        {
            QPixmap mp = QPixmap::fromImage(sourceImage);
            mp = mp.scaledToWidth(800, Qt::SmoothTransformation);
            sourceImage = mp.toImage();
        }

        displayImage(sourceImage);
        emit imageLoaded(sourceImage);
    }
}

void MainWindow::displayImage(const QImage &img)
{
    imageLabel->setPixmap(QPixmap::fromImage(img));
    imageLabel->adjustSize();
}

void MainWindow::on_applyImpulseButton_clicked()
{
    emit applyImpulseNoise(Channel::R, ui->impulseBlackWhiteSlider->value());
}
