#include "Changes.h"
#include <QProcess>
#include <QTimer>

Changes::Changes(QObject *parent) : QObject(parent) {}

void Changes::change(int val) {
    if (val == 1) {
        QProcess process;
        process.start("sh", QStringList() << "-c" << "xdotool key Caps_Lock && xdotool key Num_Lock && xdotool key Down");
        process.waitForFinished();
        QTimer::singleShot(3000, []() {
            QProcess process;
            process.start("sh", QStringList() << "-c" << "xdotool key Caps_Lock && xdotool key Num_Lock && xdotool key Down");
            process.waitForFinished();
        });
    }
}
