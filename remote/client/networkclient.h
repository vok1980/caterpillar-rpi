#pragma once

#include <QObject>

#include "messages/move.pb.h"

class NetworkClient : public QObject {
    Q_OBJECT
    Q_PROPERTY(int left READ left WRITE setLeft)
    Q_PROPERTY(int right READ right WRITE setRight)
public:
    explicit NetworkClient(QObject* parent = nullptr);

signals:

private:
    void setLeft(const int& value);
    void setRight(const int& value);
    int left();
    int right();
    void send();

private:
    Move m_message;

    std::string m_host = "192.168.0.106";
    int m_port = 1999;
};
