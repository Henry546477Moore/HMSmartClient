#-------------------------------------------------
#
# Project created by QtCreator 2017-09-29T16:05:56
#
#-------------------------------------------------

QT       += widgets

TARGET = SharePluginLibrary
TEMPLATE = lib

DEFINES += HMPLUGINWIDGETBASE_LIBRARY

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    hmpluginwidgetbase.cpp

HEADERS += \
    hmpluginwidgetbase.h \
    hmplugininterface.h \
    hmpluginwidgetbase_global.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

Release:DESTDIR = ./../../HMSmartClient_Release/ShareLibray
Release:OBJECTS_DIR = .obj
Release:MOC_DIR = .moc
Release:RCC_DIR = .rcc
Release:UI_DIR = .ui

Debug:DESTDIR = ./../../HMSmartClient_Debug/ShareLibray
Debug:OBJECTS_DIR = .obj
Debug:MOC_DIR = .moc
Debug:RCC_DIR = .rcc
Debug:UI_DIR = .ui
