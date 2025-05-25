import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import QtGraphicalEffects 1.12

import com.company.fitnessExperiment 1.0

Rectangle {
    id: root
    color: "#F4F4FB"

    readonly property int leftMargin: 20
    readonly property int labelWidth: 100
    readonly property int textFontSize: 20

    property alias exerciseComboBox: exerciseCb.currentText

    function resetRotations() {
        imageXRotation.angle = 0
        imageYRotation.angle = 0
        imageZRotation.angle = 0
    }

    ColumnLayout {

        width: stack.width

        Text {
            id: title
            Layout.topMargin: mainWindow.height / 8
            Layout.alignment: Qt.AlignCenter
            Layout.preferredHeight: titleHeight
            text: "New experiment"
            color: "#5E69EE" //#39AFEA - accent
            font.weight: Font.ExtraBold
            font.family: georgiaFont.name
            font.pixelSize: titleFontSize
        }


        RowLayout {

            Layout.alignment: Qt.AlignCenter

            Item {
                Layout.preferredWidth: labelWidth

                Text {
                    id: userText
                    text: qsTr("User: ")
                    font.family: georgiaFont.name
                    font.pixelSize: textFontSize
                }
            }

            ComboBox {
                id: userCb
                model: ["VS", "OC", "TK", "MR"]
                font.family: georgiaFont.name
                font.pixelSize: textFontSize
                Layout.preferredWidth: experimentTextField.width
                Layout.alignment: Qt.AlignBaseline
            }
            Layout.bottomMargin: leftMargin
        }

        RowLayout {

            Layout.alignment: Qt.AlignCenter

            Item {
                Layout.preferredWidth: labelWidth

                Text {
                    id: nameOfExperimentText
                    text: qsTr("Name: ")
                    font.family: georgiaFont.name
                    font.pixelSize: textFontSize
                    Layout.alignment: Qt.AlignBaseline
                }
            }
            TextField {
                id: experimentTextField
                font.family: georgiaFont.name
                font.pixelSize: textFontSize
                Layout.alignment: Qt.AlignBaseline
            }
            Layout.bottomMargin: leftMargin
        }


        RowLayout {

            Layout.alignment: Qt.AlignCenter

            Item {
                Layout.preferredWidth: labelWidth

                Text {
                    id: exerciseText
                    text: qsTr("Exercise: ")
                    font.family: georgiaFont.name
                    font.pixelSize: textFontSize
                    Layout.alignment: Qt.AlignBaseline
                }
            }

            ComboBox {
                id: exerciseCb
                model: ["Overhead triceps extension", "Bicep curl", "Tricep dumbbell kickback"]
                font.family: georgiaFont.name
                Layout.preferredWidth: experimentTextField.width
                Layout.alignment: Qt.AlignBaseline
            }
            Layout.bottomMargin: leftMargin
        }

        RowLayout {

            Layout.alignment: Qt.AlignCenter

            Item {

                Layout.preferredWidth: labelWidth

                Text {
                    id: frequencyText
                    text: qsTr("Frequency: ")
                    font.family: georgiaFont.name
                    font.pixelSize: textFontSize
                    Layout.alignment: Qt.AlignBaseline
                }
            }

            ComboBox {
                id: frequencyCb
                model: ["26", "52", "104"]
                font.family: georgiaFont.name
                font.pixelSize: textFontSize
                Layout.preferredWidth: experimentTextField.width
                Layout.alignment: Qt.AlignBaseline
            }
            Layout.bottomMargin: leftMargin
        }

        RowLayout {
            Layout.fillWidth: true
            Layout.alignment: Qt.AlignCenter

            Button {
                id: backToMainScreenFromSetParameters
                Layout.preferredWidth: stack.width / 2.15
                Layout.alignment: Qt.AlignCenter | Qt.AlignBaseline
                text: "Back"
                font.family: georgiaFont.name
                font.pixelSize: buttonFontSize
                background: Rectangle {
                    color: parent.pressed ? "#5E69EE" : (parent.hovered ? "#88AFEA" : "#39AFEA")
                    border.color: "black"
                    border.width: 2
                    radius: 8
                }
                onClicked: stack.pop()
            }

            Button {
                id: startExperimentButton
                Layout.preferredWidth: stack.width / 2.15
                Layout.alignment: Qt.AlignCenter | Qt.AlignBaseline
                Layout.bottomMargin: buttonHeight / 20
                text: "Start"
                font.family: georgiaFont.name
                font.pixelSize: buttonFontSize
                background: Rectangle {
                    color: parent.pressed ? "#5E69EE" : (parent.hovered ? "#88AFEA" : "#39AFEA")
                    border.color: "black"
                    border.width: 2
                    radius: 8
                }

                onClicked: {

                    //set starting parameters for the experiment

                    FitnessExperiment.setUser(userCb.currentText);
                    FitnessExperiment.setExperimentName(experimentTextField.text);
                    FitnessExperiment.setExperimentType(exerciseCb.currentText);
                    FitnessExperiment.setFrequency(Number(frequencyCb.currentText));

                    stack.push("qrc:/experiment.qml");
                }
            }
        }
    }
}
