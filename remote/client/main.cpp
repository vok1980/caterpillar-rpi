#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "movecontroller.h"
#include "networkclient.h"

int main(int argc, char* argv[])
{
    QGuiApplication app(argc, argv);

    qmlRegisterType<MoveController>("ru.voksoft.caterpillar", 1, 0, "MoveController");
    qmlRegisterType<NetworkClient>("ru.voksoft.caterpillar", 1, 0, "NetworkClient");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
