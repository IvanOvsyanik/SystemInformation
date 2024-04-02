#ifndef USBDEVICE_H
#define USBDEVICE_H

#include <QObject>

class USBDeviceInfo : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QStringList usbdevices READ usbdevices NOTIFY usbdevicesChanged)

public:
    explicit USBDeviceInfo(QObject *parent = nullptr);

    QStringList usbdevices() const;

signals:
    void usbdevicesChanged();

private:
    QStringList m_usbdevices;

    void readusbDevices();
};

#endif // USBDEVICE_H
