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

//object used for maintaining internal structure of experiment
class FitnessExperiment : public QObject
{
    Q_OBJECT

public:
    explicit FitnessExperiment(QObject *parent = nullptr);

    Q_INVOKABLE void addAccReading(const float &timestampTemp, const float &xTemp, const float &yTemp, const float &zTemp);
    Q_INVOKABLE void addGyrReading(const float &timestampTemp, const float &xTemp, const float &yTemp, const float &zTemp);
    Q_INVOKABLE void setUser(const QString &userTemp);
    Q_INVOKABLE void setExperimentName(const QString &nameTemp);
    Q_INVOKABLE void setExperimentType(const QString &typeTemp);
    Q_INVOKABLE void setFrequency(const uint &freqTemp);
    Q_INVOKABLE void setSpeed(const QString &speedTemp);
    Q_INVOKABLE void setTimestamp(const quint64 &timestampTemp);

    Q_INVOKABLE QVector<AccelerometerReading> *getAccReadings();
    Q_INVOKABLE QVector<GyroscopeReading> *getGyrReadings();
    Q_INVOKABLE QString getUser();
    Q_INVOKABLE QString getExperimentName();
    Q_INVOKABLE QString getExperimentType();
    Q_INVOKABLE uint getFrequency();
    Q_INVOKABLE QString getSpeed();
    Q_INVOKABLE qint64 getTimestamp();

    Q_INVOKABLE void sendToServer();
    Q_INVOKABLE void cancelExperiment();

    Q_INVOKABLE int getAccReadingsSize();

    void onConnected();
    void clearParameters();

    Q_INVOKABLE void loadFilenames();
    Q_INVOKABLE QStringList getFilenames();
    Q_INVOKABLE void loadExperiment(QString filename);

signals:
    void loadSelectExperimentPage();
    void loadAnalysisPage();

private:
    void processBinaryMessage(QByteArray message);


signals:

private:
    QVector<AccelerometerReading> accelerometerReadings;
    QVector<GyroscopeReading> gyroscopeReadings;
    QString user;
    QString experimentName;
    QString experimentType;
    uint frequency;
    QString speed;
    QJsonDocument document;
    QWebSocket *clientSocket;
    qint64 timestamp;
    QStringList filenames;
};

#endif // FITNESSEXPERIMENT_H
