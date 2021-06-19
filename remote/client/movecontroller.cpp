#include "movecontroller.h"

MoveController::MoveController(QObject* parent)
    : QObject(parent)
{
    QStringList list;

    for (int i = 0; value(i) >= -100; ++i) {
        list << QString::number(value(i));
    }

    m_speedModel.setStringList(list);
    m_left = list.indexOf(QString::number(0));
    m_right = list.indexOf(QString::number(0));
}

QAbstractListModel* MoveController::speedModel()
{
    return &m_speedModel;
}

int MoveController::leftIdx() const
{
    return m_left;
}

void MoveController::setLeftIdx(const int& value)
{
    m_left = value;
    emit leftIdxChanged();
}

int MoveController::rightIdx() const
{
    return m_right;
}

void MoveController::setRightIdx(const int& value)
{
    m_right = value;
    emit rightIdxChanged();
}

bool MoveController::started()
{
    return m_started;
}

void MoveController::setStarted(const bool& value)
{
    m_started = value;
    emit startedChanged();
}

int MoveController::value(int idx) const
{
    return 100 - 5 * idx;
}

int MoveController::left() const
{
    return value(m_left);
}

int MoveController::right() const
{
    return value(m_right);
}
