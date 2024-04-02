#ifndef PORTINFO_H
#define PORTINFO_H

#include <QObject>

class PortInfo : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QStringList portInfo READ portInfo NOTIFY portInfoChanged)

public:
    explicit PortInfo(QObject *parent = nullptr);

    QStringList portInfo() const;

signals:
    void portInfoChanged();

private:
    QStringList m_portInfo;

    void readPortInfo();
};

#endif // PORTINFO_H
