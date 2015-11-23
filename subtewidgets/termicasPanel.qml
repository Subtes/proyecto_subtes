import QtQuick 2.0

Rectangle {
    id: level3
    objectName: "panelTermicas"
    x: 0
    y: 0
    width: 900
    height: 675

    signal selected(string s)
    property string tipo: "c_termico_"

    Image {
        id: backGroundPanelTermicas
        objectName: "backGroundPanelTermicas"
        x: 0
        y: 0
        z: 0
        width: 900
        height: 675
        fillMode: Image.PreserveAspectFit
        source: "N3-PT"
        opacity: 1
    }

    Item {
        id: itemPanelTermicas
        x: 0
        y: 0
        width: 900
        height: 675

        Item {
            id: itemf1N1
            x: 253
            y: 90
            width: 82
            height: 34

            Image {
                id: conf1N1
                x: 0
                y: 0
                width: 82
                height: 34
                fillMode: Image.PreserveAspectFit
                source: "../Source/images/perillas/termicas/Tecla1_Arriba.PNG"
            }
            Image {
                id: desf1N1
                x: 0
                y: 0
                width: 82
                height: 34
                opacity: 0
                fillMode: Image.PreserveAspectFit
                source: "../Source/images/perillas/termicas/tecla1_Abajo.PNG"
            }

            MouseArea {
                id: mouseAreaf1N1
                x: 18
                y: 0
                width: 48
                height: 34
                z: 1
                onClicked: {
                    if (conf1N1.opacity == 0){
                        conf1N1.opacity = 1;
                        desf1N1.opacity = 0;
                        level3.selected("conf1N1");
                    }else{
                        desf1N1.opacity = 1;
                        conf1N1.opacity = 0;
                        level3.selected("desf1N1");
                    }
                }
            }
        }

        Item {
            id: itemDiyuntor
            x: 297
            y: 343
            width: 27
            height: 34

            Image {
                id: image13
                x: 0
                y: 0
                width: 27
                height: 34
                fillMode: Image.PreserveAspectFit
                source: "../Source/images/perillas/termicas/Tecla3_Arriba.PNG"
            }

            MouseArea {
                id: mouseArea13
                width: 27
                height: 34
            }
        }

        Item {
            id: itemf4N1
            x: 261
            y: 477
            width: 69
            height: 29

            Image {
                id: image14
                width: 69
                height: 29
                fillMode: Image.PreserveAspectFit
                source: "../Source/images/perillas/termicas/Tecla1_Arriba.PNG"
            }

            MouseArea {
                id: mouseArea14
                width: 69
                height: 29
            }
        }

        Item {
            id: itemPerillaRojo
            x: 230
            y: 600
            width: 112
            height: 26

            Image {
                id: image15
                width: 112
                height: 26
                rotation: 90
                fillMode: Image.PreserveAspectFit
                source: "../Source/images/perillas/termicas/termicas_roja.PNG"
            }

            MouseArea {
                id: mouseArea15
                x: 0
                y: -37
                width: 112
                height: 97
            }
        }

        Row {
            id: row11
            x: 332
            y: 78
            width: 253
            height: 32
            Item {
                id: item33f1
                x: 0
                width: 43
                height: 32
                Image {
                    id: con33f1
                    x: 5
                    y: 0
                    width: 28
                    height: 32
                    source: "../Source/images/perillas/termicas/Tecla2_Arriba.PNG"
                    fillMode: Image.PreserveAspectFit
                    opacity: 1
                }

                Image {
                    id: des33f1
                    x: 5
                    y: 0
                    width: 28
                    height: 32
                    source: "../Source/images/perillas/termicas/Tecla2_Abajo.PNG"
                    fillMode: Image.PreserveAspectFit
                    opacity: 0
                }

                MouseArea {
                    id: mouseArea16
                    x: 11
                    y: 1
                    width: 18
                    height: 30
                    onClicked: {
                        if (con33f1.opacity == 0){
                            con33f1.opacity = 1;
                            des33f1.opacity = 0;
                            level3.selected("con33f1");
                        }else{
                            des33f1.opacity = 1;
                            con33f1.opacity = 0;
                            level3.selected("des33f1");
                        }
                    }
                }
            }

            Item {
                id: item14
                x: 0
                width: 42
                height: 32
                Image {
                    id: image17
                    x: 6
                    y: 0
                    width: 28
                    height: 32
                    source: "../Source/images/perillas/termicas/Tecla2_Arriba.PNG"
                    fillMode: Image.PreserveAspectFit
                }

                MouseArea {
                    id: mouseArea17
                    x: 12
                    y: 1
                    width: 18
                    height: 30
                }
            }

            Item {
                id: item15
                x: 0
                width: 42
                height: 32
                Image {
                    id: image18
                    x: 6
                    y: 0
                    width: 28
                    height: 32
                    source: "../Source/images/perillas/termicas/Tecla2_Arriba.PNG"
                    fillMode: Image.PreserveAspectFit
                }

                MouseArea {
                    id: mouseArea18
                    x: 12
                    y: 1
                    width: 18
                    height: 30
                }
            }

            Item {
                id: item16
                x: 0
                width: 42
                height: 32
                Image {
                    id: image19
                    x: 6
                    y: 0
                    width: 28
                    height: 32
                    source: "../Source/images/perillas/termicas/Tecla2_Arriba.PNG"
                    fillMode: Image.PreserveAspectFit
                }

                MouseArea {
                    id: mouseArea19
                    x: 12
                    y: 1
                    width: 18
                    height: 30
                }
            }

            Item {
                id: item17
                x: 0
                width: 42
                height: 32
                Image {
                    id: image20
                    x: 6
                    y: 0
                    width: 28
                    height: 32
                    source: "../Source/images/perillas/termicas/Tecla2_Arriba.PNG"
                    fillMode: Image.PreserveAspectFit
                }

                MouseArea {
                    id: mouseArea20
                    x: 12
                    y: 1
                    width: 18
                    height: 30
                }
            }

            Item {
                id: item18
                x: 0
                width: 42
                height: 32
                Image {
                    id: image21
                    x: 6
                    y: 0
                    width: 28
                    height: 32
                    source: "../Source/images/perillas/termicas/Tecla2_Arriba.PNG"
                    fillMode: Image.PreserveAspectFit
                }

                MouseArea {
                    id: mouseArea21
                    x: 12
                    y: 1
                    width: 18
                    height: 30
                }
            }
        }

        Row {
            id: row21
            x: 205
            y: 204
            width: 253
            height: 32

            Item {
                id: item1
                x: 0
                width: 43
                height: 32

                Image {
                    id: image1
                    x: 5
                    y: 0
                    width: 28
                    height: 32
                    fillMode: Image.PreserveAspectFit
                    source: "../Source/images/perillas/termicas/Tecla2_Arriba.PNG"
                }

                MouseArea {
                    id: mouseArea1
                    x: 11
                    y: 1
                    width: 18
                    height: 30
                }
            }

            Item {
                id: item2
                x: 0
                width: 42
                height: 32
                Image {
                    id: image2
                    x: 6
                    y: 0
                    width: 28
                    height: 32
                    source: "../Source/images/perillas/termicas/Tecla2_Arriba.PNG"
                    fillMode: Image.PreserveAspectFit
                }

                MouseArea {
                    id: mouseArea2
                    x: 12
                    y: 1
                    width: 18
                    height: 30
                }
            }

            Item {
                id: item3
                x: 0
                width: 42
                height: 32
                Image {
                    id: image3
                    x: 6
                    y: 0
                    width: 28
                    height: 32
                    source: "../Source/images/perillas/termicas/Tecla2_Arriba.PNG"
                    fillMode: Image.PreserveAspectFit
                }

                MouseArea {
                    id: mouseArea3
                    x: 12
                    y: 1
                    width: 18
                    height: 30
                }
            }

            Item {
                id: item4
                x: 0
                width: 42
                height: 32
                Image {
                    id: image4
                    x: 6
                    y: 0
                    width: 28
                    height: 32
                    source: "../Source/images/perillas/termicas/Tecla2_Arriba.PNG"
                    fillMode: Image.PreserveAspectFit
                }

                MouseArea {
                    id: mouseArea4
                    x: 12
                    y: 1
                    width: 18
                    height: 30
                }
            }

            Item {
                id: item5
                x: 0
                width: 42
                height: 32
                Image {
                    id: image5
                    x: 6
                    y: 0
                    width: 28
                    height: 32
                    source: "../Source/images/perillas/termicas/Tecla2_Arriba.PNG"
                    fillMode: Image.PreserveAspectFit
                }

                MouseArea {
                    id: mouseArea5
                    x: 12
                    y: 1
                    width: 18
                    height: 30
                }
            }

            Item {
                id: item6
                x: 0
                width: 42
                height: 32
                Image {
                    id: image6
                    x: 6
                    y: 0
                    width: 28
                    height: 32
                    source: "../Source/images/perillas/termicas/Tecla2_Arriba.PNG"
                    fillMode: Image.PreserveAspectFit
                }

                MouseArea {
                    id: mouseArea6
                    x: 12
                    y: 1
                    width: 18
                    height: 30
                }
            }
        }

        Row {
            id: row22
            x: 461
            y: 204
            width: 253
            height: 32

            Item {
                id: item7
                width: 43
                height: 32
                Image {
                    id: image7
                    x: 5
                    y: 0
                    width: 28
                    height: 32
                    source: "../Source/images/perillas/termicas/Tecla2_Arriba.PNG"
                    fillMode: Image.PreserveAspectFit
                }

                MouseArea {
                    id: mouseArea7
                    x: 11
                    y: 1
                    width: 18
                    height: 30
                }
            }

            Item {
                id: item53f1
                width: 42
                height: 32
                Image {
                    id: con53f1
                    x: 6
                    y: 0
                    width: 28
                    height: 32
                    source: "../Source/images/perillas/termicas/Tecla2_Arriba.PNG"
                    fillMode: Image.PreserveAspectFit
                    opacity: 1
                }
                Image {
                    id: des53f1
                    x: 6
                    y: 0
                    width: 28
                    height: 32
                    source: "../Source/images/perillas/termicas/Tecla2_Abajo.PNG"
                    fillMode: Image.PreserveAspectFit
                    opacity: 0
                }
                MouseArea {
                    id: mouseArea8
                    x: 12
                    y: 1
                    width: 18
                    height: 30
                    onClicked: {
                        if (con53f1.opacity == 0){
                            con53f1.opacity = 1;
                            des53f1.opacity = 0;
                            level3.selected("con53f1");
                        }else{
                            des53f1.opacity = 1;
                            con53f1.opacity = 0;
                            level3.selected("des53f1");
                        }
                    }
                }
            }

            Item {
                id: item9
                width: 42
                height: 32
                Image {
                    id: image9
                    x: 6
                    y: 0
                    width: 28
                    height: 32
                    source: "../Source/images/perillas/termicas/Tecla2_Arriba.PNG"
                    fillMode: Image.PreserveAspectFit
                }

                MouseArea {
                    id: mouseArea9
                    x: 12
                    y: 1
                    width: 18
                    height: 30
                }
            }

            Item {
                id: item10
                width: 42
                height: 32
                Image {
                    id: image10
                    x: 6
                    y: 0
                    width: 28
                    height: 32
                    source: "../Source/images/perillas/termicas/Tecla2_Arriba.PNG"
                    fillMode: Image.PreserveAspectFit
                }

                MouseArea {
                    id: mouseArea10
                    x: 12
                    y: 1
                    width: 18
                    height: 30
                }
            }

            Item {
                id: item57f1
                width: 42
                height: 32
                property string termico: "57f1"
                Image {
                    id: con57f1
                    x: 6
                    y: 0
                    width: 28
                    height: 32
                    source: "../Source/images/perillas/termicas/Tecla2_Arriba.PNG"
                    fillMode: Image.PreserveAspectFit
                    opacity: 1
                }
                Image {
                    id: des57f1
                    x: 6
                    y: 6
                    width: 28
                    height: 32
                    source: "../Source/images/perillas/termicas/Tecla2_Abajo.PNG"
                    fillMode: Image.PreserveAspectFit
                    opacity: 0
                }
                MouseArea {
                    id: mouseArea11
                    x: 12
                    y: 1
                    width: 18
                    height: 30
                    onClicked: {
                        if (con57f1.opacity == 0){
                            con57f1.opacity = 1;
                            des57f1.opacity = 0;
                            level3.selected((level3.tipo)+(item57f1.termico));
                        }else{
                            des57f1.opacity = 1;
                            con57f1.opacity = 0;
                            level3.selected("des57f1");
                        }
                    }
                }
            }

            Item {
                id: item12
                width: 42
                height: 32
                Image {
                    id: image12
                    x: 6
                    y: 0
                    width: 28
                    height: 32
                    source: "../Source/images/perillas/termicas/Tecla2_Arriba.PNG"
                    fillMode: Image.PreserveAspectFit
                }

                MouseArea {
                    id: mouseArea12
                    x: 12
                    y: 1
                    width: 18
                    height: 30
                }
            }
        }

    }//End itemPanelTermicas
}//End level3
