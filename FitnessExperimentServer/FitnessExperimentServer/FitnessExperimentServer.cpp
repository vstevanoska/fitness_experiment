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
}

void FitnessExperimentServer::processTextMessage(QString message)
{
    if (debug)
        qDebug() << "Message received:" << message;
}

void FitnessExperimentServer::processBinaryMessage(QByteArray message)
{
    if (debug)
        qDebug() << "Binary message received!";

    const QJsonObject root = QJsonDocument::fromJson(message).object();

    if (root.value("mode").toString() == "save") {

        const QDateTime currentDatetime = QDateTime::currentDateTime();

        const QString filePath = dataFolderPath + root.value("user").toString() + "_" + QString::number(currentDatetime.date().year()) + "-" +
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
    }

    else if (root.value("mode").toString() == "getFilenames") {

        QJsonArray files;
        for (const QFileInfo &file : QDir(dataFolderPath).entryInfoList(QDir::Files)) {

            QJsonObject sendingFile;
            sendingFile.insert("filename", file.fileName());

            files.push_back(sendingFile);
        }

        QJsonObject rootSending;
        rootSending.insert("files", files);
        rootSending.insert("mode", "getFilenames");

        QJsonDocument sendingDocument;
        sendingDocument.setObject(rootSending);
        
        QWebSocket *pClient = qobject_cast<QWebSocket *>(sender());

        if (pClient)
            pClient->sendBinaryMessage(sendingDocument.toJson());

    } else if (root.value("mode").toString() == "getExperiment") {

        QString filePath = dataFolderPath + root.value("filename").toString();

        QFile readFile(filePath);

        if (!readFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
            qDebug() << "Can't find directory!";
            return;
        }

        const QByteArray readData = readFile.readAll();

        QJsonDocument readingDocument = QJsonDocument::fromJson(readData);
        QJsonObject readingObject = readingDocument.object();

        readingObject.insert("mode", "getExperiment");

        readingDocument.setObject(readingObject);

        QWebSocket *pClient = qobject_cast<QWebSocket *>(sender());

        if (pClient)
            pClient->sendBinaryMessage(readingDocument.toJson());
    }
}

void FitnessExperimentServer::socketDisconnected()
{
    QWebSocket *pClient = qobject_cast<QWebSocket *>(sender());

    if (pClient) {
        clients.removeAll(pClient);
        pClient->deleteLater();
    }

    if (debug)
        qDebug() << "Socket disconnected:" << pClient;
}
