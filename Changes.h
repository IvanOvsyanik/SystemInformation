#ifndef CHANGES_H
#define CHANGES_H

#include <QObject>

class Changes : public QObject
{
    Q_OBJECT
public:
    explicit Changes(QObject *parent = nullptr);

public slots:
    void change(int val);
};

#endif // CHANGES_H

