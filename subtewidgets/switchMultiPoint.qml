import QtQuick 2.0

Rectangle {
    id: switchmp
    x: 0
    y: 0
    width: 160
    height: 170

    Item {
        id: item1
        x: 29
        y: 34
        Image {
            id: backGround
        objectName: "backGround"
        x: 0
        y: 0
        z: 0
        width: 100
        height: 100
        source: "resources/alstom_giratorio_base.png"
    }

    Image {
        id: giratorio
        objectName: "giratorio"
        x: 0
        y: 0
        z: 0
        width: 100
        height: 100
        source: "resources/alstom_giratorio.png"
    }   

    MouseArea {
        id: mouseArea1
        x: 71
        y: -23
        width: 24
        height: 30
        rotation: 30
        enabled: true
        onClicked: {
            switchmp.state = "g30"
            console.log("1");}
    }

    MouseArea {
        id: mouseArea2
        x: 94
        y: 0
        width: 24
        height: 30
        rotation: 60
        enabled: true
        onClicked: {
            item1.state = "g60"
            console.log("2");}
    }

    MouseArea {
        id: mouseArea3
        x: 100
        y: 38
        width: 24
        height: 30
        enabled: true
        onClicked: {
            item1.state = "g90"
            console.log("3");}
    }

    MouseArea {
        id: mouseArea4
        x: 96
        y: 75
        width: 24
        height: 30
        rotation: -60
        enabled: true
        onClicked: {
            item1.state = "g120"
            console.log("4");}
    }

    MouseArea {
        id: mouseArea5
        x: 71
        y: 96
        width: 24
        height: 30
        rotation: -30
        enabled: true
        onClicked: {
            item1.state = "g150"
            console.log("5");}
    }

    MouseArea {
        id: mouseArea6
        x: 38
        y: 100
        width: 24
        height: 30
        enabled: true
        onClicked: {
            item1.state = "g180"
            console.log("6");}
    }

    MouseArea {
        id: mouseArea7
        x: 6
        y: 93
        width: 24
        height: 30
        rotation: 30
        enabled: true
        onClicked: {
            item1.state = "g210"
            console.log("7");}
    }

    MouseArea {
        id: mouseArea8
        x: -17
        y: 71
        width: 24
        height: 30
        rotation: 60
        enabled: true
        onClicked: {
            item1.state = "g240"
            console.log("8");}
    }


    MouseArea {
        id: mouseArea9
        x: -24
        y: 38
        width: 24
        height: 30
        enabled: true
        onClicked: {
            item1.state = "g270"
            console.log("9");}
    }

    MouseArea {
        id: mouseArea10
        x: -19
        y: 0
        width: 24
        height: 30
        rotation: -60
        enabled: true
        onClicked: {
            item1.state = "g300"
            console.log("10");}
    }

    MouseArea {
        id: mouseArea11
        x: 1
        y: -22
        width: 24
        height: 30
        rotation: -30
        enabled: true
        onClicked: {
            item1.state = "g330"
            console.log("11");}
    }

    MouseArea {
        id: mouseArea12
        x: 38
        y: -30
        width: 24
        height: 30
        enabled: true
        onClicked: {
            item1.state = "g0"
            console.log("12");}
    }

    state: "g0"
    states: [
        State {
            name: "g0"
            PropertyChanges { target: giratorio; rotation: 0}
        },
        State {
            name: "g30"
            PropertyChanges { target: giratorio; rotation: 30}
        },
        State {
            name: "g60"
            PropertyChanges { target: giratorio; rotation: 60}
        },
        State {
            name: "g90"
            PropertyChanges { target: giratorio; rotation: 90}
        },
        State {
            name: "g120"
            PropertyChanges { target: giratorio; rotation: 120}
        },
        State {
            name: "g150"
            PropertyChanges { target: giratorio; rotation: 150}
        },
        State {
            name: "g180"
            PropertyChanges { target: giratorio; rotation: 180}
        },
        State {
            name: "g210"
            PropertyChanges { target: giratorio; rotation: 210}
        },
        State {
            name: "g240"
            PropertyChanges { target: giratorio; rotation: 240}
        },
        State {
            name: "g270"
            PropertyChanges { target: giratorio; rotation: 270}
        },
        State {
            name: "g300"
            PropertyChanges { target: giratorio; rotation: 300}
        },
        State {
            name: "g330"
            PropertyChanges { target: giratorio; rotation: 330}
        }

    ]

    transitions: Transition {
        PropertyAnimation { target: giratorio; properties: "rotation"; duration: 200 }
    }
  }
}

