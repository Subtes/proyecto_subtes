import QtQuick 2.0
Rectangle {
    id: borderBackground
    width: 617
    height: 497
    radius: 0
    border.color: "#534848"
    border.width: 7

    property double currentValue: 0
    property double maxValue: 100
    property double minValue: -100
    property double maxAngle: 0
    property double offsetAngle: 0
    property double originX: width/2
    property double originY: height/2

    Image {
        id: background
        x: 4
        y: 4
        width: 610
        height: 490
        fillMode: Image.PreserveAspectFit
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
            x: 148
            y: 274
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
            text: qsTr("2500")
            font.bold: true
            font.pixelSize: 13
        }

        Text {
            id: voltimetrodigital2
            x: 245
            y: 311
            text: qsTr("2500")
            font.bold: true
            font.pixelSize: 13
        }

        Text {
            id: amperimetrodigital
            x: 426
            y: 283
            text: qsTr("400")
            font.bold: true
            font.pixelSize: 13
        }


        Rectangle {
            id: needle
            objectName: "needle"
            x: 150
            y: 291
            width: 5
            height: 60
            color: "#080505"
            rotation: 44
            transformOrigin: Item.Top
            border.color: "#00000000"
            radius: 2
            z: 1
            scale: 1.2
            border.width: 0
            smooth:true
            property double speed: 22;
            transform: Rotation{
                id: rot
                origin.x: borderBackground.originX
                origin.y: borderBackground.originY
                angle: 0
                Behavior on angle {
                    PropertyAnimation{
                        duration : 400
                        easing {type: Easing.OutQuad}
                    }
                }
            }
        }

       Rectangle {
            id: rectangle1
            x: 316
            y: 211
            width: 13
            height: 166
            color: "#000000"
            radius: 0
            antialiasing: false
            z: 0
            rotation: 0
            transformOrigin: Item.Bottom
            scale: 1
            border.width: 0
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
            id: rectangle2
            x: 341
            y: 211
            width: 13
            height: 168
            color: "#000000"
            rotation: 0
            transformOrigin: Item.Top
            border.width: 0
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
            id: rectangle3
            x: 490
            y: 210
            width: 14
            height: 85
            color: "#000000"
            rotation: 0
            border.width: 0
            transformOrigin: Item.Top
        }


        function updateNeedle(valueIN) {
            if(valueIN<minValue){
                valueIN=minValue
            }else if(valueIN>maxValue){
                valueIN=maxValue
            }
            console.log("entramos a la velocidad")
            currentValue = (valueIN/maxValue)*maxAngle + offsetAngle
            rot.angle = currentValue
            return "ok"
        }

    function updateDigitalVelocity(speed){
        velocimetrodigital.text=speed;

    }

    function updateDigitalVoltimetroLeft(volt){
        voltimetrodigital1.text=volt;

    }

    function updateDigitalVoltimetroRight(volt){
        voltimetrodigital2.text=volt;

    }
    function updateDigitalAmperimetro(amp){
         amperimetrodigital.text=amp;

    }
}

