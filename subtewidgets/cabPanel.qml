import QtQuick 2.0
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4

Item {

    id: level3
    objectName: "saloonPanel"
    x: 0
    y: 0
    width: 900
    height: 675

    signal selected(string s)

    property string type: "c_cabina"
    property string numberWagon: "_X_"
    property string token: ";"

    Image {
        id: backGround
        objectName: "backGround"
        x: 0
        y: 0
        z: 0
        width: 900
        height: 675
        visible: true
        transformOrigin: Item.Center
        fillMode: Image.PreserveAspectFit
        //source: "../Source/images/fondos/fondoCabina.png"
        source: "N3-PC"
        opacity: 1
    }

    Item {
        id: t0
        width: 120
        height: 130
        scale: 0.9

        objectName: "t0"
        property string switchName: "TERMICO-DEFAULT_"
        property int nSwitch: 0
        x: 35
        y: 183

        Image {
            id: conT0
            x: 0
            y: 0
            width: 120
            height: 130
            fillMode: Image.PreserveAspectFit
            source: "../Source/images/perillas/Cabina/setaOn.png"
            //source: "SETA-ON"
            opacity: 1
        }

        Image {
            id: desT0
            x: 0
            y: 0
            width: 120
            height: 130
            fillMode: Image.PreserveAspectFit
            source: "../Source/images/perillas/Cabina/setaOff.png"
            //source: "SETA-OFF"
            opacity: 0
        }

        MouseArea {
            id: mouseAreaT0
            x: 0
            y: 0
            width: 120
            height: 130
            onClicked: {
                if (t0.state == "des"){
                    t0.state = "con";
                    level3.selected((level3.type)+level3.token+(t0.switchName)+level3.token+(level3.numberWagon)+level3.token+"con");
                }else{
                    t0.state = "des";
                    level3.selected((level3.type)+level3.token+(t0.switchName)+level3.token+(level3.numberWagon)+level3.token+"des");
                }
            }//onClicked
        }//MouseArea
        state: "con"
        states: [
            State {
                name: "con"
                PropertyChanges { target: conT0; opacity: 1;}
                PropertyChanges { target: desT0; opacity: 0;}
            },
            State {
                name: "des"
                PropertyChanges { target: conT0; opacity: 0;}
                PropertyChanges { target: desT0; opacity: 1;}
            }
        ]
    }
    
    Slider {
        id: sliderRana
        objectName: "t1"
        property string switchName: "TERMICO-DEFAULT_"
        property int nSwitch: 1
        //property string m_state: "0"

        x: 225
        y: 123
        width: 159
        height: 243

        transformOrigin: Item.BottomLeft

        activeFocusOnPress: true
        opacity: 1
        value: 1
        updateValueWhileDragging: false
        stepSize: 1
        tickmarksEnabled: true
        orientation: Qt.Vertical
        maximumValue: 1
        minimumValue: -1
        onValueChanged: {
            //console.log("Valor RANA anterior: ----->",  sliderRana.value, " ",sliderRana.m_state);
            if (sliderRana.value == 1.0){
                sliderRana.state = "ad"
            }else if (sliderRana.value == -1.0){
                sliderRana.state = "at"
            }else{
                sliderRana.state = "0"
            }
            level3.selected(level3.type
                            +level3.token+sliderRana.switchName
                            +level3.token+level3.numberWagon
                            +level3.token+sliderRana.state);
            console.log("Valor RANA State nuevo: ", sliderRana.value, " ", sliderRana.state);
        }
        state: "ad"
        states: [
            State {
                name: "ad"
                PropertyChanges { target: sliderRana; value: 1;}
            },
            State {
                name: "at"
                PropertyChanges { target: sliderRana; value: -1;}            },
            State {
                name: "0"
                PropertyChanges { target: sliderRana; value: 0;}
            }
        ]

        style: SliderStyle {
            handle: Image {
                        id: ranaHandler
                        objectName: "ranaHandler"
                        x: parent.x
                        y: parent.y
                        //anchors.centerIn: parent
                        anchors.horizontalCenter: parent
                        width: 155
                        height: 172
                        //fillMode: Image.PreserveAspectFit
                        source: "../Source/images/perillas/Cabina/rana.png"
                        //source: "RANA"
                        opacity: 1
                        rotation: 90
                }
            groove: Rectangle {
                color: "gray"
                radius: 8
            }
        }//Style
    }//Slider

}

