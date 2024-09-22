#include "GameLogic.h"
#include "WordList.h"
#include <cstdlib>
#include <ctime>
#include <QDebug>

GameLogic::GameLogic(QObject *parent) : QObject(parent)
{
    selectRandomWord();

    for (int i = 0; i < 6; ++i) {
        m_guessData.append(QStringList{" ", " ", " ", " ", " ", " "});
        m_guessColors.append(QStringList{"white", "white", "white", "white", "white"});
    }
}

bool GameLogic::checkWord(const QString &word, int currentRow)
{
    QStringList possibleWords = WordList::getPossibleWords();

    if (!possibleWords.contains(word)) {
        qDebug() << "Word is not in the list of possible words!";
        return false;
    }

    m_guessData[currentRow] = word.split("");
    emit guessDataChanged();

    evaluateGuess(word, currentRow);

    if (word == m_currentWord) {
        emit wordChanged();
    }
    return true;
}

void GameLogic::evaluateGuess(const QString &guess, int currentRow)
{
    QStringList guessCopy = m_currentWord.split("", Qt::SkipEmptyParts);
    QStringList colors;

    for (int i = 0; i < m_currentWord.length(); ++i) {
        colors.append("white");
    }

    for (int i = 0; i < guess.length(); ++i) {
        if (guess[i] == guessCopy[i]) {
            colors[i] = "green";
            guessCopy[i] = "";
        }
    }

    // Second pass: Check for partial matches
    for (int i = 0; i < guess.length(); ++i) {
        if (colors[i] != "green" && guessCopy.contains(guess[i])) {
            colors[i] = "yellow";
            guessCopy[guessCopy.indexOf(guess[i])] = "";
        }
    }

    m_guessColors[currentRow] = colors;
    emit guessColorsChanged();
}

QList<QStringList> GameLogic::guessData() const
{
    return m_guessData;
}

QList<QStringList> GameLogic::guessColors() const
{
    return m_guessColors;
}

void GameLogic::selectRandomWord()
{
    QStringList possibleWords = WordList::getPossibleWords();
    srand(static_cast<unsigned int>(time(nullptr)));
    int randomIndex = rand() % possibleWords.size();
    m_currentWord = possibleWords[randomIndex];
    qDebug() << "Selected word:" << m_currentWord;
}
