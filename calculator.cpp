// calculator.h
#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QObject>

class Calculator : public QObject {
    Q_OBJECT
    Q_PROPERTY(int result READ result NOTIFY resultChanged)

public:
    explicit Calculator(QObject* parent = nullptr) : QObject(parent), m_result(0) {}

    int result() const {
        return m_result;
    }

    Q_INVOKABLE void add(int a, int b) {
        m_result = a + b;
        emit resultChanged();
    }

signals:
    void resultChanged();

private:
    int m_result;
};

#endif // CALCULATOR_H
