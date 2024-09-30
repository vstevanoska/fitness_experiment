import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import QtGraphicalEffects 1.12
import QtSensors 5.0
import QtQuick.Dialogs 1.2
import com.company.fitnessExperiment 1.0
// import QtWebSockets 1.7

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
    // property string user: ""
    // property string experimentName: ""
    // property string exerciseSpeed: "Normal"
    property AccelerometerReading currentAccReading: null
    property GyroscopeReading currentGyrReading: null
    // property int experimentCountdown : 0
    // property string currentExperiment: ""
//! [0]

    Accelerometer {
        id: accSensor
        dataRate: 104        //check if this is correct

        // property real x: 0
        // property real y: 0
        // property real z: 0

        onReadingChanged: {
            // x = reading.x;
            // y = reading.y;
            // z = reading.z;

            // experimentData.addAccReading(reading.timestamp, x, y, z);

            currentAccReading = reading;

            // experimentData.addAccReading(reading);

            // console.log("Accelerometer reading: x: ", x, " y: ", y, " z: ", z, "\n");
            // imageTranslation.x = -reading.x * 10
            // imageTranslation.y = reading.y * 10
        }

        // Component.onCompleted: {
        //     var dataRates = accSensor.availableDataRates;
        //     console.log(dataRates.objectName);
        //     console.log(dataRates.maximum);
        //     console.log("Available data rates (Hz):");
        //     for (var i = 0; i < dataRates.length; i++) {
        //         console.log(dataRates[i]);
        //     }
        // }
    }

    Gyroscope {
        id: gyrSensor
        dataRate: 104

        // property variant lastTimeStamp: 0

        // property real x: 0
        // property real y: 0
        // property real z: 0

        onReadingChanged: {

            // x = reading.x
            // y = reading.y
            // z = reading.z

            // experimentData.addGyrReading(reading.timestamp, x, y, z);

            currentGyrReading = reading;

            // experimentData.addGyrReading(reading);

            // console.log("Gyroscope reading: x: ", x, " y: ", y, " z: ", z, "\n");

            // var firstCall = false
            // if (lastTimeStamp == 0) {
            //     firstCall = true
            // }

            // var timeSinceLast = reading.timestamp - lastTimeStamp
            // lastTimeStamp = reading.timestamp

            // //Skipping the initial time jump from 0
            // if (firstCall === true) return

            // var normalizedX = reading.x * (timeSinceLast/1000000)
            // imageXRotation.angle += normalizedX

            // var normalizedY = reading.y * (timeSinceLast/1000000)
            // imageYRotation.angle -= normalizedY

            // var normalizedZ = reading.z * (timeSinceLast/1000000)
            // imageZRotation.angle += normalizedZ
        }
    }

    // FitnessExperiment {
    //     id: experimentData
    // }

    // WebSocket {
    //     id: socket
    //     // url: "ws://ws.ifelse.io" // different url
    //     url: new QUrl("127.0.0.1:1234")

    //     onTextMessageReceived: function(message) {
    //         // messageBox.text = messageBox.text + "\nReceived message: " + message
    //         console.log(message);
    //     }

    //     // onStatusChanged: if (socket.status == WebSocket.Error) {
    //     //                      console.log("Error: " + socket.errorString)
    //     //                  } else if (socket.status == WebSocket.Open) {
    //     //                      socket.sendTextMessage(experimentData.convertToJson())
    //     //                  } else if (socket.status == WebSocket.Closed) {
    //     //                      console.log("Socket closed!")
    //     //                  }
    //     active: false
    // }

    // function saveFile(fileUrl, text) {
    //     var request = new XMLHttpRequest();
    //     request.open("PUT", fileUrl, false);
    //     request.send(text);
    //     return request.status;
    // }

    ColumnLayout {

        width: stack.width

        Text {
            Layout.topMargin: mainWindow.height / 8
            Layout.preferredWidth: stack.width
            id: exerciseName
            // property alias text: title.text
            text: exerciseCombo
            // text: FitnessExperiment.getExperimentType()
            // Layout.topMargin: mainWindow.height/100
            Layout.alignment: Qt.AlignCenter
            Layout.preferredHeight: titleHeight
            color: "#5E69EE" //#39AFEA - accent
            font.weight: Font.ExtraBold
            font.family: georgiaFont.name
            font.pixelSize: titleFontSize
            wrapMode: Text.Wrap
            horizontalAlignment: Qt.AlignCenter
        }

        // Text {
        //     // Layout.top: exerciseName.bottom
        //     id: informationText
        //     text: if (exerciseCombo == "Overhead triceps extension")
        //               qsTr("Standing with your feet shoulder-width apart, raise the dumbbells over your head. Keep your upper arms in place and hinge your elbow, lifting the dumbbells overhead through a full range of motion.")
        //               // qsTr("Standing with your feet shoulder-width apart")
        //         else if (exerciseCombo == "Bicep curl")
        //               // qsTr("Begin with your arm fully extended with a supinated")
        //               qsTr("Begin with your arm fully extended with a supinated grip on the dumbbell. Bend your elbow until it is fully flexed, then slowly lower the dumbbells to the starting position.")
        //         else
        //               // qsTr("Hold a dumbbell in each hand with your palms facing")
        //              qsTr("Hold a dumbbell in each hand with your palms facing in toward each other, keeping your knees bent slightly. Bringing your torso almost parallel to the floor. On an exhale, engage your triceps by straightening your elbows. Pause, then inhale to return the dumbbells to the starting position.")


        //     // Layout.topMargin: mainWindow.height/100
        //     Layout.bottomMargin: 5
        //     Layout.alignment: Qt.AlignCenter
        //     Layout.preferredWidth: stack.width
        //     // Layout.preferredHeight: titleHeight
        //     // font.weight: Font.ExtraBold
        //     font.family: georgiaFont.name
        //     font.pixelSize: extraSmallSize
        //     wrapMode: Text.Wrap
        //     horizontalAlignment: Qt.AlignJustify
        // }

        Item { // Spacer item to act as a container for the image
            Layout.fillWidth: true
            height: 300 // Set the height as needed
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
                // anchors.top: informationText.bottom
                // Layout.alignment: Qt.AlignCenter
                anchors.left: parent.left
                anchors.right: parent.right
                // Layout.topMargin: 10
                // Layout.leftMargin: 10
                // Layout.rightMargin: 10
            }
        }

        Timer {
            // interval: 500; running: true; repeat: true
            id: timer
            running: true
            repeat: true
            onTriggered: {

                if (timerValue == 0) {

                    if (startCountdown) {

                        accSensor.active = false;
                        gyrSensor.active = false;
                        timer.stop();

                        saveExperimentDialog.visible = true;

                        // experimentData.sendToServer();

                        // socket.active = true;
                        // socket.sendBinaryMessage(experimentData.convertToJson());
                        // socket.active = false;

                        // console.log("Done!");
                    } else {

                        // experimentData.setUser(user);
                        // experimentData.setExperimentName(experimentName);
                        // experimentData.setExperimentType(exerciseCombo);
                        // experimentData.setFrequency(sampleRate);
                        // experimentData.setSpeed(exerciseSpeed);

                        FitnessExperiment.setTimestamp(Date.now());
                        FitnessExperiment.clearVectors();


                        // experimentData.setTimestamp(Date.now());

                        // console.log("Accelerometer data rates minimum: ", accSensor.outputRanges);
                        // // console.log("Accelerometer data rates maximum: ", accSensor.availableDataRates.maximum);
                        // console.log("Gyroscope data rates minimum: ", gyrSensor.outputRanges);
                        // // console.log("Gyroscope data rates maximum: ", gyrSensor.availableDataRates.maximum);

                        timer.interval = 1000 / sampleRate;
                        // timerValue = 30 * timer.interval;
                        timerValue = 30;
                        // console.log("Current timer value: ", timerValue);
                        startCountdown = true;
                        accSensor.active = true;
                        gyrSensor.active = true;
                    }
                }

                countdownText.text = timerValue.toString();

                if (!startCountdown) {
                    timerValue--;
                }

                if (startCountdown && currentAccReading != null) {

                    if (FitnessExperiment.getAccReadingsSize() < sampleRate * 30) {
                        FitnessExperiment.addAccReading(currentAccReading.timestamp, currentAccReading.x, currentAccReading.y, currentAccReading.z);

                        if (currentGyrReading != null)
                            FitnessExperiment.addGyrReading(currentGyrReading.timestamp, currentGyrReading.x, currentGyrReading.y, currentGyrReading.z);
                    }

                    if (FitnessExperiment.getAccReadingsSize() % sampleRate == 0)
                        timerValue--;

                    // if (experimentData.getAccReadingsSize() == sampleRate * 30)


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

            // Component.onCompleted: visible = false

            onYes: {

                FitnessExperiment.sendToServer();
                stack.pop();
            }

            onNo: {

                FitnessExperiment.cancelExperiment();
                stack.pop();
            }
        }

        Text {
            // Layout.top: imageSpacer.bottom
            id: countdownText
            // text: qsTr("1, 2, 3")
            // Layout.topMargin: mainWindow.height/100
            Layout.alignment: Qt.AlignCenter
            // Layout.preferredHeight: titleHeight
            // font.weight: Font.ExtraBold
            font.family: georgiaFont.name
            font.pixelSize: textSize
            Layout.bottomMargin: leftMargin
            wrapMode: Text.Wrap //delete later
            horizontalAlignment: Qt.AlignCenter
            Layout.preferredWidth: stack.width
        }

        Button {
            id: cancelButton
            // Layout.fillHeight: true
            Layout.preferredWidth: stack.width / 2
            Layout.alignment: Qt.AlignCenter
            text: "Cancel"
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

                FitnessExperiment.cancelExperiment();
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

    // Component.onCompleted: {
    //     // fitnessExperiment.onPageLoaded();
    //     var component = Qt.createComponent("accelerometer.qml");
    //     var loadwin = component.createObject(root);

    // }
}
