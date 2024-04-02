#include "deviceinfo.h"
#include <QFile>
#include <QByteArray>
#include <QTextStream>
#include <QProcess>
#include <QFile>

DeviceInfo::DeviceInfo(QObject *parent) : QObject(parent)
{
    readDevices();
}

QStringList DeviceInfo::devices() const
{
    return m_devices;
}

void DeviceInfo::readDevices()
{
    QProcess process;
    process.start("sh", QStringList() << "-c" << "cat /proc/devices");
    process.waitForFinished();

    if (process.error() != QProcess::UnknownError) {
        return;
    }

    QString devicesInfo = process.readAllStandardOutput();

    QFile file("/home/ivan/Desktop/deviceinfo.txt");
    if (file.open(QIODevice::WriteOnly)) {
        QTextStream stream(&file);
        stream << devicesInfo;
        file.close();
    }

    QFile file2("/home/ivan/Desktop/deviceinfo.txt");
    if (!file2.open(QIODevice::ReadOnly | QIODevice::Text)){
        return;
    }

    m_devices.clear();

    QTextStream in(&file2);
    while (!in.atEnd())
    {
        QString line = in.readLine();
        m_devices.append(line);
    }

    file.close();

    emit devicesChanged();
}
