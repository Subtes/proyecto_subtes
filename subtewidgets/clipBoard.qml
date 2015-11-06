import QtQuick 2.0

Rectangle {
    id: level3
    objectName: "thermalPanel"
    x: 0
    y: 0
    width: 900
    height: 675

    signal selected(string s)

    property string type: "c_termico_"
    property string numberWagon: "X"
    property string token: ";"

    property variant  thermalsVector: []
    property int index: 0
    property int index1: thermalsVector.length

    Image {
        id: backGround
        objectName: "backGround"
        x: 0
        y: 0
        z: 0
        width: 900
        height: 675
        fillMode: Image.PreserveAspectFit
        //source: "../Source/images/fondos/Termicas_Mod.PNG"
        //source: "../Source/images/fondos/fondoTermicas2.png"
        source: "../Source/images/fondos/Termicas_Resize.PNG"
        //source: "N3-PT"
        opacity: 1
    }//Image

    Row {
        id: row0
        x: 315
        y: 74
        width: 451
        height: 40
        layoutDirection: Qt.LeftToRight
        spacing: 17

        Repeater{
            id: repeaterThermal0
            model: 9

            Item {
                id: t0
                width: 35
                height: 39
                transformOrigin: Item.Left

                objectName: "t"+index
                property string thermal: "TERMICO-DEFAULT"+index
                property int nThermal: index
                state: "des"

                Image {
                    id: con0
                    objectName: "con0T"+index
                    x: 0
                    y: 0
                    width: 35
                    height: 38
                    fillMode: Image.Stretch
                    //source: "../Source/images/perillas/termicas/Tecla2_Arriba.PNG"
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
                            console.log("Entro en IF de Termico: ",level3.type+(thermalsVector[nThermal].thermal)+level3.numberWagon+token+"des");
                            level3.selected(level3.type+(thermalsVector[nThermal].thermal)+level3.numberWagon+token+"des");
                        }else{
                            parent.state = "con";
                            level3.selected(level3.type+(thermalsVector[nThermal].thermal)+level3.numberWagon+token+"con");
                            console.log("Entro en ELSE de Termico: ",level3.type+(thermalsVector[nThermal].thermal)+level3.numberWagon+token+"con");
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
    }//Row

}//Rectangle
