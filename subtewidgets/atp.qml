import QtQuick 2.0

Rectangle {
    width: 1024
    height: 768
    color: "#00000000"
    radius: 0
    border.color: "#00000000"

    Image {
        id: imageBckAtp
        x: 0
        y: 0
        width: 1024
        height: 768
        fillMode: Image.PreserveAspectFit
        sourceSize.height: 480
        sourceSize.width: 640
        clip: false
        source: "resources/ATP_FONDO1024_Resize.PNG"

        Item {
            id: iCMC
            x: 176
            y: 185
            width: 95
            height: 46
            Image {
                id: imCMC
                x: 0
                y: 0
                width: 95
                height: 46
                fillMode: Image.Stretch
                opacity: 1
                source: "resources/ATPoCMC.PNG"
            }
        }

        Item {
            id: iFserv
            x: 176
            y: 224
            width: 95
            height: 46

            Image {
                id: imFServ
                x: 0
                y: 0
                width: 95
                height: 46
                opacity: 1
                fillMode: Image.Stretch
                source: "resources/ATPoFoSERV.PNG"
            }
        }

        Item {
            id: iCL
            x: 97
            y: 184
            width: 95
            height: 46
            Image {
                id: imCL
                x: 0
                y: 0
                width: 95
                height: 46
                fillMode: Image.Stretch
                opacity: 1
                source: "resources/ATPoCL.PNG"
            }
        }

        Item {
            id: iFrenoUrg
            x: 256
            y: 224
            width: 95
            height: 46
            Image {
                id: imFurg
                x: 0
                y: 0
                width: 95
                height: 46
                fillMode: Image.Stretch
                opacity: 1
                source: "resources/ATPoFreEmrg.PNG"
            }
        }

        Item {
            id: iCMC1
            x: 256
            y: 185
            width: 95
            height: 46
            Image {
                id: imCMC1
                x: 0
                y: 0
                width: 95
                height: 46
                fillMode: Image.Stretch
                opacity: 1
                source: "resources/ATPofalla.PNG"
            }
        }

        Item {
            id: iCMC2
            x: 97
            y: 224
            width: 95
            height: 46
            Image {
                id: imCMC2
                x: 0
                y: 0
                width: 95
                height: 46
                fillMode: Image.Stretch
                opacity: 1
                source: "resources/ATOoCORTE.PNG"
            }
        }

        Item {
            id: l0
            x: 102
            y: 273
            width: 100
            height: 100
            opacity: 1

            Image {
                id: image1
                x: 0
                y: 0
                width: 100
                height: 100
                source: "resources/ATP_0L.png"
            }
        }

        Item {
            id: l1
            x: 240
            y: 273
            width: 100
            height: 100
            Image {
                id: image2
                x: 0
                y: 0
                width: 100
                height: 100
                source: "resources/ATP_0L.png"
            }
            opacity: 1
        }

        Item {
            id: l2
            x: 170
            y: 273
            width: 100
            height: 100
            Image {
                id: image3
                x: 0
                y: 0
                width: 100
                height: 100
                source: "resources/ATP_0L.png"
            }
            opacity: 1
        }

        Item {
            id: s0
            x: 739
            y: 196
            width: 60
            height: 70

            Image {
                id: image4
                x: 0
                y: 0
                width: 60
                height: 70
                source: "resources/ATP_0S.png"
            }
        }

        Item {
            id: s1
            x: 784
            y: 197
            width: 60
            height: 70
            Image {
                id: image5
                x: 0
                y: 0
                width: 60
                height: 70
                source: "resources/ATP_0S.png"
            }
        }

        Item {
            id: s2
            x: 829
            y: 197
            width: 60
            height: 70
            Image {
                id: image6
                x: 0
                y: 0
                width: 60
                height: 70
                source: "resources/ATP_0S.png"
            }
        }

//        Item {
//            id: led
//            x: 374
//            y: 274
//            width: 8
//            height: 21

//            Image {
//                id: image8
//                x: 0
//                y: 0
//                width: 8
//                height: 21
//                source: "resources/ATPoLed2.png"
//            }
//        }
}
    Row {
        id: velocidad
        x: 373
        y: 346
        width: 490
        height: 23
        Repeater{
            //49
            model:posLed()
            Image {
                id: image7
                //x: 373
                //y: 274
                x: 0
                y: 0
                width: 10
                height: 23
                source: "resources/ATPoCorL.PNG"
                opacity: 1
            }
//            state:[
//                State{
//                        name:"on"
//                        PropertyChanges {
//                            target: image7; opacity:1;
//                        }
//                },
//                State{
//                        name:"off"
//                        PropertyChanges {
//                            target: image7; opacity:0;
//                        }
//                }
//             ]
           transitions: Transition{
               PropertyAnimation {
                   properties: "opacity"; duration: 200
               }
           }//transition
        }//Repeater}
    }//Row LED


  property int velTramo0: 0
  property int velTramo1: 15
  property int velTramo2: 25
  property int velTramo3: 30
  property int velTramo4: 40
  property int velTramo5: 50
  property int velTramo6: 60
  property int velTramoCL: 10


  function posLed(){
      return velTramoCL
  }
}
