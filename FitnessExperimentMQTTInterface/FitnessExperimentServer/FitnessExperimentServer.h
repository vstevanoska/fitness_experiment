#ifndef FITNESSEXPERIMENTSERVER_H
#define FITNESSEXPERIMENTSERVER_H

#include <QObject>
#include <QWebSocketServer>

class FitnessExperimentServer : public QObject
{
    Q_OBJECT
public:
    explicit FitnessExperimentServer(quint16 port, bool isDebug = false, QObject *parent = nullptr);
    ~FitnessExperimentServer();

signals:
    void closed();

private slots:
    void onNewConnection();
    void processTextMessage(QString message);
    void processBinaryMessage(QByteArray message);
    void socketDisconnected();

private:
    QWebSocketServer *socketServer;
    QList<QWebSocket *> clients;
    bool debug;
};

#endif // FITNESSEXPERIMENTSERVER_H
