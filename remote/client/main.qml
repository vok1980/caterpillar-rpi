import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.15

Window {
    id: mainWindow

    width: 800
    height: 600
    visible: true
    title: qsTr("Robot remote control")
    color: "#ffffff"

    RowLayout {
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 5
        Button {
            text: "Left"
//            onClicked: model.submit()
        }
        Button {
            text: "Right"
//            onClicked: model.revert()
        }
    }
}
