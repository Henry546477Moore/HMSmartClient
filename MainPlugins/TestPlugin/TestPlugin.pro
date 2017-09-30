#-------------------------------------------------
#
# Project created by QtCreator 2017-09-28T22:44:34
#
#-------------------------------------------------

QT       += widgets uiplugin

TARGET = TestPlugin

CONFIG += debug_and_release
CONFIG(debug, debug|release){
    unix: TARGET = $$join(TARGET,,,_debug)
    else: TARGET = $$join(TARGET,,,d)
}

TEMPLATE = lib
QMAKE_LIBS_OPENGL = -lGL
DEFINES += TESTPLUGIN_LIBRARY

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
        testplugin.cpp \
    testwidget.cpp

HEADERS += \
        testplugin.h \
        testplugin_global.h \ 
    testwidget.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

FORMS += \
    testwidget.ui \
    testwidget.ui

DISTFILES += \
    testplugin.json

DESTDIR = ./../../../HMSmartClient/MainPlugins
OBJECTS_DIR = .obj
MOC_DIR = .moc
RCC_DIR = .rcc
UI_DIR = .ui

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../HMSmartClient/ShareLibray/ -lSharePluginLibrary
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../HMSmartClient/ShareLibray/ -lSharePluginLibraryd
else:unix:!macx: LIBS += -L$$PWD/../../HMSmartClient/ShareLibray/ -lSharePluginLibrary_debug

INCLUDEPATH += $$PWD/../../SharePluginLibrary
DEPENDPATH += $$PWD/../../SharePluginLibrary
