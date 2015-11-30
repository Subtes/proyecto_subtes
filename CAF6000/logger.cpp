#include "logger.h"

logger::logger()
{

}

void logger::logMessageOutput(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    QString txt, str;
    QByteArray localMsg = msg.toLocal8Bit();
    str = context.file;
      if (str.contains(".qml", Qt::CaseInsensitive)){
        switch (type) {
        case QtDebugMsg:           
            txt = QString("[QML]").append("[");
            txt.append(context.file).append("][").append(context.function).append("] - ").append(localMsg.constData());
            LOG(DEBUG) << txt.toStdString();
            break;            
        case QtWarningMsg:
            txt = QString("QML Warning: ").append("[");
            txt.append(context.file).append("][").append(context.function).append("] - ").append(localMsg.constData());
            LOG(WARNING) << txt.toStdString();
            break;
        case QtCriticalMsg:
            txt = QString("QML Critical: ").append("[");
            txt.append(context.file).append("][").append(context.function).append("] - ").append(localMsg.constData());
            LOG(ERROR) << txt.toStdString();
            break;
        case QtFatalMsg:
            txt = QString("QML Fatal: ").append("[");
            txt.append(context.file).append("][").append(context.function).append("] - ").append(localMsg.constData());
            LOG(FATAL) << txt.toStdString();
            abort();
          }
        }
        else
            switch (type) {
            case QtDebugMsg:               
                txt = QString(localMsg.constData());
                LOG(DEBUG) << txt.toStdString();
                break;                
            case QtWarningMsg:
                txt = QString(localMsg.constData());
                LOG(WARNING) << txt.toStdString();
                break;
            case QtCriticalMsg:
                txt = QString(localMsg.constData());
                LOG(ERROR) << txt.toStdString();
                break;
            case QtFatalMsg:
                txt = QString(localMsg.constData());
                LOG(FATAL) << txt.toStdString();
                abort();
            }       
}

