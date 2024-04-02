#include "cpuinfo.h"
#include <QFile>
#include <QByteArray>
#include <QTextStream>
#include <QProcess>
#include <QFile>

CpuInfo::CpuInfo(QObject *parent) : QObject(parent)
{
    readCpuInfo();
}

QStringList CpuInfo::cpuInfo() const
{
    return m_cpuInfo;
}

void CpuInfo::readCpuInfo()
{
    QProcess process;
    process.start("sh", QStringList() << "-c" << "cat /proc/cpuinfo");
    process.waitForFinished();

    if (process.error() != QProcess::UnknownError) {
        return;
    }

    QString devicesInfo = process.readAllStandardOutput();

    QFile file("/home/ivan/Desktop/cpuinfo.txt");
    if (file.open(QIODevice::WriteOnly)) {
        QTextStream stream(&file);
        stream << devicesInfo;
        file.close();
    }

    QFile file2("/home/ivan/Desktop/cpuinfo.txt");
    if (!file2.open(QIODevice::ReadOnly | QIODevice::Text)){
        return;
    }

    m_cpuInfo.clear();

    QTextStream in(&file2);
    while (!in.atEnd())
    {
        QString line = in.readLine();
        m_cpuInfo.append(line);
    }

    file.close();

    emit cpuInfoChanged();
}
