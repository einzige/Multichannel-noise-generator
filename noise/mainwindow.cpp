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

    ui->toolsDock->setWidget(ui->toolsScrollArea);
    ui->toolsLayout->setMargin(10);
    ui->toolsScrollAreaContent->setLayout(ui->toolsLayout);

    ui->brightnessDock->setWidget(ui->brightnessScrollArea);
    ui->brightnessLayout->setMargin(10);
    ui->brightnessScrollAreaContents->setLayout(ui->brightnessLayout);

    ui->filtersDock->setWidget(ui->filtersScrollArea);
    ui->filtersLayout->setMargin(5);
    ui->filtersScrollArea->setLayout(ui->filtersLayout);

    ui->multiTab->setLayout(ui->multiLayout);
    ui->multiLayout->setMargin(10);

    ui->additTab->setLayout(ui->additLayout);
    ui->additLayout->setMargin(10);

    ui->impulseTab->setLayout(ui->impulseLayout);
    ui->impulseLayout->setMargin(10);

    ui->autolevelsGroupBox->setLayout(ui->autolevelsLayout);
    ui->linContrastGroupBox->setLayout(ui->linContrastLayout);
    //ui->autolevelsLayout->setMargin(5);

    ui->brightnessDock->hide();
    // signals & slots
    connect(ui->loadButton, SIGNAL(clicked()), this, SLOT(loadImage()));

    connect(ui->showToolsAction,      SIGNAL(toggled(bool)),     ui->toolsDock,      SLOT(setShown(bool)));
    connect(ui->showBrightnessAction, SIGNAL(toggled(bool)),     ui->brightnessDock, SLOT(setShown(bool)));

    connect(ui->showProcessedButton,  SIGNAL(clicked()),         this, SIGNAL(restoreImage()));
    connect(ui->noiseDial,            SIGNAL(valueChanged(int)), this, SIGNAL(rateChanged(int)));
    connect(ui->filterOffsetBox,      SIGNAL(valueChanged(int)), this, SIGNAL(offsetChanged(int)));
    connect(ui->actionGrayscale,      SIGNAL(triggered()),       this, SIGNAL(grayscale()));
    connect(ui->histAction,           SIGNAL(triggered()),       this, SIGNAL(showHist()));
    connect(ui->invertseAction,       SIGNAL(triggered()),       this, SIGNAL(inverse()));
    connect(ui->equalizeAction,       SIGNAL(triggered()),       this, SIGNAL(equalize()));

    // test
    connect(ui->showConvolutionAction, SIGNAL(toggled(bool)), ui->filtersDock, SLOT(setShown(bool)));

    ui->collectionsTab->setLayout(ui->collectionsLayout);
    ui->collectionsLayout->setMargin(5);

    this->resize(1000, 600);
    this->move(50, 50);
    this->raise();
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
    QString file_name = QFileDialog::getOpenFileName(this, tr("Open File"), QDir::currentPath(), "Images(*.png *.jpg *.bmp)");

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
    emit applyImpulseNoise(ui->impulseBlackWhiteSlider->value());
}

void MainWindow::on_channelsBox_currentIndexChanged(QString channelName )
{
    emit channelChanged(channelName);
}

void MainWindow::on_applyAdditButton_clicked()
{
    emit applyAdditionalNoise(ui->additMaxPlusSlider->value());
}

void MainWindow::on_applyMultiButton_clicked()
{
    emit applyMultiNoise(ui->multiSlider->value());
}

void MainWindow::on_applyBrightnessButton_clicked()
{
    emit applyBrightness(ui->brightnessSlider->value());
    emit applyContrast(ui->contrastSlider->value());
    emit applyGamma(ui->expSlider->value());
}

void MainWindow::on_autolevelsApplyButton_clicked()
{
    emit applyAutoLevels(ui->autolevelsMinimumSlider->value(), ui->autolevelsMaximumSlider->value());
}

void MainWindow::setTicks(int ticks) {
    ui->ticks->display(ticks);
}

void MainWindow::on_linContrastApplyButton_clicked()
{
    emit applyAutoContrast(ui->linContrastMinSlider->value(), ui->linContrastMaxSlider->value());
}

void MainWindow::on_applyFilterButton_clicked()
{
    QString mask = ui->filterTextEdit->toPlainText();

    if (mask.trimmed().isEmpty()) return;

    if(ui->filterTypeCombo->currentText() == "Среднее арифметическое")
    {
        emit applyAverageConvolution(mask);
    }
    else if(ui->filterTypeCombo->currentText() == "Среднее геометрическое")
    {
        emit applyGeometricConvolution(mask);
    }
    else if(ui->filterTypeCombo->currentText() == "Дополняющий изображение")
    {
        emit applyAdditionalConvolution(mask);
    }
    else
    {
        emit applyMedianConvolution(mask);
    }
}

void MainWindow::on_collectionsList_currentTextChanged(QString currentText)
{
    if(currentText == "Лапласиан №2")
    {
        ui->filterTextEdit->setPlainText("1\t-2\t1");
        ui->filterTypeCombo->setCurrentIndex(3);
        ui->filterOffsetBox->setValue(0);
    }
    else if (currentText == "Лапласиан №1")
    {
        ui->filterTextEdit->setPlainText(QString("0\t1\t0\n") +
                                         QString("1\t-4\t1\n") +
                                         QString("0\t1\t0"));
        ui->filterTypeCombo->setCurrentIndex(3);
        ui->filterOffsetBox->setValue(0);
    }
    else if (currentText == "Инвертирование")
    {
        ui->filterTextEdit->setPlainText(QString("0\t0\t0\n") +
                                         QString("0\t-1\t0\n") +
                                         QString("0\t0\t0"));
        ui->filterTypeCombo->setCurrentIndex(0);
        ui->filterOffsetBox->setValue(255);
    }
    else if (currentText == "Гаус")
    {
        ui->filterTextEdit->setPlainText(QString("1\t2\t3\t2\t1\n") +
                                         QString("2\t3\t4\t3\t2\n") +
                                         QString("3\t4\t5\t4\t3\n") +
                                         QString("2\t3\t4\t3\t2\n") +
                                         QString("1\t2\t3\t2\t1"));
        ui->filterTypeCombo->setCurrentIndex(0);
        ui->filterOffsetBox->setValue(0);
    }
}


void MainWindow::on_twoDCleanerButton_clicked()
{
   emit this->apply2DCleaner(ui->filterTextEdit->toPlainText(), ui->twoDClenerDeal->value());
}
