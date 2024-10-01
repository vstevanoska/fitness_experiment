#include <QApplication>
#include <QQmlApplicationEngine>

#include "FitnessExperiment.h"

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreated,
        &app,
        [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        },
        Qt::QueuedConnection);

    //register an instance of FitnessExperiment in QML
    //application starts and immediately connects to server. connection is open until app stops running.
    FitnessExperiment *fitnessExperiment = new FitnessExperiment();
    qmlRegisterSingletonInstance<FitnessExperiment>("com.company.fitnessExperiment", 1, 0, "FitnessExperiment", fitnessExperiment);

    engine.load(url);

    return app.exec();
}
