#ifndef KEYPRESSHANDLER_H
#define KEYPRESSHANDLER_H

#include <QObject>
#include <QKeyEvent>
#include <QQuickWindow>

class KeyPressHandler : public QObject
{
    Q_OBJECT

public:
    KeyPressHandler(QQuickWindow* window);

protected:
    bool eventFilter(QObject *watched, QEvent *event) override;

private:
    QQuickWindow* m_window;
};

#endif // KEYPRESSHANDLER_H

