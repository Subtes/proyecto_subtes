import QtQuick 2.0


Rectangle {
    width: 260
    height: 260
    color: "#00000000"
    border.color: "#00000000"

    Image {
        id: background
        x: 0
        y: 0
        width: 260
        height: 260
        source: "resources/velocimetro.png"
    }

    Rectangle {
        id: aguja
        objectName: "aguja"
        x: 130
        y: 130
        width: 5
        height: 60
        color: "#a03131"
        rotation: 17
        transformOrigin: Item.Top
        border.color: "#00000000"
        radius: 2
        border.width: 0
        smooth:true

    }

    Rectangle {
        x: 125
        y: 123
        width: 14
        height: 14
        color: "#650303"
        radius: 7
        smooth:true

    }

}
