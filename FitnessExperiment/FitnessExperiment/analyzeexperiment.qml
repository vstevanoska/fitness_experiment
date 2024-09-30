import QtQuick 2.15
import QtQuick.Layouts 1.15
import QtQuick.Controls 2.15
import QtCharts 2.15

import com.company.fitnessExperiment 1.0

Rectangle {
    id: root
    color: "#F4F4FB"
    property string filename: ""
    property string user: ""
    property string experimentName: ""
    property string experimentType: ""
    property string speed : ""
    property int frequency: 0
    property var timestamp: 0
    property string popupString: ""

    readonly property int leftMargin: 20
    // readonly property int textFontSize: 20

    Component.onCompleted: FitnessExperiment.loadExperiment(filename);

    Connections {
        target: FitnessExperiment
        onLoadAnalysisPage: {

            user = FitnessExperiment.getUser();
            experimentName = FitnessExperiment.getExperimentName();
            experimentType = FitnessExperiment.getExperimentType();
            speed = FitnessExperiment.getSpeed();
            frequency = FitnessExperiment.getFrequency();
            timestamp = FitnessExperiment.getTimestamp();

            popupString = popupString.concat("User: \t\t", user, "\nExperiment name: \t", experimentName,
                                             "\nExperiment type: \t", experimentType, "\nFrequency: \t\t", frequency,
                                             "Hz\nSpeed: \t\t", speed, "\nTimestamp: \t", new Date(timestamp));

            analysisTitle.text = experimentName;
            informationButton.visible = true;

            //draw the acc charts

            //x-chart
            // chartView1.axes[0].min = FitnessExperiment.getAccTsMin();
            // chartView1.axes[0].max = FitnessExperiment.getAccTsMax();

            chartView1.axes[0].min = calculateTimepoint(FitnessExperiment.getAccTsMin(), FitnessExperiment.getAccTsMin());
            chartView1.axes[0].max = calculateTimepoint(FitnessExperiment.getAccTsMin(), FitnessExperiment.getAccTsMax());
            chartView1.axes[1].min = FitnessExperiment.getAccXMin();
            chartView1.axes[1].max = FitnessExperiment.getAccXMax();

            //y-chart
            chartView2.axes[0].min = chartView1.axes[0].min;
            chartView2.axes[0].max = chartView1.axes[0].max;
            chartView2.axes[1].min = FitnessExperiment.getAccYMin();
            chartView2.axes[1].max = FitnessExperiment.getAccYMax();

            //z-chart
            chartView3.axes[0].min = chartView1.axes[0].min;
            chartView3.axes[0].max = chartView1.axes[0].max;
            chartView3.axes[1].min = FitnessExperiment.getAccZMin();
            chartView3.axes[1].max = FitnessExperiment.getAccZMax();

            for (var i = 0; i < FitnessExperiment.getAccReadingsSize(); ++i) {

                // let ts = FitnessExperiment.getAccTimestampAt(i);
                let ts = calculateTimepoint(FitnessExperiment.getAccTsMin(), FitnessExperiment.getAccTimestampAt(i));
                let x = FitnessExperiment.getAccXAt(i);
                let y = FitnessExperiment.getAccYAt(i);
                let z = FitnessExperiment.getAccZAt(i);

                chartView1.series(0).append(ts, x);
                chartView2.series(0).append(ts, y);
                chartView3.series(0).append(ts, z);
            }

            chartView1.update();
            chartView2.update();
            chartView3.update();


            //draw the gyr charts

            //x-chart
            chartView4.axes[0].min = calculateTimepoint(FitnessExperiment.getGyrTsMin(), FitnessExperiment.getGyrTsMin());
            chartView4.axes[0].max = calculateTimepoint(FitnessExperiment.getGyrTsMin(), FitnessExperiment.getGyrTsMax());
            chartView4.axes[1].min = FitnessExperiment.getGyrXMin();
            chartView4.axes[1].max = FitnessExperiment.getGyrXMax();

            //y-chart
            chartView5.axes[0].min = chartView4.axes[0].min;
            chartView5.axes[0].max = chartView4.axes[0].max;
            chartView5.axes[1].min = FitnessExperiment.getGyrYMin();
            chartView5.axes[1].max = FitnessExperiment.getGyrYMax();

            //z-chart
            chartView6.axes[0].min = chartView4.axes[0].min;
            chartView6.axes[0].max = chartView4.axes[0].max;
            chartView6.axes[1].min = FitnessExperiment.getGyrZMin();
            chartView6.axes[1].max = FitnessExperiment.getGyrZMax();

            for (var j = 0; j < FitnessExperiment.getGyrReadingsSize(); ++j) {

                let ts = calculateTimepoint(FitnessExperiment.getGyrTsMin(), FitnessExperiment.getGyrTimestampAt(j));
                let x = FitnessExperiment.getGyrXAt(j);
                let y = FitnessExperiment.getGyrYAt(j);
                let z = FitnessExperiment.getGyrZAt(j);

                chartView4.series(0).append(ts, x);
                chartView5.series(0).append(ts, y);
                chartView6.series(0).append(ts, z);
            }

            chartView4.update();
            chartView5.update();
            chartView6.update();

            //update labels below every chart

            //first argument: sensor (1 -> acc; 2 -> gyr)
            //second argument: coordinates (1 -> x; 2 -> y; 3 -> z)

            chart1Text.text = FitnessExperiment.getCalculatedData(1, 1);
            chart2Text.text = FitnessExperiment.getCalculatedData(1, 2);
            chart3Text.text = FitnessExperiment.getCalculatedData(1, 3);
            chart4Text.text = FitnessExperiment.getCalculatedData(2, 1);
            chart5Text.text = FitnessExperiment.getCalculatedData(2, 2);
            chart6Text.text = FitnessExperiment.getCalculatedData(2, 3);

        }
    }

    //returns epoch

    // function calculateTimepoint(timestamp, fixedPoint, currentPoint) {

    //     if (fixedPoint === currentPoint)
    //         return timestamp;

    //     var difference = (currentPoint - fixedPoint) / 1000; //turn microseconds to ms

    //     timestamp += difference;

    //     return timestamp;
    // }

    //returns seconds

    function calculateTimepoint(fixedPoint, currentPoint) {
        return (currentPoint - fixedPoint) / 1000000; //turn microseconds to seconds
    }

    ColumnLayout {

        // Layout.fillWidth: true
        // anchors.fill: parent
        spacing: 6

        RowLayout {

            id: rowLayout

            Text {
                id: analysisTitle
                // anchors.fill: parent
                // text: FitnessExperiment.getUser()
                font.weight: Font.ExtraBold
                font.family: georgiaFont.name
                font.pixelSize: buttonFontSize
            }

            Button {
                id: informationButton
                // anchors.fill: parent
                // onClicked: console.log(FitnessExperiment.getAccReadingsSize())
                Layout.preferredWidth: 24
                Layout.preferredHeight: 24
                icon.source: "qrc:/images/info.png"
                icon.width: 24
                icon.height: 24

                background: Rectangle {
                    color: "#F4F4FB"
                }

                // background: "white"
                visible: false

                onClicked: {

                    popupText.text = popupString
                    popup.open();
                }
            }

            // Layout.preferredWidth: parent.width
            Layout.fillWidth: true
            // fillWidth: true
            // alignment: Qt.AlignCenter
            // Layout.bottomMargin: leftMargin * 2
            Layout.alignment: Qt.AlignCenter
            // Layout.preferredHeight: 50
        }

        ScrollView {

            Layout.preferredWidth: root.width
            Layout.preferredHeight: root.height / 1.18

            id: scrollView

            clip: true

            Column {

                id: columnContent

                width: scrollView.width

                ChartView {
                    title: "Accelerometer values for X coordinate"

                    id: chartView1

                    antialiasing: true
                    width: scrollView.width
                    height: 400

                    legend.visible: false

                    ValueAxis {
                        id: axisX1
                    }

                    ValueAxis {
                        id: axisY1
                    }

                    LineSeries {
                        // name: "TestSeries"
                        axisX: axisX1
                        axisY: axisY1
                    }
                }

                Text {
                    id: chart1Text

                    // text: "Chart 1"

                    font.family: georgiaFont.name
                    anchors.horizontalCenter: parent.horizontalCenter
                }

                ChartView {
                    title: "Accelerometer values for Y coordinate"

                    id: chartView2

                    antialiasing: true
                    width: scrollView.width
                    height: 400

                    legend.visible: false

                    ValueAxis {
                        id: axisX2
                    }

                    ValueAxis {
                        id: axisY2
                    }

                    LineSeries {
                        // name: "TestSeries"

                        axisX: axisX2
                        axisY: axisY2
                    }
                }

                Text {
                    id: chart2Text

                    // text: "Chart 2"

                    font.family: georgiaFont.name
                    anchors.horizontalCenter: parent.horizontalCenter
                }

                ChartView {
                    title: "Accelerometer values for Z coordinate"

                    id: chartView3

                    antialiasing: true
                    width: scrollView.width
                    height: 400

                    legend.visible: false

                    ValueAxis {
                        id: axisX3
                    }

                    ValueAxis {
                        id: axisY3
                    }

                    LineSeries {
                        // name: "TestSeries"

                        axisX: axisX3
                        axisY: axisY3
                    }
                }

                Text {
                    id: chart3Text

                    // text: "Chart 3"

                    font.family: georgiaFont.name
                    anchors.horizontalCenter: parent.horizontalCenter
                }

                ChartView {
                    title: "Gyroscope values for X coordinate"

                    id: chartView4

                    antialiasing: true
                    width: scrollView.width
                    height: 400

                    legend.visible: false

                    ValueAxis {
                        id: axisX4
                    }

                    ValueAxis {
                        id: axisY4
                    }

                    LineSeries {
                        // name: "TestSeries"

                        axisX: axisX4
                        axisY: axisY4
                    }
                }

                Text {
                    id: chart4Text

                    // text: "Chart 4"

                    font.family: georgiaFont.name
                    anchors.horizontalCenter: parent.horizontalCenter
                }

                ChartView {
                    title: "Gyroscope values for Y coordinate"

                    id: chartView5

                    antialiasing: true
                    width: scrollView.width
                    height: 400

                    legend.visible: false

                    ValueAxis {
                        id: axisX5
                    }

                    ValueAxis {
                        id: axisY5
                    }

                    LineSeries {
                        // name: "TestSeries"

                        axisX: axisX5
                        axisY: axisY5
                    }
                }

                Text {
                    id: chart5Text

                    // text: "Chart 5"

                    font.family: georgiaFont.name
                    anchors.horizontalCenter: parent.horizontalCenter
                }

                ChartView {
                    title: "Gyroscope values for Z coordinate"

                    id: chartView6

                    antialiasing: true
                    width: scrollView.width
                    height: 400

                    legend.visible: false

                    ValueAxis {
                        id: axisX6
                    }

                    ValueAxis {
                        id: axisY6
                    }

                    LineSeries {
                        // name: "TestSeries"

                        axisX: axisX6
                        axisY: axisY6
                    }
                }

                Text {
                    id: chart6Text

                    // text: "Chart 6"

                    font.family: georgiaFont.name
                    anchors.horizontalCenter: parent.horizontalCenter
                }
            }
        }

        Button {
            id: backToSelectExperimentScreen

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
            onClicked: {

                stack.pop();
            }
        }

        Popup {
            id: popup
            x: 40
            y: 350
            width: 330
            height: 110
            modal: true
            focus: true

            contentItem: Text {

                id: popupText
                font.family: georgiaFont.name
                font.pixelSize: 12

                // text: "Hi there!"
            }

            closePolicy: Popup.CloseOnEscape | Popup.CloseOnPressOutside
        }
    }
}
