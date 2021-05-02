import QtQuick 2.0


Rectangle {
    id: root
    border.color: "black"
    property var model;
    property int currentIndex;

    function incrementCurrentIndex() {
        view.incrementCurrentIndex()
        currentIndex = view.currentIndex
    }

    function decrementCurrentIndex() {
        view.decrementCurrentIndex()
        currentIndex = view.currentIndex
    }

    ListView {
        id: view
        anchors.fill: parent
        model: parent.model
        currentIndex: parent.currentIndex
        clip: true

        delegate: Text {
            id: container
            width: parent ? parent.width : 0
            text: display
            horizontalAlignment: Text.AlignHCenter

            MouseArea {
                id: mouseArea
                anchors.fill: parent
                hoverEnabled: true

                onClicked: {
                    root.currentIndex = index
                    container.ListView.view.currentIndex = index
                    container.forceActiveFocus()
                }
            }
        }

        highlight: Rectangle { color: "lightsteelblue"; radius: 5 }
    }
}
