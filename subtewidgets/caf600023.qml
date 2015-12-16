import QtQuick 2.0
import QtQuick.Controls 1.4

StackView{
    id:stack
    initialItem: formacion

    width: 1024
    height: 93

    signal selected(string s)
    property string selectedWagon: ""
    objectName: "formacion"
    property string namecoche1: "1"
    property string namecoche2: "2"
    property string namecoche3: "3"
    property string namecoche4: "4"
    property string namecoche5: "5"
    property string namecoche6: "6"

        Rectangle {
//            z: 0
            id: formacion
            width: parent.width
            height: parent.height

            state: "formacionAll"

            states: [
                State {
                    name: "formacionAll"

                    PropertyChanges {
                        target: bckGrey;
                        opacity: 0
                    }
                    PropertyChanges {
                        target: bck;
                        opacity: 1
                    }
                },
                State {
                    name: "formacionBackground";
                    PropertyChanges {
                        target: bckGrey;
                        opacity: 1;
                    }
                    PropertyChanges {
                        target: bck;
                        opacity: 0
                    }
                },
                State {
                    name: "formacionBackgroundOff";
                    PropertyChanges {
                        target: bckGreyOff;
                        opacity: 1;
                    }
                    PropertyChanges {
                        target: bckGreyOff;
                        opacity: 0
                    }
                }
            ]

            Image{
                id: bck
                z:0
                anchors.fill: parent
                source: "MM-MM-MM-BCK"
                //source: "../Source/images/fondos/coches_crop.png"
                opacity: 0
            }

            Image{
                id: bckGrey
                z:0
                opacity: 0
                anchors.fill: parent
                source: "MM-MM-MM-BCK-GREY"
            }

            Image{
                id: bckGreyOff
                z:0
                opacity: 0
                anchors.fill: parent
                //source: "MM-MM-MM-BCK-GREY"
                source: "../Source/images/fondos/coches_opcionapagados_crop.png"
            }

         }//Rectangle

        Item {
            id: coche1
            anchors.fill: parent
            z: 1

            Image {
                id: cocheImage1
                objectName: "C1"
                anchors.fill: parent
                source: "C1"
                opacity: 0
                PropertyAnimation { id: animationOne; target: cocheImage1;alwaysRunToEnd: true; property: "opacity"; easing.type: Easing.Linear; to: 1; duration: 500
                    onStopped: animationTwo.start()}
                PropertyAnimation { id: animationTwo; target: cocheImage1;alwaysRunToEnd: true; property: "opacity"; to: 0; duration: 300 }
            }

            MouseArea {
                id: mouseAreaCoche1
                x: 20
                y: 0
                width: 160
                height: 93
                onClicked: {
                    if (cocheImage1.opacity == 0){
                        if (stack.depth > 0){
                            //console.log(("Antes del POP!"));
                            stack.currentItem.opacity = 0;
                            stack.pop();
                            //console.log("Entrando en POP");
                        }
                        //stack.push({item:formacion, properties:{state:"formacionBackground"}});
                        //formacion.state = "formacionBackground";
                        //cocheImage1.opacity = 1;
//                        stack.push({item:bckGreyOff, properties:{opacity:1}});
                        stack.push({item:cocheImage1, properties:{opacity:1}});
                        stack.selected(namecoche1);
                        //formacion.state = "formacionAll";
                       // formacion.state = "formacionBackgroundOff";
                    }else{
                        cocheImage1.opacity = 0;
                        //stack.currentItem.opacity = 0;
                        stack.pop();
                        //stack.currentItem.state = "formacionAll";
                        //formacion.state = "formacionAll";
                        stack.push({item:bck,properties:{opacity:1}});
                        //stack.push({item:formacion,properties:{state:"formacionAll"}});
                        stack.selected("off");
                    }
                    console.log("On Click, mouseAreaCoche1")
                }
            }
        }//Item1, coche1

        Item {
            id: coche2
            anchors.fill: parent
            z: 1

            Image {
                id: cocheImage2
                objectName: "C2"
                anchors.fill: parent
                source: "C2"
                opacity: 0
                z: 1
            }

            MouseArea {
                id: mouseAreaCoche2
                x: 181
                y: 0
                width: 160
                height: 93
                onClicked: {
                    if (cocheImage2.opacity == 0){
                        if ((stack.depth) > 0){
                            //console.log("Entrando antes del POP COCHE 1!");
                            stack.currentItem.opacity = 0;
                            stack.pop();
                            //console.log("Saliendo en POP COCHE 1!");
                        }
                        //console.log("Entrando en opacity COCHE 2 @");
                        //formacion.state = "formacionBackground";
                        //cocheImage2.opacity = 1;
                        stack.push({item:cocheImage2, properties:{opacity:1}});
                        stack.selected(namecoche2);
                        //selectedWagon = cocheImage2.objectName;
                        //console.log("PASE push opacity COCHE 2 @");
                       // formacion.state = "formacionBackgroundOff";
                    }else{
                        cocheImage2.opacity = 0;
                        stack.pop();
                        //formacion.state = "formacionAll";
                        stack.push({item:bck,properties:{opacity:1}});
                        stack.selected("off");
                    }
                    console.log("On Click, mouseAreaCoche2")
                }
            }
        }//Item2, coche2

        Item {
            id: coche3
            anchors.fill: parent
            z: 1
            //x: -1
            //y: -3

            Image {
                id: cocheImage3
                objectName: "C3"
                source: "C3"
                //source: "../Source/images/fondos/coche1On.png"
                anchors.fill: parent
                opacity: 0
                PropertyAnimation { id: animation31;
                                    target: cocheImage3;
                                    alwaysRunToEnd: true;
                                    property: "opacity";
                                    to: 1; duration: 500
                                    onStopped: animation32.start()
                }
                PropertyAnimation { id: animation32;
                                    target: cocheImage3;
                                    alwaysRunToEnd: true;
                                    property: "opacity";
                                    to: 0; duration: 300
                }
            }

            MouseArea {
                id: mouseAreaCoche3
                x: 349
                y: 0
                width: 160
                height: 93
                onClicked: {
                    if (cocheImage3.opacity == 0){
                        if ((stack.depth) > 0){
                            //console.log("Entrando (Coche 3)antes del POP! ",stack.currentItem.objectName, " opacity: ", stack.currentItem.opacity.toString());
                            stack.currentItem.opacity = 0;
                            stack.pop();
                            //console.log("Saliendo de POP COCHE 3 !");
                        }
                        //console.log("Entrando en opacity COCHE 3 @");
                        //formacion.state = "formacionBackground";
                        //cocheImage3.opacity = 1;
                        stack.push({item:cocheImage3, properties:{opacity:1}});
                        stack.selected(namecoche3);
                        //stack.selectedWagon = cocheImage3.objectName;
                        //console.log("PASE push opacity COCHE 3 @ ");
                    }else{
                        cocheImage3.opacity = 0;
                        stack.pop();
                        //formacion.state = "formacionAll";
                        //stack.selectedWagon = "";
                        //console.log("On Click, ELSE mouseAreaCoche3 ");
                        stack.push({item:bck,properties:{opacity:1}});
                        stack.selected("off");
                    }
                    console.log("On Click, mouseAreaCoche3")
                }
            }
        }

        Item {
            id: coche4
            anchors.fill: parent
            z: 1
            //x: -2
            //y: 0

            Image {
                id: cocheImage4
                objectName: "C4"
                source: "C4"
                opacity: 0
                anchors.fill: parent
                PropertyAnimation { id: animation41;
                                    target: cocheImage4;
                                    alwaysRunToEnd: true;
                                    property: "opacity";
                                    to: 1; duration: 500;
                                    onStopped: animation42.start()
                }
                PropertyAnimation { id: animation42;
                                    target: cocheImage4;
                                    alwaysRunToEnd: true;
                                    property: "opacity";
                                    to: 0; duration: 300
                }
            }

            MouseArea {
                id: mouseAreaCoche4
                x: 510
                y: 0
                width: 160
                height: 93
                onClicked: {
                    if (cocheImage4.opacity == 0){
                        if (stack.depth > 0){
                            //console.log(("Antes del POP!"));
                            stack.currentItem.opacity = 0;
                            stack.pop();
                            //console.log("Entrando en POP");
                        }
                        //formacion.state = "formacionBackground";
                        //cocheImage1.opacity = 1;
//                        stack.push({item:bckGreyOff, properties:{opacity:1}});
                        stack.push({item:cocheImage4, properties:{opacity:1}});
                        stack.selected(namecoche4);
                        //formacion.state = "formacionAll";
                       // formacion.state = "formacionBackgroundOff";
                    }else{
                        cocheImage4.opacity = 0;
                        stack.pop();
                        //formacion.state = "formacionAll";
                        stack.push({item:bck,properties:{opacity:1}});
                        stack.selected("off");
                    }
                    console.log("On Click, mouseAreaCoche4")
                }
            }

        }//Item4, coche4

        Item {
            id: coche5
            anchors.fill: parent
            z: 1
            //x: -7
            //y: -2

            Image {
                id: cocheImage5
                objectName: "C5"
                source: "C5"
                opacity: 0
                anchors.fill: parent
                PropertyAnimation { id: animation51;
                                    target: cocheImage5;
                                    alwaysRunToEnd: true;
                                    property: "opacity";
                                    to: 1; duration: 500;
                                    onStopped: animation52.start()
                }
                PropertyAnimation { id: animation52;
                                    target: cocheImage5;
                                    alwaysRunToEnd: true;
                                    property: "opacity";
                                    to: 0; duration: 300
                }
            }

            MouseArea {
                id: mouseAreaCoche5
                x: 682
                y: 0
                width: 160
                height: 93
                onClicked: {
                    if (cocheImage5.opacity == 0){
                        if (stack.depth > 0){
                            //console.log(("Antes del POP!"));
                            stack.currentItem.opacity = 0;
                            stack.pop();
                            //console.log("Entrando en POP");
                        }
                        stack.push({item:cocheImage5, properties:{opacity:1}});
                        stack.selected(namecoche5);
                    }else{
                        cocheImage5.opacity = 0;
                        stack.pop();
                        stack.push({item:bck,properties:{opacity:1}});
                        stack.selected("off");
                    }
                    console.log("On Click, mouseAreaCoche5")
                }
            }

        }//Item5, coche5

        Item {
            id: coche6
            anchors.fill: parent
            z: 1
//            x: -6
//            y: -4

            Image {
                id: cocheImage6
                objectName: "C6"
                source: "C6"
                opacity: 0
                anchors.fill: parent
            }

            MouseArea {
                id: mouseAreaCoche6
                x: 843
                y: 0
                width: 160
                height: 93
                onClicked: {
                    if (cocheImage6.opacity == 0){
                        if (stack.depth > 0){
                            //console.log(("Antes del POP!"));
                            stack.currentItem.opacity = 0;
                            stack.pop();
                            //console.log("Entrando en POP");
                        }
                        stack.push({item:cocheImage6, properties:{opacity:1}});
                        stack.selected(namecoche6);
                    }else{
                        cocheImage6.opacity = 0;
                        stack.pop();
                        stack.push({item:bck,properties:{opacity:1}});
                        stack.selected("off");
                    }
                    console.log("On Click, mouseAreaCoche6")
                }
            }
        }
}//StackView
