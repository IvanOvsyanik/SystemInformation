#ifndef DEVICEINFO_H
#define DEVICEINFO_H

#include <QObject>

class DeviceInfo : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QStringList devices READ devices NOTIFY devicesChanged)

public:
    explicit DeviceInfo(QObject *parent = nullptr);

    QStringList devices() const;

signals:
    void devicesChanged();

private:
    QStringList m_devices;

    void readDevices();
};

#endif // DEVICEINFO_H

