import QtQuick 2.15
import QtQuick.Layouts 1.15
import QtQuick.Controls 2.15
import com.company.fitnessExperiment 1.0

Rectangle {
    id: root
    color: "#F4F4FB"
    property string filename: ""
    // readonly property int leftMargin: 20
    readonly property int textFontSize: 20
    // property FitnessExperiment experimentData: null

    ColumnLayout {

        Text {
            id: analysisTitle
            // text: experimentData.getUser()
            font.weight: Font.ExtraBold
            font.family: georgiaFont.name
        }

        FitnessExperiment {
            id: experimentData

            // Component.onCompleted: experimentData.loadExperiment(filename);
        }

        Connections {
            target: experimentData
            onLoadSelectExperimentPage: {
                console.log("This happens");

                analysisTitle.text = experimentData.getUser();
                console.log(experimentData.getUser());
            }
        }

        Button {
            id: backToSelectExperimentScreen
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
            onClicked: {

                stack.pop();
            }
        }
    }

    Component.onCompleted: {
        experimentData.loadExperiment(filename);
    }
}
