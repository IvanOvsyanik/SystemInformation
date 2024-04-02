#include <QKeyEvent>
#include <QProcess>
#include <QDebug>

class KeyPressWatcher : public QObject {
public:
    bool eventFilter(QObject *obj, QEvent *event) override {
        if (event->type() == QEvent::KeyPress) {
            QKeyEvent *keyEvent = static_cast<QKeyEvent*>(event);
            if (keyEvent->key() >= Qt::Key_F1 && keyEvent->key() <= Qt::Key_F12) {
                QProcess process;
                process.start("sh", QStringList() << "-c" << "xdotool key Caps_Lock && xdotool key Num_Lock");
                process.waitForFinished();
                qDebug() << "Инвертированы клавиши Caps Lock, Insert и NumLock";
            }
        }

        return false;
    }
};
