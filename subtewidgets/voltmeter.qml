import QtQuick 2.0

Rectangle {
    width: 212
    height: 212

    Image {
        id: image1
        anchors.fill: parent
        source: "resources/Relojtecho01.png"
    }

    Image {
        id: image2
        anchors.rightMargin: -71
        anchors.bottomMargin: 13
        anchors.leftMargin: 71
        anchors.topMargin: -13
        transformOrigin: Item.Center
        z: 1
        rotation: 58
        anchors.fill: parent
        antialiasing: true
        smooth: true
        source: "resources/RelojtechoAGUJA01.png"
    }
}

