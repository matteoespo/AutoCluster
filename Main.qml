import QtQuick
import QtQuick.Window
import QtQuick.Layouts
import AutoCluster

Window {
    width: 640
    height: 480
    visible: true
    title: "Instrument Cluster Simulation"
    color: "#1e1e1e"

    VehicleData {
        id: carData
    }

    ColumnLayout {
        anchors.centerIn: parent
        spacing: 20

        Text {
            text: carData.speed + " km/h"
            font.pixelSize: 80
            font.bold: true
            color: "#00E5FF"
            Layout.alignment: Qt.AlignHCenter
        }

        Text {
            text: carData.rpm + " RPM"
            font.pixelSize: 40
            color: "#ff4444"
            Layout.alignment: Qt.AlignHCenter
        }
    }
}
