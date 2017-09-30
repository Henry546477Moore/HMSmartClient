#include "mainwidget.h"
#include <QApplication>
#include <QMutex>
#include <QDateTime>
#include <QDir>
#include <QFile>
#include <QTextStream>
#include <QPlainTextEdit>
#include <QDebug>
#include "hmappconfig.h"
#include <QString>
#include <QSettings>

HMAppConfig *AppConfig;

/*!
 * \brief HandlerMessageInfo
 * handle hole system debug\error ETC message, output to UI or local file
 * \param type mesaage type
 * \param context message from context
 * \param msg message text info
 * \author lsq
 * \date 2017-09-30 10:43
 */
void HandlerMessageInfo(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    // add lock
    static QMutex mutex;
    mutex.lock();

    //create log dir
    QString logDirPath = QString("%1/%2").arg(QCoreApplication::applicationDirPath()).arg(AppConfig->LogDirName);
    QDir logDir(logDirPath);
    if(!logDir.exists()){
        if(QDir::mkdir(logDir)){
            return;
        }
    }

    //delete over max file count file
    if(-1 != AppConfig->MaxLogFileCount){
        logDir.setFilter(QDir::Files);
        logDir.setSorting(QDir::Time);
        QFileInfoList list = logDir.entryInfoList();
        if(list.size() > AppConfig->MaxLogFileCount){
            for (int i = list.size(); i > AppConfig->MaxLogFileCount; --i){
                logDir.remove(list.at(i).fileName());
            }
        }
    }

    //create current log file
    QString currentLogFilePath = QString("%1/%2.log").arg(logDirPath).arg(AppConfig->LogFileNameFormat);
    QFile currentLogFile(currentLogFilePath);
    if(!currentLogFile.exists()){
        currentLogFile.
    }
    QString message = QString("%1").arg(QDateTime.currentDateTime().toString(""));
    QByteArray localMsg = msg.toLocal8Bit();

    QString strMsg("");
    switch(type)
    {
    case QtDebugMsg:
        strMsg = QString("Debug:");
        break;
    case QtInfoMsg:
        strMsg = QString("Info");
        break;
    case QtWarningMsg:
        strMsg = QString("Warning:");
        break;
    case QtCriticalMsg:
        strMsg = QString("Critical:");
        break;
    case QtFatalMsg:
        strMsg = QString("Fatal:");
        break;
    }

    // 设置输出信息格式
    QString strDateTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
    QString strMessage = QString("Message:%1 File:%2  Line:%3  Function:%4  DateTime:%5")
            .arg(localMsg.constData()).arg(context.file).arg(context.line).arg(context.function).arg(strDateTime);

    // 输出信息至文件中（读写、追加形式）
    QFile file("log.txt");
    file.open(QIODevice::ReadWrite | QIODevice::Append);
    QTextStream stream(&file);
    stream << strMessage << "\r\n";
    file.flush();
    file.close();

    // 解锁
    mutex.unlock();
}

/*!
 * \brief ReadApplicationConfig
 * read application config file
 * \return config info
 * \author lsq
 * \date 2017-09-30 16:57
 */
void ReadApplicationConfig(HMAppConfig* config)
{
    //read the fact file config
    QString configFilePath = QString("%1/config.ini").arg(QCoreApplication::applicationDirPath());
    QFile file(configFilePath);
    if(!file.exists())
    {
        qWarning() << "Application not found config file(config.ini), "
                      "application will use default values.";
        return;
    }

    QSettings initRead(configFilePath, QSettings::IniFormat);
    initRead.setIniCodec("utf-8");
    QString str = initRead.value("log/LOG_DIR").toString();
    if(!str.isEmpty()){
        config->LogDirName = str;
    }
    str = initRead.value("log/LOG_FILE").toString();
    if(!str.isEmpty()){
        config->LogFileNameFormat = str;
    }
    qint32 i32;
    bool ok = false;
    i32 = initRead.value("log/MAX_FILE_COUNT").toInt(&ok);
    if(ok && i32 != 0){
        config->MaxLogFileCount = i32;
    }
    qint64 i64;
    i64 = initRead.value("log/MAX_FILE_SIZE").toLongLong(&ok);
    if(ok && i64 != 0){
        config->MaxLogFileSize = i64;
    }
    i32 = initRead.value("log/Log_TYPE").toInt(&ok);
    if(ok && i32 >= -1 && i32 <= 5){
        config->LogType = i32;
    }
    i32 = initRead.value("log/DISPLAY_ROW_COUNT").toInt(&ok);
    if(ok && i32 >= 10){
        config->DisplayMaxLogRowCount = i32;
    }
    str = initRead.value("log/DISPLAY_TIME_COLOR").toString();
    if(!str.isEmpty()){
        config->DisplayTimeColor = str;
    }
    str = initRead.value("log/DISPLAY_LOG_TYPE_COLOR").toString();
    if(!str.isEmpty()){
        config->DisplayLogTypeColor = str;
        config->DisplayLogTypeColorList = str.split(" ", SkipEmptyParts);
    }
}

int main(int argc, char *argv[])
{
    AppConfig = new HMAppConfig;
    qInstallMessageHandler(HandlerMessageInfo);
    ReadApplicationConfig(AppConfig);

    QApplication a(argc, argv);
    MainWidget w;
    w.show();

    return a.exec();
}
