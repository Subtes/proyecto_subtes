import QtQuick 2.0

Rectangle {
    width: 100
    height: 180
    color: "#00000000"
    border.color: "#00000000"

    Image {
        id: image1
        anchors.rightMargin: 0
        anchors.bottomMargin: 0
        anchors.leftMargin: 0
        anchors.topMargin: 0
        fillMode: Image.PreserveAspectFit
        anchors.fill: parent
        source: "resources/techo_llave45.png"
    }
}

