#include "meminfo.h"
#include <QFile>
#include <QByteArray>
#include <QTextStream>
#include <QProcess>
#include <QFile>

MemInfo::MemInfo(QObject *parent) : QObject(parent)
{
    readMemInfo();
}

QStringList MemInfo::memInfo() const
{
    return m_memInfo;
}

void MemInfo::readMemInfo()
{
    QProcess process;
    process.start("sh", QStringList() << "-c" << "cat /proc/meminfo");
    process.waitForFinished();

    if (process.error() != QProcess::UnknownError) {
        return;
    }

    QString devicesInfo = process.readAllStandardOutput();

    QFile file("/home/ivan/Desktop/meminfo.txt");
    if (file.open(QIODevice::WriteOnly)) {
        QTextStream stream(&file);
        stream << devicesInfo;
        file.close();
    }

    QFile file2("/home/ivan/Desktop/meminfo.txt");
    if (!file2.open(QIODevice::ReadOnly | QIODevice::Text)){
        return;
    }

    m_memInfo.clear();

    QTextStream in(&file2);
    while (!in.atEnd())
    {
        QString line = in.readLine();
        m_memInfo.append(line);
    }

    file.close();

    emit memInfoChanged();
}
