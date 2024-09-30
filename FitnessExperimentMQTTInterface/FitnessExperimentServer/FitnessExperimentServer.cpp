#include "FitnessExperimentServer.h"
#include <QWebSocket>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QFile>
#include <QDir>

FitnessExperimentServer::FitnessExperimentServer(quint16 port, bool isDebug, QObject *parent) :
    QObject(parent),
    socketServer(new QWebSocketServer(QStringLiteral("Fitness Experiment Server"), QWebSocketServer::NonSecureMode, this)),
    debug(isDebug)
{
    if (socketServer->listen(QHostAddress::Any, port)) {

        if (debug)
            qDebug() << "Server listening on port" << port;

        connect(socketServer, &QWebSocketServer::newConnection, this, &FitnessExperimentServer::onNewConnection);
        connect(socketServer, &QWebSocketServer::closed,        this, &FitnessExperimentServer::closed);
    }
}

FitnessExperimentServer::~FitnessExperimentServer()
{
    socketServer->close();
    qDeleteAll(clients.begin(), clients.end());
}

void FitnessExperimentServer::onNewConnection()
{
    if (debug)
        qDebug() << "New connection!";

    QWebSocket *pSocket = socketServer->nextPendingConnection();

    connect(pSocket, &QWebSocket::textMessageReceived,      this, &FitnessExperimentServer::processTextMessage);
    connect(pSocket, &QWebSocket::binaryMessageReceived,    this, &FitnessExperimentServer::processBinaryMessage);
    connect(pSocket, &QWebSocket::disconnected,             this, &FitnessExperimentServer::socketDisconnected);

    clients << pSocket;

    // if (debug)
    //     qDebug() << "Added to clients";
}

void FitnessExperimentServer::processTextMessage(QString message)
{
    QWebSocket *pClient = qobject_cast<QWebSocket *>(sender());

    if (debug)
        qDebug() << "Message received:" << message;

    if (pClient)
        pClient->sendTextMessage("Hello back to you!");
}

void FitnessExperimentServer::processBinaryMessage(QByteArray message)
{
    // QWebSocket *pClient = qobject_cast<QWebSocket *>(sender());

    if (debug)
        // qDebug() << "Binary message received:" << QString(message);
        qDebug() << "Binary message received!";

    QJsonDocument document = QJsonDocument::fromJson(message);
    QJsonObject root = document.object();

    if (root.value("mode").toString() == "save") {

        QDateTime currentDatetime = QDateTime::currentDateTime();

        QString filePath = "C:\\Users\\Viktorija\\Desktop\\VR\\RV1\\FitnessExperimentServer\\FitnessExperimentServer\\data\\" +
                           root.value("user").toString() + "_" + QString::number(currentDatetime.date().year()) + "-" +
                           QString::number(currentDatetime.date().month()) + "-" + QString::number(currentDatetime.date().day()) +
                           "-" + QString::number(currentDatetime.time().hour()) + "-" + QString::number(currentDatetime.time().minute()) +
                           "-" + QString::number(currentDatetime.time().second()) + ".json";

        QFile saveFile(filePath);

        if (!saveFile.open(QIODevice::WriteOnly | QIODevice::Text)) {
            qDebug() << "Can't find directory!";
            return;
        }

        QTextStream outStream(&saveFile);
        outStream << message;

        saveFile.close();

    } /*else if (root.value("mode").toString() == "getFile") {

        QJsonDocument sendingDocument;
        QJsonObject rootSending;

        QJsonArray files;

        for (const QFileInfo &file : QDir("C:\\Users\\Viktorija\\Desktop\\VR\\RV1\\FitnessExperimentServer\\FitnessExperimentServer\\data").entryInfoList(QDir::Files)) {

            QJsonObject sendingFile;
            sendingFile.insert("filename", file.fileName());

            QFile readFile(file.absoluteFilePath());

            if (!readFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
                qDebug() << "Can't open file!";
                return;
            }

            sendingFile.insert("content", QJsonDocument::fromJson(readFile.readAll()).object());

            files.push_back(sendingFile);
        }

        rootSending.insert("files", files);
        sendingDocument.setObject(rootSending);

        QWebSocket *pClient = qobject_cast<QWebSocket *>(sender());

        if (pClient)
            pClient->sendBinaryMessage(sendingDocument.toJson());

    }*/
    else if (root.value("mode").toString() == "getFilenames") {

        QJsonDocument sendingDocument;
        QJsonObject rootSending;

        QJsonArray files;

        for (const QFileInfo &file : QDir("C:\\Users\\Viktorija\\Desktop\\VR\\RV1\\FitnessExperimentServer\\FitnessExperimentServer\\data").entryInfoList(QDir::Files)) {

            QJsonObject sendingFile;
            sendingFile.insert("filename", file.fileName());

            files.push_back(sendingFile);
        }

        rootSending.insert("files", files);
        rootSending.insert("mode", "getFilenames");
        sendingDocument.setObject(rootSending);

        QWebSocket *pClient = qobject_cast<QWebSocket *>(sender());

        if (pClient)
            pClient->sendBinaryMessage(sendingDocument.toJson());

    } else if (root.value("mode").toString() == "getExperiment") {

        QString filePath = "C:\\Users\\Viktorija\\Desktop\\VR\\RV1\\FitnessExperimentServer\\FitnessExperimentServer\\data\\" +
                           root.value("filename").toString();

        QFile readFile(filePath);

        if (!readFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
            qDebug() << "Can't find directory!";
            return;
        }

        QByteArray readData = readFile.readAll();

        QJsonDocument readingDocument = QJsonDocument::fromJson(readData);
        QJsonObject readingObject = readingDocument.object();

        readingObject.insert("mode", "getExperiment");

        readingDocument.setObject(readingObject);

        QWebSocket *pClient = qobject_cast<QWebSocket *>(sender());

        if (pClient)
            pClient->sendBinaryMessage(readingDocument.toJson());
    }

    // if (pClient)
    //     pClient->sendBinaryMessage(QByteArray("Hello back to you!"));


}

void FitnessExperimentServer::socketDisconnected()
{
    QWebSocket *pClient = qobject_cast<QWebSocket *>(sender());

    if (debug)
        qDebug() << "Socket disconnected:" << pClient;

    if (pClient) {
        clients.removeAll(pClient);
        pClient->deleteLater();
    }
}
