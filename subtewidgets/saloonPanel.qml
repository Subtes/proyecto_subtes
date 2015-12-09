import QtQuick 2.0

Rectangle {
    id: level3
    objectName: "saloonPanel"
    x: 0
    y: 0
    width: 900
    height: 675
    color: "#00000000"
    border.color: "#00000000"

    signal selected(string s)
    property string type: "c_grifo_"
    property string numberWagon: "cocheDEFAULT"
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
        //source: "../Source/images/fondos/Salon_Mod.PNG"
        source: "N3-PS"
        opacity: 1
    }

    Item {
        id: g1
        width: 98
        height: 72
        objectName: "t0"
        property string switchName: "DEFAULT"
        property int nSwitch: 0
        x: 193
        y: 186

        Image {
            id: con0
            objectName: "con0"
            x: 6
            y: 6
            width: 85
            height: 60
            transformOrigin: Item.Center
            scale: 1.1
            z: 1
            //rotation: 0
            fillMode: Image.PreserveAspectFit
            source: "../Source/images/perillas/Salon/mariposaAmarillaCON.png"
            opacity: 1
        }//ImageCON

        Image {
            id: des0
            objectName: "des0"
            x: 4
            y: -2
            width: 85
            height: 60
            transformOrigin: Item.Center
            scale: 1
            z: 1
            //rotation: 0
            fillMode: Image.PreserveAspectFit
            source: "../Source/images/perillas/Salon/mariposaAmarillaDES.png"
            opacity: 1
        }//ImageDES

        MouseArea {
            id: mouseAreaG1
            x: 0
            y: 0
            width: 98
            height: 72
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

        state: "des"
        states: [
            State {
                name: "con"
                PropertyChanges { target: con0; opacity: 1}
                PropertyChanges { target: des0; opacity: 0}
            },
            State {
                name: "des"
                PropertyChanges { target: con0; opacity: 0}
                PropertyChanges { target: des0; opacity: 1}
            }
        ]

        transitions: Transition {
            PropertyAnimation { target: con0; properties: "opacity"; duration: 200 }
            PropertyAnimation { target: des0; properties: "opacity"; duration: 200 }
        }
    }//Item
}

