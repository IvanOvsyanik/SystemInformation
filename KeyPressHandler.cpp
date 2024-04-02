#include "KeyPressHandler.h"
#include <QProcess>
#include <QKeyEvent>
#include <QDebug>
#include <QTimer>
KeyPressHandler::KeyPressHandler(QQuickWindow* window) : m_window(window) {
    if (m_window) {
        m_window->installEventFilter(this);
    }
}

bool KeyPressHandler::eventFilter(QObject *watched, QEvent *event) {
    if (event->type() == QEvent::KeyPress) {
        QKeyEvent *keyEvent = static_cast<QKeyEvent*>(event);
        if (keyEvent->key() == Qt::Key_F1) {
            QProcess::execute("sh", QStringList() << "-c" << "xdotool key Caps_Lock && xdotool key Num_Lock && xdotool key Down");
            return true;
        }
    }
    return QObject::eventFilter(watched, event);
}
