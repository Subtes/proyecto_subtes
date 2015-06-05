import QtQuick 2.0

Rectangle {
    width: 212
    height: 212


    Image {
        id: image2
        anchors.fill: parent
        source: "resources/Relojtecho02.png"

        Image {
            id: image1
            x: 0
            y: 14
            anchors.rightMargin: 1
            anchors.bottomMargin: -13
            anchors.leftMargin: -1
            anchors.topMargin: 13
            rotation: 124
            anchors.fill: parent
            antialiasing: true
            smooth: true
            source: "resources/RelojtechoAGUJA02.png"
        }
    }
}


