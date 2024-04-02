#include "KeyPressHandler.h"
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QProcess>
#include <QFile>
#include "deviceinfo.h"
#include "cpuinfo.h"
#include "meminfo.h"
#include "usbdevice.h"
#include "Changes.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    Changes changes;
    DeviceInfo deviceInfo;
    MemInfo memInfo;
    CpuInfo cpuInfo;
    USBDeviceInfo usbDevice;
    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("changes", &changes);
    engine.rootContext()->setContextProperty("deviceInfo", &deviceInfo);
    engine.rootContext()->setContextProperty("usbDevice", &usbDevice);
    engine.rootContext()->setContextProperty("cpuInfo", &cpuInfo);
    engine.rootContext()->setContextProperty("memInfo", &memInfo);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    if (engine.rootObjects().isEmpty())
        return -1;

    QQuickWindow *window = qobject_cast<QQuickWindow*>(engine.rootObjects().at(0));
    KeyPressHandler handler(window);

    return app.exec();
}
