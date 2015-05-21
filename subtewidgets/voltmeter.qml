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
        transformOrigin: Item.Center
        z: 1
        rotation: 0
        anchors.fill: parent
        source: "resources/RelojtechoAGUJA01.png"
    }
}

