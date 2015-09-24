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
    property variant puertasCoche: []
    property int variablePuertas: 0
    property int valorRenglonActual: 0
    property int valorRenglonFin: 0
    property int tamArreRenglon: 0



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
        }

        MouseArea {
            id: menu2
            x: 92
            y: 438
            width: 35
            height: 34
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
            onClicked: moverSelectorSig();
        }

        MouseArea {
            id: siguiente2
            x: 274
            y: 438
            width: 35
            height: 34
            onClicked: moverSelectorSig();

        }

        MouseArea {
            id: anterior1
            x: 318
            y: 438
            width: 35
            height: 34
            onClicked: moverSelectorAnt();

        }

        MouseArea {
            id: anterior2
            x: 365
            y: 439
            width: 35
            height: 34
            onClicked: moverSelectorAnt();

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
            opacity: 0
            text: qsTr("Siguiente")
            visible: true
            font.family: "Arial"
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: 12
        }

        Text {
            id: anterior
            x: 300
            y: 378
            opacity: 0
            width: 70
            height: 20
            text: qsTr("Anterior")
            visible: true
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
            id: maquinatrenstart
            x: 57
            y: 98
            width: 16
            height: 54
            objectName:"actualtrainstart"
            fillMode: Image.PreserveAspectFit
            source: "resources/sicas_azul.png"
        }


        Image {
            id: maquinatrenend
            x: 520
            y: 98
            width: 16
            height: 53
            visible: false
            objectName:"actualtrainend"
            fillMode: Image.PreserveAspectFit
            source: "resources/sicas_azul.png"
        }


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

     //GUION DE LAS PUERTAS HACER REPEATER


    Image {
        id: imgerror
        x: 62
        y: 171
        width: 465
        height: 115
        opacity: 0.5
        source: "resources/sicas_imgError.png"
    }

    Image {
        id: glass
        x: 38
        y: 37
        opacity: 0.7
        width: 518
        height: 387
        source: "resources/sicas_glass.png"
    }

  }// FIN BACKGROUND


 function changeText(error1,trenes2,letra3,val){


     console.log("1: " + error1 + " 2: " + trenes2 + " 3: " + letra3 + " v: " +val)
         sicassinerror.opacity=0;
         textoError[val].opacity =1;
         textoError[val].text=error1;
         trenConFalla[val].opacity =1;
         trenConFalla[val].text = trenes2;
         prioridadLetra[val].opacity =1;
         prioridadLetra[val].text=letra3;
         getColorText(error1,trenes2,letra3,val);
  }

 function getColorText(error1,trenes2,letra3,val){
     if(letra3=="A"){
         textoError[val].color="red";
         trenConFalla[val].color="red";
          prioridadLetra[val].color="red";
     }

     if(letra3=="B"){
         textoError[val].color="yellow";
         trenConFalla[val].color="yellow";
          prioridadLetra[val].color="yellow";
     }
     if(letra3=="C"){
         textoError[val].color="green";
         trenConFalla[val].color="green";
          prioridadLetra[val].color="green";
 }
 }




 Repeater {
     model: 6
     delegate: Image {
         id: f
         width: 15
         height: 23
         opacity: 0
         x:getXFailure(Math.floor(index/2),index)
         y:getYFailure(Math.floor(index/2),index)
         source: "resources/sicas_f.png"
         antialiasing: true
         smooth: true

         states: [
             State {
                 name: "con"
                 PropertyChanges { target: f; opacity: 1;}
             },
             State {
                 name: "des"
                 PropertyChanges { target: f; opacity: 0;}
             },
             State {
                 name: "inhab"
                 PropertyChanges { target: f; opacity: 0.5;}
             },
             State {
                 name: "blink"
                 PropertyChanges { target: blinkAnimation; running:true;}
             }
         ]

         transitions: Transition {
             PropertyAnimation { properties: "opacity"; duration: 100 }
         }

        SequentialAnimation {
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
        }

     }
     onItemAdded: failure[index] = item
 }


 function getXFailure(index,cantf){
     if (cantf % 2 ==0){
         return (57+(160*index));
      }// par
     return(199+(160*index)); // impar
 }

    function getYFailure(p,cantf){
       if (cantf % 2 ==0)
         return (126);
     return (104);
 }

 function turnOffFailure(valF){
    failure[valF].state = "des";
 }

 function turnOnFailure(valF){
     failure[valF].state = "con";

 }
 function turnBlinkFailure(valF){
     failure[valF].state = "blink";

 }
 function turnInhabFailure(valF){
     failure[valF].state = "inhab";

 }

// REPEATER DE PANTALLA SICAS
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
         horizontalAlignment: Text.AlignLeft
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
         return(84)
   }
 function getYTextError(p){
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
         horizontalAlignment: Text.AlignLeft
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
         return(245)
 }

 function getYTrenesError(p){
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
         horizontalAlignment: Text.AlignLeft
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
         return(410)
 }

 function getYPrioLetra(p){
         return (173+(20*p))
 }


 Repeater {
     model: 48
     Image {
         id: puertastren
         width: 12
         height: 2
         opacity: 0
         x: getXpuertastren(index)
         y: getYpuertastren(index)
         source: "resources/sicas_doors.png"
         antialiasing: true
         smooth: true
         states: [
             State {
                 name: "con"
                 PropertyChanges { target: puertastren; opacity: 1;}
             },
             State {
                 name: "des"
                 PropertyChanges { target: puertastren; opacity: 0;}
             }
         ]

         transitions: Transition {
             PropertyAnimation { properties: "opacity"; duration: 500 }
         }
     }
     onItemAdded: puertasCoche[index] = item
 }

 Image {
     id: sicas_renglon
     x: 75
     y: 176
     width: 426
     height: 13
     opacity: 0.5
     source: "resources/sicas_renglon.png"
 }

 function getXpuertastren(p){
   var nroCoche = Math.floor(p/8);
   return((75)+(nroCoche*63)+(34*Math.floor(nroCoche/2))+((p%4)*15));
 }

 function getYpuertastren(p){
    var acum=(Math.floor(p/4)%2);
     if (acum==0)
         return (105);
     return(145);
 }
 function turnOffDoors(valF){
    puertasCoche[valF].state = "des";
    }

 function turnOnDoors(valF){
     puertasCoche[valF].state = "con";
    }
 function actualizarTamArreRenglon(valorFin,tamIndiceArre){
     valorRenglonFin=valorFin;
     tamArreRenglon=tamIndiceArre;
     movimientoCursor();
 }

function movimientoCursor(){
      if((valorRenglonFin > 0)&&(valorRenglonActual<tamArreRenglon)){
           siguiente.opacity=1;
            }
       else{
            siguiente.opacity=0;}
       if((valorRenglonActual > 0) && (valorRenglonActual<=tamArreRenglon)){
            anterior.opacity=1;}
       else{
            anterior.opacity=0;}

}

function moverSelectorSig(){
    if((sicas_renglon.y <256)&&(valorRenglonActual<=valorRenglonFin)){
        sicas_renglon.y= sicas_renglon.y +20;
        valorRenglonActual++;
        movimientoCursor();

    }
}
function moverSelectorAnt(){
    if(sicas_renglon.y >176){
        sicas_renglon.y= sicas_renglon.y -20;
        valorRenglonActual--;
        movimientoCursor();
    }
}



}//FIN RECTANGLO
