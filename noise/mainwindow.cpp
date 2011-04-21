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
    mImageLabel = new QLabel("Загрузите изображение");
    mImageLabel->setBackgroundRole(QPalette::Dark);

    ui->scrollArea->setWidget(mImageLabel);

    mImageLabel->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    mImageLabel->setBackgroundRole(QPalette::Base);

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

    connect(ui->showProcessedButton, SIGNAL(clicked()), this, SIGNAL(RestoreImage()));
    connect(ui->noiseDial, SIGNAL(valueChanged(int)),   this, SIGNAL(RateChanged(int)));
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
        mSourceImage = QImage(file_name);
        if (mSourceImage.isNull())
        {
            QMessageBox::information(this, tr("Image Viewer"), tr("Cannot load %1.").arg(file_name));
            return;
        }
        if (mSourceImage.width() > 800)
        {
            QPixmap mp = QPixmap::fromImage(mSourceImage);
            mp = mp.scaledToWidth(800, Qt::SmoothTransformation);
            mSourceImage = mp.toImage();
        }

        DisplayImage(mSourceImage);
        emit ImageLoaded(mSourceImage);
    }
}

void MainWindow::DisplayImage(const QImage &img)
{
    mImageLabel->setPixmap(QPixmap::fromImage(img));
    mImageLabel->adjustSize();
}

void MainWindow::on_applyImpulseButton_clicked()
{
    emit ApplyImpulseNoise(Channel::R, ui->impulseBlackWhiteSlider->value());
}
