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

    // property alias exerciseCombobox: exerciseCb.currentText

    // readonly property int appWidth: 540

    function resetRotations() {
        imageXRotation.angle = 0
        imageYRotation.angle = 0
        imageZRotation.angle = 0
    }

//! [0]
    // Accelerometer {
    //     id: accelerometer
    //     active: true
    //     dataRate: 25

    //     property real x: 0
    //     property real y: 0
    //     property real z: 0

    //     onReadingChanged: {
    //         // x = reading.x
    //         // y = reading.y
    //         // z = reading.z

    //         // imageTranslation.x = -reading.x * 10
    //         // imageTranslation.y = reading.y * 10
    //     }
    // }
//! [0]

    ColumnLayout {

        width: stack.width

        Text {
            id: title
            Layout.topMargin: mainWindow.height / 8
            Layout.alignment: Qt.AlignCenter
            Layout.preferredHeight: titleHeight
            // anchors.topMargin: mainWindow.height / 100
            // anchors.bottomMargin: leftMargin * 2
            // horizontalAlignment: Qt.AlignCenter
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
                // Layout.preferredHeight: titleHeight / 2

                Text {
                    id: userText
                    text: qsTr("User: ")
                    font.family: georgiaFont.name
                    font.pixelSize: textFontSize
                }
            }

            ComboBox {
                id: userCb
                // Layout.alignment: Qt.AlignVCenter
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

            Layout.alignment: Qt.AlignCenter

            Item {

                Layout.preferredWidth: labelWidth
                // Layout.leftMargin: leftMargin
                // Layout.alignment: Qt.AlignCenter | Qt.AlignBaseline

                Text {
                    id: speedText
                    text: qsTr("Speed: ")
                    font.family: georgiaFont.name
                    font.pixelSize: textFontSize
                    Layout.alignment: Qt.AlignBaseline
                }
            }

            ComboBox {
                id: speedCb
                model: ["Normal", "Slow", "Fast"]
                font.family: georgiaFont.name
                font.pixelSize: textFontSize
                Layout.preferredWidth: experimentTextField.width
                Layout.alignment: Qt.AlignBaseline

            }
            Layout.bottomMargin: leftMargin * 3
        }

        RowLayout {
            Layout.fillWidth: true
            Layout.alignment: Qt.AlignCenter

            Button {
                id: backToMainScreenFromSetParameters
                // Layout.fillHeight: true
                Layout.preferredWidth: stack.width / 2.15
                Layout.alignment: Qt.AlignCenter | Qt.AlignBaseline
                text: "Back"
                font.family: georgiaFont.name
                font.pixelSize: buttonFontSize
                // background: Rectangle {
                //    color: "#39AFEA"
                // }
                background: Rectangle {
                    color: parent.pressed ? "#5E69EE" : (parent.hovered ? "#88AFEA" : "#39AFEA")
                    border.color: "black"
                    border.width: 2
                    radius: 8  // Rounded corners

                    // // Adding shadow effect
                    // layer.enabled: true
                    // layer.effect: DropShadow {
                    //     color: "#00000080"
                    //     horizontalOffset: 3
                    //     verticalOffset: 3
                    //     radius: 6
                    // }
                }
                onClicked: stack.pop()
            }

            Button {
                // Layout.fillHeight: true
                id: startExperimentButton
                Layout.preferredWidth: stack.width / 2.15
                Layout.alignment: Qt.AlignCenter | Qt.AlignBaseline
                Layout.bottomMargin: buttonHeight / 20
                text: "Start"
                font.family: georgiaFont.name
                font.pixelSize: buttonFontSize
                // background: Rectangle {
                //    color: "#39AFEA"
                // }
                background: Rectangle {
                    color: parent.pressed ? "#5E69EE" : (parent.hovered ? "#88AFEA" : "#39AFEA")
                    border.color: "black"
                    border.width: 2
                    radius: 8  // Rounded corners

                    // // Adding shadow effect
                    // layer.enabled: true
                    // layer.effect: DropShadow {
                    //     color: "#00000080"
                    //     horizontalOffset: 3
                    //     verticalOffset: 3
                    //     radius: 6
                    // }
                }

                onClicked: {

                    // fitnessExperiment.startExperiment(userCb.currentText, experimentTextField.text, exerciseCb.currentText, frequencyCb.currentText, speedCb.currentText);

                    // experimentPage.experimentName = exerciseCb.currentText

                    FitnessExperiment.setUser(userCb.currentText);
                    FitnessExperiment.setExperimentName(experimentTextField.text);
                    FitnessExperiment.setExperimentType(exerciseCb.currentText);
                    FitnessExperiment.setFrequency(Number(frequencyCb.currentText));
                    FitnessExperiment.setSpeed(speedCb.currentText);

                    // stack.push("qrc:/experiment.qml", {"user": userCb.currentText,
                    //                "experimentName": experimentTextField.text,
                    //                "exerciseCombo": exerciseCb.currentText,
                    //                "sampleRate": Number(frequencyCb.currentText),
                    //                "exerciseSpeed": speedCb.currentText})
                    stack.push("qrc:/experiment.qml");
                }
            }

            // DropShadow {
            //     anchors.fill: startExperimentButton
            //     horizontalOffset: 3
            //     verticalOffset: 3
            //     radius: 0
            //     samples: 17
            //     color: "#5E46EE"
            //     source: startExperimentButton
            // }

            // DropShadow {
            //     anchors.fill: backToMainScreenFromSetParameters
            //     horizontalOffset: 3
            //     verticalOffset: 3
            //     radius: 0
            //     samples: 17
            //     color: "#5E46EE"
            //     source: backToMainScreenFromSetParameters
            // }
        }

        // DropShadow {
        //     anchors.fill: userCb
        //     horizontalOffset: 3
        //     verticalOffset: 3
        //     radius: 0
        //     samples: 17
        //     color: "#5E46EE"
        //     source: userCb
        // }

        // DropShadow {
        //     anchors.fill: experimentCb
        //     horizontalOffset: 3
        //     verticalOffset: 3
        //     radius: 0
        //     samples: 17
        //     color: "#5E46EE"
        //     source: experimentCb
        // }

        // DropShadow {
        //     anchors.fill: frequencyCb
        //     horizontalOffset: 3
        //     verticalOffset: 3
        //     radius: 0
        //     samples: 17
        //     color: "#5E46EE"
        //     source: frequencyCb
        // }

        // DropShadow {
        //     anchors.fill: speedCb
        //     horizontalOffset: 3
        //     verticalOffset: 3
        //     radius: 0
        //     samples: 17
        //     color: "#5E46EE"
        //     source: speedCb
        // }

        // DropShadow {
        //     anchors.fill: backButton
        //     horizontalOffset: 3
        //     verticalOffset: 3
        //     radius: 0
        //     samples: 17
        //     color: "#5E46EE"
        //     source: backButton
        // }
    }
}
    // ColumnLayout {
    //     anchors.fill: parent
    //     id: layout

    //     Text {
    //         Layout.topMargin: titleTopMargin
    //         Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
    //         Layout.preferredHeight: textHeight
    //         color: "White"
    //         text: "Accelerometer"
    //         font.pixelSize: titleFontSize
    //     }

    //     Image {
    //         id: image
    //         Layout.alignment: Qt.AlignCenter
    //         Layout.fillHeight: true
    //         Layout.preferredWidth: root.width/2
    //         Layout.preferredHeight: root.height/3
    //         source: "qrc:/images/2560px-Qt_logo_2016.png"
    //         fillMode: Image.PreserveAspectFit

    //         transform: [
    //             Translate {
    //                 id: imageTranslation
    //                 x: 0
    //                 y: 0
    //             }
    //         ]
    //     }

    //     Text {
    //         Layout.preferredWidth: root.width
    //         Layout.preferredHeight: textHeight
    //         Layout.leftMargin: layout.spacing
    //         color: "White"
    //         text: "X: " + accelerometer.x.toFixed(2)
    //         font.pixelSize: textFontSize
    //     }

    //     ProgressBar {
    //         id: xbar
    //         value: 0.5 + (accelerometer.x / 100)
    //         Layout.preferredWidth: root.width
    //     }

    //     Text {
    //         Layout.preferredWidth: root.width
    //         Layout.preferredHeight: textHeight
    //         Layout.leftMargin: layout.spacing
    //         color: "White"
    //         text: "Y: " + accelerometer.y.toFixed(2)
    //         font.pixelSize: textFontSize
    //     }
    //     ProgressBar {
    //         id: ybar
    //         value: 0.5 + (accelerometer.y / 100)
    //         Layout.preferredWidth: root.width
    //     }
    //     Text {
    //         Layout.preferredWidth: root.width
    //         Layout.preferredHeight: textHeight
    //         Layout.leftMargin: layout.spacing
    //         color: "White"
    //         text: "Z: " + accelerometer.z.toFixed(2)
    //         font.pixelSize: textFontSize
    //     }
    //     ProgressBar {
    //         id: zbar
    //         value: 0.5 + (accelerometer.z / 100)
    //         Layout.preferredWidth: root.width
    //     }
    //     Button {
    //         Layout.alignment: Qt.AlignBottom
    //         Layout.preferredWidth: root.width
    //         Layout.preferredHeight: buttonHeight
    //         text:"Back"
    //         font.pixelSize: buttonFontSize
    //         onClicked:stack.pop()
    //     }
    // }
