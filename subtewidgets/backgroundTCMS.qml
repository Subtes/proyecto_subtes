import QtQuick 2.0
Rectangle {
    id: borderBackground
    width: 617
    height: 497
    radius: 0
    border.color: "#534848"
    border.width: 7
    property variant puertasCoche: []
    property double currentValue: 0
    property double maxValue: 100
    property double minValue: -100
    property double maxAngle: 0
    property double offsetAngle: 0
    property double originX: width/2
    property double originY: height/2

    //variables repeater puertas diferentes offset

    property double offset_coche: 41
    property double offset_inicio_puerta: 61
    property double offset_entre_coches: 30
    property double offset_espacio_entre_puertas: 21
    property double puertas_X_coche: 8
    property double puertas_X_lado: 4
    property double cantidad_de_lados_por_coche: 2
    property double pos_puertas_arriba: 87
    property double pos_puertas_abajo: 117
    property double escala_maxima_volt: 2500
    property double escala_maxima_amper: 400
    property double escala_minima_amper: -400





    Image {
        id: background
        x: 4
        y: 4
        width: 610
        height: 490
        transformOrigin: Item.Center
        fillMode: Image.PreserveAspectCrop
        rotation: 0
        source: "resources/alstom_background.png"
    }
    Rectangle {
        id: circulovelocidad
        x: 125
        y: 266
        width: 60
        height: 60
        color: "#ffffff"
        radius: 30
        scale: 0.9
        z: 2
        border.width: 3
    }
    Text {
        id: velocimetrodigital
        x: 146
        y: 275
        width: 12
        height: 21
        text: qsTr(" ")
        z: 3
        font.bold: true
        font.pixelSize: 14
    }

    Text {
        id: kilometros
        x: 136
        y: 297
        text: qsTr("km/h")
        font.bold: true
        z: 3
        font.pixelSize: 13
    }

    Text {
        id: voltimetrodigital1
        x: 243
        y: 284
        text: qsTr(" ")
        font.bold: true
        font.pixelSize: 13
    }

    Text {
        id: voltimetrodigital2
        x: 245
        y: 311
        text: qsTr(" ")
        font.bold: true
        font.pixelSize: 13
    }

    Text {
        id: amperimetrodigital
        x: 426
        y: 283
        text: qsTr(" ")
        font.bold: true
        font.pixelSize: 13
    }


    Rectangle {
        id: needle
        objectName: "needle"
        x: 152
        y: 283
        width: 4
        height: 60
        color: "#080505"
        rotation: -4
        transformOrigin: Item.Top
        border.color: "#00000000"
        radius: 2
        z: 1
        scale: 1.2
        property double speed: 22;
        transform: Rotation{


           id: rot
            origin.x: 0
            origin.y: 0
            angle: 44
//            Behavior on angle {
//                PropertyAnimation{
//                    duration : 400
//                    easing {type: Easing.OutQuad}
//                }
//            }
        }
    }


  // valor de donde debe comenzar el ángulo 44
  //offset para acomodar aguja 360-44 = 316/120 =2.6333333
    function updateNeedle(valueIN) {

        rot.angle=(valueIN *2.38)+(44);

        //        if(valueIN<minValue){
//            valueIN=minValue
//        }else if(valueIN>maxValue){
//            valueIN=maxValue
//        }
//        console.log("entramos a la velocidad")
//        currentValue = (valueIN/maxValue)*maxAngle + offsetAngle
//        rot.angle = currentValue
//        return "ok"
    }

    Rectangle {
        id: barravoltimetroleft
        x: 316
        y: 211
        width: 13
        height: 166
        color: "#000000"
        antialiasing: false
        transform: Scale { id:tranfobarravoltimetroleft ;origin.x: 0; origin.y: 170; yScale: 0.1}
    }

    Text {
        id: notacionvoltimetro1
        x: 283
        y: 283
        text: qsTr("V")
        font.bold: true
        font.pixelSize: 13
    }

    Text {
        id: notacionvoltimetro2
        x: 284
        y: 311
        text: qsTr("V")
        font.bold: true
        font.pixelSize: 13
    }

    Rectangle {
        id: barravoltimetroright
        x: 341
        y: 211
        width: 13
        height: 168
        color: "#000000"
        transform: Scale { id:tranfovoltimetroright ;origin.x: 0; origin.y: 170}

    }

    Text {
        id: notacionamperimetro
        x: 456
        y: 283
        text: qsTr("KN")
        font.bold: true
        font.pixelSize: 13
    }

    Rectangle {
        id: barraamperimetro
        x: 490
        y: 215
        width: 15
        height: 21
        color: "#000000"
        transformOrigin: Item.Center
        scale: 1
        transform: Scale { id:tranfobarraamperimetro ;origin.x: 0; origin.y: 90}

    }


    function updateDigitalVelocity(speed){
        velocimetrodigital.text=speed;

    }

    function updateDigitalVoltimetroLeft(volt){
        voltimetrodigital1.text=volt;
        tranfobarravoltimetroleft.yScale = (volt/escala_maxima_volt);


    }

    function updateDigitalVoltimetroRight(volt){
        voltimetrodigital2.text=volt;
        tranfovoltimetroright.yScale = (volt/escala_maxima_volt);


    }
    function updateDigitalAmperimetro(amp){
        amperimetrodigital.text=amp;
        tranfobarraamperimetro.yScale= (amp/escala_maxima_amper);
//        if(amp >=0){
//            tranfobarraamperimetro.xScale= amp/escala_maxima_amper
//        }else
//        {
//            tranfobarraamperimetro.xScale= amp/escala_minima_amper

//        }
    }



    //REPEAT QUE GENERA en el renglon en la viuaizacion del tren

    Repeater {
        model: 48
        Image {
            id: puertastren
            width: 18
            height: 22
            opacity: 1
            x: getXpuertastren(index)
            y: getYpuertastren(index)
            source: "resources/alstom_puertas_cerradas_bloqueadas.png"
            antialiasing: true
            smooth: true
            states: [
                State {
                    name: "con"
                    PropertyChanges { target: abrirpuertas;running:true}

                },
                State {
                    name: "des"
                    PropertyChanges { target: cerrarpuertas;running:true}

                },
                State {
                    name: "int"
                    PropertyChanges { target: blinkAnimation2; running:true;}
                }
            ]

            transitions: Transition {
                PropertyAnimation { properties: "opacity"; duration: 100 }
            }

            SequentialAnimation {
                id: abrirpuertas

//                 PropertyChanges { target: puertastren;source: "resources/alstom_puertas_entreabiertas.png"; opacity: 1}
//                 NumberAnimation {target: puertastren;duration: 500 }
//                 PropertyChanges { target: puertastren;source: "resources/alstom_puertas_cerradas.png"; opacity: 1}
//                 NumberAnimation {target: puertastren;duration: 500 }
//                 PropertyChanges { target: puertastren;source: "resources/alstom_puertas_cerradas_bloqueadas.png"; opacity: 1}
             }
            SequentialAnimation {
                id: cerrarpuertas

//                  NumberAnimation {target: puertastren;duration: 500 }
//                  PropertyChanges { target: puertastren;source: "resources/alstom_puertas_cerradas.png"; opacity: 1}
//                  NumberAnimation {target: puertastren;duration: 500 }
//                  PropertyChanges { target: puertastren;source: "resources/alstom_puertas_cerradas_bloqueadas.png"; opacity: 1}
             }

        }
        onItemAdded: puertasCoche[index] = item
    }

    function getXpuertastren(p){
        var nroCoche = Math.floor(p/puertas_X_coche);
        var valor = ((offset_coche)+(nroCoche*(offset_inicio_puerta))+(offset_entre_coches*nroCoche)+((p%puertas_X_lado)*offset_espacio_entre_puertas));
        return valor;
    }

    function getYpuertastren(p){
        var acum=(Math.floor(p/puertas_X_lado)%cantidad_de_lados_por_coche);
        if (acum==0)
            return (pos_puertas_arriba);
        return(pos_puertas_abajo);
    }

}//FIN RECTANGULO

