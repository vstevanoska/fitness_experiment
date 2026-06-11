#ifndef FITNESSEXPERIMENT_H
#define FITNESSEXPERIMENT_H

#include <QObject>
#include <QString>
#include <QVector>
#include <QJsonDocument>
#include <QWebSocket>
#include <QAccelerometerReading>
#include <QGyroscopeReading>

struct AccelerometerReading
{
    float timestamp;
    float x;
    float y;
    float z;
};

struct GyroscopeReading
{
    float timestamp;
    float x;
    float y;
    float z;
};

class FitnessExperiment : public QObject
{
    Q_OBJECT

public:
    explicit FitnessExperiment(QObject *parent = nullptr);

    //setters

    Q_INVOKABLE void addAccReading(const float timestampTemp, const float xTemp, const float yTemp, const float zTemp);
    Q_INVOKABLE void addGyrReading(const float timestampTemp, const float xTemp, const float yTemp, const float zTemp);
    Q_INVOKABLE void setUser(const QString &userTemp);
    Q_INVOKABLE void setExperimentName(const QString &nameTemp);
    Q_INVOKABLE void setExperimentType(const QString &typeTemp);
    Q_INVOKABLE void setFrequency(const uint freqTemp);
    Q_INVOKABLE void setTimestamp(const quint64 timestampTemp);
    Q_INVOKABLE void setNumberOfReps(const int numberOfRepsTemp);

    //getters

    Q_INVOKABLE QVector<AccelerometerReading> *getAccReadings();
    Q_INVOKABLE QVector<GyroscopeReading> *getGyrReadings();
    Q_INVOKABLE QString getUser() const;
    Q_INVOKABLE QString getExperimentName() const;
    Q_INVOKABLE QString getExperimentType() const;
    Q_INVOKABLE uint getFrequency() const;
    Q_INVOKABLE qint64 getTimestamp() const;

    Q_INVOKABLE int getAccReadingsSize() const;
    Q_INVOKABLE int getGyrReadingsSize() const;

    Q_INVOKABLE float getAccTimestampAt(int index) const;
    Q_INVOKABLE float getAccXAt(int index) const;
    Q_INVOKABLE float getAccYAt(int index) const;
    Q_INVOKABLE float getAccZAt(int index) const;

    Q_INVOKABLE float getGyrTimestampAt(int index) const;
    Q_INVOKABLE float getGyrXAt(int index) const;
    Q_INVOKABLE float getGyrYAt(int index) const;
    Q_INVOKABLE float getGyrZAt(int index) const;

    Q_INVOKABLE float getAccTsMin() const;
    Q_INVOKABLE float getAccTsMax() const;
    Q_INVOKABLE float getAccXMin() const;
    Q_INVOKABLE float getAccXMax() const;
    Q_INVOKABLE float getAccYMin() const;
    Q_INVOKABLE float getAccYMax() const;
    Q_INVOKABLE float getAccZMin() const;
    Q_INVOKABLE float getAccZMax() const;

    Q_INVOKABLE float getGyrTsMin() const;
    Q_INVOKABLE float getGyrTsMax() const;
    Q_INVOKABLE float getGyrXMin() const;
    Q_INVOKABLE float getGyrXMax() const;
    Q_INVOKABLE float getGyrYMin() const;
    Q_INVOKABLE float getGyrYMax() const;
    Q_INVOKABLE float getGyrZMin() const;
    Q_INVOKABLE float getGyrZMax() const;

    Q_INVOKABLE QString getCalculatedData(uint sensorMode, uint coordinateMode) const;

    Q_INVOKABLE QStringList getFilenames() const;

    Q_INVOKABLE void sendToServer() const;  //sends recorded data from experiment to server
    Q_INVOKABLE void clearParameters();     //clear experiment parameters

    void onConnected();         //websockets slot

    Q_INVOKABLE void clearVectors();    //clear only accelerometer and gyroscope vectors

    Q_INVOKABLE void loadFilenames();                   //get filenames from server
    Q_INVOKABLE void loadExperiment(QString filename);  //get specific experiment data from server

    void clearLoadExperimentRanges();   //clear avg and std values

signals:
    void loadSelectExperimentPage();
    void loadAnalysisPage();

private:
    void processBinaryMessage(QByteArray message);

private:
    QVector<AccelerometerReading> accelerometerReadings;
    QVector<GyroscopeReading> gyroscopeReadings;
    QString user;
    QString experimentName;
    QString experimentType;
    uint frequency;
    qint64 timestamp;
    QStringList filenames;
    int numberOfReps;

    QWebSocket *clientSocket;

    float accTsMin = 0.0f;
    float accTsMax = 0.0f;
    float accXMin = 0.0f;
    float accXMax = 0.0f;
    float accYMin = 0.0f;
    float accYMax = 0.0f;
    float accZMin = 0.0f;
    float accZMax = 0.0f;

    float gyrTsMin = 0.0f;
    float gyrTsMax = 0.0f;
    float gyrXMin = 0.0f;
    float gyrXMax = 0.0f;
    float gyrYMin = 0.0f;
    float gyrYMax = 0.0f;
    float gyrZMin = 0.0f;
    float gyrZMax = 0.0f;

    float accXAvg = 0.0f;
    float accYAvg = 0.0f;
    float accZAvg = 0.0f;
    float accXStd; = 0.0f
    float accYStd = 0.0f;
    float accZStd = 0.0f;

    float gyrXAvg = 0.0f;
    float gyrYAvg = 0.0f;
    float gyrZAvg = 0.0f;
    float gyrXStd = 0.0f;
    float gyrYStd = 0.0f;
    float gyrZStd = 0.0f;
};

#endif // FITNESSEXPERIMENT_H
