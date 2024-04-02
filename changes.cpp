#include "changes.h"
#include <QProcess>

changes::changes(QObject *parent) : QObject(parent) {}

void change(int val) {
    if(val == 1) {
        QProcess process;
        process.start("sh", QStringList() << "-c" << "xdotool key Caps_Lock && xdotool key Num_Lock");
        process.waitForFinished();

        if (process.error() != QProcess::UnknownError) {
            return;
        }
    }
}
