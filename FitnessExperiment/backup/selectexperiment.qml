import QtQuick 2.15
import QtQuick.Layouts 1.15
import QtQuick.Controls 2.15
import QtGraphicalEffects 1.12
// import com.company.fitnessExperiment 1.0

Rectangle {
    id: root
    color: "#F4F4FB"
    property var filenames: []
    readonly property int leftMargin: 20
    readonly property int textFontSize: 20

    // property FitnessExperiment experimentData: null

    // FitnessExperiment {
    //     id: experimentData

    //     Component.onCompleted: {

    //         experimentData.loadFilenames();

    //     //     printExperiments.text = experimentData.getFilenames();
    //     }
    // }

    // FitnessExperiment {
    //     id: experimentData
    // }

    ColumnLayout {
        Text {
            id: printExperiments
            // Layout.topMargin: mainWindow.height / 8
            Layout.alignment: Qt.AlignLeft
            Layout.topMargin: mainWindow.height / 20
            Layout.leftMargin: leftMargin
            Layout.preferredWidth: stack.width
            // Layout.preferredHeight: titleHeight
            // anchors.topMargin: mainWindow.height / 100
            // anchors.bottomMargin: leftMargin * 2
            // horizontalAlignment: Qt.AlignCenter
            // text: experimentData.getFilenames();
            // text: filenames
            text: "Experiments:"
            color: "#5E69EE" //#39AFEA - accent
            Layout.bottomMargin: backToMainScreen.height / 1.25
            font.weight: Font.ExtraBold
            font.family: georgiaFont.name
            font.pixelSize: textFontSize + 5
        }

        ListView {
            id: experimentList
            // Layout.alignment: Qt.AlignHCenter
            // Layout.leftMargin: leftMargin
            Layout.bottomMargin: backToMainScreen.height / 1.25
            model: filenames
            // highlight: Rectangle { color: "#5E69EE"; radius: 5 }
            // focus: true
            height: root.height / 1.4
            Layout.preferredWidth: stack.width
            spacing: -1

            delegate: Rectangle {

                property bool selected: false
                // Layout.alignment: Qt.AlignCenter
                // Layout.leftMargin: leftMargin
                // anchors.fill: parent
                anchors.left: parent.left
                anchors.right: parent.right

                id: itemRectangle

                Layout.preferredWidth: stack.width
                // width: experimentList.view.width
                // height: leftMargin * 3
                height: 60
                color: selected ? "#5E69EE" : "white"
                // color: "white"
                // color: "#5E69EE"
                border.color: "black"
                border.width:  1
                z: experimentList.currentIndex === model.index ? 2 : 1

                // border.width: index == 0 ? itemRectangle.border.width : 0

                // Rectangle {
                //     anchors.fill: parent
                //     color: "#F4F4FB"
                //     border.color: "black"

                Text {
                   id: experimentName
                   // Layout.alignment: Qt.AlignRight
                   // Layout.leftMargin: leftMargin
                   text: modelData  // Display each string from the array
                   font.family: georgiaFont.name
                   font.pixelSize: textFontSize
                   anchors.centerIn: parent
                }

                MouseArea {
                   // anchors.fill: itemRectangle
                   // width: experimentList.view.width
                   // Layout.leftMargin: leftMargin
                   // height: leftMargin * 2.5

                    anchors.fill: parent

                    onClicked: {
                        selected = true;
                        // console.log(experimentName.text, " is clicked!");

                        // experimentData.loadExperiment(experimentName.text);

                        stack.push("qrc:/analyzeexperiment.qml", {"filename": experimentName.text});
                    }
                }

                // Connections {
                //     target: experimentData
                //     onLoadAnalysisPage: stack.push("qrc:/analyzeexperiment.qml", {"filename": experimentName.text,
                //                                                                     "experimentData": experimentData});
                // }

               // }
            }
        }

        Button {
            id: backToMainScreen
            // Layout.fillHeight: true
            Layout.preferredWidth: stack.width / 2
            Layout.alignment: Qt.AlignCenter
            // Layout.leftMargin: root.width / 2
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
