import QtQuick 2.0

Rectangle {
    id: borderBackground
    width: 617
    height: 497
    radius: 0
    border.color: "#534848"
    border.width: 7
    property variant trainsdoors: []
    property double currentValue: 0
    property double maxValue: 100
    property double minValue: -100
    property double maxAngle: 0
    property double offsetAngle: 0
    property double originX: width/2
    property double originY: height/2
    
    //variables repeater puertas diferentes offset

    property double offset_train: 41
    property double offset_init_doors: 61
    property double offset_between_trains: 30
    property double offset_space_between_doors: 21
    property double doors_X_wagon: 8
    property double doors_X_side: 4
    property double number_of_sides_per_wagon: 2
    property double pos_doors_up: 87
    property double pos_doors_down: 117

    //max value amper, velocity, voltimetre
    property double escala_maxima_volt: 2500
    property double escala_maxima_amper: 400
    property double offset_needle_effort: 86
    property double offset_needle_volt: 170
    property double offset_start_angle:44
    property double offset_rot_needle:2.27
    
    
    
    
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

        Rectangle {
            id: wagon1
            x: 11
            y: 100
            width: 18
            height: 17
            color: "#ffffff"
            radius: 8
            z: 2

            Text {
                id: wagontext1
                x: 5
                y: 2
                width: 13
                height: 14
                text: qsTr("1")
                z: 3
                font.family: "Arial"
                font.pixelSize: 12
            }
        }

        Rectangle {
            id: wagon2
            x: 582
            y: 100
            width: 18
            height: 18
            color: "#ffffff"
            radius: 8
            z: 1

            Text {
                id: wagontext2
                x: 5
                y: 2
                width: 13
                height: 14
                text: qsTr("2")
                z: 2
                font.pixelSize: 12
            }
        }

        Image {
            id: convertidorauxiliarleft
            x: 64
            y: 155
            width: 38
            height: 38
            source: "resources/alstom_convertidor_auxiliar_1_operativo.png"
        }

        Image {
            id: pantografoleft
            x: 130
            y: 155
            width: 38
            height: 38
            source: "resources/alstom_pantografo_para_arriba.png"
        }

        Image {
            id: pceleft
            x: 174
            y: 155
            width: 38
            height: 38
            source: "resources/alstom_PCE_operativo.png"
        }

        Image {
            id: pcecenterleft
            x: 239
            y: 155
            width: 38
            height: 38
            source: "resources/alstom_PCE_operativo.png"
        }

        Image {
            id: contactordetransferencia
            x: 289
            y: 155
            width: 38
            height: 38
            source: "resources/alstom_contactor_de_transferencia_abierto.png"
        }

        Image {
            id: pcecenterright
            x: 335
            y: 155
            width: 38
            height: 38
            source: "resources/alstom_PCE_operativo.png"
        }

        Image {
            id: pceright
            x: 404
            y: 155
            width: 38
            height: 38
            source: "resources/alstom_PCE_operativo.png"
        }

        Image {
            id: pantografoder
            x: 448
            y: 155
            width: 38
            height: 38
            source: "resources/alstom_pantografo_para_arriba.png"
        }

        Image {
            id: convertidorauxiliarder
            x: 508
            y: 155
            width: 38
            height: 38
            source: "resources/alstom_convertidor_auxiliar_1_operativo.png"
        }

        Image {
            id: half_moon_change_active2
            x: 576
            y: 80
            width: 32
            height: 58
            z: 0
            opacity: 0
            source: "resources/alstom_medialuna_cabina2.png"
        }

        Image {
            id: half_moon_change_active1
            x: 2
            y: 80
            width: 32
            height: 57
            z: 0
            opacity: 1
            source: "resources/alstom_medialuna_cabina1.png"
        }

    }

    Text {
        id: velocimetrodigital
        x: 142
        y: 272
        width: 29
        height: 21
        text: qsTr("0")
        horizontalAlignment: Text.AlignHCenter
        z: 3
        font.bold: true
        font.pixelSize: 14
    }
    
    Text {
        id: kilometros
        x: 139
        y: 293
        text: qsTr("km/h")
        font.bold: true
        z: 3
        font.pixelSize: 13
    }
    
    Text {
        id: voltimetrodigital1
        x: 244
        y: 284
        width: 39
        height: 16
        text: qsTr("0")
        horizontalAlignment: Text.AlignHCenter
        font.bold: true
        font.pixelSize: 13
    }
    
    Text {
        id: voltimetrodigital2
        x: 244
        y: 311
        width: 39
        height: 16
        text: qsTr("0")
        horizontalAlignment: Text.AlignHCenter
        font.bold: true
        font.pixelSize: 13
    }
    
    Text {
        id: digitaleffort
        x: 425
        y: 283
        width: 31
        height: 16
        text: qsTr("0")
        horizontalAlignment: Text.AlignHCenter
        font.bold: true
        font.pixelSize: 13
    }
    
    
    Rectangle {
        id: barvoltimetreleft
        x: 317
        y: 212
        width: 13
        height: 168
        color: "#000000"
        antialiasing: true
        transform: Scale { id:changebarvoltimetreleft ;origin.x: 0; origin.y: 170; yScale:0}
    }
    
    Rectangle {
        id: rectangle1
        x: 76
        y: 208
        width: 162
        height: 162
        color: "#00ffffff"
        radius: 80
        border.color: "#00000000"
        
        Rectangle {
            id: circulovelocidad
            x: 51
            y: 53
            width: 60
            height: 60
            color: "#ffffff"
            radius: 30
            transformOrigin: Item.Center
            scale: 0.9
            z: 2
            border.width: 3
        }
        
        Rectangle {
            id: needle
            objectName: "needle"
            x: 79
            y: 81
            width: 4
            height: 60
            color: "#080505"
            rotation: 90
            transformOrigin: Item.Top
            border.color: "#00000000"
            radius: 2
            z: 1
            smooth:true
            scale: 1.2
            property double speed: 22;
         }
    }
    
    

    function updateNeedle(valueIN) {
        needle.rotation=(valueIN *offset_rot_needle)+(offset_start_angle);
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
        antialiasing: true
        smooth: true
        font.pixelSize: 13
    }
    
    Rectangle {
        id: barvoltimetreright
        x: 341
        y: 212
        width: 13
        height: 168
        color: "#000000"
        antialiasing: true
        smooth: true
        transform: Scale { id:changebarvoltimetreright ;origin.x: 0; origin.y: 170; yScale:0}
    }
    
    Image {
        id: needle_volt
        x: 302
        y: 375
        width: 68
        height: 13
        z: 1
        opacity: 1
        source: "resources/alstom_needle_bar.png"
        transform: Translate{id: change_needle_volt;y:0}
    }

    Rectangle {
        id: bareffort
        x: 490
        y: 212
        width: 15
        height: 84
        color: "#000000"
        transformOrigin: Item.Center
        antialiasing: true
        smooth: true
        transform: Scale { id:changebareffort ;origin.x: 0; origin.y: 85; yScale:0}
     }

    Image {
        id: needle_effort
        x: 483
        y: 291
        width: 35
        height: 13
        z: 1
        opacity: 1
        transform: Translate  {id:change_needle_effort; y:0}

        source: "resources/alstom_needle_bar.png"
    }

    Text {
        id: notationeffort
        x: 456
        y: 283
        text: qsTr("KN")
        font.bold: true
        font.pixelSize: 13
    }
    
    
    function updateDigitalVelocity(speed){
        velocimetrodigital.text=speed;
    }
    
    function updateDigitalVoltimetroLeft(volt){
        voltimetrodigital1.text=volt;
        changebarvoltimetreleft.yScale = (volt/escala_maxima_volt);
        change_needle_volt.y = (-(volt*offset_needle_volt)/escala_maxima_volt);
    }
    
    function updateDigitalVoltimetroRight(volt){
        voltimetrodigital2.text=volt;
        changebarvoltimetreright.yScale = (volt/escala_maxima_volt);
        change_needle_volt.y = (-(volt*offset_needle_volt)/escala_maxima_volt);
        
    }
    function updateDigitalAmperimetro(amp){
        digitaleffort.text=amp;
        changebareffort.yScale= (amp/escala_maxima_amper);
        change_needle_effort.y = (-(amp * offset_needle_effort)/escala_maxima_amper);
    }
    
    
    //REPEAT QUE GENERA en el renglon en la viuaizacion del tren
    



    Repeater {
        model: 48
        delegate: Image {
            id: doors_train
            width: 18
            height: 22
            opacity: 1
            x: getXdoors_train(index)
            y: getYdoors_train(index)
            source: "resources/alstom_puertas_cerradas_bloqueadas.png"
            antialiasing: true
            smooth: true
            states: [
                State {
                    name: "puerta_abierta"
                    PropertyChanges { target: doors_train;source:"resources/alstom_puerta_abierta.png"}
                },
                State {
                    name: "puertas_entreabiertas"
                    PropertyChanges { target: doors_train;source:"resources/alstom_puertas_entreabiertas.png"}

                },
                State {
                    name: "puertas_cerradas"
                    PropertyChanges { target: doors_train;source:"resources/alstom_puertas_cerradas.png"}
                },
                State {
                    name: "puertas_cerradas_bloqueadas"
                    PropertyChanges { target: doors_train;source:"resources/alstom_puertas_cerradas_bloqueadas.png"}
                },
                State {
                    name: "puerta_aislada"
                    PropertyChanges { target: doors_train;source:"resources/alstom_puerta_aislada.png"}
                },
                State {
                    name: "puerta_conobstaculo"
                    PropertyChanges { target: doors_train;source:"resources/alstom_puerta_conobstaculo.png"}
                }
            ]
            
            transitions: Transition {
                PropertyAnimation { properties: "opacity"; duration: 100 }
            }
        }
        onItemAdded: trainsdoors[index] = item
    }

    
    function getXdoors_train(p){
        var nroCoche = Math.floor(p/doors_X_wagon);
        var valor = ((offset_train)+(nroCoche*(offset_init_doors))+(offset_between_trains*nroCoche)+((p%doors_X_side)*offset_space_between_doors));
        return valor;
    }
    
    function getYdoors_train(p){
        var acum=(Math.floor(p/doors_X_side)%number_of_sides_per_wagon);
        if (acum==0)
            return (pos_doors_up);
        return(pos_doors_down);
    }

    function closedoors(valF){
        trainsdoors[valF].state = "puertas_cerradas";
    }

    function doornotclosedandnotopened(valF){
        trainsdoors[valF].state = "puertas_entreabiertas";
    }

    function opendoors(valF){
        trainsdoors[valF].state = "puerta_abierta";
    }

    function obstacledetected(valF){
        trainsdoors[valF].state = "puerta_conobstaculo";
    }

    function doorisolated(valF){
        trainsdoors[valF].state = "puerta_aislada";
    }

    function doorclosedandlocked(valF){
        trainsdoors[valF].state = "puertas_cerradas_bloqueadas";
    }

}//FIN RECTANGULO

