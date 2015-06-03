import QtQuick 2.0

Rectangle {
    width: 212
    height: 212

    Image {
        id: image1
        anchors.fill: parent
        source: "resources/Relojtecho03.png"
    }

    Image {
        id: image2
        anchors.rightMargin: -3
        anchors.bottomMargin: -11
        anchors.leftMargin: 3
        anchors.topMargin: 11
        rotation: 111
        anchors.fill: parent
        antialiasing: true
        smooth: true
        source: "resources/RelojtechoAGUJA03.png"
    }
}
