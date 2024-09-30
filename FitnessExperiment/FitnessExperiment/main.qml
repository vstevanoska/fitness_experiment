import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import QtSensors 5.0
import QtGraphicalEffects 1.12

import com.company.fitnessExperiment 1.0

ApplicationWindow {
    title: "Fitness Monitor"
    id: mainWindow
    width: 540
    height: 1200
    visible: true
    color: "#F4F4FB"

    property int titleHeight: height/7
    readonly property real buttonHeight: height/7
    property int textHeight: height/24
    readonly property int buttonFontSize: 30
    readonly property int textFontSize: 20
    readonly property int titleFontSize: 35
    readonly property int titleTopMargin: mainWindow.height/24

    FontLoader {
        id: georgiaFont
        source: "qrc:/fonts/georgia.ttf"
    }

    // FitnessExperiment {
    //     id: experimentData
    // }

    StackView {
        id: stack
        anchors.fill: parent
        initialItem: ColumnLayout {
            width: stack.width
            Text {
                id: title
                Layout.topMargin: mainWindow.height/8
                Layout.alignment: Qt.AlignCenter
                Layout.preferredHeight: titleHeight
                text: "Fitness Monitor"
                color: "#5E69EE" //#39AFEA - accent
                font.weight: Font.Black
                font.family: georgiaFont.name
                font.pixelSize: titleFontSize
            }

            Button {
                // Layout.fillHeight: true
                id: newExperimentButton
                Layout.preferredWidth: stack.width / 1.5
                Layout.alignment: Qt.AlignCenter
                // Layout.topMargin: mainWindow.height
                anchors.topMargin: mainWindow.height / 13
                text: "New experiment"
                font.family: georgiaFont.name
                font.pixelSize: buttonFontSize
                // background: Rectangle {
                //    color: "#39AFEA"
                // }
                anchors.top: title.bottom
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

                onClicked: stack.push("qrc:/setparameters.qml")
            }

            Button {
                id: visualizeButton
                // Layout.fillHeight: true
                Layout.preferredWidth: stack.width / 1.5
                Layout.alignment: Qt.AlignCenter
                anchors.topMargin: buttonHeight / 2.5
                text: "Visualize results"
                font.family: georgiaFont.name
                font.pixelSize: buttonFontSize
                // background: Rectangle {
                //    color: "#39AFEA"
                // }
                anchors.top: newExperimentButton.bottom
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

                    // FitnessExperiment.loadFilenames();

                    // experimentData.loadFilenames();
                    stack.push("qrc:/selectexperiment.qml");
                    // stack.push("qrc:/selectexperiment.qml", {"experimentData": experimentData});
                }
            }

            // Connections {
            //     target: experimentData
            //     onLoadSelectExperimentPage: stack.push("qrc:/selectexperiment.qml", {"filenames": experimentData.getFilenames()});
            // }
            // Connections {
            //     target: FitnessExperiment
            //     onLoadSelectExperimentPage: {

            //         console.log("load select experiment page!");

            //         // experimentList.model = FitnessExperiment.getUser();
            //     }
            // }

            DropShadow {
                anchors.fill: visualizeButton
                horizontalOffset: 3
                verticalOffset: 3
                radius: 0
                samples: 17
                color: "#5E46EE"
                source: visualizeButton
            }

            DropShadow {
                anchors.fill: newExperimentButton
                horizontalOffset: 3
                verticalOffset: 3
                radius: 0
                samples: 17
                color: "#5E46EE"
                source: newExperimentButton
            }
        }
    }
}
