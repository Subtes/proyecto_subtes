import QtQuick 2.0

Rectangle {
    id: atp
    width: 1024
    height: 768
    color: "#00000000"
    radius: 0
    border.color: "#00000000"

    property int velTramo0: 0
    property int velTramo1: 10
    property int velTramo2: 20
    property int velTramo3: 30
    property int velTramo4: 40
    property int velTramo5: 50
    property int velTramo6: 60
    property int velTramoCL: 10

    property  int  indexLed: 0
    property variant ledsSpeed: []

    property variant digitsL1: []
    property variant digitsL2: []

    function reset(){

    }

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
            id: itCMC
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
            id: itFserv
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
                opacity: 0
                fillMode: Image.Stretch
                source: "resources/ATPoFoSERV.PNG"
            }
        }

        Item {
            id: itCL
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
                opacity: 0
                source: "resources/ATPoCL.PNG"
            }
        }

        Item {
            id: itFrenoUrg
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
                opacity: 0
                source: "resources/ATPoFreEmrg.PNG"
            }
        }

        Item {
            id: itFalla
            x: 256
            y: 185
            width: 95
            height: 46
            Image {
                id: imFalla
                x: 0
                y: 0
                width: 95
                height: 46
                fillMode: Image.Stretch
                opacity: 0
                source: "resources/ATPofalla.PNG"
            }
        }

        Item {
            id: itCorte
            x: 97
            y: 224
            width: 95
            height: 46
            Image {
                id: imCorte
                x: 0
                y: 0
                width: 95
                height: 46
                fillMode: Image.Stretch
                opacity: 0
                source: "resources/ATOoCORTE.PNG"
            }
        }

        Item {
            id: l0
            x: 102
            y: 273
            width: 100
            height: 100
            //opacity: 1

            Image {
                id: iml0
                x: 0
                y: 0
                width: 100
                height: 100
                source: "resources/ATP_0L.png"
                opacity:0
            }
        }

        Item {
            id: l1
            x: 170
            y: 273
            width: 100
            height: 100
            //opacity: 1
            Image {
                id: iml1
                x: 0
                y: 0
                width: 100
                height: 100
                source: "resources/ATP_0L.png"
                opacity:0
            }
        }

        Item {
            id: l2
            x: 240
            y: 273
            width: 100
            height: 100
            //opacity: 1
            Image {
                id: iml2
                x: 0
                y: 0
                width: 100
                height: 100
                source: "resources/ATP_0L.png"
                opacity:0
            }
        }

        Item {
            id: s0
            x: 739
            y: 196
            width: 60
            height: 70
            Image {
                id: ims0
                x: 0
                y: 0
                width: 60
                height: 70
                opacity: 1
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
                id: ims1
                x: 0
                y: 0
                width: 60
                height: 70
                opacity: 1
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
                id: ims2
                x: 0
                y: 0
                width: 60
                height: 70
                opacity: 1
                source: "resources/ATP_0S.png"
            }
        }
    }

    Row {
        id: velocidad
        x: 373
        y: 346
        width: 516
        height: 24
        Repeater{
            //49
            id: repeaterLed
            model:49
            Image {
                id: ledVelocidad
                x: 0
                y: 0
                width: 10
                height: 23
                source: "resources/ATPoLed2.png"
                opacity: 0
            }
            onItemAdded: ledsSpeed[index] = item
          }//Repeater
    }//Row LED

  function posLed(x){

      for (indexLed=0; indexLed<=(x-1); indexLed++){
          ledsSpeed[indexLed].opacity=1;
      };
      for (indexLed=x; indexLed < ledsSpeed.length; indexLed++){
          ledsSpeed[indexLed].opacity=0;
      };

  }

  function targetSpeed(v){

      v = parseInt(v);

      if (v === velTramo0){
          //0
          ims1.opacity=1;
      }else{
          ims1.opacity=0;
      };

      if (v === velTramo1){
          //10
          image10.opacity=1;
      } else{
          image10.opacity=0;
      };

      if (v === velTramo2){
          //20
          image20.opacity=1;
      }else{
          image20.opacity=0;
      };

      if (v === velTramo3){
          //30
          image30.opacity=1;
      }else{
          image30.opacity=0;
      };

      if (v === velTramo4){
          //40
          image40.opacity=1;
      }else{
          image40.opacity=0;
      };

      if (v === velTramo5){
          //50
          image50.opacity=1;
      }else{
          image50.opacity=0;
      };

      if (v === velTramo6){
          //60
          image60.opacity=1;
      }else{
          image60.opacity=0;
      };
  }

  function allowedSpeed(v){

  }

  function targetSpeedLCD(v){
      console.log("Velocidad LCD D1---> ",getD1(v));
      console.log("Velocidad LCD D2---> ",getD2(v));
      v = parseInt(v);
      //digitsL1[getD1(v)].opacity = 1;
      digitsL1[getD1(v)].opacity = 1;
      digitsL2[getD2(v)].opacity = 1;

      //digitsL1[4].opacity = 1;
      //digitsL2[3].opacity = 1;
  }

  //Creater digits
  Repeater{
      id: digitsL1
      model: 10
      Image {
          id: dl
          x: 170
          y: 273
          width: 100
          height: 100
          source: "resources/ATP_"+index+"L.png"
          opacity: 0
      }
      onItemAdded: digitsL1[index] = item
  }

  Repeater{
      id: digitsL2
      model: 10
      Image {
          id: d2
          x: 240
          y: 273
          width: 100
          height: 100
          source: "resources/ATP_"+index+"L.png"
          opacity: 0
      }
      onItemAdded: digitsL2[index] = item
  }

  //calculate digits
  function getD1(v){
      v = parseInt(v);
      return (parseInt(v/10));
  }

  function getD2(v){
      v = parseInt(v);
      console.log("SEGUNDO Digito LDC: ------>",v - ((parseInt(v/10)*10)));
      return (v - ((parseInt(v/10)*10)));
  }

  //10
    Item {
        id: s10
        x: 784
        y: 197
        width: 60
        height: 70
        Image {
            id: image10
            x: 0
            y: 0
            width: 60
            height: 70
            opacity: 0
            source: "resources/ATP_1S.png"
        }
    }
  //20
    Item {
        id: s20
        x: 784
        y: 197
        width: 60
        height: 70
        Image {
            id: image20
            x: 0
            y: 0
            width: 60
            height: 70
            opacity: 0
            source: "resources/ATP_2S.png"
        }
    }
  //30
    Item {
        id: s30
        x: 784
        y: 197
        width: 60
        height: 70
        Image {
            id: image30
            x: 0
            y: 0
            width: 60
            height: 70
            opacity: 0
            source: "resources/ATP_3S.png"
        }
    }
  //40
    Item {
        id: s40
        x: 784
        y: 197
        width: 60
        height: 70
        Image {
            id: image40
            x: 0
            y: 0
            width: 60
            height: 70
            opacity: 0
            source: "resources/ATP_4S.png"
        }
    }
  //50
    Item {
        id: s50
        x: 784
        y: 197
        width: 60
        height: 70
        Image {
            id: image50
            x: 0
            y: 0
            width: 60
            height: 70
            opacity: 0
            source: "resources/ATP_5S.png"
        }
    }
  //60
    Item {
        id: s60
        x: 784
        y: 197
        width: 60
        height: 70
        Image {
            id: image60
            x: 0
            y: 0
            width: 60
            height: 70
            opacity: 0
            source: "resources/ATP_6S.png"
        }
    }

}