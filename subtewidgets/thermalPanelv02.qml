import QtQuick 2.0

Rectangle {
    id: level3
    objectName: "thermalPanel"
    x: 0
    y: 0
    width: 900
    height: 675
    Component.onCompleted: {console.log("@_ Cargado Panel de Termicas");
                            thermalsVector[thermalsVector.length]=r1;
                            thermalsVector[thermalsVector.length]=r2;
                            thermalsVector[thermalsVector.length]=r3;
                            thermalsVector[thermalsVector.length]=r4;
                            console.log("Vector de Termicas: ---> ",thermalsVector.toString());
    }

    signal selected(string s)
    signal ready(string s)
    signal ready0(string s)

    property string type: "c_termico_"
    property string numberWagon: "_X_"
    property string token: ";"

    property  int cantRow0: 9
    property  int cantRow1: 13
    property  int cantRow2: 10
    property  int cantRow3: 10

    property variant  thermalsVector: []
    property int index0: 0
    property int index1: 9
    property int index2: 22
    property int index3: 32

    property int cantThermal: 0;

    Image {
        id: backGround
        objectName: "backGround"
        x: 0
        y: 0
        z: 0
        width: 900
        height: 675
        fillMode: Image.PreserveAspectFit
        //source: "../Source/images/fondos/Termicas_Resize.PNG"
        source: "N3-PT"
        opacity: 1
    }

        Row {
            id: row0
            objectName: "row0"
            x: 315
            y: 74
            width: 451
            height: 40
            layoutDirection: Qt.LeftToRight
            spacing: 17

            Repeater{
                id: repeaterThermal0
                objectName: "repeaterThermal0"
                model: cantRow0             

                Item {
                    id: t0
                    width: 35
                    height: 39
                    transformOrigin: Item.Left
                    state: "con"

                    objectName: "t"+index
                    property string switchName: "TERMICO-DEFAULT_"+index
                    property int nSwitch: index

                    Component.onCompleted: {
                        countThermal();
                        console.log("@:_...Item Thermal: ",objectName);
                    }

                    Image {
                        id: con0
                        objectName: "con0T"+index
                        x: 0
                        y: 0
                        width: 35
                        height: 38
                        fillMode: Image.Stretch
                        source: "../Source/images/perillas/termicas/Tecla2_Arriba_Resize.PNG"
                        opacity: 0
                    }

                    Image {
                        id: des0
                        objectName: "des0T"+index
                        x: 0
                        y: 6
                        width: 35
                        height: 38
                        fillMode: Image.Stretch
                        source: "../Source/images/perillas/termicas/Tecla2_Abajo_Resize.PNG"
                        opacity: 1
                    }

                    MouseArea {
                        id: mouseAreaT0
                        x: 0
                        y: 0
                        width: 35
                        height: 40
                        onClicked: {
                            if ( parent.state == "con"){
                                parent.state = "des";
                                level3.selected(level3.type+level3.token+(thermalsVector[nSwitch].switchName)+level3.token+level3.numberWagon+level3.token+"des");
                                //console.log("Entro en IF de Termico: ",level3.type+(thermalsVector[nSwitch].switchName)+level3.numberWagon+token+"des");
                                //console.log("------------------------------------------------ Nombre Objeto Item: ",thermalsVector[nSwitch].objectName);
                            }else{
                                parent.state = "con";
                                level3.selected(level3.type+level3.token+(thermalsVector[nSwitch].switchName)+level3.token+level3.numberWagon+level3.token+"con");
                                //console.log("Entro en ELSE de Termico: ",level3.type+(thermalsVector[nSwitch].switchName)+level3.numberWagon+token+"con");
                                //console.log("------------------------------------------------ Nombre Objeto Item: ",thermalsVector[nSwitch].objectName);
                            }
                        }//onClicked
                    }//MouseArea
                    states: [
                        State {
                            name: "con"
                            PropertyChanges { target: con0; opacity: 1;}
                            PropertyChanges { target: des0; opacity: 0;}
                        },
                        State {
                            name: "des"
                            PropertyChanges { target: con0; opacity: 0;}
                            PropertyChanges { target: des0; opacity: 1;}
                        }
                    ]
                }//Item
                onItemAdded: thermalsVector[index] = item
            }//Repeater
        }//Row0

        Row {
            id: row1
            objectName: "row1"
            x: 157
            y: 203
            width: 663
            height: 40
            layoutDirection: Qt.LeftToRight
            spacing: 17

            Repeater {
                id: repeaterThermal1
                objectName: "repeaterThermal1"
                model: cantRow1

                Item {
                    id: t1
                    y: 0
                    width: 35
                    height: 38
                    transformOrigin: Item.Left

                    objectName: "t"+ ((index1 +index).toString())
                    property string switchName: "TERMICO-DEFAULT_"+(index1+index)
                    property int nSwitch: index1+index
                    state: "con"

                    Component.onCompleted: {
                        countThermal();
                        console.log("@:_...Item Thermal: ",objectName);
                    }

                    Image {
                        id: con1
                        x: 0
                        y: 0
                        width: 35
                        height: 38
                        objectName: "con1T"+(index1+index)
                        opacity: 0
                        fillMode: Image.Stretch
                        source: "../Source/images/perillas/termicas/Tecla2_Arriba_Resize.PNG"
                    }

                    Image {
                        id: des1
                        x: 0
                        y: 6
                        width: 35
                        height: 38
                        objectName: "des1T"+(index1+index)
                        opacity: 1
                        fillMode: Image.Stretch
                        source: "../Source/images/perillas/termicas/Tecla2_Abajo_Resize.PNG"
                    }

                    MouseArea {
                        id: mouseAreaT1
                        x: 0
                        y: 0
                        width: 35
                        height: 38
                        onClicked: {
                            if ( parent.state == "con"){
                                parent.state = "des";
                                level3.selected(level3.type+level3.token+(thermalsVector[nSwitch].switchName)+level3.token+level3.numberWagon+level3.token+"des");
                                //console.log("Entro en IF de Termico: ",level3.type+(thermalsVector[nSwitch].switchName)+level3.numberWagon+token+"des");
                                //console.log("------------------------------------------------ Nombre Objeto Item: ",thermalsVector[nSwitch].objectName);
                            }else{
                                parent.state = "con";
                                level3.selected(level3.type+level3.token+(thermalsVector[nSwitch].switchName)+level3.token+level3.numberWagon+level3.token+"con");
                                //console.log("Entro en ELSE de Termico: ",level3.type+(thermalsVector[nSwitch].switchName)+level3.numberWagon+token+"con");
                                //console.log("------------------------------------------------ Nombre Objeto Item: ",thermalsVector[nSwitch].objectName);
                            }
                        }//onClicked
                    }//MouseArea
                    states: [
                        State {
                            name: "con"
                            PropertyChanges {
                                target: con1
                                opacity: 1
                            }

                            PropertyChanges {
                                target: des1
                                opacity: 0
                            }
                        },
                        State {
                            name: "des"
                            PropertyChanges {
                                target: con1
                                opacity: 0
                            }

                            PropertyChanges {
                                target: des1
                                opacity: 1
                            }
                        }]
                }//Item
               onItemAdded: thermalsVector[cantRow0+index] = item
            }//Repeater
        }//Row1

        Row {
            id: row2
            objectName: "row2"
            x: 315
            y: 335
            width: 505
            height: 40
            spacing: 17
            layoutDirection: Qt.LeftToRight
            Repeater {
                id: repeaterThermal2
                objectName: "repeaterThermal2"
                model: cantRow2

                Item {
                    id: t2
                    width: 35
                    height: 38
                    transformOrigin: Item.Left

                    objectName: "t"+(index2+index)
                    property string switchName: "TERMICO-DEFAULT_"+(index2+index)
                    property int nSwitch: (index2+index)
                    state: "con"

                    Component.onCompleted: {
                        countThermal();
                        console.log("@:_...Item Thermal: ",objectName);
                    }

                    Image {
                        id: con2
                        x: 0
                        y: 0
                        width: 35
                        height: 38
                        objectName: "con2T"+(index2+index)
                        opacity: 0
                        fillMode: Image.Stretch
                        source: "../Source/images/perillas/termicas/Tecla2_Arriba_Resize.PNG"
                    }

                    Image {
                        id: des2
                        x: 0
                        y: 6
                        width: 35
                        height: 38
                        objectName: "des2T"+(index2+index)
                        opacity: 1
                        fillMode: Image.Stretch
                        source: "../Source/images/perillas/termicas/Tecla2_Abajo_Resize.PNG"
                    }

                    MouseArea {
                        id: mouseAreaT2
                        x: 0
                        y: 0
                        width: 35
                        height: 40
                        onClicked: {
                            if ( parent.state == "con"){
                                parent.state = "des";
                                level3.selected(level3.type+level3.token+(thermalsVector[nSwitch].switchName)+level3.token+level3.numberWagon+level3.token+"des");
                                //console.log("Entro en IF de Termico: ",level3.type+(thermalsVector[nSwitch].switchName)+level3.numberWagon+token+"des");
                                //console.log("------------------------------------------------ Nombre Objeto Item: ",thermalsVector[nSwitch].objectName);
                            }else{
                                parent.state = "con";
                                level3.selected(level3.type+level3.token+(thermalsVector[nSwitch].switchName)+level3.token+level3.numberWagon+level3.token+"con");
                                //console.log("Entro en ELSE de Termico: ",level3.type+(thermalsVector[nSwitch].switchName)+level3.numberWagon+token+"con");
                                //console.log("------------------------------------------------ Nombre Objeto Item: ",thermalsVector[nSwitch].objectName);
                            }
                        }//onClicked
                    }//MouseArea
                    states: [
                        State {
                            name: "con"
                            PropertyChanges {
                                target: con2
                                opacity: 1
                            }

                            PropertyChanges {
                                target: des2
                                opacity: 0
                            }
                        },
                        State {
                            name: "des"
                            PropertyChanges {
                                target: con2
                                opacity: 0
                            }

                            PropertyChanges {
                                target: des2
                                opacity: 1
                            }
                        }]
                }//Item
               onItemAdded: thermalsVector[index2+index] = item
            }//Repeater
        }//Row2

        Row {
            id: row3
            objectName: "row3"
            x: 315
            y: 472
            width: 505
            height: 40
            layoutDirection: Qt.LeftToRight
            spacing: 17

            Repeater {
                id: repeaterThermal3
                objectName: "repeaterThermal3"
                model: cantRow3
                Item {
                    id: t3
                    width: 35
                    height: 38
                    transformOrigin: Item.Left

                    objectName: "t"+(index3+index)
                    property string switchName: "TERMICO-DEFAULT_"+(index3+index)
                    property int nSwitch: index3+index
                    state: "con"

                    Component.onCompleted: {
                        countThermal();
                        console.log("@:_...Item Thermal: ",objectName);
                    }

                    Image {
                        id: con3
                        x: 0
                        y: 0
                        width: 35
                        height: 38
                        objectName: "con3T"+(index3+index)
                        opacity: 0
                        fillMode: Image.Stretch
                        source: "../Source/images/perillas/termicas/Tecla2_Arriba_Resize.PNG"
                    }

                    Image {
                        id: des3
                        x: 0
                        y: 6
                        width: 35
                        height: 38
                        objectName: "des3T"+(index3+index)
                        opacity: 1
                        fillMode: Image.Stretch
                        source: "../Source/images/perillas/termicas/Tecla2_Abajo_Resize.PNG"
                    }

                    MouseArea {
                        id: mouseAreaT3
                        x: 0
                        y: 0
                        width: 35
                        height: 40
                        onClicked: {
                            if ( parent.state == "con"){
                                parent.state = "des";
                                level3.selected(level3.type+level3.token+(thermalsVector[nSwitch].switchName)+level3.token+level3.numberWagon+level3.token+"des");
                                //console.log("Entro en IF de Termico: ",level3.type+(thermalsVector[nSwitch].switchName)+level3.numberWagon+token+"des");
                                //console.log("------------------------------------------------ Nombre Objeto Item: ",thermalsVector[nSwitch].objectName);
                            }else{
                                parent.state = "con";
                                level3.selected(level3.type+level3.token+(thermalsVector[nSwitch].switchName)+level3.token+level3.numberWagon+level3.token+"con");
                                //console.log("Entro en ELSE de Termico: ",level3.type+(thermalsVector[nSwitch].switchName)+level3.numberWagon+token+"con");
                                //console.log("------------------------------------------------ Nombre Objeto Item: ",thermalsVector[nSwitch].objectName);
                            }
                        }//onClicked
                    }
                    states: [
                        State {
                            name: "con"
                            PropertyChanges {
                                target: con3
                                opacity: 1
                            }

                            PropertyChanges {
                                target: des3
                                opacity: 0
                            }
                        },
                        State {
                            name: "des"
                            PropertyChanges {
                                target: con3
                                opacity: 0
                            }

                            PropertyChanges {
                                target: des3
                                opacity: 1
                            }
                        }]
                }//Item
            onItemAdded: thermalsVector[index3+index] = item
            }//Repeater
        }//Row3

        Item {
            id: r1
            x: 230
            y: 600
            width: 112
            height: 26
            objectName: "r1"
            property string switchName: "TERMICO-DEFAULT_switchRed"

            Component.onCompleted: {
                countThermal();
                console.log("@:_...Item Thermal: ",objectName);
            }

            Image {
                id: conR1
                x: -1
                width: 110
                height: 26
                rotation: 0
                fillMode: Image.PreserveAspectFit
                source: "../Source/images/perillas/termicas/Termicas_roja_Resize.PNG"
            }

            MouseArea {
                id: mouseAreaR1
                x: 0
                y: -37
                width: 112
                height: 97
                onClicked: {
                    if (r1.state == "des"){
                        r1.state = "con";
                        level3.selected((level3.type)+level3.token+(r1.switchName)+level3.token+(level3.numberWagon)+level3.token+"con");
                    }else{
                        r1.state = "des";
                        level3.selected((level3.type)+level3.token+(r1.switchName)+level3.token+(level3.numberWagon)+level3.token+"des");
                    }
                }
            }
            state: "con"
            states: [
                State {
                    name: "con"
                    PropertyChanges {
                        target: conR1
                        rotation: 90
                    }
                },
                State {
                    name: "des"
                    PropertyChanges {
                        target: conR1
                        rotation: 0
                    }
                }]
            transitions: Transition {
                PropertyAnimation { target: conR1; properties: "rotation"; duration: 200 }
            }
        }
/*************************************************************************************/
        Item {
            id: r2
            x: 204
            y: 87
            width: 100
            height: 41
            objectName: "r2"
            property string switchName: "TERMICO-DEFAULT_switchOrange"

            Component.onCompleted: {
                countThermal();
                console.log("@:_...Item Thermal: ",objectName);
            }

            Image {
                id: conR2
                x: 6
                y: -2
                width: 100
                height: 41
                fillMode: Image.PreserveAspectFit
                source: "../Source/images/perillas/termicas/Tecla1_Arriba_Resize.PNG"
            }

            Image {
                id: desR2
                x: 6
                y: 8
                width: 101
                height: 39
                scale: 1.1
                fillMode: Image.PreserveAspectFit
                source: "../Source/images/perillas/termicas/Tecla1_Abajo_Resize.PNG"
            }

            MouseArea {
                id: mouseAreaR2
                x: 21
                y: 1
                width: 71
                height: 42
                onClicked: {
                    if (r2.state == "des"){
                        r2.state = "con";
                        level3.selected((level3.type)+level3.token+(r2.switchName)+level3.token+(level3.numberWagon)+level3.token+"con");
                    }else{
                        r2.state = "des";
                        level3.selected((level3.type)+level3.token+(r2.switchName)+level3.token+(level3.numberWagon)+level3.token+"des");
                    }
                }
            }
            state: "con"
            states: [
                State {
                    name: "con"
                    PropertyChanges {
                        target: conR2
                        opacity: 1
                    }

                    PropertyChanges {
                        target: desR2
                        opacity: 0
                    }
                },
                State {
                    name: "des"
                    PropertyChanges {
                        target: conR2
                        opacity: 0
                    }

                    PropertyChanges {
                        target: desR2
                        opacity: 1
                    }
                }]
            transitions: Transition {
                PropertyAnimation { target: conR2; properties: "opacity"; duration: 200 }
                PropertyAnimation { target: desR2; properties: "opacity"; duration: 200 }
            }
        }
/*************************************************************************************/
        Item {
            id: r3
            x: 223
            y: 485
            width: 77
            height: 35
            objectName: "r3"
            property string switchName: "TERMICO-DEFAULT_switchOrange"

            Component.onCompleted: {
                countThermal();
                console.log("@:_...Item Thermal: ",objectName);
            }

            Image {
                id: conR3
                x: 0
                y: -12
                width: 77
                height: 35
                fillMode: Image.PreserveAspectFit
                source: "../Source/images/perillas/termicas/Tecla4_Arriba_Resize.PNG"
            }

            Image {
                id: desR3
                x: 0
                y: -3
                width: 77
                height: 35
                fillMode: Image.PreserveAspectFit
                source: "../Source/images/perillas/termicas/Tecla4_Abajo_Resize.PNG"
            }

            MouseArea {
                id: mouseAreaR3
                x: -2
                y: -10
                width: 77
                height: 42
                onClicked: {
                    if (r3.state == "des"){
                        r3.state = "con";
                        level3.selected((level3.type)+level3.token+(r3.switchName)+level3.token+(level3.numberWagon)+level3.token+"con");
                    }else{
                        r3.state = "des";
                        level3.selected((level3.type)+level3.token+(r3.switchName)+level3.token+(level3.numberWagon)+level3.token+"des");
                    }
                }
            }
            state: "con"
            states: [
                State {
                    name: "con"
                    PropertyChanges {
                        target: conR3
                        opacity: 1
                    }

                    PropertyChanges {
                        target: desR3
                        opacity: 0
                    }
                },
                State {
                    name: "des"
                    PropertyChanges {
                        target: conR3
                        opacity: 0
                    }

                    PropertyChanges {
                        target: desR3
                        opacity: 1
                    }
                }]
            transitions: Transition {
                PropertyAnimation { target: conR3; properties: "opacity"; duration: 200 }
                PropertyAnimation { target: desR3; properties: "opacity"; duration: 200 }
            }
        }
/*************************************************************************************/
        Item {
            id: r4
            x: 264
            y: 338
            width: 31
            height: 39
            objectName: "r4"
            property string switchName: "TERMICO-DEFAULT_switchOrange"

            Component.onCompleted: {
                countThermal();
                console.log("@:_...Item Thermal: ",objectName);
            }

            Image {
                id: conR4
                x: -1
                y: 1
                width: 32
                height: 38
                scale: 1
                fillMode: Image.PreserveAspectFit
                source: "../Source/images/perillas/termicas/Tecla3_Arriba_Resize.PNG"
            }

            Image {
                id: desR4
                x: -1
                y: 7
                width: 31
                height: 38
                fillMode: Image.PreserveAspectFit
                source: "../Source/images/perillas/termicas/Tecla3_Abajo_Resize.PNG"
            }

            MouseArea {
                id: mouseAreaR4
                x: 0
                y: 0
                width: 31
                height: 39
                onClicked: {
                    if (r4.state == "des"){
                        r4.state = "con";
                        level3.selected((level3.type)+level3.token+(r4.switchName)+level3.token+(level3.numberWagon)+level3.token+"con");
                    }else{
                        r4.state = "des";
                        level3.selected((level3.type)+level3.token+(r4.switchName)+level3.token+(level3.numberWagon)+level3.token+"des");
                    }
                }
            }
            state: "con"
            states: [
                State {
                    name: "con"
                    PropertyChanges {
                        target: conR4
                        opacity: 1
                    }

                    PropertyChanges {
                        target: desR4
                        opacity: 0
                    }
                },
                State {
                    name: "des"
                    PropertyChanges {
                        target: conR4
                        opacity: 0
                    }

                    PropertyChanges {
                        target: desR4
                        opacity: 1
                    }
                }]
            transitions: Transition {
                PropertyAnimation { target: conR4; properties: "opacity"; duration: 200 }
                PropertyAnimation { target: desR4; properties: "opacity"; duration: 200 }
            }
        }
/*************************************************************************************/

    function setThermal(i,n,v){
        thermalsVector[i].switchName = n;
        thermalsVector[i].state = v;
        console.log("@:_Setting thermal name, number: ",i," to name: ",n," value: ",v);
    }

    function countThermal(){
        level3.cantThermal++;
        if (level3.cantThermal == (cantRow0+cantRow1+cantRow2+cantRow3-1)){
            level3.ready0("true");
            console.log("@:_ COMPLETED THERMAL RACKS..........OK");
        }
        //console.log("Entro en countThermal");
    }

    function readyThermal(){
        console.log("Entro en QML thermalPanel");
        level3.ready0("true");
    }
}
