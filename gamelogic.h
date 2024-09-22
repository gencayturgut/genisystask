#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include <QObject>
#include <QStringList>

class GameLogic : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QList<QStringList> guessData READ guessData NOTIFY guessDataChanged)
    Q_PROPERTY(QList<QStringList> guessColors READ guessColors NOTIFY guessColorsChanged)

public:
    explicit GameLogic(QObject *parent = nullptr);

    Q_INVOKABLE bool checkWord(const QString &word, const int currentRow);

    QList<QStringList> guessData() const;
    QList<QStringList> guessColors() const;

signals:
    void guessDataChanged();
    void guessColorsChanged();
    void wordChanged();

private:
    QString m_currentWord;
    QList<QStringList> m_guessData;
    QList<QStringList> m_guessColors;
    void evaluateGuess(const QString &guess, const int currentRow);
    void selectRandomWord();
};

#endif
