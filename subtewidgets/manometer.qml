import QtQuick 2.0

Rectangle {
    width: 170
    height: 170
    color: "#00000000"
    border.color: "#00000000"



    Image {
        id: image1
        anchors.fill: parent
        source: "resources/manometro_bkg.png"
    }
    Image {
        id: image2
        anchors.fill: parent
        source: "resources/manometro_aguja_blanca.png"
    }
    Image {
        id: image3
        rotation: 46
        anchors.fill: parent
        source: "resources/manometro_aguja_roja.png"
    }

    Image {
        id: image4
        anchors.fill: parent
        source: "resources/manometro_glass.png"
    }
}

