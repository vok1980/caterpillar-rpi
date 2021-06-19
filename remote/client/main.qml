import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.15

import ru.voksoft.caterpillar 1.0


Window {
    id: mainWindow

    width: 800
    height: 600
    visible: true
    title: qsTr("Robot remote control")
    color: "#ffffff"

    MoveController {
        id: controller
    }

    NetworkClient {
        id: netclient
        left: controller.started ? controller.left : 0
        right: controller.started ? controller.right : 0
    }

    Item {
        anchors.fill: parent

        Keys.onPressed: {
            if (event.key === Qt.Key_Q) {
                leftSpeed.decrementCurrentIndex()
                event.accepted = true;
            } else if (event.key === Qt.Key_A) {
                leftSpeed.incrementCurrentIndex()
                event.accepted = true;
            } else if (event.key === Qt.Key_W) {
                rightSpeed.decrementCurrentIndex()
                event.accepted = true;
            } else if (event.key === Qt.Key_S) {
                rightSpeed.incrementCurrentIndex()
                event.accepted = true;
            } else if (event.key === Qt.Key_Space) {
                event.accepted = true;
                engine.clicked()
            }
        }

        RowLayout {
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: parent.top
            anchors.bottomMargin: 5

            Text {
                text: controller.leftIdx
            }
            Text {
                text: controller.rightIdx
            }
        }


        SpeedRegulator {
            id: rightSpeed
            anchors.top: parent.top
            anchors.right: parent.right
            anchors.bottom: parent.bottom
            anchors.topMargin: 5
            anchors.bottomMargin: 5
            anchors.rightMargin: 5
            width: 25
            model: controller.speedModel
            currentIndex: controller.rightIdx
            onCurrentIndexChanged: {
                if (controller.rightIdx !== currentIndex) {
                    controller.rightIdx = currentIndex;
                }
            }
        }

        SpeedRegulator {
            id: leftSpeed
            anchors.top: parent.top
            anchors.left: parent.left
            anchors.bottom: parent.bottom
            anchors.topMargin: 5
            anchors.bottomMargin: 5
            anchors.leftMargin: 5
            width: 25
            model: controller.speedModel
            currentIndex: controller.leftIdx
            onCurrentIndexChanged: {
                if (controller.leftIdx !== currentIndex) {
                    controller.leftIdx = currentIndex;
                }
            }
        }

        Button {
            id: engine
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 5
            focus: true

            text: controller.started ? "Stop" : "Start"
            onClicked: {
                controller.started = !controller.started
            }
        }
    }
}
