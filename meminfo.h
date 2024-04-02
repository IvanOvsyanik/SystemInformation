#ifndef MEMINFO_H
#define MEMINFO_H

#include <QObject>

class MemInfo : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QStringList memInfo READ memInfo NOTIFY memInfoChanged)

public:
    explicit MemInfo(QObject *parent = nullptr);

    QStringList memInfo() const;

signals:
    void memInfoChanged();

private:
    QStringList m_memInfo;

    void readMemInfo();
};

#endif // MEMINFO_H
