#pragma once

#include <QObject>
#include <QStringListModel>

class MoveController : public QObject {
    Q_OBJECT
    Q_PROPERTY(bool started READ started WRITE setStarted NOTIFY startedChanged)
    Q_PROPERTY(int left READ left NOTIFY leftIdxChanged)
    Q_PROPERTY(int right READ right NOTIFY rightIdxChanged)
    Q_PROPERTY(int leftIdx READ leftIdx WRITE setLeftIdx NOTIFY leftIdxChanged)
    Q_PROPERTY(int rightIdx READ rightIdx WRITE setRightIdx NOTIFY rightIdxChanged)
    Q_PROPERTY(QAbstractListModel* speedModel READ speedModel NOTIFY speedModelChanged)

public:
    explicit MoveController(QObject* parent = nullptr);

public slots:
    int value(int idx) const;

signals:
    void leftIdxChanged();
    void rightIdxChanged();
    void speedModelChanged();
    void startedChanged();

private:
    bool started();
    void setStarted(const bool& value);
    QAbstractListModel* speedModel();
    int leftIdx() const;
    void setLeftIdx(const int& value);
    int rightIdx() const;
    void setRightIdx(const int& value);
    int left() const;
    int right() const;

private:
    bool m_started = false;
    int m_left = 0;
    int m_right = 0;
    QStringListModel m_speedModel;
};
