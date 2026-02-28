import QtQuick
import QtQuick.Window
import QtQuick.Layouts
import AutoCluster

Window {
    width: 1024
    height: 600
    visible: true
    title: "Automotive Cluster Simulator"
    color: "#121212"

    VehicleData {
        id: carData
    }

    // Place items side-by-side
    RowLayout {
        anchors.centerIn: parent
        spacing: 100 // Gap between the two gauges

        // GAUGE 1: SPEEDOMETER
        CircularGauge {
            currentValue: carData.speed
            maxValue: 160
            unitText: "km/h"
            activeColor: "#00E5FF" // Neon Cyan

            width: 350
            height: 350
        }

        // GAUGE 2: TACHOMETER (RPM)
        CircularGauge {
            currentValue: carData.rpm
            maxValue: 8000 // Max RPM
            unitText: "RPM"
            activeColor: "#ff4444" // Red

            width: 350
            height: 350
        }
    }

    // GEAR INDICATOR
    Text {
        anchors.bottom: parent.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottomMargin: 50

        text: carData.gear
        font.pixelSize: 64
        font.bold: true
        color: "#00FF00"
    }
}
