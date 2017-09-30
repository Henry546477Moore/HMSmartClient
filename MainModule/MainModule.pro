QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = HMSmartClient

CONFIG += debug_and_release
CONFIG(debug, debug|release){
    unix: TARGET = $$join(TARGET,,,_debug)
    else: TARGET = $$join(TARGET,,,d)
}

TEMPLATE = app
DEFINES += QT_DEPRECATED_WARNINGS

HEADERS += \
    mainwidget.h

FORMS += \
    mainwidget.ui

SOURCES += \
    mainwidget.cpp \
    main.cpp

DISTFILES += \
    readme.txt \
    config.ini

DESTDIR = ./../../HMSmartClient
OBJECTS_DIR = .obj
MOC_DIR = .moc
RCC_DIR = .rcc
UI_DIR = .ui

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../HMSmartClient/ShareLibray/ -lSharePluginLibrary
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../HMSmartClient/ShareLibray/ -lSharePluginLibraryd
else:unix: LIBS += -L$$PWD/../HMSmartClient/ShareLibray/ -lSharePluginLibrary

INCLUDEPATH += $$PWD/../SharePluginLibrary
DEPENDPATH += $$PWD/../SharePluginLibrary
