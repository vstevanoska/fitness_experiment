import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import QtGraphicalEffects 1.12
import QtSensors 5.0
import QtQuick.Dialogs 1.2
import com.company.fitnessExperiment 1.0

Rectangle {
    id: root
    color: "#F4F4FB"
    readonly property int textSize: 30
    readonly property int smallSize: 20
    readonly property int extraSmallSize: 15
    readonly property int leftMargin: 20
    property bool startCountdown: false
    property int timerValue: 5
    property string exerciseCombo: FitnessExperiment.getExperimentType()
    property int sampleRate: FitnessExperiment.getFrequency()
    property AccelerometerReading currentAccReading: null
    property GyroscopeReading currentGyrReading: null

    Accelerometer {
        id: accSensor
        dataRate: 104
        // dataRate: sampleRate //needs to be tested with this again

        onReadingChanged: currentAccReading = reading;
    }

    Gyroscope {
        id: gyrSensor
        dataRate: 104
        // dataRate: sampleRate //needs to be tested with this again

        onReadingChanged: currentGyrReading = reading;
    }

    ColumnLayout {

        width: stack.width

        Text {
            Layout.topMargin: mainWindow.height / 8
            Layout.preferredWidth: stack.width
            id: exerciseName
            text: exerciseCombo
            Layout.alignment: Qt.AlignCenter
            Layout.preferredHeight: titleHeight
            color: "#5E69EE" //#39AFEA - accent
            font.weight: Font.ExtraBold
            font.family: georgiaFont.name
            font.pixelSize: titleFontSize
            wrapMode: Text.Wrap
            horizontalAlignment: Qt.AlignCenter
        }

        Item {
            Layout.fillWidth: true
            height: 300
            id: imageSpacer
            Image {
                id: exerciseImage
                source: if (exerciseCombo == "Overhead triceps extension")
                            "qrc:/images/dumbbell-triceps-extension-exercise-illustration.jpg"
                        else if (exerciseCombo == "Bicep curl")
                            "qrc:/images/biceps-curl-exercise-illustration.jpg"
                        else
                            "qrc:/images/dumbbell-triceps-kickback-exercise-illustration.jpg"

                fillMode: Image.PreserveAspectFit
                anchors.left: parent.left
                anchors.right: parent.right
            }
        }

        /*this timer overrides the sensors' sampling rate. since I was getting a constant sampling rate of around 100Hz, I
        chose to use this approach as a temporary solution. In the application, the timer first counts down from 5, upon which
        the experiment starts. Then, it counts down from 30, and every second it takes sampleRate samples and saves them in the
        internal structure's vectors. In the background, the timer isn't counting down from 30, but it's actually counting down
        from 1000 / sampleRate 30 times. This way it takes sampleRate samples in the span of 1 second (1000 milliseconds). This
        in turn means that it's prone to calculation errors; the 104Hz timer physically counts down faster than the 26Hz one.*/

        Timer {
            id: timer
            running: true
            repeat: true
            onTriggered: {

                if (timerValue == 0) {  //if countdown has finished

                    if (startCountdown) {   //if the timer has counted down from 30

                        //stop the sensors and timer
                        accSensor.active = false;
                        gyrSensor.active = false;
                        timer.stop();

                        //ask user to save experiment
                        saveExperimentDialog.visible = true;

                    } else {    //else, if the timer has counted down from 5

                        FitnessExperiment.setTimestamp(Date.now()); //set the starting time
                        FitnessExperiment.clearVectors();           //clear acc and gyr vectors

                        timer.interval = 1000 / sampleRate;
                        timerValue = 30;
                        startCountdown = true;
                        accSensor.active = true;
                        gyrSensor.active = true;
                    }
                }

                countdownText.text = timerValue.toString(); //update timer text in UI

                if (!startCountdown)
                    timerValue--;   //counting down from 5

                if (startCountdown && currentAccReading != null) {      //if the experiment has started and there is a valid current reading

                    if (FitnessExperiment.getAccReadingsSize() < sampleRate * 30) {
                        FitnessExperiment.addAccReading(currentAccReading.timestamp, currentAccReading.x, currentAccReading.y, currentAccReading.z);

                        if (currentGyrReading != null)  //currentGyrReading isn't in the grandparent if statement, because it turns on slower than the accelerometer
                            FitnessExperiment.addGyrReading(currentGyrReading.timestamp, currentGyrReading.x, currentGyrReading.y, currentGyrReading.z);
                    }

                    if (FitnessExperiment.getAccReadingsSize() % sampleRate == 0)
                        timerValue--;   //counting down from 30
                }
            }
        }

        MessageDialog
        {
            id: saveExperimentDialog
            title: "Save Experiment"
            text: "Would you like to save the recorded experiment?"

            standardButtons: StandardButton.Yes | StandardButton.No

            visible: false

            onYes: {

                FitnessExperiment.sendToServer();
                stack.pop();
            }

            onNo: {

                FitnessExperiment.cancelExperiment();   //cancelExperiment() is redundant
                stack.pop();
            }
        }

        Text {
            id: countdownText
            Layout.alignment: Qt.AlignCenter
            font.family: georgiaFont.name
            font.pixelSize: textSize
            Layout.bottomMargin: leftMargin
            wrapMode: Text.Wrap
            horizontalAlignment: Qt.AlignCenter
            Layout.preferredWidth: stack.width
        }

        Button {
            id: cancelButton
            Layout.preferredWidth: stack.width / 2
            Layout.alignment: Qt.AlignCenter
            text: "Cancel"
            font.family: georgiaFont.name
            font.pixelSize: buttonFontSize
            background: Rectangle {
                color: parent.pressed ? "#5E69EE" : (parent.hovered ? "#88AFEA" : "#39AFEA")
                border.color: "black"
                border.width: 2
                radius: 8
            }

            onClicked: {

                FitnessExperiment.cancelExperiment();   //cancelExperiment() is redundant
                stack.pop();
            }
        }

        DropShadow {
            anchors.fill: cancelButton
            horizontalOffset: 3
            verticalOffset: 3
            radius: 0
            samples: 17
            color: "#5E46EE"
            source: cancelButton
        }
    }
}
