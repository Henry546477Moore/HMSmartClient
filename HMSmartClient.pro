TEMPLATE = subdirs

#SUBDIRS += \
#    MainModule \
#    MainPlugins/TestPlugin

SUBDIRS += $$PWD/SharePluginLibrary/SharePluginLibrary.pro \
           $$PWD/MainModule/MainModule.pro \
           $$PWD/MainPlugins/TestPlugin/TestPlugin.pro \


CONFIG += ordered
