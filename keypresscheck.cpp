#include "keypresscheck.h"
#include <QKeyEvent>
#include <QProcess>

Keypresscheck::Keypresscheck(QObject *parent) : QObject(parent) {}

void Keypresscheck::keypress() {
    QProcess process;
    process.start("sh", QStringList() << "-c" << "xdotool key Caps_Lock && xdotool key Num_Lock");
    process.waitForFinished();

    setResultText("Инвертированы клавиши Caps Lock и Num Lock");
}

QString Keypresscheck::resultText() const {
    return m_resultText;
}

void Keypresscheck::setResultText(const QString &text) {
    if (text == m_resultText)
        return;

    m_resultText = text;
    emit resultTextChanged();
}

/*#include <QKeyEvent>
#include <QProcess>
#include "keypresscheck.h"

Keypresscheck::Keypresscheck(QObject *parent) : QObject(parent) {}

bool Keypresscheck::keypress(QObject *obj, QEvent *event) {
    if (event->type() == QEvent::KeyPress) {
        QKeyEvent *keyEvent = static_cast<QKeyEvent*>(event);
        if (keyEvent->key() >= Qt::Key_F1 && keyEvent->key() <= Qt::Key_F12) {
            QProcess process;
            process.start("sh", QStringList() << "-c" << "xdotool key Caps_Lock && xdotool key Num_Lock");
            process.waitForFinished();
        }
    }
    return false;
}
*/
