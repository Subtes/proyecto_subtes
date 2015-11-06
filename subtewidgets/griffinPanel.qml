import QtQuick 2.0

Rectangle {
    id: level3
    objectName: "griffinPanel"
    x: 0
    y: 0
    width: 900
    height: 675
    color: "#00000000"
    border.color: "#00000000"

    signal selected(string s)
    property string type: "c_grifo_"
    property string numberWagon: "_X_"
    property string token: ";"

    Image {
        id: backGround
        objectName: "backGround"
        x: 0
        y: 0
        z: 0
        width: 900
        height: 675
        fillMode: Image.PreserveAspectFit
        //source: "../Source/images/fondos/PaneNeumatico_mod.png"
        source: "N3-PN"
        opacity: 1
    }

    Item {
        id: g0
        objectName: "t0"
        property string switchName: "DEFAULT"
        property int nSwitch: 0
        x: 95
        y: 160
        width: 90
        height: 90

        Image {
            id: conG0
            x: 8
            y: 10
            width: 75
            height: 70
            rotation: 0
            fillMode: Image.PreserveAspectFit
            source: "../Source/images/perillas/Neumatico/mariposaBlanca.png"
            opacity: 1
        }

        MouseArea {
            id: mouseAreaG0
            x: 0
            y: 0
            width: 90
            height: 90
            onClicked: {
                if (g0.state == "des"){
                    g0.state = "con";
                    level3.selected((level3.type)+level3.token+(g0.switchName)+level3.token+(level3.numberWagon)+level3.token+"con");
                }else{
                    g0.state = "des";
                    level3.selected((level3.type)+level3.token+(g0.switchName)+level3.token+(level3.numberWagon)+level3.token+"des");
                }
            }//onClicked
        }//MouseArea
        state: "con"
        states: [
            State {
                name: "con"
                PropertyChanges { target: conG0; rotation: 0}
            },
            State {
                name: "des"
                PropertyChanges { target: conG0; rotation: 90}
            }
        ]

        transitions: Transition {
            PropertyAnimation { target: conG0; properties: "rotation"; duration: 200 }
        }
    }//Item

    Item {
        id: g1
        objectName: "t1"
        property string switchName: "DEFAULT"
        property int nSwitch: 1
        x: 374
        y: 193
        width: 98
        height: 72

        Image {
            id: conG1
            x: 0
            y: 0
            width: 98
            height: 72
            rotation: 0
            fillMode: Image.PreserveAspectFit
            source: "../Source/images/perillas/Neumatico/neumatico_red.png"
            opacity: 1
        }

        MouseArea {
            id: mouseAreaG1
            x: 10
            y: 0
            width: 85
            height: 68
            onClicked: {
                if (g1.state == "des"){
                    g1.state = "con";
                    level3.selected((level3.type)+level3.token+(g1.switchName)+level3.token+(level3.numberWagon)+level3.token+"con");
                }else{
                    g1.state = "des";
                    level3.selected((level3.type)+level3.token+(g1.switchName)+level3.token+(level3.numberWagon)+level3.token+"des");
                }
            }//onClicked
        }//MouseArea
        state: "con"
        states: [
            State {
                name: "con"
                PropertyChanges { target: conG1; rotation: 0}
            },
            State {
                name: "des"
                PropertyChanges { target: conG1; rotation: 90}
            }
        ]

        transitions: Transition {
            PropertyAnimation { target: conG1; properties: "rotation"; duration: 200 }
        }
    }//Item

    Item {
        id: g2
        objectName: "t2"
        property string switchName: "DEFAULT"
        property int nSwitch: 2
        x: 510
        y: 181
        width: 98
        height: 72

        Image {
            id: conG2
            x: 0
            y: 0
            width: 98
            height: 72
            rotation: 0
            fillMode: Image.PreserveAspectFit
            source: "../Source/images/perillas/Neumatico/neumatico_red.png"
            opacity: 1
        }

        MouseArea {
            id: mouseAreaG2
            x: 10
            y: 0
            width: 85
            height: 68
            onClicked: {
                if (g2.state == "des"){
                    g2.state = "con";
                    level3.selected((level3.type)+level3.token+(g2.switchName)+level3.token+(level3.numberWagon)+level3.token+"con");
                }else{
                    g2.state = "des";
                    level3.selected((level3.type)+level3.token+(g2.switchName)+level3.token+(level3.numberWagon)+level3.token+"des");
                }
            }//onClicked
        }//MouseArea
        state: "con"
        states: [
            State {
                name: "con"
                PropertyChanges { target: conG2; rotation: 0}
            },
            State {
                name: "des"
                PropertyChanges { target: conG2; rotation: 90}
            }
        ]

        transitions: Transition {
            PropertyAnimation { target: conG2; properties: "rotation"; duration: 200 }
        }
    }//Item

    Item {
        id: g3
        objectName: "t3"
        property string switchName: "DEFAULT"
        property int nSwitch: 3
        x: 338
        y: 271
        width: 98
        height: 72

        Image {
            id: conG3
            x: 0
            y: 0
            width: 98
            height: 72
            rotation: 0
            fillMode: Image.PreserveAspectFit
            source: "../Source/images/perillas/Neumatico/neumatico_red.png"
            opacity: 1
        }

        MouseArea {
            id: mouseAreaG3
            x: 10
            y: 0
            width: 85
            height: 68
            onClicked: {
                if (g3.state == "des"){
                    g3.state = "con";
                    level3.selected((level3.type)+level3.token+(g3.switchName)+level3.token+(level3.numberWagon)+level3.token+"con");
                }else{
                    g3.state = "des";
                    level3.selected((level3.type)+level3.token+(g3.switchName)+level3.token+(level3.numberWagon)+level3.token+"des");
                }
            }//onClicked
        }//MouseArea
        state: "con"
        states: [
            State {
                name: "con"
                PropertyChanges { target: conG3; rotation: 0}
            },
            State {
                name: "des"
                PropertyChanges { target: conG3; rotation: 90}
            }
        ]

        transitions: Transition {
            PropertyAnimation { target: conG3; properties: "rotation"; duration: 200 }
        }
    }//Item

    Item {
        id: g4
        objectName: "t4"
        property string switchName: "DEFAULT"
        property int nSwitch: 4
        x: 510
        y: 252
        width: 98
        height: 72

        Image {
            id: conG4
            x: 0
            y: 0
            width: 98
            height: 72
            rotation: 0
            fillMode: Image.PreserveAspectFit
            source: "../Source/images/perillas/Neumatico/neumatico_red.png"
            opacity: 1
        }

        MouseArea {
            id: mouseAreaG4
            x: 10
            y: 0
            width: 85
            height: 68
            onClicked: {
                if (g4.state == "des"){
                    g4.state = "con";
                    level3.selected((level3.type)+level3.token+(g4.switchName)+level3.token+(level3.numberWagon)+level3.token+"con");
                }else{
                    g4.state = "des";
                    level3.selected((level3.type)+level3.token+(g4.switchName)+level3.token+(level3.numberWagon)+level3.token+"des");
                }
            }//onClicked
        }//MouseArea
        state: "con"
        states: [
            State {
                name: "con"
                PropertyChanges { target: conG4; rotation: 0}
            },
            State {
                name: "des"
                PropertyChanges { target: conG4; rotation: 90}
            }
        ]

        transitions: Transition {
            PropertyAnimation { target: conG4; properties: "rotation"; duration: 200 }
        }
    }//Item

    Item {
        id: g5
        objectName: "t5"
        property string switchName: "DEFAULT"
        property int nSwitch: 5
        x: 383
        y: 341
        width: 90
        height: 70

        Image {
            id: conG5
            x: 23
            y: 9
            width: 50
            height: 50
            transformOrigin: Item.Center
            scale: 1.8
            rotation: 0
            fillMode: Image.PreserveAspectFit
            source: "../Source/images/perillas/Neumatico/mariposaGris.png"
            opacity: 1
        }

        MouseArea {
            id: mouseAreaG5
            x: 18
            y: 9
            width: 60
            height: 60
            rotation: 0
            onClicked: {
                if (g5.state == "des"){
                    g5.state = "con";
                    level3.selected((level3.type)+level3.token+(g5.switchName)+level3.token+(level3.numberWagon)+level3.token+"con");
                }else{
                    g5.state = "des";
                    level3.selected((level3.type)+level3.token+(g5.switchName)+level3.token+(level3.numberWagon)+level3.token+"des");
                }
            }//onClicked
        }//MouseArea
        state: "con"
        states: [
            State {
                name: "con"
                PropertyChanges { target: conG5; rotation: 0}
            },
            State {
                name: "des"
                PropertyChanges { target: conG5; rotation: 90}
            }
        ]

        transitions: Transition {
            PropertyAnimation { target: conG5; properties: "rotation"; duration: 200 }
        }
    }//Item

    Item {
        id: g6
        objectName: "t6"
        property string switchName: "DEFAULT"
        property int nSwitch: 6
        x: 622
        y: 341
        width: 104
        height: 94
        rotation: 0

        Image {
            id: conG6
            x: -6
            y: -14
            width: 109
            height: 98
            scale: 0.85
            transformOrigin: Item.Center
            antialiasing: true
            rotation: -40
            fillMode: Image.PreserveAspectFit
            source: "../Source/images/perillas/Neumatico/mariposaBronce.png"
            opacity: 1
//            transform: Rotation {
//                id: g6r
//                origin.x: parent.x/2
//                origin.y: parent.y/2
//                axis { x: 0; y: 0; z: 1 }
//                angle: 0
//                Behavior on angle{
//                    SpringAnimation{
//                        spring: 1.4
//                        damping: 0.15
//                    }
//                }
//            }
        }

        MouseArea {
            id: mouseAreaG6
            x: 0
            y: 5
            width: 98
            height: 57
            rotation: 0
            onClicked: {
                if (g6.state == "des"){
                    g6.state = "con";
                    level3.selected((level3.type)+level3.token+(g6.switchName)+level3.token+(level3.numberWagon)+level3.token+"con");
                }else{
                    g6.state = "des";
                    level3.selected((level3.type)+level3.token+(g6.switchName)+level3.token+(level3.numberWagon)+level3.token+"des");
                }
            }//onClicked
        }//MouseArea
        state: "con"
        states: [
            State {
                name: "con"
                PropertyChanges { target: conG6; rotation: 0}
            },
            State {
                name: "des"
                PropertyChanges { target: conG6; rotation: -45}
            }
        ]

        transitions: Transition {
            PropertyAnimation { target: conG6; properties: "rotation"; duration: 200 }
        }
    }//Item

    Item {
        id: g7
        objectName: "t7"
        property string switchName: "DEFAULT"
        property int nSwitch: 7
        x: 655
        y: 440
        width: 90
        height: 85
        antialiasing: true

        Image {
            id: conG7
            x: 1
            y: 8
            width: 90
            height: 72
            scale: 1
            transformOrigin: Item.Center
            fillMode: Image.PreserveAspectFit
            source: "../Source/images/perillas/Neumatico/mariposaRojaCON.png"
            opacity: 1
        }

        Image {
            id: desG7
            x: 26
            y: 16
            z: 1
            width: 38
            height: 54
            scale: 0.8
            transformOrigin: Item.Center
            fillMode: Image.PreserveAspectFit
            source: "../Source/images/perillas/Neumatico/mariposaRojaDES.png"
            opacity: 0
        }

        MouseArea {
            id: mouseAreaG7
            x: 0
            y: 7
            width: 90
            height: 72
            onClicked: {
                if (g7.state == "con"){
                    g7.state = "des";
                    level3.selected((level3.type)+level3.token+(g7.switchName)+level3.token+(level3.numberWagon)+level3.token+"des");
                }else{
                    g7.state = "con";
                    level3.selected((level3.type)+level3.token+(g7.switchName)+level3.token+(level3.numberWagon)+level3.token+"con");
                }
            }//onClicked
        }//MouseArea

        state: "con"
        states: [
            State {
                name: "con"
                PropertyChanges { target: conG7; opacity: 1}
                PropertyChanges { target: desG7; opacity: 0}
            },
            State {
                name: "des"
                PropertyChanges { target: conG7; opacity: 0}
                PropertyChanges { target: desG7; opacity: 1}
            }
        ]

//        transitions: Transition {
//            PropertyAnimation { target: conG7; properties: "opacity"; duration: 100 }
//            PropertyAnimation { target: desG7; properties: "opacity"; duration: 300 }
//        }
    }//Item
}
