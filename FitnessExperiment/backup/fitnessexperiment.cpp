#include "fitnessexperiment.h"
#include <QDebug>
#include <QJsonArray>
#include <QJsonObject>
#include <QFile>
#include <QDateTime>
#include <QWebSocket>
#include <QQmlEngine>
#include <QQmlComponent>

FitnessExperiment::FitnessExperiment(QObject *parent)
    : QObject{parent}
{
    clientSocket = new QWebSocket();
    connect(clientSocket, &QWebSocket::connected, this, &FitnessExperiment::onConnected);
    // connect(clientSocket, &QWebSocket::disconnected,    this, &FitnessExperiment::closed);

    clientSocket->open(QUrl("ws://192.168.10.117:1234"));   //if not connecting to server, ip has updated
}

void FitnessExperiment::addAccReading(const float &timestampTemp, const float &xTemp, const float &yTemp, const float &zTemp)
{
    AccelerometerReading reading;
    reading.timestamp = timestampTemp;
    reading.x = xTemp;
    reading.y = yTemp;
    reading.z = zTemp;

    accelerometerReadings.push_back(reading);
}

void FitnessExperiment::addGyrReading(const float &timestampTemp, const float &xTemp, const float &yTemp, const float &zTemp)
{
    GyroscopeReading reading;
    reading.timestamp = timestampTemp;
    reading.x = xTemp;
    reading.y = yTemp;
    reading.z = zTemp;

    gyroscopeReadings.push_back(reading);
}

void FitnessExperiment::setUser(const QString &userTemp)
{
    user = userTemp;
}

void FitnessExperiment::setExperimentName(const QString &nameTemp)
{
    experimentName = nameTemp;
}

void FitnessExperiment::setExperimentType(const QString &typeTemp)
{
    experimentType = typeTemp;
}

void FitnessExperiment::setFrequency(const uint &freqTemp)
{
    frequency = freqTemp;
}

void FitnessExperiment::setSpeed(const QString &speedTemp)
{
    speed = speedTemp;
}

void FitnessExperiment::setTimestamp(const quint64 &timestampTemp)
{
    timestamp = timestampTemp;
}

QVector<AccelerometerReading> * FitnessExperiment::getAccReadings()
{
    return &accelerometerReadings;
}

int FitnessExperiment::getAccReadingsSize()
{
    return accelerometerReadings.size();
}

QVector<GyroscopeReading> * FitnessExperiment::getGyrReadings()
{
    return &gyroscopeReadings;
}

QString FitnessExperiment::getUser()
{
    return user;
}

QString FitnessExperiment::getExperimentName()
{
    return experimentName;
}

QString FitnessExperiment::getExperimentType()
{
    return experimentType;
}

uint FitnessExperiment::getFrequency()
{
    return frequency;
}

QString FitnessExperiment::getSpeed()
{
    return speed;
}

qint64 FitnessExperiment::getTimestamp()
{
    return timestamp;
}

void FitnessExperiment::sendToServer()
{
    // //connect to ws
    // clientSocket = new QWebSocket();
    // connect(clientSocket, &QWebSocket::connected, this, &FitnessExperiment::onConnected);
    // // connect(clientSocket, &QWebSocket::disconnected,    this, &FitnessExperiment::closed);

    // clientSocket->open(QUrl("ws://192.168.10.126:1234"));

    QJsonObject root;

    root.insert("user", user);
    root.insert("experimentName", experimentName);
    root.insert("experimentType", experimentType);
    root.insert("frequency", (int)frequency);
    root.insert("speed", speed);
    root.insert("timestamp", timestamp);

    //prepare the two measurement arrays
    QJsonArray accMeasurements;

    for (int i = 0; i < accelerometerReadings.size(); ++i) {

        QJsonObject tempMeasurement;
        tempMeasurement.insert("timestamp", accelerometerReadings.at(i).timestamp);
        tempMeasurement.insert("x", accelerometerReadings.at(i).x);
        tempMeasurement.insert("y", accelerometerReadings.at(i).y);
        tempMeasurement.insert("z", accelerometerReadings.at(i).z);

        accMeasurements.push_back(tempMeasurement);
    }

    QJsonArray gyrMeasurements;

    for (int i = 0; i < gyroscopeReadings.size(); ++i) {

        QJsonObject tempMeasurement;
        tempMeasurement.insert("timestamp", gyroscopeReadings.at(i).timestamp);
        tempMeasurement.insert("x", gyroscopeReadings.at(i).x);
        tempMeasurement.insert("y", gyroscopeReadings.at(i).y);
        tempMeasurement.insert("z", gyroscopeReadings.at(i).z);

        gyrMeasurements.push_back(tempMeasurement);
    }

    //and add them to the final json object
    root.insert("accMeasurements", accMeasurements);
    root.insert("gyrMeasurements", gyrMeasurements);

    root.insert("mode", "save");

    document.setObject(root);

    clientSocket->sendBinaryMessage(document.toJson());
    clientSocket->close();


    // return document.toJson();

    //save the root object in the filesystem

    // QDateTime currentTimestamp = QDateTime::currentDateTime();

    // QFile saveFile(QString("C:\\Users\\Viktorija\\Desktop\\VR\\RV1\\Test2\\test2\\build\\Android_Qt_5_15_2_Clang_Multi_Abi-Debug\\x86\\" +
    //                        user + "_" + currentTimestamp.date().year() + "-" + currentTimestamp.date().month() +
    //                        "-" + currentTimestamp.date().day() + "-" + currentTimestamp.time().hour() + "-" +
    //                        currentTimestamp.time().minute() + ".json"));

    // if (!saveFile.open(QIODevice::WriteOnly)) {

        //     qDebug() << "Unable to open file!";

    //     //On Android, it's expected to have access permission to the parent of the file name, otherwise,
    //     //it won't be possible to create this non-existing file.

    //     return;
    // }

    // saveFile.write(document.toJson());
    // saveFile.close();

    //(test on pc first!!!)
}

void FitnessExperiment::onConnected()
{
    // qDebug() << "Client is connected!";
    // clientSocket->sendBinaryMessage(document.toJson());

    connect(clientSocket, &QWebSocket::binaryMessageReceived,    this, &FitnessExperiment::processBinaryMessage);
}

void FitnessExperiment::processBinaryMessage(QByteArray message)
{
    qDebug() << "Binary message received!";

    QJsonDocument document = QJsonDocument::fromJson(message);
    QJsonObject root = document.object();

    if (root.value("mode").toString() == "getFilenames") {

        QJsonArray array = root.value("files").toArray();

        for (int i = 0; i < array.size(); ++i)
            filenames.push_back(array.at(i).toObject().value("filename").toString());

        qDebug() << "Size: " << filenames.size();

        emit loadSelectExperimentPage();

    } else if (root.value("mode").toString() == "getExperiment") {

        clearParameters();

        user            = root.value("user").toString();
        experimentName  = root.value("experimentName").toString();
        experimentType  = root.value("experimentType").toString();
        speed           = root.value("speed").toString();
        frequency       = root.value("frequency").toInt();
        timestamp       = (qint64) root.value("timestamp").toDouble();

        QJsonArray accelerometerArray   = root.value("accMeasurements").toArray();
        QJsonArray gyroscopeArray       = root.value("gyrMeasurements").toArray();

        for (int i = 0; i < accelerometerArray.size(); ++i) {

            QJsonObject tempObject = accelerometerArray[i].toObject();

            addAccReading((float) tempObject.value("timestamp").toDouble(),
                          (float) tempObject.value("x").toDouble(),
                          (float) tempObject.value("y").toDouble(),
                          (float) tempObject.value("z").toDouble());
        }

        for (int i = 0; i < gyroscopeArray.size(); ++i) {

            QJsonObject tempObject = gyroscopeArray[i].toObject();

            addGyrReading((float) tempObject.value("timestamp").toDouble(),
                          (float) tempObject.value("x").toDouble(),
                          (float) tempObject.value("y").toDouble(),
                          (float) tempObject.value("z").toDouble());
        }

        qDebug() << "Emitting...";

        emit loadAnalysisPage();
    }

    clientSocket->close();
}

QStringList FitnessExperiment::getFilenames()
{
    return filenames;
}

void FitnessExperiment::cancelExperiment()
{
    clearParameters();

    clientSocket->close();
}

void FitnessExperiment::clearParameters()
{
    accelerometerReadings.clear();
    gyroscopeReadings.clear();

    user            = "";
    experimentName  = "";
    experimentType  = "";
    speed           = "";
    frequency       = 0;
    timestamp       = 0;
}

void FitnessExperiment::loadFilenames()
{
    // while (clientSocket->state() != QAbstractSocket::ConnectedState)
    //     continue;

    qDebug() << "load filenames";

    filenames.clear();

    QJsonObject getFilenamesObj;
    getFilenamesObj.insert("mode", "getFilenames");

    QJsonDocument document;
    document.setObject(getFilenamesObj);

    clientSocket->sendBinaryMessage(document.toJson());
    // clientSocket->close();
}

void FitnessExperiment::loadExperiment(QString filename)
{
    qDebug() << "load experiment";

    QJsonObject getExperiment;
    getExperiment.insert("mode", "getExperiment");
    getExperiment.insert("filename", filename);

    qDebug() << getExperiment;

    QJsonDocument document;
    document.setObject(getExperiment);

    qDebug() << clientSocket->state();

    while (clientSocket->state() != QAbstractSocket::ConnectedState)
        continue;

    if (clientSocket->isValid())
        qDebug() << "Client is valid!";

    clientSocket->sendBinaryMessage(document.toJson());

    qDebug() << "message sent!";
}
