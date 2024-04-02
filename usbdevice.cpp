#include "usbdevice.h"
#include <QFile>
#include <QByteArray>
#include <QTextStream>
#include <QProcess>
#include <QFile>

USBDeviceInfo::USBDeviceInfo(QObject *parent) : QObject(parent)
{
    readusbDevices();
}

QStringList USBDeviceInfo::usbdevices() const
{
    return m_usbdevices;
}

void USBDeviceInfo::readusbDevices()
{
    QProcess process;
    process.start("sh", QStringList() << "-c" << "dmesg | grep usb");
    process.waitForFinished();

    if (process.error() != QProcess::UnknownError) {
        return;
    }

    QString devicesInfo = process.readAllStandardOutput();

    QFile file("/home/ivan/Desktop/usbdevice.txt");
    if (file.open(QIODevice::WriteOnly)) {
        QTextStream stream(&file);
        stream << devicesInfo;
        file.close();
    }

    QFile file2("/home/ivan/Desktop/usbdevice.txt");
    if (!file2.open(QIODevice::ReadOnly | QIODevice::Text)){
        return;
    }

    m_usbdevices.clear();

    QTextStream in(&file2);
    while (!in.atEnd())
    {
        QString line = in.readLine();
        m_usbdevices.append(line);
    }

    file.close();

    emit usbdevicesChanged();
}
