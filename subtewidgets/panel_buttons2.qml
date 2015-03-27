import QtQuick 2.0

Rectangle {
    width: 100
    height: 150

    id: panelButtons2
    objectName: "panelButtons2"

    //Interface basica de SIGNAL & SLOT
    signal button1Clicked()
    signal button2Clicked()

    //Interface tipo switch
    signal button1_ClickedOn()
    signal button1_ClickedOff()
    signal button2_ClickedOn()
    signal button2_ClickedOff()

    SequentialAnimation{
        id: animationAlarmButton2
        loops: 50
        PropertyAnimation { target: button2; property: "state"; to: "stateButton2Off"; duration: 500 }
        PropertyAnimation { target: button2; property: "state"; to: "stateButton2On"; duration: 500 }
    }


    function clickButton1(){
        if (button1.state == "stateButton1On"){
            button1.state = "stateButton1Off";
            button1_ClickedOff();
            console.log("click Button1 OFF --> ",button1.state);
        }
        else{
            button1.state = "stateButton1On";
            console.log("click Button1 ON --> ",button1.state);
        };
        panelButtons2.button1Clicked();
    }

    function alarm_light(accion){
        if (accion){
            animationAlarmButton2.start();
            console.log(" Disparo Alarma HombreVivoHombreMuerto !!!!!!!");
        }else{
            animationAlarmButton2.stop();
            console.log("Abortado alarma HombreVivoHombreMuerto *******");
        }
    }

    function light_Button2(accion){
        if (accion == "ON"){
            button2.state = "stateButton2On";
            console.log("Prendiendo Luz ROJA -- ON --> ",accion);
        }
        else{
            button2.state = "stateButton2Off";
            console.log("Apagando Luz ROJA -- OFF --> ",accion);
        };
        return (button2.state + accion);
    }

    function light_Button1(accion){
        if (accion == "ON"){
            button1.state = "stateButton1On";
            console.log("Prendiendo luz Azul --> accion == ON ",accion);
        }
        else{
            button1.state = "stateButton1Off";
            console.log("Apagando luz Azul --> ELSE de accion == ON ",accion);
        };
        return (button1.state + accion);
    }

    function enable_mouseArea1(enable1){
        mouseArea1.enabled = enable1;
        console.log("enable_mouseArea1: ",enable1);
    }

    function enable_mouseArea2(enable2){
        mouseArea2.enabled = enable2;
        console.log("enable_mouseArea2",enable2);
    }

    Image {
        id: image1
        anchors.fill: parent
        source: "resources/BKG_botonera_HM.png"

        Column {
            id: column1
            anchors.fill: parent

            Item {
                id: button2
                y: 0
                width: 100
                height: 75

                Image {
                    id: button2OFF
                    x: 0
                    y: 0
                    width: 65
                    height: 65
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.verticalCenter: parent.verticalCenter
                    source: "resources/red.png"
                    opacity: 1
                }

                Image {
                    id: button2ON
                    x: 0
                    y: 0
                    width: 65
                    height: 65
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.verticalCenter: parent.verticalCenter
                    source: "resources/redON.png"
                    opacity: 0
                }

                states: [
                    State {
                        name: "stateButton2On";
                        PropertyChanges { target: button2ON; opacity: 1}
                    },
                    State {
                        name: "stateButton2Off";
                        PropertyChanges { target: button2ON; opacity: 0}

                    }
                ]

                transitions:[
                    Transition {
                        from: "*"
                        to: "*"
                        NumberAnimation { properties: "opacity"; duration: 200  }
                    }
                ]

                MouseArea {
                    id: mouseArea2
                    anchors.fill: parent
                    onClicked: {

                        if (button2.state == "stateButton2On"){
                            button2.state = "stateButton2Off"
                        }
                        else{
                            button2.state = "stateButton2On"
                            panelButtons2.button1Clicked()
                        }
                    }
                }
            }

            Item {
                id: button1
                y: 75
                width: 100
                height: 75
                transformOrigin: Item.Center
                anchors.horizontalCenter: parent.horizontalCenter

                Image {
                    id: button1OFF
                    x: 0
                    y: 0
                    width: 65
                    height: 65
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.verticalCenter: parent.verticalCenter
                    source: "resources/blue.png"
                    opacity: 1
                }

                Image {
                    id: button1ON
                    x: 0
                    y: 0
                    width: 65
                    height: 65
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.verticalCenter: parent.verticalCenter
                    source: "resources/blueON.png"
                    opacity: 0
                }

                states: [
                    State {
                        name: "stateButton1On";
                        PropertyChanges { target: button1ON; opacity: 1}
                    },
                    State {
                        name: "stateButton1Off";
                        PropertyChanges { target: button1ON; opacity: 0}

                    }
                ]

                transitions:[
                    Transition {
                        from: "*"
                        to: "*"
                        NumberAnimation { properties: "opacity"; duration: 200  }
                    }
                ]

                MouseArea {
                    id: mouseArea1
                    anchors.fill: parent
                    onClicked: {    panelButtons2.clickButton1();
                                    console.log("Mouse Area 1 clicked");
                    }
                }//Mouse Area1
            }
        }
    }
}

