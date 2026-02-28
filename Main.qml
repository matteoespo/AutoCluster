import QtQuick
import QtQuick.Window
import QtQuick.Layouts
import QtQuick.Shapes // Shapes module for vector graphics
import AutoCluster

Window {
    width: 800
    height: 600
    visible: true
    title: "Automotive Cluster Simulator"
    color: "#121212" // Dark mode

    VehicleData {
        id: carData
    }

    // Container for Gauge
    Item {
        width: 400
        height: 400
        anchors.centerIn: parent

        // Property that follows the real speed
        property real displaySpeed: carData.speed

        Behavior on displaySpeed {
            NumberAnimation {
                duration: 250 // Takes 250ms to catch up
                easing.type: Easing.OutQuad // Smooth deceleration
            }
        }
        // Vector Shape Drawer
        Shape {
            anchors.fill: parent
            layer.enabled: true // Enables anti-aliasing for smooth edges
            layer.samples: 4

            ShapePath {
                strokeColor: "#00E5FF"
                strokeWidth: 20
                fillColor: "transparent"
                capStyle: ShapePath.RoundCap

                PathAngleArc {
                    centerX: 200; centerY: 200
                    radiusX: 180; radiusY: 180
                    startAngle: 135
                    sweepAngle: (parent.displaySpeed / 160.0) * 270
                }
            }
            // Active Speed Track
            ShapePath {
                strokeColor: "#00E5FF"
                strokeWidth: 20
                fillColor: "transparent"
                capStyle: ShapePath.RoundCap

                PathAngleArc {
                    centerX: 200; centerY: 200
                    radiusX: 180; radiusY: 180
                    startAngle: 135
                    // (Current Speed / Max Speed) * Total Degrees
                    sweepAngle: (carData.speed / 160.0) * 270
                }
            }
        }

        // Text in the Center
        ColumnLayout {
            anchors.centerIn: parent
            spacing: 0

            Text {
                text: carData.speed
                font.pixelSize: 80
                font.bold: true
                color: "#ffffff"
                Layout.alignment: Qt.AlignHCenter
            }

            Text {
                text: "km/h"
                font.pixelSize: 24
                font.bold: true
                color: "#888888"
                Layout.alignment: Qt.AlignHCenter
            }

            Text {
                text: carData.rpm + " RPM"
                font.pixelSize: 20
                color: "#ff4444"
                Layout.alignment: Qt.AlignHCenter
                Layout.topMargin: 15
            }
            Text {
                text: carData.gear
                font.pixelSize: 36
                font.bold: true
                color: "#00FF00" // Neon Green
                Layout.alignment: Qt.AlignHCenter
                Layout.topMargin: 10
            }
        }
    }
}
