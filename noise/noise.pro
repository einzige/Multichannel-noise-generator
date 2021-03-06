# -------------------------------------------------
# Project created by QtCreator 2011-02-06T18:57:01
# -------------------------------------------------
QT += testlib
TARGET = noise
TEMPLATE = app
SOURCES += main.cpp \
    mainwindow.cpp \
    ../model.cpp \
    ../filters/redfilter.cpp \
    ../filters/bluefilter.cpp \
    ../filters/greenfilter.cpp \
    ../filters/huefilter.cpp \
    ../filters/saturationfilter.cpp \
    ../filters/lightnessfilter.cpp \
    ../channel.cpp \
    ../ifilter.cpp \
    ../inoise.cpp \
    ../filters/additivenoise.cpp \
    ../filters/impulsenoise.cpp \
    ../filters/multinoise.cpp \
    ../helpers/color.cpp \
    ../noisemodel.cpp \
    ../colorspace.cpp \
    ../colorspaces/rgbcs.cpp \
    ../colorspaces/hlscs.cpp \
    ../noisepresenter.cpp \
    ../filters/grayscalefilter.cpp \
    ../filters/hist.cpp \
    ../filters/brightnessfilter.cpp \
    ../filters/contrastfilter.cpp \
    ../filters/invertfilter.cpp \
    ../filters/equalize.cpp \
    ../filters/exp.cpp \
    ../filters/autolevels.cpp \
    ../filters/autocontrast.cpp \
    ../filters/averageconvolution.cpp \
    ../filters/geometricconvolution.cpp \
    ../filters/medianconvolution.cpp \
    ../filters/twodclean.cpp \
    ../filters/additionalconvolution.cpp \
    ../colorspaces/yuvcs.cpp \
    ../filters/yfilter.cpp \
    ../filters/ufilter.cpp \
    ../filters/vfilter.cpp
HEADERS += mainwindow.h \
    ../IView.h \
    ../model.h \
    ../ifilter.h \
    ../filters/redfilter.h \
    ../filters/bluefilter.h \
    ../filters/greenfilter.h \
    ../filters/huefilter.h \
    ../filters/saturationfilter.h \
    ../filters/lightnessfilter.h \
    ../channel.h \
    ../inoise.h \
    ../filters/additivenoise.h \
    ../helpers/color.h \
    ../filters/impulsenoise.h \
    ../helpers/definions.h \
    ../filters/multinoise.h \
    ../noisemodel.h \
    ../colorspace.h \
    ../colorspaces/rgbcs.h \
    ../colorspaces/hlscs.h \
    ../noisepresenter.h \
    ../filters/grayscalefilter.h \
    ../filters/hist.h \
    ../filters/brightnessfilter.h \
    ../filters/contrastfilter.h \
    ../filters/invertfilter.h \
    ../filters/equalize.h \
    ../filters/exp.h \
    ../filters/autolevels.h \
    ../filters/autocontrast.h \
    ../filters/averageconvolution.h \
    ../filters/geometricconvolution.h \
    ../filters/medianconvolution.h \
    ../filters/twodclean.h \
    ../filters/additionalconvolution.h \
    ../colorspaces/yuvcs.h \
    ../filters/yfilter.h \
    ../filters/ufilter.h \
    ../filters/vfilter.h
FORMS += mainwindow.ui
