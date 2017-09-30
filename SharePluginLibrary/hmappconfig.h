#ifndef HMAPPCONFIG_H
#define HMAPPCONFIG_H

#include "hmappconfig_global.h"
#include <QString>
#include <QStringList>

/*!
 * \brief The HMAppConfig struct
 * current application config info
 * \author lsq
 * \date 2017-09-30 16:05
 */
struct HMAPPCONFIG_EXPORT HMAppConfig
{
    //log save dir name,
    //if value is emtpy, default use "LocalLogs"
    QString LogDirName;
    //log save file name format:time format string,code auto add extention ".log",
    //if value is empty,default use yyyy-mm-dd.log
    QString LogFileNameFormat;
    //log save max file count,
    //if value is -1 or empty,unlimited file count
    qint32 MaxLogFileCount;
    //log save file size,
    //if value is -1 or empty, unliited file size
    qint64 MaxLogFileSize;
    //log type: OFF(100) > INFO(4) > FATAL(3) > CRITICAL(2) > WARNING(1) > DEBUG(0) > ALL(-1)
    //if value is empty, default use 1
    qint32 LogType;
    //log display to widget max row count
    //if value is emtpy or small than 10, default use 500
    qint32 DisplayMaxLogRowCount;
    //display time string color,
    //if value is empty, default use #8a8a8a
    QString DisplayTimeColor;
    //log display type string color, format is "[INFO] [FATAL] [CRITICAL] [WARNING] [DEBUG]"
    //if value is empty or wrong format, default use "#1afa29 #d81e06 #d81e06   #f5ea17 #000000"
    QString DisplayLogTypeColor;
    //log display type list
    QStringList DisplayLogTypeColorList;


    //log save dir name,
    //if value is emtpy, default use "LocalLogs"
    QString DefaultLogDirName = "LocalLogs";
    //log save file name format:time format string,code auto add extention ".log",
    //if value is empty,default use yyyy-mm-dd.log
    QString DefaultLogFileNameFormat = "yyyy-mm-dd";
    //log save max file count,
    //if value is -1 or empty,unlimited file count
    qint32 DefaultMaxLogFileCount = 30;
    //log save file size,
    //if value is -1 or empty, unliited file size
    qint64 DefaultMaxLogFileSize = 100 * 1024 * 1024;
    //log type: OFF(100) > INFO(4) > FATAL(3) > CRITICAL(2) > WARNING(1) > DEBUG(0) > ALL(-1)
    //if value is empty, default use 1
    qint32 DefaultLogType = 1;
    //log display to widget max row count
    //if value is emtpy or small than 10, default use 500
    qint32 DefaultDisplayMaxLogRowCount = 500;
    //display time string color,
    //if value is empty, default use #8a8a8a
    QString DefaultDisplayTimeColor = "#8a8a8a";
    //log display type string color, format is "[INFO] [FATAL] [CRITICAL] [WARNING] [DEBUG]"
    //if value is empty or wrong format, default use "#1afa29 #d81e06 #d81e06   #f5ea17 #000000"
    QString DefaultDisplayLogTypeColor = "#1afa29 #d81e06 #d81e06   #f5ea17 #000000";
public:

    /*!
     * \brief HMAppConfig init config info
     */
    HMAppConfig()
    {
        this->LogDirName = this->DefaultLogDirName;
        this->LogFileNameFormat = this->DefaultLogFileNameFormat;
        this->MaxLogFileCount = this->DefaultMaxLogFileCount;
        this->MaxLogFileSize = this->DefaultMaxLogFileSize;
        this->LogType = this->DefaultLogType;
        this->DisplayMaxLogRowCount = this->DefaultDisplayMaxLogRowCount;
        this->DisplayTimeColor = this->DefaultDisplayTimeColor;
        this->DisplayLogTypeColor = this->DefaultDisplayLogTypeColor;
        this->DisplayLogTypeColorList = this->DisplayLogTypeColor.split(" ", QString::SkipEmptyParts);
    }
};

#endif // HMAPPCONFIG_H
