QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = HMSmartClient
TEMPLATE = app
DEFINES += QT_DEPRECATED_WARNINGS

HEADERS += \
    hmsmartplugininterface.h \
    mainwidget.h

FORMS += \
    mainwidget.ui

SOURCES += \
    mainwidget.cpp \
    main.cpp

DISTFILES += \
    readme
