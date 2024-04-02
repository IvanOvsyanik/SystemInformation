#ifndef KEYPRESSWATCHER_H
#define KEYPRESSWATCHER_H

#include <QObject>

class KeyPressWatcher : public QObject {
    Q_OBJECT

public:
    explicit KeyPressWatcher(QObject *parent = nullptr);
    bool eventFilter(QObject *obj, QEvent *event) override;

signals:

};

#endif // KEYPRESSWATCHER_H

