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
    ../noisepresenter.cpp
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
    ../noisepresenter.h
FORMS += mainwindow.ui
