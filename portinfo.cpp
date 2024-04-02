#include "portinfo.h"
#include <QFile>
#include <QByteArray>
#include <QTextStream>
#include <QProcess>
#include <QFile>

PortInfo::PortInfo(QObject *parent) : QObject(parent)
{
    readPortInfo();
}

QStringList PortInfo::portInfo() const
{
    return m_portInfo;
}

void PortInfo::readPortInfo()
{
    QProcess process;
    process.start("sh", QStringList() << "-c" << "setserial -g /dev/ttyS[0123]");
    process.waitForFinished();

    QProcess process1;
    process1.start("stty", QStringList() << "-F" << "/dev/ttyS[0123]" << "2400");
    process1.waitForFinished();

    QProcess process2;
    process2.start("stty", QStringList() << "-F" << "/dev/ttyS[0123]" << "cs7" << "cstopb" << "-parenb");
    process2.waitForFinished();

    if (process.error() != QProcess::UnknownError) {
        return;
    }

    QString devicesInfo = process.readAllStandardOutput();

    QFile file("/home/ivan/Desktop/portinfo.txt");
    if (file.open(QIODevice::WriteOnly)) {
        QTextStream stream(&file);
        stream << devicesInfo;
        file.close();
    }

    QFile file2("/home/ivan/Desktop/portinfo.txt");
    if (!file2.open(QIODevice::ReadOnly | QIODevice::Text)){
        return;
    }

    m_portInfo.clear();

    QTextStream in(&file2);
    while (!in.atEnd())
    {
        QString line = in.readLine();
        m_portInfo.append(line);
    }

    file.close();

    emit portInfoChanged();
}
