import QtQuick 2.15
import QtQuick.Controls 2.15
import genisystask 1.0

ApplicationWindow {
    visible: true
    width: 400
    height: 600
    title: "Wordle"
    property int currentRow: 0
    property bool gameOver: false
    property bool isValid: true
    GameLogic {
        id: gameLogic
        onWordChanged: {
            resultMessage.visible = true
            resultMessage.text = "Correct word! You won!"
            resultMessage.color = "green"
            gameOver = true
        }
    }

    Column {
        anchors.centerIn: parent
        spacing: 10

        Repeater {
            model: 6
            delegate: Row {
                spacing: 5
                property int row: index
                Repeater {
                    model: 5
                    delegate: Rectangle {
                        width: 50
                        height: 50
                        border.color: "gray"
                        color: gameLogic.guessColors[row][index]
                        Text {
                            anchors.centerIn: parent
                            text: gameLogic.guessData[row][index + 1]
                            font.pixelSize: 24
                        }
                    }
                }
            }
        }

        Row {
            spacing: 5
            TextField {
                id: letterInput
                width: 250
                placeholderText: "Enter 5-letter word"
                maximumLength: 5
                enabled: !gameOver
                validator: RegExpValidator {
                    regExp: /[a-zA-Z]+/
                }
            }
            Button {
                text: "Submit"
                enabled: !gameOver
                onClicked: {
                    if (letterInput.text.length === 5 && currentRow < 6) {
                        const isValid = gameLogic.checkWord(letterInput.text,
                                                            currentRow)
                        isValid && currentRow++
                        console.log("currentRow:", currentRow)
                        letterInput.text = ""
                    }
                }
            }
        }

        Text {
            id: resultMessage
            text: ""
            color: "green"
            font.pixelSize: 24
            visible: false
        }
    }
}
