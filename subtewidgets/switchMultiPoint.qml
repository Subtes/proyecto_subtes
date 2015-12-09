import QtQuick 2.0

Rectangle {
    id: switchmp
    x: 0
    y: 0
    width: 160
    height: 170
    color: "#00000000"

    signal onPressPos(string pos);

    property int posActual: 0
    property int giroActual: 0
    property int gradoActual: 0

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
            objectName: "p1"
            x: 71
            y: -23
            width: 24
            height: 30
            rotation: 30
            enabled: false
            onClicked: {
                setGrado(30)
                item1.state = "g30"
                posActual = 1
                onPressPos("1")
                console.log("1");}
        }

        MouseArea {
            id: mouseArea2
            objectName: "p2"
            x: 94
            y: 0
            width: 24
            height: 30
            rotation: 60
            enabled: false
            onClicked: {
                setGrado(60)
                item1.state = "g60"
                posActual = 2
                onPressPos("2")
                console.log("2");}
        }

        MouseArea {
            id: mouseArea3
            objectName: "p3"
            x: 100
            y: 38
            width: 24
            height: 30
            enabled: false
            onClicked: {
                setGrado(90)
                item1.state = "g90"
                posActual = 3
                onPressPos("3")
                console.log("3");}
        }

        MouseArea {
            id: mouseArea4
            objectName: "p4"
            x: 96
            y: 75
            width: 24
            height: 30
            rotation: -60
            enabled: false
            onClicked: {
                setGrado(120)
                item1.state = "g120"
                posActual = 4
                onPressPos("4")
                console.log("4");}
        }

        MouseArea {
            id: mouseArea5
            objectName: "p5"
            x: 71
            y: 96
            width: 24
            height: 30
            rotation: -30
            enabled: false
            onClicked: {
                setGrado(150)
                item1.state = "g150"
                posActual = 5
                onPressPos("5")
                console.log("5");}
        }

        MouseArea {
            id: mouseArea6
            objectName: "p6"
            x: 38
            y: 100
            width: 24
            height: 30
            enabled: false
            onClicked: {
                setGrado(180)
                item1.state = "g180"
                posActual = 6
                onPressPos("6")
                console.log("6");}
        }

        MouseArea {
            id: mouseArea7
            objectName: "p7"
            x: 6
            y: 93
            width: 24
            height: 30
            rotation: 30
            enabled: false
            onClicked: {
                setGrado(210)
                item1.state = "g210"
                posActual = 7
                onPressPos("7")
                console.log("7");}
        }

        MouseArea {
            id: mouseArea8
            objectName: "p8"
            x: -17
            y: 71
            width: 24
            height: 30
            rotation: 60
            enabled: false
            onClicked: {
                setGrado(240)
                item1.state = "g240"
                posActual = 8
                onPressPos("8")
                console.log("8");}
        }


        MouseArea {
            id: mouseArea9
            objectName: "p9"
            x: -24
            y: 38
            width: 24
            height: 30
            enabled: false
            onClicked: {
                setGrado(270)
                item1.state = "g270"
                posActual = 9
                onPressPos("9")
                console.log("9");}
        }

        MouseArea {
            id: mouseArea10
            objectName: "p10"
            x: -19
            y: 0
            width: 24
            height: 30
            rotation: -60
            enabled: false
            onClicked: {
                setGrado(300)
                item1.state = "g300"
                posActual = 10
                onPressPos("10")
                console.log("10");}
        }

        MouseArea {
            id: mouseArea11
            objectName: "p11"
            x: 1
            y: -22
            width: 24
            height: 30
            rotation: -30
            enabled: false
            onClicked: {
                setGrado(330)
                item1.state = "g330"
                posActual = 11
                onPressPos("11")
                console.log("11");}
        }

        MouseArea {
            id: mouseArea12
            objectName: "p12"
            x: 38
            y: -30
            width: 24
            height: 30
            enabled: false
            onClicked: {
                setGrado(0)
                item1.state = "g0"
                posActual = 12
                onPressPos("12")
                console.log("12");}
        }

        state: "g0"
        states: [
            State {
                name: "g0"
                PropertyChanges { target: giratorio; rotation: giroActual}
            },
            State {
                name: "g30"
                PropertyChanges { target: giratorio; rotation: giroActual}
            },
            State {
                name: "g60"
                PropertyChanges { target: giratorio; rotation: giroActual}
            },
            State {
                name: "g90"
                PropertyChanges { target: giratorio; rotation: giroActual}
            },
            State {
                name: "g120"
                PropertyChanges { target: giratorio; rotation: giroActual}
            },
            State {
                name: "g150"
                PropertyChanges { target: giratorio; rotation: giroActual}
            },
            State {
                name: "g180"
                PropertyChanges { target: giratorio; rotation: giroActual}
            },
            State {
                name: "g210"
                PropertyChanges { target: giratorio; rotation: giroActual}
            },
            State {
                name: "g240"
                PropertyChanges { target: giratorio; rotation: giroActual}
            },
            State {
                name: "g270"
                PropertyChanges { target: giratorio; rotation: giroActual}
            },
            State {
                name: "g300"
                PropertyChanges { target: giratorio; rotation: giroActual}
            },
            State {
                name: "g330"
                PropertyChanges { target: giratorio; rotation: giroActual}
            }

        ]

        transitions: Transition {
            PropertyAnimation { target: giratorio; properties: "rotation"; duration: 200 }
        }
    }

    function setGrado(gradoobjetivo){
        if ((switchmp.gradoActual - gradoobjetivo) > 0)
        {
            switchmp.giroActual =  gradoobjetivo - switchmp.gradoActual;
        }
        else{
            switchmp.giroActual = gradoobjetivo - 360 - switchmp.gradoActual;
        }
    }

}

