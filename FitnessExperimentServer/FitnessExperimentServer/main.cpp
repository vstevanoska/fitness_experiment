#include <QCoreApplication>

#include "FitnessExperimentServer.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    FitnessExperimentServer *server = new FitnessExperimentServer(1234, true);

    QObject::connect(server, &FitnessExperimentServer::closed, &a, &QCoreApplication::quit);

    return a.exec();
}
