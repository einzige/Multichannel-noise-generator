/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Thu Apr 21 20:02:42 2011
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDial>
#include <QtGui/QDockWidget>
#include <QtGui/QFormLayout>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLCDNumber>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QScrollArea>
#include <QtGui/QSlider>
#include <QtGui/QSpacerItem>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *loadAction;
    QAction *exitAction;
    QWidget *centralWidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *mainLayout;
    QVBoxLayout *contentLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menu_3;
    QStatusBar *statusBar;
    QDockWidget *toolsDock;
    QWidget *dockWidgetContents;
    QScrollArea *toolsScrollArea;
    QWidget *toolsScrollAreaContent;
    QFrame *toolsFrame;
    QWidget *layoutWidget;
    QVBoxLayout *toolsLayout;
    QGroupBox *noiseRateGroup;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout;
    QLCDNumber *lcdNumber;
    QDial *noiseDial;
    QLabel *filtersLabel;
    QTabWidget *noiseTabs;
    QWidget *impulseTab;
    QWidget *verticalLayoutWidget_4;
    QVBoxLayout *impulseLayout;
    QGridLayout *gridLayout;
    QLabel *label_6;
    QSlider *impulseBlackWhiteSlider;
    QLabel *label_7;
    QPushButton *applyImpulseButton;
    QWidget *additTab;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *additLayout;
    QFormLayout *formLayout_2;
    QLabel *label_4;
    QLCDNumber *lcdNumber_3;
    QSlider *additMaxMinusSlider;
    QFormLayout *formLayout_4;
    QLabel *label_5;
    QLCDNumber *lcdNumber_4;
    QSlider *additMaxPlusSlider;
    QPushButton *applyAdditButton;
    QWidget *multiTab;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *multiLayout;
    QVBoxLayout *verticalLayout_2;
    QFormLayout *formLayout;
    QLabel *label_3;
    QLCDNumber *lcdNumber_2;
    QSlider *multiSlider;
    QPushButton *applyMultiButton;
    QSpacerItem *verticalSpacer_3;
    QFrame *hline0;
    QPushButton *loadButton;
    QPushButton *showProcessedButton;
    QFrame *hline1;
    QCheckBox *showOriginal;
    QFrame *hline2;
    QFormLayout *channelsLayout;
    QLabel *channelsLabel;
    QComboBox *channelsBox;
    QSpacerItem *verticalSpacer;
    QProgressBar *progressBar;
    QSpacerItem *verticalSpacer_2;
    QFormLayout *ticksLayout;
    QLabel *label;
    QLCDNumber *ticks;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(711, 533);
        loadAction = new QAction(MainWindow);
        loadAction->setObjectName(QString::fromUtf8("loadAction"));
        exitAction = new QAction(MainWindow);
        exitAction->setObjectName(QString::fromUtf8("exitAction"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayoutWidget = new QWidget(centralWidget);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(0, 0, 701, 568));
        mainLayout = new QHBoxLayout(horizontalLayoutWidget);
        mainLayout->setSpacing(6);
        mainLayout->setContentsMargins(11, 11, 11, 11);
        mainLayout->setObjectName(QString::fromUtf8("mainLayout"));
        mainLayout->setContentsMargins(5, 5, 10, 5);
        contentLayout = new QVBoxLayout();
        contentLayout->setSpacing(6);
        contentLayout->setObjectName(QString::fromUtf8("contentLayout"));
        scrollArea = new QScrollArea(horizontalLayoutWidget);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 682, 554));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(scrollAreaWidgetContents->sizePolicy().hasHeightForWidth());
        scrollAreaWidgetContents->setSizePolicy(sizePolicy);
        scrollArea->setWidget(scrollAreaWidgetContents);

        contentLayout->addWidget(scrollArea);


        mainLayout->addLayout(contentLayout);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 711, 27));
        menu = new QMenu(menuBar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QString::fromUtf8("menu_2"));
        menu_3 = new QMenu(menuBar);
        menu_3->setObjectName(QString::fromUtf8("menu_3"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);
        toolsDock = new QDockWidget(MainWindow);
        toolsDock->setObjectName(QString::fromUtf8("toolsDock"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(toolsDock->sizePolicy().hasHeightForWidth());
        toolsDock->setSizePolicy(sizePolicy1);
        toolsDock->setMinimumSize(QSize(250, 41));
        toolsDock->setFloating(false);
        toolsDock->setFeatures(QDockWidget::AllDockWidgetFeatures);
        toolsDock->setAllowedAreas(Qt::LeftDockWidgetArea|Qt::RightDockWidgetArea);
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QString::fromUtf8("dockWidgetContents"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(200);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(dockWidgetContents->sizePolicy().hasHeightForWidth());
        dockWidgetContents->setSizePolicy(sizePolicy2);
        dockWidgetContents->setMinimumSize(QSize(200, 0));
        toolsScrollArea = new QScrollArea(dockWidgetContents);
        toolsScrollArea->setObjectName(QString::fromUtf8("toolsScrollArea"));
        toolsScrollArea->setGeometry(QRect(0, 0, 251, 411));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(200);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(toolsScrollArea->sizePolicy().hasHeightForWidth());
        toolsScrollArea->setSizePolicy(sizePolicy3);
        toolsScrollArea->setMinimumSize(QSize(200, 0));
        toolsScrollArea->setFrameShape(QFrame::NoFrame);
        toolsScrollArea->setFrameShadow(QFrame::Plain);
        toolsScrollArea->setLineWidth(0);
        toolsScrollArea->setWidgetResizable(true);
        toolsScrollAreaContent = new QWidget();
        toolsScrollAreaContent->setObjectName(QString::fromUtf8("toolsScrollAreaContent"));
        toolsScrollAreaContent->setGeometry(QRect(0, 0, 251, 411));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(200);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(toolsScrollAreaContent->sizePolicy().hasHeightForWidth());
        toolsScrollAreaContent->setSizePolicy(sizePolicy4);
        toolsScrollAreaContent->setMinimumSize(QSize(200, 0));
        toolsFrame = new QFrame(toolsScrollAreaContent);
        toolsFrame->setObjectName(QString::fromUtf8("toolsFrame"));
        toolsFrame->setGeometry(QRect(0, 0, 231, 401));
        toolsFrame->setFrameShape(QFrame::NoFrame);
        toolsFrame->setFrameShadow(QFrame::Raised);
        layoutWidget = new QWidget(toolsFrame);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 0, 241, 558));
        toolsLayout = new QVBoxLayout(layoutWidget);
        toolsLayout->setSpacing(6);
        toolsLayout->setContentsMargins(10, 10, 10, 10);
        toolsLayout->setObjectName(QString::fromUtf8("toolsLayout"));
        toolsLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        toolsLayout->setContentsMargins(0, 0, 0, 0);
        noiseRateGroup = new QGroupBox(layoutWidget);
        noiseRateGroup->setObjectName(QString::fromUtf8("noiseRateGroup"));
        noiseRateGroup->setMinimumSize(QSize(0, 120));
        noiseRateGroup->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        horizontalLayoutWidget_2 = new QWidget(noiseRateGroup);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(10, 30, 181, 79));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        lcdNumber = new QLCDNumber(horizontalLayoutWidget_2);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));
        QSizePolicy sizePolicy5(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(lcdNumber->sizePolicy().hasHeightForWidth());
        lcdNumber->setSizePolicy(sizePolicy5);
        lcdNumber->setMinimumSize(QSize(10, 10));
        lcdNumber->setMaximumSize(QSize(80, 40));
        lcdNumber->setLayoutDirection(Qt::LeftToRight);
        lcdNumber->setStyleSheet(QString::fromUtf8("color:gray;\n"
"font-size:12pt;\n"
""));
        lcdNumber->setFrameShape(QFrame::NoFrame);
        lcdNumber->setLineWidth(1);
        lcdNumber->setNumDigits(3);
        lcdNumber->setProperty("intValue", QVariant(1));

        horizontalLayout->addWidget(lcdNumber);

        noiseDial = new QDial(horizontalLayoutWidget_2);
        noiseDial->setObjectName(QString::fromUtf8("noiseDial"));
        sizePolicy5.setHeightForWidth(noiseDial->sizePolicy().hasHeightForWidth());
        noiseDial->setSizePolicy(sizePolicy5);
        noiseDial->setMinimumSize(QSize(10, 10));
        noiseDial->setLayoutDirection(Qt::LeftToRight);
        noiseDial->setAutoFillBackground(false);
        noiseDial->setStyleSheet(QString::fromUtf8(""));
        noiseDial->setMinimum(1);
        noiseDial->setMaximum(100);
        noiseDial->setSliderPosition(1);
        noiseDial->setTracking(true);
        noiseDial->setInvertedAppearance(false);
        noiseDial->setInvertedControls(false);
        noiseDial->setWrapping(false);
        noiseDial->setNotchesVisible(true);

        horizontalLayout->addWidget(noiseDial);


        toolsLayout->addWidget(noiseRateGroup);

        filtersLabel = new QLabel(layoutWidget);
        filtersLabel->setObjectName(QString::fromUtf8("filtersLabel"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        filtersLabel->setFont(font);
        filtersLabel->setStyleSheet(QString::fromUtf8(""));
        filtersLabel->setAlignment(Qt::AlignCenter);

        toolsLayout->addWidget(filtersLabel);

        noiseTabs = new QTabWidget(layoutWidget);
        noiseTabs->setObjectName(QString::fromUtf8("noiseTabs"));
        QSizePolicy sizePolicy6(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(noiseTabs->sizePolicy().hasHeightForWidth());
        noiseTabs->setSizePolicy(sizePolicy6);
        noiseTabs->setMinimumSize(QSize(0, 0));
        noiseTabs->setMaximumSize(QSize(16777, 16777215));
        noiseTabs->setTabPosition(QTabWidget::North);
        noiseTabs->setTabShape(QTabWidget::Rounded);
        impulseTab = new QWidget();
        impulseTab->setObjectName(QString::fromUtf8("impulseTab"));
        verticalLayoutWidget_4 = new QWidget(impulseTab);
        verticalLayoutWidget_4->setObjectName(QString::fromUtf8("verticalLayoutWidget_4"));
        verticalLayoutWidget_4->setGeometry(QRect(0, 0, 211, 151));
        impulseLayout = new QVBoxLayout(verticalLayoutWidget_4);
        impulseLayout->setSpacing(6);
        impulseLayout->setContentsMargins(11, 11, 11, 11);
        impulseLayout->setObjectName(QString::fromUtf8("impulseLayout"));
        impulseLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetMaximumSize);
        label_6 = new QLabel(verticalLayoutWidget_4);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 0, 0, 1, 1);

        impulseBlackWhiteSlider = new QSlider(verticalLayoutWidget_4);
        impulseBlackWhiteSlider->setObjectName(QString::fromUtf8("impulseBlackWhiteSlider"));
        impulseBlackWhiteSlider->setMaximum(100);
        impulseBlackWhiteSlider->setSliderPosition(50);
        impulseBlackWhiteSlider->setOrientation(Qt::Horizontal);
        impulseBlackWhiteSlider->setInvertedAppearance(false);
        impulseBlackWhiteSlider->setTickPosition(QSlider::TicksBothSides);

        gridLayout->addWidget(impulseBlackWhiteSlider, 0, 1, 1, 1);

        label_7 = new QLabel(verticalLayoutWidget_4);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 0, 2, 1, 1);


        impulseLayout->addLayout(gridLayout);

        applyImpulseButton = new QPushButton(verticalLayoutWidget_4);
        applyImpulseButton->setObjectName(QString::fromUtf8("applyImpulseButton"));

        impulseLayout->addWidget(applyImpulseButton);

        noiseTabs->addTab(impulseTab, QString());
        additTab = new QWidget();
        additTab->setObjectName(QString::fromUtf8("additTab"));
        verticalLayoutWidget_2 = new QWidget(additTab);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(0, 0, 222, 171));
        additLayout = new QVBoxLayout(verticalLayoutWidget_2);
        additLayout->setSpacing(6);
        additLayout->setContentsMargins(11, 11, 11, 11);
        additLayout->setObjectName(QString::fromUtf8("additLayout"));
        additLayout->setContentsMargins(0, 0, 0, 0);
        formLayout_2 = new QFormLayout();
        formLayout_2->setSpacing(6);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        formLayout_2->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        label_4 = new QLabel(verticalLayoutWidget_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_4);

        lcdNumber_3 = new QLCDNumber(verticalLayoutWidget_2);
        lcdNumber_3->setObjectName(QString::fromUtf8("lcdNumber_3"));
        lcdNumber_3->setFrameShape(QFrame::NoFrame);
        lcdNumber_3->setFrameShadow(QFrame::Sunken);
        lcdNumber_3->setSegmentStyle(QLCDNumber::Flat);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, lcdNumber_3);


        additLayout->addLayout(formLayout_2);

        additMaxMinusSlider = new QSlider(verticalLayoutWidget_2);
        additMaxMinusSlider->setObjectName(QString::fromUtf8("additMaxMinusSlider"));
        additMaxMinusSlider->setMaximum(255);
        additMaxMinusSlider->setOrientation(Qt::Horizontal);
        additMaxMinusSlider->setTickPosition(QSlider::TicksAbove);

        additLayout->addWidget(additMaxMinusSlider);

        formLayout_4 = new QFormLayout();
        formLayout_4->setSpacing(6);
        formLayout_4->setObjectName(QString::fromUtf8("formLayout_4"));
        formLayout_4->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        label_5 = new QLabel(verticalLayoutWidget_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        formLayout_4->setWidget(0, QFormLayout::LabelRole, label_5);

        lcdNumber_4 = new QLCDNumber(verticalLayoutWidget_2);
        lcdNumber_4->setObjectName(QString::fromUtf8("lcdNumber_4"));
        lcdNumber_4->setFrameShape(QFrame::NoFrame);
        lcdNumber_4->setFrameShadow(QFrame::Sunken);
        lcdNumber_4->setSegmentStyle(QLCDNumber::Flat);

        formLayout_4->setWidget(0, QFormLayout::FieldRole, lcdNumber_4);


        additLayout->addLayout(formLayout_4);

        additMaxPlusSlider = new QSlider(verticalLayoutWidget_2);
        additMaxPlusSlider->setObjectName(QString::fromUtf8("additMaxPlusSlider"));
        additMaxPlusSlider->setMaximum(255);
        additMaxPlusSlider->setOrientation(Qt::Horizontal);
        additMaxPlusSlider->setTickPosition(QSlider::TicksAbove);

        additLayout->addWidget(additMaxPlusSlider);

        applyAdditButton = new QPushButton(verticalLayoutWidget_2);
        applyAdditButton->setObjectName(QString::fromUtf8("applyAdditButton"));

        additLayout->addWidget(applyAdditButton);

        noiseTabs->addTab(additTab, QString());
        multiTab = new QWidget();
        multiTab->setObjectName(QString::fromUtf8("multiTab"));
        verticalLayoutWidget = new QWidget(multiTab);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 0, 261, 121));
        multiLayout = new QVBoxLayout(verticalLayoutWidget);
        multiLayout->setSpacing(6);
        multiLayout->setContentsMargins(5, 5, 5, 5);
        multiLayout->setObjectName(QString::fromUtf8("multiLayout"));
        multiLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setSizeConstraint(QLayout::SetMinimumSize);
        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_3);

        lcdNumber_2 = new QLCDNumber(verticalLayoutWidget);
        lcdNumber_2->setObjectName(QString::fromUtf8("lcdNumber_2"));
        lcdNumber_2->setFrameShape(QFrame::NoFrame);
        lcdNumber_2->setFrameShadow(QFrame::Sunken);
        lcdNumber_2->setSegmentStyle(QLCDNumber::Flat);

        formLayout->setWidget(0, QFormLayout::FieldRole, lcdNumber_2);


        verticalLayout_2->addLayout(formLayout);

        multiSlider = new QSlider(verticalLayoutWidget);
        multiSlider->setObjectName(QString::fromUtf8("multiSlider"));
        multiSlider->setMinimum(0);
        multiSlider->setMaximum(100);
        multiSlider->setOrientation(Qt::Horizontal);
        multiSlider->setTickPosition(QSlider::TicksBothSides);

        verticalLayout_2->addWidget(multiSlider);


        multiLayout->addLayout(verticalLayout_2);

        applyMultiButton = new QPushButton(verticalLayoutWidget);
        applyMultiButton->setObjectName(QString::fromUtf8("applyMultiButton"));

        multiLayout->addWidget(applyMultiButton);

        multiLayout->setStretch(1, 1);
        noiseTabs->addTab(multiTab, QString());

        toolsLayout->addWidget(noiseTabs);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        toolsLayout->addItem(verticalSpacer_3);

        hline0 = new QFrame(layoutWidget);
        hline0->setObjectName(QString::fromUtf8("hline0"));
        hline0->setFrameShape(QFrame::HLine);
        hline0->setFrameShadow(QFrame::Sunken);

        toolsLayout->addWidget(hline0);

        loadButton = new QPushButton(layoutWidget);
        loadButton->setObjectName(QString::fromUtf8("loadButton"));
        QSizePolicy sizePolicy7(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy7.setHorizontalStretch(0);
        sizePolicy7.setVerticalStretch(0);
        sizePolicy7.setHeightForWidth(loadButton->sizePolicy().hasHeightForWidth());
        loadButton->setSizePolicy(sizePolicy7);
        loadButton->setMinimumSize(QSize(0, 0));
        loadButton->setCheckable(false);

        toolsLayout->addWidget(loadButton);

        showProcessedButton = new QPushButton(layoutWidget);
        showProcessedButton->setObjectName(QString::fromUtf8("showProcessedButton"));
        showProcessedButton->setMinimumSize(QSize(0, 0));

        toolsLayout->addWidget(showProcessedButton);

        hline1 = new QFrame(layoutWidget);
        hline1->setObjectName(QString::fromUtf8("hline1"));
        hline1->setFrameShape(QFrame::HLine);
        hline1->setFrameShadow(QFrame::Sunken);

        toolsLayout->addWidget(hline1);

        showOriginal = new QCheckBox(layoutWidget);
        showOriginal->setObjectName(QString::fromUtf8("showOriginal"));

        toolsLayout->addWidget(showOriginal);

        hline2 = new QFrame(layoutWidget);
        hline2->setObjectName(QString::fromUtf8("hline2"));
        hline2->setFrameShape(QFrame::HLine);
        hline2->setFrameShadow(QFrame::Sunken);

        toolsLayout->addWidget(hline2);

        channelsLayout = new QFormLayout();
        channelsLayout->setSpacing(6);
        channelsLayout->setObjectName(QString::fromUtf8("channelsLayout"));
        channelsLabel = new QLabel(layoutWidget);
        channelsLabel->setObjectName(QString::fromUtf8("channelsLabel"));

        channelsLayout->setWidget(1, QFormLayout::LabelRole, channelsLabel);

        channelsBox = new QComboBox(layoutWidget);
        channelsBox->setObjectName(QString::fromUtf8("channelsBox"));

        channelsLayout->setWidget(1, QFormLayout::FieldRole, channelsBox);


        toolsLayout->addLayout(channelsLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        toolsLayout->addItem(verticalSpacer);

        progressBar = new QProgressBar(layoutWidget);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setEnabled(true);
        sizePolicy7.setHeightForWidth(progressBar->sizePolicy().hasHeightForWidth());
        progressBar->setSizePolicy(sizePolicy7);
        progressBar->setAutoFillBackground(true);
        progressBar->setStyleSheet(QString::fromUtf8(""));
        progressBar->setMaximum(100);
        progressBar->setValue(0);
        progressBar->setTextVisible(true);
        progressBar->setOrientation(Qt::Horizontal);
        progressBar->setInvertedAppearance(false);

        toolsLayout->addWidget(progressBar);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        toolsLayout->addItem(verticalSpacer_2);

        ticksLayout = new QFormLayout();
        ticksLayout->setSpacing(6);
        ticksLayout->setObjectName(QString::fromUtf8("ticksLayout"));
        ticksLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        ticksLayout->setWidget(3, QFormLayout::LabelRole, label);

        ticks = new QLCDNumber(layoutWidget);
        ticks->setObjectName(QString::fromUtf8("ticks"));
        ticks->setFrameShape(QFrame::StyledPanel);
        ticks->setFrameShadow(QFrame::Raised);

        ticksLayout->setWidget(3, QFormLayout::FieldRole, ticks);


        toolsLayout->addLayout(ticksLayout);

        toolsScrollArea->setWidget(toolsScrollAreaContent);
        toolsDock->setWidget(dockWidgetContents);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(1), toolsDock);
#ifndef QT_NO_SHORTCUT
        label_3->setBuddy(multiSlider);
#endif // QT_NO_SHORTCUT

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menuBar->addAction(menu_3->menuAction());
        menu->addAction(loadAction);
        menu->addSeparator();
        menu->addAction(exitAction);

        retranslateUi(MainWindow);
        QObject::connect(noiseDial, SIGNAL(valueChanged(int)), lcdNumber, SLOT(display(int)));
        QObject::connect(loadAction, SIGNAL(triggered()), loadButton, SLOT(click()));
        QObject::connect(exitAction, SIGNAL(triggered()), MainWindow, SLOT(close()));
        QObject::connect(multiSlider, SIGNAL(valueChanged(int)), lcdNumber_2, SLOT(display(int)));
        QObject::connect(additMaxPlusSlider, SIGNAL(valueChanged(int)), lcdNumber_4, SLOT(display(int)));
        QObject::connect(additMaxMinusSlider, SIGNAL(valueChanged(int)), lcdNumber_3, SLOT(display(int)));

        noiseTabs->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\320\233\320\260\320\261\320\276\321\200\320\260\321\202\320\276\321\200\320\275\320\260\321\217 #1", 0, QApplication::UnicodeUTF8));
        loadAction->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214", 0, QApplication::UnicodeUTF8));
        exitAction->setText(QApplication::translate("MainWindow", "\320\222\321\213\321\205\320\276\320\264", 0, QApplication::UnicodeUTF8));
        menu->setTitle(QApplication::translate("MainWindow", "\320\244\320\260\320\271\320\273", 0, QApplication::UnicodeUTF8));
        menu_2->setTitle(QApplication::translate("MainWindow", "\320\236\321\202\321\207\320\265\321\202", 0, QApplication::UnicodeUTF8));
        menu_3->setTitle(QApplication::translate("MainWindow", "\320\237\320\276\320\274\320\276\321\211\321\214", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        toolsDock->setToolTip(QApplication::translate("MainWindow", "\320\237\320\260\320\275\320\265\320\273\321\214 \320\270\320\275\321\201\321\202\321\200\321\203\320\274\320\265\320\275\321\202\320\276\320\262", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        toolsDock->setStatusTip(QApplication::translate("MainWindow", "\320\237\320\260\320\275\320\265\320\273\321\214 \320\270\320\275\321\201\321\202\321\200\321\203\320\274\320\265\320\275\321\202\320\276\320\262", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        toolsDock->setWhatsThis(QApplication::translate("MainWindow", "\320\237\320\260\320\275\320\265\320\273\321\214 \320\270\320\275\321\201\321\202\321\200\321\203\320\274\320\265\320\275\321\202\320\276\320\262", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        toolsDock->setWindowTitle(QApplication::translate("MainWindow", "\320\237\320\260\320\275\320\265\320\273\321\214 \320\270\320\275\321\201\321\202\321\200\321\203\320\274\320\265\320\275\321\202\320\276\320\262", 0, QApplication::UnicodeUTF8));
        noiseRateGroup->setTitle(QApplication::translate("MainWindow", "\320\243\321\200\320\276\320\262\320\265\320\275\321\214 \320\267\320\260\321\210\321\203\320\274\320\273\320\265\320\275\320\275\320\276\321\201\321\202\320\270, %", 0, QApplication::UnicodeUTF8));
        filtersLabel->setText(QApplication::translate("MainWindow", "\320\244\320\270\320\273\321\214\321\202\321\200\321\213 \321\210\321\203\320\274\320\276\320\262", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MainWindow", "\320\221\320\265\320\273\321\213\320\271", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("MainWindow", "\320\247\320\265\321\200\320\275\321\213\320\271", 0, QApplication::UnicodeUTF8));
        applyImpulseButton->setText(QApplication::translate("MainWindow", "\320\237\321\200\320\270\320\274\320\265\320\275\320\270\321\202\321\214", 0, QApplication::UnicodeUTF8));
        noiseTabs->setTabText(noiseTabs->indexOf(impulseTab), QApplication::translate("MainWindow", "\320\230\320\274\320\277\321\203\320\273\321\214\321\201\320\275\321\213\320\271", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "\320\234\320\260\320\272\321\201\320\270\320\274\320\260\320\273\321\214\320\275\321\213\320\271 \320\274\320\270\320\275\321\203\321\201:", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWindow", "\320\234\320\260\320\272\321\201\320\270\320\274\320\260\320\273\321\214\320\275\321\213\320\271 \320\277\320\273\321\216\321\201:", 0, QApplication::UnicodeUTF8));
        applyAdditButton->setText(QApplication::translate("MainWindow", "\320\237\321\200\320\270\320\274\320\265\320\275\320\270\321\202\321\214", 0, QApplication::UnicodeUTF8));
        noiseTabs->setTabText(noiseTabs->indexOf(additTab), QApplication::translate("MainWindow", "\320\220\320\264\320\264\320\270\321\202.", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "\320\232\320\276\321\215\321\204. \321\203\320\274\320\275\320\276\320\266\320\265\320\275\320\270\321\217:", 0, QApplication::UnicodeUTF8));
        applyMultiButton->setText(QApplication::translate("MainWindow", "\320\237\321\200\320\270\320\274\320\265\320\275\320\270\321\202\321\214", 0, QApplication::UnicodeUTF8));
        noiseTabs->setTabText(noiseTabs->indexOf(multiTab), QApplication::translate("MainWindow", "\320\234\321\203\320\273\321\214\321\202.", 0, QApplication::UnicodeUTF8));
        loadButton->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214 \320\270\320\267\320\276\320\261\321\200\320\260\320\266\320\265\320\275\320\270\320\265", 0, QApplication::UnicodeUTF8));
        showProcessedButton->setText(QApplication::translate("MainWindow", "\320\222\320\276\321\201\321\201\321\202\320\260\320\275\320\276\320\262\320\270\321\202\321\214 \320\270\320\267\320\276\320\261\321\200\320\260\320\266\320\265\320\275\320\270\320\265", 0, QApplication::UnicodeUTF8));
        showOriginal->setText(QApplication::translate("MainWindow", "\320\237\320\276\320\272\320\260\320\267\321\213\320\262\320\260\321\202\321\214 \320\276\321\200\320\270\320\263\320\270\320\275\320\260\320\273", 0, QApplication::UnicodeUTF8));
        channelsLabel->setText(QApplication::translate("MainWindow", "\320\232\320\260\320\275\320\260\320\273:", 0, QApplication::UnicodeUTF8));
        channelsBox->clear();
        channelsBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "\320\222\321\201\320\265 \320\272\320\260\320\275\320\260\320\273\321\213", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\320\232\321\200\320\260\321\201\320\275\321\213\320\271", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\320\227\320\265\320\273\320\265\320\275\321\213\320\271", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\320\241\320\270\320\275\320\270\320\271", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\320\236\321\202\321\202\320\265\320\275\320\276\320\272", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\320\241\320\262\320\265\321\202\320\273\320\276\321\201\321\202\321\214", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\320\235\320\260\321\201\321\213\321\211\320\265\320\275\320\275\320\276\321\201\321\202\321\214", 0, QApplication::UnicodeUTF8)
        );
        progressBar->setFormat(QApplication::translate("MainWindow", "%p %", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "\320\242\320\260\320\272\321\202\321\213 \320\275\320\260 \320\276\320\277\320\265\321\200\320\260\321\206\320\270\321\216", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
