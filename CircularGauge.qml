import QtQuick
import QtQuick.Layouts
import QtQuick.Shapes

Item {
    id: root
    width: 300
    height: 300

    // Custom properties
    property real currentValue: 0
    property real maxValue: 100
    property string unitText: ""
    property color activeColor: "#00E5FF"

    property real displayValue: currentValue
    Behavior on displayValue {
        NumberAnimation {
            duration: 250
            easing.type: Easing.OutQuad
        }
    }

    // Vector grahics
    Shape {
        anchors.fill: parent
        layer.enabled: true
        layer.samples: 4

        ShapePath {
            strokeColor: "#333333"
            strokeWidth: 20
            fillColor: "transparent"
            capStyle: ShapePath.RoundCap

            PathAngleArc {
                centerX: root.width / 2; centerY: root.height / 2
                radiusX: root.width / 2 - 20; radiusY: root.height / 2 - 20
                startAngle: 135
                sweepAngle: 270
            }
        }

        ShapePath {
            strokeColor: root.activeColor
            strokeWidth: 20
            fillColor: "transparent"
            capStyle: ShapePath.RoundCap

            PathAngleArc {
                centerX: root.width / 2; centerY: root.height / 2
                radiusX: root.width / 2 - 20; radiusY: root.height / 2 - 20
                startAngle: 135

                // Calculates the angle dynamically based on maxValue
                sweepAngle: (root.displayValue / root.maxValue) * 270
            }
        }
    }

    // Text in the center
    ColumnLayout {
        anchors.centerIn: parent
        spacing: 0

        Text {
            text: Math.round(root.currentValue)
            font.pixelSize: root.width * 0.2
            font.bold: true
            color: "#ffffff"
            Layout.alignment: Qt.AlignHCenter
        }

        Text {
            text: root.unitText
            font.pixelSize: root.width * 0.08
            font.bold: true
            color: "#888888"
            Layout.alignment: Qt.AlignHCenter
        }
    }
}
