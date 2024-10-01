#ifndef FitnessExperiment_H
#define FitnessExperiment_H

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

//object used for maintaining internal structure of experiment
class FitnessExperiment : public QObject
{
    Q_OBJECT

    // Q_PROPERTY(QStringList filenames READ getFilenames WRITE setFilenames NOTIFY loadSelectExperimentPage)


public:
    explicit FitnessExperiment(QObject *parent = nullptr);

    //setters

    Q_INVOKABLE void addAccReading(const float &timestampTemp, const float &xTemp, const float &yTemp, const float &zTemp);
    Q_INVOKABLE void addGyrReading(const float &timestampTemp, const float &xTemp, const float &yTemp, const float &zTemp);
    Q_INVOKABLE void setUser(const QString &userTemp);
    Q_INVOKABLE void setExperimentName(const QString &nameTemp);
    Q_INVOKABLE void setExperimentType(const QString &typeTemp);
    Q_INVOKABLE void setFrequency(const uint &freqTemp);
    Q_INVOKABLE void setSpeed(const QString &speedTemp);
    Q_INVOKABLE void setTimestamp(const quint64 &timestampTemp);


    //getters

    Q_INVOKABLE QVector<AccelerometerReading> *getAccReadings();
    Q_INVOKABLE QVector<GyroscopeReading> *getGyrReadings();
    Q_INVOKABLE QString getUser();
    Q_INVOKABLE QString getExperimentName();
    Q_INVOKABLE QString getExperimentType();
    Q_INVOKABLE uint getFrequency();
    Q_INVOKABLE QString getSpeed();
    Q_INVOKABLE qint64 getTimestamp();

    Q_INVOKABLE int getAccReadingsSize();
    Q_INVOKABLE int getGyrReadingsSize();

    Q_INVOKABLE float getAccTimestampAt(int index);
    Q_INVOKABLE float getAccXAt(int index);
    Q_INVOKABLE float getAccYAt(int index);
    Q_INVOKABLE float getAccZAt(int index);

    Q_INVOKABLE float getGyrTimestampAt(int index);
    Q_INVOKABLE float getGyrXAt(int index);
    Q_INVOKABLE float getGyrYAt(int index);
    Q_INVOKABLE float getGyrZAt(int index);

    Q_INVOKABLE float getAccTsMin();
    Q_INVOKABLE float getAccTsMax();
    Q_INVOKABLE float getAccXMin();
    Q_INVOKABLE float getAccXMax();
    Q_INVOKABLE float getAccYMin();
    Q_INVOKABLE float getAccYMax();
    Q_INVOKABLE float getAccZMin();
    Q_INVOKABLE float getAccZMax();

    Q_INVOKABLE float getGyrTsMin();
    Q_INVOKABLE float getGyrTsMax();
    Q_INVOKABLE float getGyrXMin();
    Q_INVOKABLE float getGyrXMax();
    Q_INVOKABLE float getGyrYMin();
    Q_INVOKABLE float getGyrYMax();
    Q_INVOKABLE float getGyrZMin();
    Q_INVOKABLE float getGyrZMax();

    Q_INVOKABLE QString getCalculatedData(uint sensorMode, uint coordinateMode);

    Q_INVOKABLE QStringList getFilenames();


    Q_INVOKABLE void sendToServer();        //sends recorded data from experiment to server
    Q_INVOKABLE void cancelExperiment();    //redundant

    void onConnected();
    void clearParameters();

    Q_INVOKABLE void clearVectors();

    Q_INVOKABLE void loadFilenames();
    Q_INVOKABLE void loadExperiment(QString filename);

    void clearLoadExperimentRanges();

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
    QString speed;
    qint64 timestamp;
    QStringList filenames;

    QJsonDocument document;
    QWebSocket *clientSocket;

    QVector<float> loadExperimentTimestampsStart;
    QVector<float> loadExperimentTimestampsEnd;

    QVector<float> loadExperimentAccStart;
    QVector<float> loadExperimentAccEnd;

    QVector<float> loadExperimentGyrStart;
    QVector<float> loadExperimentGyrEnd;

    float accTsMin;
    float accTsMax;
    float accXMin;
    float accXMax;
    float accYMin;
    float accYMax;
    float accZMin;
    float accZMax;

    float gyrTsMin;
    float gyrTsMax;
    float gyrXMin;
    float gyrXMax;
    float gyrYMin;
    float gyrYMax;
    float gyrZMin;
    float gyrZMax;

    float accXAvg;
    float accYAvg;
    float accZAvg;
    float accXStd;
    float accYStd;
    float accZStd;

    float gyrXAvg;
    float gyrYAvg;
    float gyrZAvg;
    float gyrXStd;
    float gyrYStd;
    float gyrZStd;
};

#endif // FitnessExperiment_H
