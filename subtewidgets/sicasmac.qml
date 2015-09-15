import QtQuick 2.0

Rectangle {
    id: mac_sicas
    width: 627
    height: 482
    color: "#00000000"
    border.color: "#00000000"

    property variant prioridadLetra: []
    property variant trenConFalla: []
    property variant textoError: []
    property variant failure: []
    property variant puertasCocheIzq: []
    property variant puertasCocheDer: []

    Image {
        id: background
        anchors.rightMargin: 0
        anchors.bottomMargin: 0
        anchors.leftMargin: 0
        anchors.topMargin: 0
        objectName:"background"
        anchors.fill: parent
        source: "resources/sicas_bkg.jpg"

 //MODIFICARLOS CON EL Repeater ACTUALIZANDO LA X CADA 45 COMENZANDO DE 47

        MouseArea {

            id: menu1
            x: 47
            y: 438
            width: 35
            height: 34
            // onClicked: blinkAnimationf1.complete();
            onClicked: blinkAnimationf1.stop()
        }

        MouseArea {
            id: menu2
            x: 92
            y: 438
            width: 35
            height: 34
             onClicked: blinkAnimationf1.start()
        }

        MouseArea {
            id: contraste1
            x: 137
            y: 439
            width: 35
            height: 34
        }

        MouseArea {
            id: contraste2
            x: 183
            y: 438
            width: 35
            height: 34
        }

        MouseArea {
            id: siguiente1
            x: 227
            y: 438
            width: 35
            height: 34
        }

        MouseArea {
            id: siguiente2
            x: 274
            y: 438
            width: 35
            height: 34
        }

        MouseArea {
            id: anterior1
            x: 318
            y: 438
            width: 35
            height: 34
        }

        MouseArea {
            id: anterior2
            x: 365
            y: 439
            width: 35
            height: 34
        }

        MouseArea {
            id: mouseArea9
            x: 410
            y: 438
            width: 35
            height: 34
        }

        MouseArea {
            id: mouseArea10
            x: 456
            y: 438
            width: 35
            height: 34
        }

        MouseArea {
            id: rec
            x: 500
            y: 439
            width: 35
            height: 34
        }



        Text {
            id: menu
            x: 60
            y: 378
            width: 70
            height: 20
            text: qsTr("Menús")
            font.family: "Arial"
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: 12
        }

        Text {
            id: contraste
            x: 140
            y: 378
            width: 70
            height: 20
            text: qsTr("Contraste")
            font.family: "Arial"
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: 12
        }

        Text {
            id: siguiente
            x: 220
            y: 378
            width: 70
            height: 20
            text: qsTr("Siguiente")
            visible: false
            font.family: "Arial"
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: 12
        }

        Text {
            id: anterior
            x: 300
            y: 378
            width: 70
            height: 20
            text: qsTr("Anterior")
            visible: false
            font.family: "Arial"
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: 12
        }

        Text {
            id: averia
            x: 380
            y: 378
            width: 70
            height: 20
            text: qsTr("Avería")
            visible: true
            font.family: "Arial"
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: 12
        }

        Text {
            id: reconocer
            x: 460
            y: 378
            width: 70
            height: 20
            text: qsTr("Reconocer")
            visible: false
            font.family: "Arial"
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: 12
        }


   // GENERAR Repeater SOBRE LA X COMENZANDO EN 74 CADA VER BIEN POR QUE ES
        //CADA 2 COCHES QUE SE MANTIENE EL VALOR LUEGO CAMBIA



        Text {
            id: coche1
            x: 74
            y: 117
            width: 60
            height: 20
            text: qsTr("M 6017")
            font.family: "Arial"
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: 12
        }

        Text {
            id: coche2
            x: 138
            y: 117
            width: 60
            height: 20
            text: qsTr("M 6018")
            font.family: "Arial"
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: 12
        }

        Text {
            id: coche3
            x: 233
            y: 117
            width: 60
            height: 20
            text: qsTr("M 6003")
            font.family: "Arial"
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: 12
        }

        Text {
            id: coche4
            x: 297
            y: 117
            width: 60
            height: 20
            text: qsTr("M 6004")
            font.family: "Arial"
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: 12
        }

        Text {
            id: coche5
            x: 393
            y: 117
            width: 60
            height: 20
            text: qsTr("M 6015")
            font.family: "Arial"
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: 12
        }

        Text {
            id: coche6
            x: 456
            y: 117
            width: 60
            height: 20
            text: qsTr("M 6016")
            font.family: "Arial"
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: 12
        }


//VER SI VALE LA PENA MODIFICAR SON SOLO DOS ME DICEN EN DONDE ESTA EL MOTORMAN


        Image {
            id: image2
            x: 57
            y: 98
            width: 16
            height: 54
            objectName:"actualtrainstart"
            fillMode: Image.PreserveAspectFit
            source: "resources/sicas_azul.png"
        }


        Image {
            id: image4
            x: 520
            y: 98
            width: 16
            height: 53
            visible: false
            objectName:"actualtrainend"
            fillMode: Image.PreserveAspectFit
            source: "resources/sicas_azul.png"
        }


        // GENERAR UN REPEATER MODIFICANDO LA X CADA 80 COMENZANDO DE 60







   /*  Image {
            id: f1
            x: 54
            y: 126
            width: 19
            height: 23
            opacity: 1
            sourceSize.height: 38
            sourceSize.width: 28
            objectName:"failure1"
            fillMode: Image.PreserveAspectFit
            source: "resources/sicas_f.png"
        }

    Image {
        id: f2
        x: 199
        y: 104
        width: 19
        height: 23
        sourceSize.width: 28
        sourceSize.height: 38
        objectName:"failure2"
        source: "resources/sicas_f.png"
        opacity: 1
        fillMode: Image.PreserveAspectFit
    }

    Image {
        id: f3
        x: 215
        y: 126
        width: 19
        height: 23
        sourceSize.width: 28
        sourceSize.height: 38
        objectName:"failure3"
        source: "resources/sicas_f.png"
        opacity: 1
        fillMode: Image.PreserveAspectFit
    }

    Image {
        id: f4
        x: 358
        y: 104
        width: 19
        height: 23
        sourceSize.width: 28
        sourceSize.height: 38
        objectName:"failure4"
        source: "resources/sicas_f.png"
        opacity: 1
        fillMode: Image.PreserveAspectFit
    }

    Image {
        id: f5
        x: 375
        y: 126
        width: 19
        height: 23
        sourceSize.width: 28
        sourceSize.height: 38
        objectName:"failure5"
        source: "resources/sicas_f.png"
        opacity: 1
        fillMode: Image.PreserveAspectFit
    }

    Image {
        id: f6
        x: 518
        y: 101
        width: 19
        height: 23
        sourceSize.width: 28
        sourceSize.height: 38
        objectName:"failure6"
        source: "resources/sicas_f.png"
        opacity: 1
        fillMode: Image.PreserveAspectFit
    }*/

    Text {
        id: tren
        x: 47
        y: 63
        width: 60
        height: 20
        text: qsTr("Tren: X")
        font.bold: true
        font.family: "Arial"
        font.pixelSize: 13
        horizontalAlignment: Text.AlignHCenter
    }

    Text {
        id: linea
        x: 134
        y: 63
        width: 60
        height: 20
        text: qsTr("Linea: X")
        font.bold: true
        font.family: "Arial"
        font.pixelSize: 13
        horizontalAlignment: Text.AlignHCenter
    }

    Text {
        id: destino
        x: 269
        y: 63
        width: 60
        height: 20
        text: qsTr("Destino: X")
        font.bold: true
        font.pixelSize: 14
        font.family: "Arial"
        horizontalAlignment: Text.AlignHCenter
    }

    Text {
        id: agente
        x: 411
        y: 63
        width: 99
        height: 20
        text: qsTr("N° Agente: X")
        font.family: "Arial"
        font.pixelSize: 14
        horizontalAlignment: Text.AlignHCenter
        font.bold: true
    }

    Text {
        id: panelS
        x: 233
        y: 45
        width: 137
        height: 20
        text: qsTr("Panel SICAS S6000")
        font.pixelSize: 13
        font.family: "Arial"
        horizontalAlignment: Text.AlignHCenter
        font.bold: true
    }

 //TEXTO CAMBIA LA Y PARA EL ERROR




 /*   Text {
        id: p1error
        x: 84
        y: 173
        width: 114
        height: 14
        text: qsTr(" ")
        horizontalAlignment: Text.AlignHCenter
        font.family: "Arial"
        font.pixelSize: 12
    }




    Text {
        id: p2error
        x: 84
        y: 193
        width: 114
        height: 14
        text: qsTr(" ")
        horizontalAlignment: Text.AlignHCenter
        font.family: "Arial"
        font.pixelSize: 12
    }

    Text {
        id: p3error
        x: 84
        y: 215
        width: 114
        height: 14
        text: qsTr(" ")
        horizontalAlignment: Text.AlignHCenter
        font.family: "Arial"
        font.pixelSize: 12
    }

    Text {
        id: p4error
        x: 84
        y: 236
        width: 114
        height: 14
        text: qsTr(" ")
        horizontalAlignment: Text.AlignHCenter
        font.family: "Arial"
        font.pixelSize: 12
    }

    Text {
        id: p5error
        x: 84
        y: 258
        width: 114
        height: 14
        text: qsTr(" ")
        horizontalAlignment: Text.AlignHCenter
        font.family: "Arial"
        font.pixelSize: 12
    }
*/


    Text {
        id: sicassinerror
        x: 86
        y: 212
        width: 426
        height: 37
        text: qsTr("Composición sin incidencias")
        z: 1
        horizontalAlignment: Text.AlignHCenter
        font.bold: true
        font.family: "Arial"
        font.pixelSize: 20
    }

 //TEXTO CAMBIA LA Y PARA LOS TRENES CON ERROR





   /* Text {
        id: p1trenes
        x: 245
        y: 173
        width: 114
        height: 14
        text: qsTr(" ")
        font.family: "Arial"
        horizontalAlignment: Text.AlignHCenter
        font.pixelSize: 12
    }

    Text {
        id: p2trenes
        x: 245
        y: 193
        width: 114
        height: 14
        text: qsTr(" ")
        font.family: "Arial"
        horizontalAlignment: Text.AlignHCenter
        font.pixelSize: 12
    }


    Text {
        id: p3trenes
        x: 245
        y: 215
        width: 114
        height: 14
        text: qsTr(" ")
        font.family: "Arial"
        horizontalAlignment: Text.AlignHCenter
        font.pixelSize: 12
    }

    Text {
        id: p4trenes
        x: 245
        y: 236
        width: 114
        height: 14
        text: qsTr(" ")
        font.family: "Arial"
        horizontalAlignment: Text.AlignHCenter
        font.pixelSize: 12
    }
    Text {
        id: p5trenes
        x: 245
        y: 258
        width: 114
        height: 14
        text: qsTr(" ")
        font.family: "Arial"
        horizontalAlignment: Text.AlignHCenter
        font.pixelSize: 12
    }
*/
 //LETRA QUE DETERINA LA IMPORTANCIA HACER REPEATER





  /*
    Text {
        id: p1letra
        x: 410
        y: 173
        width: 114
        height: 14
        text: qsTr(" ")
        font.family: "Arial"
        horizontalAlignment: Text.AlignHCenter
        font.pixelSize: 12
    }
    Text {
        id: p2letra
        x: 410
        y: 193
        width: 114
        height: 14
        text: qsTr(" ")
        font.family: "Arial"
        horizontalAlignment: Text.AlignHCenter
        font.pixelSize: 12
    }



    Text {
        id: p3letra
        x: 410
        y: 215
        width: 114
        height: 14
        text: qsTr(" ")
        font.family: "Arial"
        horizontalAlignment: Text.AlignHCenter
        font.pixelSize: 12
    }


    Text {
        id: p4letra
        x: 410
        y: 236
        width: 114
        height: 14
        text: qsTr(" ")
        font.family: "Arial"
        horizontalAlignment: Text.AlignHCenter
        font.pixelSize: 12
    }



    Text {
        id: p5letra
        x: 410
        y: 258
        width: 114
        height: 14
        text: qsTr(" ")
        font.family: "Arial"
        horizontalAlignment: Text.AlignHCenter
        font.pixelSize: 12
    }*/

    //GUION DE LAS PUERTAS HACER REPEATER

    Image {
        id: puerta1c1
        x: 76
        y: 105
        width: 10
        height: 2
        visible: true
        source: "resources/sicas_doors.png"
    }

    Image {
        id: puerta2c1
        x: 91
        y: 105
        width: 10
        height: 1
        source: "resources/sicas_doors.png"
    }

    Image {
        id: puerta3c1
        x: 106
        y: 105
        width: 10
        height: 1
        source: "resources/sicas_doors.png"
    }

    Image {
        id: puerta4c1
        x: 120
        y: 105
        width: 10
        height: 1
        source: "resources/sicas_doors.png"
    }

    Image {
        id: puerta5c1
        x: 76
        y: 146
        width: 10
        height: 1
        source: "resources/sicas_doors.png"
    }

    Image {
        id: puerta6c1
        x: 91
        y: 146
        width: 10
        height: 1
        source: "resources/sicas_doors.png"
    }

    Image {
        id: puerta7c1
        x: 106
        y: 146
        width: 10
        height: 1
        source: "resources/sicas_doors.png"
    }

    Image {
        id: puerta8c1
        x: 120
        y: 146
        width: 10
        height: 1
        source: "resources/sicas_doors.png"
    }

    Image {
        id: puerta1c2
        x: 140
        y: 105
        width: 10
        height: 1
        source: "resources/sicas_doors.png"
    }

    Image {
        id: puerta2c2
        x: 155
        y: 105
        width: 10
        height: 1
        source: "resources/sicas_doors.png"
    }

    Image {
        id: puerta3c2
        x: 170
        y: 105
        width: 10
        height: 1
        source: "resources/sicas_doors.png"
    }

    Image {
        id: puerta4c2
        x: 184
        y: 105
        width: 10
        height: 1
        source: "resources/sicas_doors.png"
    }

    Image {
        id: puerta5c2
        x: 140
        y: 146
        width: 10
        height: 1
        source: "resources/sicas_doors.png"
    }

    Image {
        id: puerta6c2
        x: 155
        y: 146
        width: 10
        height: 1
        source: "resources/sicas_doors.png"
    }

    Image {
        id: puerta7c2
        x: 170
        y: 146
        width: 10
        height: 1
        source: "resources/sicas_doors.png"
    }

    Image {
        id: puerta8c2
        x: 184
        y: 146
        width: 10
        height: 1
        source: "resources/sicas_doors.png"
    }

    Image {
        id: puerta1c3
        x: 237
        y: 105
        width: 10
        height: 1
        source: "resources/sicas_doors.png"
    }

    Image {
        id: puerta2c3
        x: 252
        y: 105
        width: 10
        height: 1
        source: "resources/sicas_doors.png"
    }

    Image {
        id: puerta3c3
        x: 267
        y: 105
        width: 10
        height: 1
        source: "resources/sicas_doors.png"
    }

    Image {
        id: puerta4c3
        x: 281
        y: 105
        width: 10
        height: 1
        source: "resources/sicas_doors.png"
    }

    Image {
        id: puerta5c3
        x: 237
        y: 146
        width: 10
        height: 1
        source: "resources/sicas_doors.png"
    }

    Image {
        id: puerta6c3
        x: 252
        y: 146
        width: 10
        height: 1
        source: "resources/sicas_doors.png"
    }

    Image {
        id: puerta7c3
        x: 267
        y: 146
        width: 10
        height: 1
        source: "resources/sicas_doors.png"
    }

    Image {
        id: puerta8c3
        x: 281
        y: 146
        width: 10
        height: 1
        source: "resources/sicas_doors.png"
    }

    Image {
        id: puerta1c4
        x: 301
        y: 105
        width: 10
        height: 1
        source: "resources/sicas_doors.png"
    }

    Image {
        id: puerta2c4
        x: 316
        y: 105
        width: 10
        height: 1
        source: "resources/sicas_doors.png"
    }

    Image {
        id: puerta3c4
        x: 331
        y: 105
        width: 10
        height: 1
        source: "resources/sicas_doors.png"
    }

    Image {
        id: puerta4c4
        x: 345
        y: 105
        width: 10
        height: 1
        source: "resources/sicas_doors.png"
    }

    Image {
        id: puerta5c4
        x: 301
        y: 146
        width: 10
        height: 1
        source: "resources/sicas_doors.png"
    }

    Image {
        id: puerta6c4
        x: 316
        y: 146
        width: 10
        height: 1
        source: "resources/sicas_doors.png"
    }

    Image {
        id: puerta7c4
        x: 331
        y: 146
        width: 10
        height: 1
        source: "resources/sicas_doors.png"
    }

    Image {
        id: puerta8c4
        x: 345
        y: 146
        width: 10
        height: 1
        source: "resources/sicas_doors.png"
    }

    Image {
        id: puerta1c5
        x: 396
        y: 105
        width: 10
        height: 1
        source: "resources/sicas_doors.png"
    }

    Image {
        id: puerta2c5
        x: 411
        y: 105
        width: 10
        height: 1
        source: "resources/sicas_doors.png"
    }

    Image {
        id: puerta3c5
        x: 426
        y: 105
        width: 10
        height: 1
        source: "resources/sicas_doors.png"
    }

    Image {
        id: puerta4c5
        x: 440
        y: 105
        width: 10
        height: 1
        source: "resources/sicas_doors.png"
    }

    Image {
        id: puerta5c5
        x: 396
        y: 146
        width: 10
        height: 1
        source: "resources/sicas_doors.png"
    }

    Image {
        id: puerta6c5
        x: 411
        y: 146
        width: 10
        height: 1
        source: "resources/sicas_doors.png"
    }

    Image {
        id: puerta7c5
        x: 426
        y: 146
        width: 10
        height: 1
        source: "resources/sicas_doors.png"
    }

    Image {
        id: puerta8c5
        x: 440
        y: 146
        width: 10
        height: 1
        source: "resources/sicas_doors.png"
    }

    Image {
        id: puerta1c6
        x: 458
        y: 105
        width: 10
        height: 1
        source: "resources/sicas_doors.png"
    }

    Image {
        id: puerta2c6
        x: 475
        y: 105
        width: 10
        height: 1
        source: "resources/sicas_doors.png"
    }

    Image {
        id: puerta3c6
        x: 490
        y: 105
        width: 10
        height: 1
        source: "resources/sicas_doors.png"
    }

    Image {
        id: puerta4c6
        x: 504
        y: 105
        width: 10
        height: 1
        source: "resources/sicas_doors.png"
    }

    Image {
        id: puerta5c6
        x: 460
        y: 146
        width: 10
        height: 1
        source: "resources/sicas_doors.png"
    }

    Image {
        id: puerta6c6
        x: 475
        y: 146
        width: 10
        height: 1
        source: "resources/sicas_doors.png"
    }

    Image {
        id: puerta7c6
        x: 490
        y: 146
        width: 10
        height: 1
        source: "resources/sicas_doors.png"
    }

    Image {
        id: puerta8c6
        x: 504
        y: 146
        width: 10
        height: 1
        source: "resources/sicas_doors.png"
    }

    Image {
        id: imgerror
        x: 62
        y: 171
        width: 465
        height: 115
        opacity: 0.6
        source: "resources/sicas_imgError.png"
    }
    }
    Image {
        id: image10
        x: 101
        y: -334
        width: 510
        height: 392
        fillMode: Image.PreserveAspectFit
        objectName:"glassmac"

        source: "resources/sicas_glass.png"
    }

  /*  SequentialAnimation {
        id: blinkAnimationf1
        loops: Animation.Infinite

        PropertyAnimation {
            properties: "opacity"
            to: 0
            duration: 200
            target: f1
        }
        PauseAnimation { duration: 400 }
        PropertyAnimation {
            properties: "opacity"
            to: 1
            duration: 200
            target: f1
        }
        PauseAnimation { duration: 400 }
    }

    SequentialAnimation {
        id: blinkAnimationf2
        loops: Animation.Infinite

        PropertyAnimation {
            properties: "opacity"
            to: 0
            duration: 200
            target: f2
        }
        PauseAnimation { duration: 400 }
        PropertyAnimation {
            properties: "opacity"
            to: 1
            duration: 200
            target: f2
        }
        PauseAnimation { duration: 400 }
    }

    SequentialAnimation {
        id: blinkAnimationf3
        loops: Animation.Infinite

        PropertyAnimation {
            properties: "opacity"
            to: 0
            duration: 200
            target: f3
        }
        PauseAnimation { duration: 400 }
        PropertyAnimation {
            properties: "opacity"
            to: 1
            duration: 200
            target: f3
        }
        PauseAnimation { duration: 400 }
    }

    SequentialAnimation {
        id: blinkAnimationf4
        loops: Animation.Infinite

        PropertyAnimation {
            properties: "opacity"
            to: 0
            duration: 200
            target: f4
        }
        PauseAnimation { duration: 400 }
        PropertyAnimation {
            properties: "opacity"
            to: 1
            duration: 200
            target: f4
        }
        PauseAnimation { duration: 400 }
    }

    SequentialAnimation {
        id: blinkAnimationf5
        loops: Animation.Infinite

        PropertyAnimation {
            properties: "opacity"
            to: 0
            duration: 200
            target: f5
        }
        PauseAnimation { duration: 400 }
        PropertyAnimation {
            properties: "opacity"
            to: 1
            duration: 200
            target: f5
        }
        PauseAnimation { duration: 400 }
    }

    SequentialAnimation {
        id: blinkAnimationf6
        loops: Animation.Infinite

        PropertyAnimation {
            properties: "opacity"
            to: 0
            duration: 200
            target: f1
        }
        PauseAnimation { duration: 400 }
        PropertyAnimation {
            properties: "opacity"
            to: 1
            duration: 200
            target: f1
        }
        PauseAnimation { duration: 400 }
    }*/



function startBlinkFailure(val) {

    //failure[val].blinkAnimation.start();
   /* if (val===1)
        blinkAnimationf1.start();
    if (val===2)
        blinkAnimationf2.start();
    if (val===3)
        blinkAnimationf3.start();
    if (val===4)
        blinkAnimationf4.start();
    if (val===5)
        blinkAnimationf5.start();
    if (val===6)
        blinkAnimationf6.start();*/
}


    function stopBlinkFailure(val) {
      /*  if (val===1)
            blinkAnimationf1.stop();
        if (val===2)
            blinkAnimationf2.stop();
        if (val===3)
            blinkAnimationf3.stop();
        if (val===4)
            blinkAnimationf4.stop();
        if (val===5)
            blinkAnimationf5.stop();
        if (val===6)
            blinkAnimationf6.stop();
*/

    }



 function changeText(error1,trenes2,letra3,val){


     console.log("1: " + error1 + " 2: " + trenes2 + " 3: " + letra3 + " v: " +val)
         sicassinerror.opacity=0;
         textoError[val].opacity =1;
         textoError[val].text=error1;
         trenConFalla[val].opacity =1;
         trenConFalla[val].text = trenes2;
         prioridadLetra[val].opacity =1;
         prioridadLetra[val].text=letra3;

  }




 Repeater {
     model: 6
     delegate: Image {
         id: f
         width: 15
         height: 23
         opacity: 1
         x:getXFailure(Math.floor(index/2),index)
         y:getYFailure(Math.floor(index/2),index)

         source: "resources/sicas_f.png"
         antialiasing: true
         smooth: true

         states: [
             State {
                 name: "on"
                 PropertyChanges { target: f; opacity: 1;}
             },
             State {
                 name: "off"
                 PropertyChanges { target: f; opacity: 0;}
             }
         ]

         transitions: Transition {
             PropertyAnimation { properties: "opacity"; duration: 100 }
         }

       /*  SequentialAnimation {
             id: blinkAnimation
             loops: Animation.Infinite

             PropertyAnimation {
                 properties: "opacity"
                 to: 0
                 duration: 200
                 target: f
             }
             PauseAnimation { duration: 200 }
             PropertyAnimation {
                 properties: "opacity"
                 to: 1
                 duration: 200
                 target: f
             }
             PauseAnimation { duration: 200 }
         }*/

     }
     onItemAdded: failure[index] = item
 }


 function getXFailure(index,cantf){
     if (cantf % 2 ==0){
      //   console.log("valor de X IMPAR v para F ---->", (54+(160*index)),"  valor index  ",index);
         return (57+(160*index));
      }// par
   //  console.log("valor de x PAR v para F---->", (199+(160*index)), "  valor index  ",index) ;
     return(199+(160*index)); // impar
 }

    function getYFailure(p,cantf){
       if (cantf % 2 ==0)
         return (126);
     return (104);
 }



 Repeater {
     model: 5
     Text {
         id: textoE
         width: 114
         height: 14
         opacity: 1
         x: getXTextError(index)
         y: getYTextError(index)
         text: qsTr(" ")
         horizontalAlignment: Text.AlignHCenter
         font.family: "Arial"
         font.pixelSize: 12
         states: [
             State {
                 name: "on"
                 PropertyChanges { target: textoE; opacity: 1;}
             },
             State {
                 name: "off"
                 PropertyChanges { target: textoE; opacity: 0;}
             }
         ]

         transitions: Transition {
             PropertyAnimation { properties: "opacity"; duration: 200 }
         }
     }
     onItemAdded: textoError[index] = item
 }
 function getXTextError(p){
     //    console.log("valor de x PAR v texto ---->", 84, "  valor index  ",p);
         return(84)
   }
 function getYTextError(p){
    // console.log("valor de Y IMPAR v texto ---->", (173+(20*p)), "  valor index  ",p);

         return (173+(20*p))
 }


 Repeater {
     model: 5
     Text {
         id: trenesE
         width: 114
         height: 14
         opacity: 1
         x: getXTrenesError(index)
         y: getYTrenesError(index)
         text: qsTr(" ")
         horizontalAlignment: Text.AlignHCenter
         font.family: "Arial"
         font.pixelSize: 12
         states: [
             State {
                 name: "on"
                 PropertyChanges { target: trenesE; opacity: 1;}
             },
             State {
                 name: "off"
                 PropertyChanges { target: trenesE; opacity: 0;}
             }
         ]

         transitions: Transition {
             PropertyAnimation { properties: "opacity"; duration: 200 }
         }
     }
     onItemAdded: trenConFalla[index] = item
 }
 function getXTrenesError(p){
   //  console.log("valor de x PAR v trenes ---->", 245);

         return(245)
   }
 function getYTrenesError(p){
    // console.log("valor de Y IMPAR v trenes ---->", (173+(20*p)), "  valor index  ",p);

         return (173+(20*p))
 }



 //REPEAT QUE GENERA CADA UNA DE LAS LETRAS


 Repeater {
     model: 5
     Text {
         id: prioLetra
         width: 114
         height: 14
         opacity: 1
         x: getXPrioLetra(index)
         y: getYPrioLetra(index)
         text: qsTr(" ")
         horizontalAlignment: Text.AlignHCenter
         font.family: "Arial"
         font.pixelSize: 12
         states: [
             State {
                 name: "on"
                 PropertyChanges { target: prioLetra; opacity: 1;}
             },
             State {
                 name: "off"
                 PropertyChanges { target: prioLetra; opacity: 0;}
             }
         ]

         transitions: Transition {
             PropertyAnimation { properties: "opacity"; duration: 200 }
         }
     }
     onItemAdded: prioridadLetra[index] = item
 }
 function getXPrioLetra(p){
    // console.log("valor de x PAR v para Letra ---->", 410, "  valor index  ",p);

         return(410)
   }
 function getYPrioLetra(p){
   //  console.log("valor de Y IMPAR v letra ---->", (173+(20*p)), "  valor index  ",p);

         return (173+(20*p))
 }


}

