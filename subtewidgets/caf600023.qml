import QtQuick 2.0

Rectangle {
    id: setaButton
    width: 150
    height: 150
    color: "#00000000"

    signal pressedButton(string s)
    signal releasedButton(string s)

    Item {
        id: item_SetaButton
        anchors.fill: parent

        MouseArea {
            id: mouseArea_SetaButton
            anchors.fill: parent
            onClicked: {
                if ( setaButton.state == "State1_SetaON"){
                    setaButton.state = "State1_SetaOFF";
                    releasedButton();
                }
                else{
                    setaButton.state = "State1_SetaON";
                    pressedButton("Holaaaa");
                }
            }
        }

        Image {
            id: imageBase_SetaOff
            anchors.fill: parent
            source: "resources/setaOff.png"
        }
    }

    states: [
        State {
            name: "State1_SetaON"

            PropertyChanges {
                target: imageBase_SetaOff
                source: "resources/setaOn.png"
            }
        },
        State {
            name: "State2_SetaOFF"

            PropertyChanges {
                target: imageBase_SetaOff
                source: "resources/setaOff.png"
            }
        }
    ]

    function isPressed(){
        if ( setaButton.state == "State1_SetaON"){
            return true;
        }
        else{
            return false;
        }
    }









//    id: formacion
//    width: 1024
//    height: 93
////    color: "transparent"
////    border.color: "transparent"
////    focus: true

//    signal selected(string s)

//    Item {
//        id: coche1
//        anchors.fill: parent

//        Image {
//            id: coche1Image
//            anchors.fill: parent
//            source: "C1"
//            opacity: 0
//        }
//    }//Item1, coche1

//    MouseArea {
//        id: mouseAreaCoche1
//        x: 20
//        y: 0
//        width: 160
//        height: 93
//        onClicked: {
////            formacion.state = "formacionBackground";
////            coche1Image.opacity = 1;
////            selected("C1");
//            console.log("On Click, mouseAreaCoche1")
//        }
//    }

//    Item {
//        id: coche2
//        anchors.fill: parent

//        Image {
//            id: coche2Image
//            anchors.fill: parent
//            source: "C2"
//            opacity: 0
//        }
//    }//Item2, coche2

//    MouseArea {
//        id: mouseAreaCoche2
//        x: 181
//        y: 0
//        width: 160
//        height: 93

//        onClicked: {
////            formacion.state = "formacionBackground";
////            coche2Image.opacity = 1;
////            formacion.selected("C2");
//            console.log("On Click, mouseAreaCoche1")
//        }
//    }

//    Image{
//        id: bck
//        anchors.fill: parent
//        source: "../Source/images/fondos/coches_crop.png"
//        opacity: 1
//    }

//    Image{
//        id: bckGrey
//        opacity: 0
//        anchors.fill: parent
//        source: "../Source/images/fondos/coches_opcion_desatu_crop.png"
//    }

//    states: [
//        State {
//            name: "formacionAll"

//            PropertyChanges {
//                target: bckGrey;
//                opacity: 0
//            }
//            PropertyChanges {
//                target: bck;
//                opacity: 1
//            }
//        },
//        State {
//            name: "formacionBackground"

//            PropertyChanges {
//                target: bckGrey;
//                opacity: 1
//            }
//            PropertyChanges {
//                target: bck;
//                opacity: 0
//            }
//        }
//    ]

//    state: "formacionAll"

}//Rectangle

