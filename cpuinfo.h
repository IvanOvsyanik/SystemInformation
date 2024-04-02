#ifndef CPUINFO_H
#define CPUINFO_H

#include <QObject>

class CpuInfo : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QStringList cpuInfo READ cpuInfo NOTIFY cpuInfoChanged)

public:
    explicit CpuInfo(QObject *parent = nullptr);

    QStringList cpuInfo() const;

signals:
    void cpuInfoChanged();

private:
    QStringList m_cpuInfo;

    void readCpuInfo();
};

#endif // CPUINFO_H
