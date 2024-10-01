#include "FitnessExperiment.h"
#include <QDebug>
#include <QJsonArray>
#include <QJsonObject>
#include <QFile>
#include <QDateTime>
#include <QWebSocket>
#include <QQmlEngine>
#include <QQmlComponent>
#include <QtMath>

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

float FitnessExperiment::getAccTimestampAt(int index)
{
    return accelerometerReadings.at(index).timestamp;
}

float FitnessExperiment::getAccXAt(int index)
{
    return accelerometerReadings.at(index).x;
}

float FitnessExperiment::getAccYAt(int index)
{
    return accelerometerReadings.at(index).y;
}

float FitnessExperiment::getAccZAt(int index)
{
    return accelerometerReadings.at(index).z;
}


QVector<GyroscopeReading> * FitnessExperiment::getGyrReadings()
{
    return &gyroscopeReadings;
}

int FitnessExperiment::getGyrReadingsSize()
{
    return gyroscopeReadings.size();
}

float FitnessExperiment::getGyrTimestampAt(int index)
{
    return gyroscopeReadings.at(index).timestamp;
}

float FitnessExperiment::getGyrXAt(int index)
{
    return gyroscopeReadings.at(index).x;
}

float FitnessExperiment::getGyrYAt(int index)
{
    return gyroscopeReadings.at(index).y;
}

float FitnessExperiment::getGyrZAt(int index)
{
    return gyroscopeReadings.at(index).z;
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
    //start building the json object to be sent to the server
    //called in experiment.qml

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

    root.insert("accMeasurements", accMeasurements);
    root.insert("gyrMeasurements", gyrMeasurements);

    root.insert("mode", "save");

    document.setObject(root);

    clientSocket->sendBinaryMessage(document.toJson());
}

void FitnessExperiment::onConnected()
{
    connect(clientSocket, &QWebSocket::binaryMessageReceived,    this, &FitnessExperiment::processBinaryMessage);
}

void FitnessExperiment::processBinaryMessage(QByteArray message)
{
    qDebug() << "Binary message received!";

    QJsonDocument document = QJsonDocument::fromJson(message);
    QJsonObject root = document.object();

    if (root.value("mode").toString() == "getFilenames") {

        //a list of every file in the data folder in the server has been returned

        QJsonArray array = root.value("files").toArray();

        for (int i = 0; i < array.size(); ++i)
            filenames.push_back(array.at(i).toObject().value("filename").toString());

        emit loadSelectExperimentPage();    //caught in selectexperiment.qml

    } else if (root.value("mode").toString() == "getExperiment") {

        //a json object with data of the experiment has been returned

        //clear parameters from previously loaded experiment
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

        //find min/max for axes for accelerator

        accTsMin = accelerometerReadings.at(0).timestamp;
        accXMin = accelerometerReadings.at(0).x;
        accYMin = accelerometerReadings.at(0).y;
        accZMin = accelerometerReadings.at(0).z;
        accXAvg = accelerometerReadings.at(0).x;
        accYAvg = accelerometerReadings.at(0).y;
        accZAvg = accelerometerReadings.at(0).z;

        for (int i = 1; i < accelerometerReadings.size(); ++i) {

            if (accTsMin > accelerometerReadings.at(i).timestamp)
                accTsMin = accelerometerReadings.at(i).timestamp;

            else if (accTsMax < accelerometerReadings.at(i).timestamp)
                accTsMax = accelerometerReadings.at(i).timestamp;


            if (accXMin > accelerometerReadings.at(i).x)
                accXMin = accelerometerReadings.at(i).x;

            else if (accXMax < accelerometerReadings.at(i).x)
                accXMax = accelerometerReadings.at(i).x;


            if (accYMin > accelerometerReadings.at(i).y)
                accYMin = accelerometerReadings.at(i).y;

            else if (accYMax < accelerometerReadings.at(i).y)
                accYMax = accelerometerReadings.at(i).y;


            if (accZMin > accelerometerReadings.at(i).z)
                accZMin = accelerometerReadings.at(i).z;

            else if (accZMax < accelerometerReadings.at(i).z)
                accZMax = accelerometerReadings.at(i).z;

            accXAvg += accelerometerReadings.at(i).x;
            accYAvg += accelerometerReadings.at(i).y;
            accZAvg += accelerometerReadings.at(i).z;
        }

        accXAvg /= accelerometerReadings.size();
        accYAvg /= accelerometerReadings.size();
        accZAvg /= accelerometerReadings.size();

        //calculate std for accelerator

        for (int i = 0; i < accelerometerReadings.size(); ++i) {
            accXStd += qPow(accelerometerReadings.at(i).x - accXAvg, 2);
            accYStd += qPow(accelerometerReadings.at(i).y - accYAvg, 2);
            accZStd += qPow(accelerometerReadings.at(i).z - accZAvg, 2);
        }

        accXStd = qSqrt(accXStd / (accelerometerReadings.size() - 1));
        accYStd = qSqrt(accYStd / (accelerometerReadings.size() - 1));
        accZStd = qSqrt(accZStd / (accelerometerReadings.size() - 1));


        //find min/max for axes for gyroscope

        gyrTsMin = gyroscopeReadings.at(0).timestamp;
        gyrXMin = gyroscopeReadings.at(0).x;
        gyrYMin = gyroscopeReadings.at(0).y;
        gyrZMin = gyroscopeReadings.at(0).z;

        for (int i = 1; i < gyroscopeReadings.size(); ++i) {

            if (gyrTsMin > gyroscopeReadings.at(i).timestamp)
                gyrTsMin = gyroscopeReadings.at(i).timestamp;

            else if (gyrTsMax < gyroscopeReadings.at(i).timestamp)
                gyrTsMax = gyroscopeReadings.at(i).timestamp;


            if (gyrXMin > gyroscopeReadings.at(i).x)
                gyrXMin = gyroscopeReadings.at(i).x;

            else if (gyrXMax < gyroscopeReadings.at(i).x)
                gyrXMax = gyroscopeReadings.at(i).x;


            if (gyrYMin > gyroscopeReadings.at(i).y)
                gyrYMin = gyroscopeReadings.at(i).y;

            else if (gyrYMax < gyroscopeReadings.at(i).y)
                gyrYMax = gyroscopeReadings.at(i).y;


            if (gyrZMin > gyroscopeReadings.at(i).z)
                gyrZMin = gyroscopeReadings.at(i).z;

            else if (gyrZMax < gyroscopeReadings.at(i).z)
                gyrZMax = gyroscopeReadings.at(i).z;

            gyrXAvg = gyroscopeReadings.at(0).x;
            gyrYAvg = gyroscopeReadings.at(0).y;
            gyrZAvg = gyroscopeReadings.at(0).z;
        }

        gyrXAvg /= gyroscopeReadings.size();
        gyrYAvg /= gyroscopeReadings.size();
        gyrZAvg /= gyroscopeReadings.size();

        //calculate std for gyroscope

        for (int i = 0; i < gyroscopeReadings.size(); ++i) {
            gyrXStd += qPow(gyroscopeReadings.at(i).x - gyrXAvg, 2);
            gyrYStd += qPow(gyroscopeReadings.at(i).y - gyrYAvg, 2);
            gyrZStd += qPow(gyroscopeReadings.at(i).z - gyrZAvg, 2);
        }

        gyrXStd = qSqrt(gyrXStd / (gyroscopeReadings.size() - 1));
        gyrYStd = qSqrt(gyrYStd / (gyroscopeReadings.size() - 1));
        gyrZStd = qSqrt(gyrZStd / (gyroscopeReadings.size() - 1));

        emit loadAnalysisPage();    //caught in analyzeexperiment.qml
    }
}

float FitnessExperiment::getAccTsMin()
{
    return accTsMin;
}

float FitnessExperiment::getAccTsMax()
{
    return accTsMax;
}

float FitnessExperiment::getAccXMin()
{
    return accXMin;
}

float FitnessExperiment::getAccXMax()
{
    return accXMax;
}

float FitnessExperiment::getAccYMin()
{
    return accYMin;
}

float FitnessExperiment::getAccYMax()
{
    return accYMax;
}

float FitnessExperiment::getAccZMin()
{
    return accZMin;
}

float FitnessExperiment::getAccZMax()
{
    return accZMax;
}

float FitnessExperiment::getGyrTsMin()
{
    return gyrTsMin;
}

float FitnessExperiment::getGyrTsMax()
{
    return gyrTsMax;
}

float FitnessExperiment::getGyrXMin()
{
    return gyrXMin;
}

float FitnessExperiment::getGyrXMax()
{
    return gyrXMax;
}

float FitnessExperiment::getGyrYMin()
{
    return gyrYMin;
}

float FitnessExperiment::getGyrYMax()
{
    return gyrYMax;
}

float FitnessExperiment::getGyrZMin()
{
    return gyrZMin;
}

float FitnessExperiment::getGyrZMax()
{
    return gyrZMax;
}

void FitnessExperiment::clearVectors()
{
    accelerometerReadings.clear();
    gyroscopeReadings.clear();
}

QStringList FitnessExperiment::getFilenames()
{
    return filenames;
}

void FitnessExperiment::cancelExperiment()  // redundant function! improvement: make clearParameters Q_INVOKABLE
{
    clearParameters();
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
    //function called from selectexperiment.qml

    //clear previously loaded filenames
    filenames.clear();

    QJsonObject getFilenamesObj;
    getFilenamesObj.insert("mode", "getFilenames");

    QJsonDocument document;
    document.setObject(getFilenamesObj);

    clientSocket->sendBinaryMessage(document.toJson());
}

void FitnessExperiment::loadExperiment(QString filename)
{
    //function called from analyzeexperiment.qml

    clearParameters();              //clear parameters from previously loaded experiment
    clearLoadExperimentRanges();    //clear axes ranges from charts

    QJsonObject getExperiment;
    getExperiment.insert("mode", "getExperiment");
    getExperiment.insert("filename", filename);

    QJsonDocument document;
    document.setObject(getExperiment);

    clientSocket->sendBinaryMessage(document.toJson());
}

void FitnessExperiment::clearLoadExperimentRanges()
{
    accTsMin = 0;
    accTsMax = 0;
    accXMin = 0;
    accXMax = 0;
    accYMin = 0;
    accYMax = 0;
    accZMin = 0;
    accZMax = 0;

    gyrTsMin = 0;
    gyrTsMax = 0;
    gyrXMin = 0;
    gyrXMax = 0;
    gyrYMin = 0;
    gyrYMax = 0;
    gyrZMin = 0;
    gyrZMax = 0;

    //avgs and stds needn't be cleared, since they're being set in processBinaryMessage
}

QString FitnessExperiment::getCalculatedData(uint sensorMode, uint coordinateMode)
{
    //calculate average, standard deviation, add min and max to string for charts page
    //sensorMode values: 1 -> acc; 2 -> gyr
    //coordinateMode values: 1 -> x; 2 -> y; 3 -> z
    //improvement: enums

    float min = 0, max = 0, average = 0, standardDeviation = 0;

    if (sensorMode == 1) {

        if (coordinateMode == 1) {

            min = getAccXMin();
            max = getAccXMax();
            average = accXAvg;
            standardDeviation = accXStd;

        } else if (coordinateMode == 2) {

            min = getAccYMin();
            max = getAccYMax();
            average = accYAvg;
            standardDeviation = accYStd;

        } else {

            min = getAccZMin();
            max = getAccZMax();
            average = accZAvg;
            standardDeviation = accZStd;

        }

    } else {
        if (coordinateMode == 1) {

            min = getGyrXMin();
            max = getGyrXMax();
            average = gyrXAvg;
            standardDeviation = gyrXStd;

        } else if (coordinateMode == 2) {

            min = getGyrYMin();
            max = getGyrYMax();
            average = gyrYAvg;
            standardDeviation = gyrYStd;

        } else {

            min = getGyrZMin();
            max = getGyrZMax();
            average = gyrZAvg;
            standardDeviation = gyrZStd;
        }
    }

    return QString("Min: " + QString::number(min) + "   Max: " + QString::number(max) + "   Avg: " +
                   QString::number(average) + "   Std: " + QString::number(standardDeviation));
}

