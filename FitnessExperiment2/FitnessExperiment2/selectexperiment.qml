import QtQuick 2.15
import QtQuick.Layouts 1.15
import QtQuick.Controls 2.15
import QtGraphicalEffects 1.12

import com.company.fitnessExperiment 1.0

Rectangle {
    id: root
    color: "#F4F4FB"
    readonly property int leftMargin: 20
    readonly property int textFontSize: 20

    Component.onCompleted: FitnessExperiment.loadFilenames();

    Connections {
        target: FitnessExperiment
        onLoadSelectExperimentPage: experimentList.model = FitnessExperiment.getFilenames();
    }

    ColumnLayout {
        Text {
            id: printExperiments
            Layout.alignment: Qt.AlignLeft
            Layout.topMargin: mainWindow.height / 20
            Layout.leftMargin: leftMargin
            Layout.preferredWidth: stack.width
            text: "Experiments:"
            color: "#5E69EE" //#39AFEA - accent
            Layout.bottomMargin: backToMainScreen.height / 1.25
            font.weight: Font.ExtraBold
            font.family: georgiaFont.name
            font.pixelSize: textFontSize + 5
        }

        ListView {
            id: experimentList
            Layout.bottomMargin: backToMainScreen.height / 1.25
            height: root.height / 1.4
            Layout.preferredWidth: stack.width
            spacing: -1

            delegate: Rectangle {

                anchors.left: parent.left
                anchors.right: parent.right

                id: itemRectangle

                Layout.preferredWidth: stack.width
                height: 60
                border.color: "black"
                border.width:  1
                z: experimentList.currentIndex === model.index ? 2 : 1      //check without

                Text {
                   id: experimentName
                   text: modelData
                   font.family: georgiaFont.name
                   font.pixelSize: textFontSize
                   anchors.centerIn: parent
                }

                MouseArea {

                    anchors.fill: parent

                    onClicked: stack.push("qrc:/analyzeexperiment.qml", {"filename": experimentName.text});

                    //highlighting only the pressed item, and then unhighlighting it when released

                    onPressed: itemRectangle.color = "#5E69EE";

                    onReleased: itemRectangle.color = "white";

                    onCanceled: itemRectangle.color = "white";
                }
            }
        }

        Button {
            id: backToMainScreen
            Layout.preferredWidth: stack.width / 2
            Layout.alignment: Qt.AlignCenter
            text: "Back"
            font.family: georgiaFont.name
            font.pixelSize: buttonFontSize

            background: Rectangle {
                color: parent.pressed ? "#5E69EE" : (parent.hovered ? "#88AFEA" : "#39AFEA")
                border.color: "black"
                border.width: 2
                radius: 8
            }
            onClicked: stack.pop();
        }

        DropShadow {
            anchors.fill: backToMainScreen
            horizontalOffset: 3
            verticalOffset: 3
            radius: 0
            samples: 17
            color: "#5E46EE"
            source: backToMainScreen
        }
    }
}
