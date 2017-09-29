QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = HMSmartClient
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
    readme.txt

Release:DESTDIR = ./../../HMSmartClient_Release
Release:OBJECTS_DIR = .obj
Release:MOC_DIR = .moc
Release:RCC_DIR = .rcc
Release:UI_DIR = .ui

Debug:DESTDIR = ./../../HMSmartClient_Debug
Debug:OBJECTS_DIR = .obj
Debug:MOC_DIR = .moc
Debug:RCC_DIR = .rcc
Debug:UI_DIR = .ui
