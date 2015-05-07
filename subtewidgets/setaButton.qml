import QtQuick 2.0

Rectangle {

    id: setaButton
    width: 100
    height: 100
    color: "#00000000"
    border.color: "#00000000"

    //Basic Interface of type button press/release
    signal pressedButton()
    signal releasedButton()

    //method to know device's state
    function isPressed(){
        if ( setaButton.state == "State1_SetaON"){
            return true;
        }
        else{
            return false;
        }
    }


    Item {

        id: item_SetaButton
        width: 100
        height: 100

        MouseArea {
            id: mouseArea_SetaButton
            anchors.fill: parent
            onClicked: {

                if ( setaButton.state == "State1_SetaON"){
                    setaButton.state = "State1_SetaOFF";
                    releasedButton();
                    console.log("Entro en Onclick Seta Button");
                }
                else{
                    setaButton.state = "State1_SetaON";
                    pressedButton();
                    console.log("Entro en Onclick Else Seta Button");
                }
            }
        }

        Image {
            id: imageBase_SetaOff
            x: 0
            y: 0
            width: 100
            height: 100
            anchors.fill: parent
            scale: 0.8
            z: 0
            rotation: 0
            transformOrigin: Item.Center
            fillMode: Image.PreserveAspectFit
            source: "resources/setaOff.png"
        }
    }
    states: [
        State {
            name: "State1_SetaON"

            PropertyChanges {
                target: imageBase_SetaOff
                x: 0
                y: 0
                fillMode: Image.PreserveAspectFit
                transformOrigin: Item.Center
                source: "resources/setaOn.png"
            }

            PropertyChanges {
                target: mouseArea_SetaButton
                transformOrigin: Item.Center
            }

//            PropertyChanges {
//                target: back_SetaButton
//                source: "resources/BKG_botonera_HM.png"
//            }
        },
        State {
            name: "State2_SetaOFF"

            PropertyChanges {
                target: imageBase_SetaOff
                antialiasing: true
                fillMode: Image.PreserveAspectFit
                transformOrigin: Item.Center
                source: "resources/setaOff.png"
            }

            PropertyChanges {
                target: mouseArea_SetaButton
                transformOrigin: Item.Center
            }

//            PropertyChanges {
//                target: back_SetaButton
//                source: "resources/BKG_botonera_HM.png"
//            }

            PropertyChanges {
                target: setaButton
                color: "#00000000"
                border.color: "#00000000"
            }
        }
    ]
}

