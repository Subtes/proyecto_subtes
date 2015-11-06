import QtQuick 2.0

Rectangle {
    id: level3
    objectName: "thermalPanel"
    x: 0
    y: 0
    width: 900
    height: 675
    color: "#00000000"
    border.color: "#00000000"

    signal selected(string s)
    property string type: "c_termico_"
    property string numberWagon: "cocheDEFAULT"

    Image {
        id: backGround
        objectName: "backGround"
        x: 0
        y: 0
        z: 0
        width: 900
        height: 675
        fillMode: Image.PreserveAspectFit
//        source: "../Source/images/fondos/Termicas_Mod.PNG"
        source: "N3-PT"
        opacity: 1
    }

    Item {
        id: itemThermalPanel1
        x: 0
        y: 0
        width: 900
        height: 675

        Row {
            id: row1
            x: 337
            y: 72
            width: 369
            height: 39
            spacing: 12

            Item {
                id: t1
                width: 30
                height: 39
                property string thermal: "DEFAULT"

                Image {
                    id: conT1
                    x: 0
                    y: 0
                    width: 29
                    height: 39
                    fillMode: Image.PreserveAspectFit
                    source: "../Source/images/perillas/termicas/Tecla2_Arriba.PNG"
                    opacity: 1
                }

                Image {
                    id: desT1
                    x: 0
                    y: 6
                    width: 28
                    height: 33
                    fillMode: Image.PreserveAspectFit
                    source: "../Source/images/perillas/termicas/Tecla2_Abajo.PNG"
                    opacity: 0
                }

                MouseArea {
                    id: mouseAreaT1
                    x: 0
                    y: 0
                    width: 29
                    height: 39
                    onClicked: {
                        if (conT1.opacity == 0){
                            conT1.opacity = 1;
                            desT1.opacity = 0;
                            level3.selected((level3.type)+(t1.thermal)+(level3.numberWagon)+"con");
                        }else{
                            desT1.opacity = 1;
                            conT1.opacity = 0;
                            level3.selected((level3.type)+(t1.thermal)+(level3.numberWagon)+"des");
                        }
                    }//onClicked
                }//MouseArea
            }

            Item {
                id: t2
                width: 30
                height: 39
                property string thermal: "DEFAULT"
                Image {
                    id: conT2
                    x: 0
                    y: 0
                    width: 29
                    height: 39
                    source: "../Source/images/perillas/termicas/Tecla2_Arriba.PNG"
                    fillMode: Image.PreserveAspectFit
                    opacity: 1
                }

                Image {
                    id: desT2
                    x: 0
                    y: 6
                    width: 28
                    height: 33
                    source: "../Source/images/perillas/termicas/Tecla2_Abajo.PNG"
                    fillMode: Image.PreserveAspectFit
                    opacity: 0
                }

                MouseArea {
                    id: mouseAreaT2
                    x: 0
                    y: 0
                    width: 29
                    height: 39
                }
            }

            Item {
                id: t3
                width: 30
                height: 39
                property string thermal: "DEFAULT"
                Image {
                    id: conT3
                    x: 0
                    y: 0
                    width: 29
                    height: 39
                    source: "../Source/images/perillas/termicas/Tecla2_Arriba.PNG"
                    fillMode: Image.PreserveAspectFit
                    opacity: 1
                }

                Image {
                    id: desT3
                    x: 0
                    y: 6
                    width: 28
                    height: 33
                    source: "../Source/images/perillas/termicas/Tecla2_Abajo.PNG"
                    fillMode: Image.PreserveAspectFit
                    opacity: 0
                }

                MouseArea {
                    id: mouseAreaT3
                    x: 0
                    y: 0
                    width: 29
                    height: 39
                }
            }

            Item {
                id: t4
                width: 33
                height: 39
                property string thermal: "DEFAULT"
                Image {
                    id: conT4
                    x: 0
                    y: 0
                    width: 29
                    height: 39
                    source: "../Source/images/perillas/termicas/Tecla2_Arriba.PNG"
                    fillMode: Image.PreserveAspectFit
                    opacity: 1
                }

                Image {
                    id: desT4
                    x: 0
                    y: 6
                    width: 28
                    height: 33
                    source: "../Source/images/perillas/termicas/Tecla2_Abajo.PNG"
                    fillMode: Image.PreserveAspectFit
                    opacity: 0
                }

                MouseArea {
                    id: mouseAreaT4
                    x: 0
                    y: 0
                    width: 29
                    height: 39
                }
            }

            Item {
                id: t5
                width: 30
                height: 39
                property string thermal: "DEFAULT"
                Image {
                    id: conT5
                    x: 0
                    y: 0
                    width: 29
                    height: 39
                    source: "../Source/images/perillas/termicas/Tecla2_Arriba.PNG"
                    fillMode: Image.PreserveAspectFit
                    opacity: 1
                }

                Image {
                    id: desT5
                    x: 0
                    y: 6
                    width: 28
                    height: 33
                    source: "../Source/images/perillas/termicas/Tecla2_Abajo.PNG"
                    fillMode: Image.PreserveAspectFit
                    opacity: 0
                }

                MouseArea {
                    id: mouseAreaT5
                    x: 0
                    y: 0
                    width: 29
                    height: 39
                }
            }

            Item {
                id: t6
                width: 30
                height: 39
                property string thermal: "DEFAULT"
                Image {
                    id: conT6
                    x: 0
                    y: 0
                    width: 29
                    height: 39
                    source: "../Source/images/perillas/termicas/Tecla2_Arriba.PNG"
                    fillMode: Image.PreserveAspectFit
                    opacity: 1
                }

                Image {
                    id: desT6
                    x: 0
                    y: 6
                    width: 28
                    height: 33
                    source: "../Source/images/perillas/termicas/Tecla2_Abajo.PNG"
                    fillMode: Image.PreserveAspectFit
                    opacity: 0
                }

                MouseArea {
                    id: mouseAreaT6
                    x: 0
                    y: 0
                    width: 29
                    height: 39
                }
            }

            Item {
                id: t7
                width: 30
                height: 39
                property string thermal: "DEFAULT"
                Image {
                    id: conT7
                    x: 0
                    y: 0
                    width: 29
                    height: 39
                    source: "../Source/images/perillas/termicas/Tecla2_Arriba.PNG"
                    fillMode: Image.PreserveAspectFit
                    opacity: 1
                }

                Image {
                    id: desT7
                    x: 0
                    y: 6
                    width: 28
                    height: 33
                    source: "../Source/images/perillas/termicas/Tecla2_Abajo.PNG"
                    fillMode: Image.PreserveAspectFit
                    opacity: 0
                }

                MouseArea {
                    id: mouseAreaT7
                    x: 0
                    y: 0
                    width: 29
                    height: 39
                }
            }

            Item {
                id: t8
                width: 30
                height: 39
                property string thermal: "DEFAULT"
                Image {
                    id: conT8
                    x: 0
                    y: 0
                    width: 29
                    height: 39
                    source: "../Source/images/perillas/termicas/Tecla2_Arriba.PNG"
                    fillMode: Image.PreserveAspectFit
                    opacity: 1
                }

                Image {
                    id: desT8
                    x: 0
                    y: 6
                    width: 28
                    height: 33
                    source: "../Source/images/perillas/termicas/Tecla2_Abajo.PNG"
                    fillMode: Image.PreserveAspectFit
                    opacity: 0
                }

                MouseArea {
                    id: mouseAreaT8
                    x: 0
                    y: 0
                    width: 29
                    height: 39
                }
            }

            Item {
                id: t9
                property string thermal: "DEFAULT"
                width: 30
                height: 39
                Image {
                    id: conT9
                    x: 0
                    y: 0
                    width: 29
                    height: 39
                    source: "../Source/images/perillas/termicas/Tecla2_Arriba.PNG"
                    fillMode: Image.PreserveAspectFit
                    opacity: 1
                }

                Image {
                    id: desT9
                    x: 0
                    y: 6
                    width: 28
                    height: 33
                    source: "../Source/images/perillas/termicas/Tecla2_Abajo.PNG"
                    fillMode: Image.PreserveAspectFit
                    opacity: 0
                }

                MouseArea {
                    id: mouseAreaT9
                    x: 0
                    y: 0
                    width: 29
                    height: 39
                }
            }
        }

        Row {
            id: row2
            x: 209
            y: 201
            width: 508
            height: 39
            spacing: 12

            Item {
                id: t10
                width: 30
                height: 39
                property string thermal: "DEFAULT"
                Image {
                    id: conT10
                    x: 0
                    y: 0
                    width: 29
                    height: 39
                    source: "../Source/images/perillas/termicas/Tecla2_Arriba.PNG"
                    fillMode: Image.PreserveAspectFit
                    opacity: 1
                }

                Image {
                    id: desT10
                    x: 0
                    y: 6
                    width: 28
                    height: 33
                    source: "../Source/images/perillas/termicas/Tecla2_Abajo.PNG"
                    fillMode: Image.PreserveAspectFit
                    opacity: 0
                }

                MouseArea {
                    id: mouseAreaT10
                    x: 0
                    y: 0
                    width: 29
                    height: 39
                }
            }

            Item {
                id: t11
                width: 30
                height: 39
                property string thermal: "DEFAULT"
                Image {
                    id: conT11
                    x: 0
                    y: 0
                    width: 29
                    height: 39
                    source: "../Source/images/perillas/termicas/Tecla2_Arriba.PNG"
                    fillMode: Image.PreserveAspectFit
                    opacity: 1
                }

                Image {
                    id: desT11
                    x: 0
                    y: 6
                    width: 28
                    height: 33
                    source: "../Source/images/perillas/termicas/Tecla2_Abajo.PNG"
                    fillMode: Image.PreserveAspectFit
                    opacity: 0
                }

                MouseArea {
                    id: mouseAreaT11
                    x: 0
                    y: 0
                    width: 29
                    height: 39
                }
            }

            Item {
                id: t12
                width: 32
                height: 39
                property string thermal: "DEFAULT"

                Image {
                    id: conT12
                    x: 0
                    y: 0
                    width: 29
                    height: 39
                    source: "../Source/images/perillas/termicas/Tecla2_Arriba.PNG"
                    fillMode: Image.PreserveAspectFit
                    opacity: 1
                }

                Image {
                    id: desT12
                    x: 0
                    y: 6
                    width: 28
                    height: 33
                    source: "../Source/images/perillas/termicas/Tecla2_Abajo.PNG"
                    fillMode: Image.PreserveAspectFit
                    opacity: 0
                }

                MouseArea {
                    id: mouseAreaT12
                    x: 0
                    y: 0
                    width: 29
                    height: 39
                }
            }

            Item {
                id: t13
                width: 30
                height: 39
                property string thermal: "DEFAULT"

                Image {
                    id: conT13
                    x: 0
                    y: 0
                    width: 29
                    height: 39
                    source: "../Source/images/perillas/termicas/Tecla2_Arriba.PNG"
                    fillMode: Image.PreserveAspectFit
                    opacity: 1
                }

                Image {
                    id: desT13
                    x: 0
                    y: 6
                    width: 28
                    height: 33
                    source: "../Source/images/perillas/termicas/Tecla2_Abajo.PNG"
                    fillMode: Image.PreserveAspectFit
                    opacity: 0
                }

                MouseArea {
                    id: mouseAreaT13
                    x: 0
                    y: 0
                    width: 29
                    height: 39
                }
            }

            Item {
                id: t14
                x: 173
                width: 30
                height: 39
                property string thermal: "DEFAULT"

                Image {
                    id: conT14
                    x: 0
                    y: 0
                    width: 29
                    height: 39
                    source: "../Source/images/perillas/termicas/Tecla2_Arriba.PNG"
                    fillMode: Image.PreserveAspectFit
                    opacity: 1
                }

                Image {
                    id: desT14
                    x: 0
                    y: 6
                    width: 28
                    height: 33
                    source: "../Source/images/perillas/termicas/Tecla2_Abajo.PNG"
                    fillMode: Image.PreserveAspectFit
                    opacity: 0
                }

                MouseArea {
                    id: mouseAreaT14
                    x: 0
                    y: 0
                    width: 29
                    height: 39
                }
            }

            Item {
                id: t15
                width: 30
                height: 39
                property string thermal: "DEFAULT"

                Image {
                    id: conT15
                    x: 0
                    y: 0
                    width: 29
                    height: 39
                    source: "../Source/images/perillas/termicas/Tecla2_Arriba.PNG"
                    fillMode: Image.PreserveAspectFit
                    opacity: 1
                }

                Image {
                    id: desT15
                    x: 0
                    y: 6
                    width: 28
                    height: 33
                    source: "../Source/images/perillas/termicas/Tecla2_Abajo.PNG"
                    fillMode: Image.PreserveAspectFit
                    opacity: 0
                }

                MouseArea {
                    id: mouseAreaT15
                    x: 0
                    y: 0
                    width: 29
                    height: 39
                }
            }

            Item {
                id: t16
                width: 31
                height: 39
                property string thermal: "DEFAULT"

                Image {
                    id: conT16
                    x: 0
                    y: 0
                    width: 29
                    height: 39
                    source: "../Source/images/perillas/termicas/Tecla2_Arriba.PNG"
                    fillMode: Image.PreserveAspectFit
                    opacity: 1
                }

                Image {
                    id: desT16
                    x: 0
                    y: 6
                    width: 28
                    height: 33
                    source: "../Source/images/perillas/termicas/Tecla2_Abajo.PNG"
                    fillMode: Image.PreserveAspectFit
                    opacity: 0
                }

                MouseArea {
                    id: mouseAreaT16
                    x: 0
                    y: 0
                    width: 29
                    height: 39
                }
            }

            Item {
                id: t17
                width: 33
                height: 39
                property string thermal: "DEFAULT"

                Image {
                    id: conT17
                    objectName: "conT17"
                    x: 0
                    y: 0
                    width: 29
                    height: 39
                    source: "../Source/images/perillas/termicas/Tecla2_Arriba.PNG"
                    fillMode: Image.PreserveAspectFit
                    opacity: 1
                }

                Image {
                    id: desT17
                    objectName: "desT17"
                    x: 0
                    y: 6
                    width: 28
                    height: 33
                    source: "../Source/images/perillas/termicas/Tecla2_Abajo.PNG"
                    fillMode: Image.PreserveAspectFit
                    opacity: 0
                }

                MouseArea {
                    id: mouseAreaT17
                    x: 0
                    y: 0
                    width: 29
                    height: 39
                    onClicked: {
                        if (conT17.opacity == 0){
                            conT17.opacity = 1;
                            desT17.opacity = 0;
                            level3.selected((level3.type)+(t17.thermal)+(level3.numberWagon)+"con");
                        }else{
                            desT17.opacity = 1;
                            conT17.opacity = 0;
                            level3.selected((level3.type)+(t17.thermal)+(level3.numberWagon)+"des");
                        }
                    }//onClicked
                }
            }

            Item {
                id: t18
                width: 30
                height: 39
                property string thermal: "DEFAULT"
                Image {
                    id: conT18
                    x: 0
                    y: 0
                    width: 29
                    height: 39
                    source: "../Source/images/perillas/termicas/Tecla2_Arriba.PNG"
                    fillMode: Image.PreserveAspectFit
                    opacity: 1
                }

                Image {
                    id: desT18
                    x: 0
                    y: 6
                    width: 28
                    height: 33
                    source: "../Source/images/perillas/termicas/Tecla2_Abajo.PNG"
                    fillMode: Image.PreserveAspectFit
                    opacity: 0
                }

                MouseArea {
                    id: mouseAreaT18
                    x: 0
                    y: 0
                    width: 29
                    height: 39
                }
            }

            Item {
                id: t19
                width: 31
                height: 39
                property string thermal: "DEFAULT"
                Image {
                    id: conT19
                    x: 0
                    y: 0
                    width: 29
                    height: 39
                    source: "../Source/images/perillas/termicas/Tecla2_Arriba.PNG"
                    fillMode: Image.PreserveAspectFit
                    opacity: 1
                }

                Image {
                    id: desT19
                    x: 0
                    y: 6
                    width: 28
                    height: 33
                    source: "../Source/images/perillas/termicas/Tecla2_Abajo.PNG"
                    fillMode: Image.PreserveAspectFit
                    opacity: 0
                }

                MouseArea {
                    id: mouseAreaT19
                    x: 0
                    y: 0
                    width: 29
                    height: 39
                }
            }

            Item {
                id: t20
                width: 30
                height: 39
                property string thermal: "57f1"

                Image {
                    id: conT20
                    x: 0
                    y: 0
                    width: 29
                    height: 39
                    source: "../Source/images/perillas/termicas/Tecla2_Arriba.PNG"
                    fillMode: Image.PreserveAspectFit
                    opacity: 1
                }

                Image {
                    id: desT20
                    x: 0
                    y: 6
                    width: 28
                    height: 33
                    source: "../Source/images/perillas/termicas/Tecla2_Abajo.PNG"
                    fillMode: Image.PreserveAspectFit
                    opacity: 0
                }

                MouseArea {
                    id: mouseAreaT20
                    x: 0
                    y: 0
                    width: 29
                    height: 39
                    onClicked: {
                        if (conT20.opacity == 0){
                            conT20.opacity = 1;
                            desT20.opacity = 0;
                            level3.selected((level3.type)+(t20.thermal)+(level3.numberWagon)+"con");
                        }else{
                            desT20.opacity = 1;
                            conT20.opacity = 0;
                            level3.selected((level3.type)+(t20.thermal)+(level3.numberWagon)+"des");
                        }
                    }//onClicked
                }
            }

            Item {
                id: t21
                width: 30
                height: 39
                property string thermal: "DEFAULT"

                Image {
                    id: conT21
                    x: 0
                    y: 0
                    width: 29
                    height: 39
                    source: "../Source/images/perillas/termicas/Tecla2_Arriba.PNG"
                    fillMode: Image.PreserveAspectFit
                    opacity: 1
                }

                Image {
                    id: desT21
                    x: 0
                    y: 6
                    width: 28
                    height: 33
                    source: "../Source/images/perillas/termicas/Tecla2_Abajo.PNG"
                    fillMode: Image.PreserveAspectFit
                    opacity: 0
                }

                MouseArea {
                    id: mouseAreaT21
                    x: 0
                    y: 0
                    width: 29
                    height: 39
                }
            }
        }

        Row {
            id: row3
            x: 339
            y: 335
            width: 417
            height: 39
            spacing: 12
            Item {
                id: t22
                width: 30
                height: 39
                property string thermal: "DEFAULT"

                Image {
                    id: conT22
                    x: 0
                    y: 0
                    width: 29
                    height: 39
                    source: "../Source/images/perillas/termicas/Tecla2_Arriba.PNG"
                    fillMode: Image.PreserveAspectFit
                    opacity: 1
                }

                Image {
                    id: desT22
                    x: 0
                    y: 6
                    width: 28
                    height: 33
                    source: "../Source/images/perillas/termicas/Tecla2_Abajo.PNG"
                    fillMode: Image.PreserveAspectFit
                    opacity: 0
                }

                MouseArea {
                    id: mouseAreaT22
                    x: 0
                    y: 0
                    width: 29
                    height: 39
                }
            }

            Item {
                id: t23
                width: 30
                height: 39
                property string thermal: "DEFAULT"

                Image {
                    id: conT23
                    x: 0
                    y: 0
                    width: 29
                    height: 39
                    source: "../Source/images/perillas/termicas/Tecla2_Arriba.PNG"
                    fillMode: Image.PreserveAspectFit
                    opacity: 1
                }

                Image {
                    id: desT23
                    x: 0
                    y: 6
                    width: 28
                    height: 33
                    source: "../Source/images/perillas/termicas/Tecla2_Abajo.PNG"
                    fillMode: Image.PreserveAspectFit
                    opacity: 0
                }

                MouseArea {
                    id: mouseAreaT23
                    x: 0
                    y: 0
                    width: 29
                    height: 39
                }
            }

            Item {
                id: t24
                width: 32
                height: 39
                property string thermal: "DEFAULT"

                Image {
                    id: conT24
                    x: 0
                    y: 0
                    width: 29
                    height: 39
                    source: "../Source/images/perillas/termicas/Tecla2_Arriba.PNG"
                    fillMode: Image.PreserveAspectFit
                    opacity: 1
                }

                Image {
                    id: desT24
                    x: 0
                    y: 6
                    width: 28
                    height: 33
                    source: "../Source/images/perillas/termicas/Tecla2_Abajo.PNG"
                    fillMode: Image.PreserveAspectFit
                    opacity: 0
                }

                MouseArea {
                    id: mouseAreaT24
                    x: 0
                    y: 0
                    width: 29
                    height: 39
                }
            }

            Item {
                id: t25
                width: 30
                height: 39
                property string thermal: "DEFAULT"

                Image {
                    id: conT25
                    x: 0
                    y: 0
                    width: 29
                    height: 39
                    source: "../Source/images/perillas/termicas/Tecla2_Arriba.PNG"
                    fillMode: Image.PreserveAspectFit
                    opacity: 1
                }

                Image {
                    id: desT25
                    x: 0
                    y: 6
                    width: 28
                    height: 33
                    source: "../Source/images/perillas/termicas/Tecla2_Abajo.PNG"
                    fillMode: Image.PreserveAspectFit
                    opacity: 0
                }

                MouseArea {
                    id: mouseAreaT25
                    x: 0
                    y: 0
                    width: 29
                    height: 39
                }
            }

            Item {
                id: t26
                x: 173
                width: 30
                height: 39
                property string thermal: "DEFAULT"

                Image {
                    id: conT26
                    x: 0
                    y: 0
                    width: 29
                    height: 39
                    source: "../Source/images/perillas/termicas/Tecla2_Arriba.PNG"
                    fillMode: Image.PreserveAspectFit
                    opacity: 1
                }

                Image {
                    id: desT26
                    x: 0
                    y: 6
                    width: 28
                    height: 33
                    source: "../Source/images/perillas/termicas/Tecla2_Abajo.PNG"
                    fillMode: Image.PreserveAspectFit
                    opacity: 0
                }

                MouseArea {
                    id: mouseAreaT26
                    x: 0
                    y: 0
                    width: 29
                    height: 39
                }
            }

            Item {
                id: t27
                width: 30
                height: 39
                property string thermal: "DEFAULT"

                Image {
                    id: conT27
                    x: 0
                    y: 0
                    width: 29
                    height: 39
                    source: "../Source/images/perillas/termicas/Tecla2_Arriba.PNG"
                    fillMode: Image.PreserveAspectFit
                    opacity: 1
                }

                Image {
                    id: desT27
                    x: 0
                    y: 6
                    width: 28
                    height: 33
                    source: "../Source/images/perillas/termicas/Tecla2_Abajo.PNG"
                    fillMode: Image.PreserveAspectFit
                    opacity: 0
                }

                MouseArea {
                    id: mouseAreaT27
                    x: 0
                    y: 0
                    width: 29
                    height: 39
                }
            }

            Item {
                id: t28
                width: 30
                height: 39
                property string thermal: "DEFAULT"

                Image {
                    id: conT28
                    x: 0
                    y: 0
                    width: 29
                    height: 39
                    source: "../Source/images/perillas/termicas/Tecla2_Arriba.PNG"
                    fillMode: Image.PreserveAspectFit
                    opacity: 1
                }

                Image {
                    id: desT28
                    x: 0
                    y: 6
                    width: 28
                    height: 33
                    source: "../Source/images/perillas/termicas/Tecla2_Abajo.PNG"
                    fillMode: Image.PreserveAspectFit
                    opacity: 0
                }

                MouseArea {
                    id: mouseAreaT28
                    x: 0
                    y: 0
                    width: 29
                    height: 39
                }
            }

            Item {
                id: t29
                width: 33
                height: 39
                property string thermal: "DEFAULT"

                Image {
                    id: conT29
                    x: 0
                    y: 0
                    width: 29
                    height: 39
                    source: "../Source/images/perillas/termicas/Tecla2_Arriba.PNG"
                    fillMode: Image.PreserveAspectFit
                    opacity: 1
                }

                Image {
                    id: desT29
                    x: 0
                    y: 6
                    width: 28
                    height: 33
                    source: "../Source/images/perillas/termicas/Tecla2_Abajo.PNG"
                    fillMode: Image.PreserveAspectFit
                    opacity: 0
                }

                MouseArea {
                    id: mouseAreaT29
                    x: 0
                    y: 0
                    width: 29
                    height: 39
                }
            }

            Item {
                id: t30
                width: 30
                height: 39
                property string thermal: "DEFAULT"

                Image {
                    id: conT30
                    x: 0
                    y: 0
                    width: 29
                    height: 39
                    source: "../Source/images/perillas/termicas/Tecla2_Arriba.PNG"
                    fillMode: Image.PreserveAspectFit
                    opacity: 1
                }

                Image {
                    id: desT30
                    x: 0
                    y: 6
                    width: 28
                    height: 33
                    source: "../Source/images/perillas/termicas/Tecla2_Abajo.PNG"
                    fillMode: Image.PreserveAspectFit
                    opacity: 0
                }

                MouseArea {
                    id: mouseAreaT30
                    x: 0
                    y: 0
                    width: 29
                    height: 39
                }
            }

            Item {
                id: t31
                width: 31
                height: 39
                property string thermal: "DEFAULT"

                Image {
                    id: conT31
                    x: 0
                    y: 0
                    width: 29
                    height: 39
                    source: "../Source/images/perillas/termicas/Tecla2_Arriba.PNG"
                    fillMode: Image.PreserveAspectFit
                    opacity: 1
                }

                Image {
                    id: desT31
                    x: 0
                    y: 6
                    width: 28
                    height: 33
                    source: "../Source/images/perillas/termicas/Tecla2_Abajo.PNG"
                    fillMode: Image.PreserveAspectFit
                    opacity: 0
                }

                MouseArea {
                    id: mouseAreaT31
                    x: 0
                    y: 0
                    width: 29
                    height: 39
                }
            }
        }

        Row {
            id: row4
            x: 339
            y: 469
            width: 417
            height: 39
            spacing: 12
            Item {
                id: t32
                width: 30
                height: 39
                property string thermal: "DEFAULT"

                Image {
                    id: conT32
                    x: 0
                    y: 0
                    width: 29
                    height: 39
                    source: "../Source/images/perillas/termicas/Tecla2_Arriba.PNG"
                    fillMode: Image.PreserveAspectFit
                    opacity: 1
                }

                Image {
                    id: desT32
                    x: 0
                    y: 6
                    width: 28
                    height: 33
                    source: "../Source/images/perillas/termicas/Tecla2_Abajo.PNG"
                    fillMode: Image.PreserveAspectFit
                    opacity: 0
                }

                MouseArea {
                    id: mouseAreaT32
                    x: 0
                    y: 0
                    width: 29
                    height: 39
                }
            }

            Item {
                id: t33
                width: 30
                height: 39
                property string thermal: "DEFAULT"

                Image {
                    id: conT33
                    x: 0
                    y: 0
                    width: 29
                    height: 39
                    source: "../Source/images/perillas/termicas/Tecla2_Arriba.PNG"
                    fillMode: Image.PreserveAspectFit
                    opacity: 1
                }

                Image {
                    id: desT33
                    x: 0
                    y: 6
                    width: 28
                    height: 33
                    source: "../Source/images/perillas/termicas/Tecla2_Abajo.PNG"
                    fillMode: Image.PreserveAspectFit
                    opacity: 0
                }

                MouseArea {
                    id: mouseAreaT33
                    x: 0
                    y: 0
                    width: 29
                    height: 39
                }
            }

            Item {
                id: t34
                width: 32
                height: 39
                property string thermal: "DEFAULT"

                Image {
                    id: conT34
                    x: 0
                    y: 0
                    width: 29
                    height: 39
                    source: "../Source/images/perillas/termicas/Tecla2_Arriba.PNG"
                    fillMode: Image.PreserveAspectFit
                    opacity: 1
                }

                Image {
                    id: desT34
                    x: 0
                    y: 6
                    width: 28
                    height: 33
                    source: "../Source/images/perillas/termicas/Tecla2_Abajo.PNG"
                    fillMode: Image.PreserveAspectFit
                    opacity: 0
                }

                MouseArea {
                    id: mouseAreaT34
                    x: 0
                    y: 0
                    width: 29
                    height: 39
                }
            }

            Item {
                id: t35
                width: 30
                height: 39
                property string thermal: "DEFAULT"

                Image {
                    id: conT35
                    x: 0
                    y: 0
                    width: 29
                    height: 39
                    source: "../Source/images/perillas/termicas/Tecla2_Arriba.PNG"
                    fillMode: Image.PreserveAspectFit
                    opacity: 1
                }

                Image {
                    id: desT35
                    x: 0
                    y: 6
                    width: 28
                    height: 33
                    source: "../Source/images/perillas/termicas/Tecla2_Abajo.PNG"
                    fillMode: Image.PreserveAspectFit
                    opacity: 0
                }

                MouseArea {
                    id: mouseAreaT35
                    x: 0
                    y: 0
                    width: 29
                    height: 39
                }
            }

            Item {
                id: t36
                x: 173
                width: 30
                height: 39
                property string thermal: "DEFAULT"

                Image {
                    id: conT36
                    x: 0
                    y: 0
                    width: 29
                    height: 39
                    source: "../Source/images/perillas/termicas/Tecla2_Arriba.PNG"
                    fillMode: Image.PreserveAspectFit
                    opacity: 1
                }

                Image {
                    id: desT36
                    x: 0
                    y: 6
                    width: 28
                    height: 33
                    source: "../Source/images/perillas/termicas/Tecla2_Abajo.PNG"
                    fillMode: Image.PreserveAspectFit
                    opacity: 0
                }

                MouseArea {
                    id: mouseAreaT36
                    x: 0
                    y: 0
                    width: 29
                    height: 39
                }
            }

            Item {
                id: t37
                width: 30
                height: 39
                property string thermal: "DEFAULT"

                Image {
                    id: conT37
                    x: 0
                    y: 0
                    width: 29
                    height: 39
                    source: "../Source/images/perillas/termicas/Tecla2_Arriba.PNG"
                    fillMode: Image.PreserveAspectFit
                    opacity: 1
                }

                Image {
                    id: desT37
                    x: 0
                    y: 6
                    width: 28
                    height: 33
                    source: "../Source/images/perillas/termicas/Tecla2_Abajo.PNG"
                    fillMode: Image.PreserveAspectFit
                    opacity: 0
                }

                MouseArea {
                    id: mouseAreaT37
                    x: 0
                    y: 0
                    width: 29
                    height: 39
                }
            }

            Item {
                id: t38
                width: 30
                height: 39
                property string thermal: "DEFAULT"

                Image {
                    id: conT38
                    x: 0
                    y: 0
                    width: 29
                    height: 39
                    source: "../Source/images/perillas/termicas/Tecla2_Arriba.PNG"
                    fillMode: Image.PreserveAspectFit
                    opacity: 1
                }

                Image {
                    id: desT38
                    x: 0
                    y: 6
                    width: 28
                    height: 33
                    source: "../Source/images/perillas/termicas/Tecla2_Abajo.PNG"
                    fillMode: Image.PreserveAspectFit
                    opacity: 0
                }

                MouseArea {
                    id: mouseAreaT38
                    x: 0
                    y: 0
                    width: 29
                    height: 39
                }
            }

            Item {
                id: t39
                width: 33
                height: 39
                property string thermal: "DEFAULT"

                Image {
                    id: conT39
                    x: 0
                    y: 0
                    width: 29
                    height: 39
                    source: "../Source/images/perillas/termicas/Tecla2_Arriba.PNG"
                    fillMode: Image.PreserveAspectFit
                    opacity: 1
                }

                Image {
                    id: desT39
                    x: 0
                    y: 6
                    width: 28
                    height: 33
                    source: "../Source/images/perillas/termicas/Tecla2_Abajo.PNG"
                    fillMode: Image.PreserveAspectFit
                    opacity: 0
                }

                MouseArea {
                    id: mouseAreaT39
                    x: 0
                    y: 0
                    width: 29
                    height: 39
                }
            }

            Item {
                id: t40
                width: 30
                height: 39
                property string thermal: "DEFAULT"

                Image {
                    id: conT40
                    x: 0
                    y: 0
                    width: 29
                    height: 39
                    source: "../Source/images/perillas/termicas/Tecla2_Arriba.PNG"
                    fillMode: Image.PreserveAspectFit
                    opacity: 1
                }

                Image {
                    id: desT40
                    x: 0
                    y: 6
                    width: 28
                    height: 33
                    source: "../Source/images/perillas/termicas/Tecla2_Abajo.PNG"
                    fillMode: Image.PreserveAspectFit
                    opacity: 0
                }

                MouseArea {
                    id: mouseAreaT40
                    x: 0
                    y: 0
                    width: 29
                    height: 39
                }
            }

            Item {
                id: t41
                width: 31
                height: 39
                property string thermal: "DEFAULT"

                Image {
                    id: conT41
                    x: 0
                    y: 0
                    width: 29
                    height: 39
                    source: "../Source/images/perillas/termicas/Tecla2_Arriba.PNG"
                    fillMode: Image.PreserveAspectFit
                    opacity: 1
                }

                Image {
                    id: desT41
                    x: 0
                    y: 6
                    width: 28
                    height: 33
                    source: "../Source/images/perillas/termicas/Tecla2_Abajo.PNG"
                    fillMode: Image.PreserveAspectFit
                    opacity: 0
                }

                MouseArea {
                    id: mouseAreaT41
                    x: 0
                    y: 0
                    width: 29
                    height: 39
                }
            }
        }
    }//Item itemThermalPanel

    //Item diferentes:
    Item {
        id: d1
        x: 253
        y: 90
        width: 82
        height: 34
        z: 1
        property string thermal: "termicaNaranja"

        Image {
            id: conD1
            x: 0
            y: 0
            width: 82
            height: 34
            fillMode: Image.PreserveAspectFit
            source: "../Source/images/perillas/termicas/Tecla1_Arriba.PNG"
            opacity: 1
        }
        Image {
            id: desD1
            x: 0
            y: 0
            width: 82
            height: 34
            opacity: 0
            fillMode: Image.PreserveAspectFit
            source: "../Source/images/perillas/termicas/tecla1_Abajo.PNG"
        }

        MouseArea {
            id: mouseAreaD1
            x: 18
            y: 0
            width: 48
            height: 34
            z: 1
            onClicked: {
                if (conD1.opacity == 0){
                    conD1.opacity = 1;
                    desD1.opacity = 0;
                    level3.selected((level3.type)+(d1.thermal)+(level3.numberWagon)+"con");
                }else{
                    conD1.opacity = 0;
                    desD1.opacity = 1;
                    level3.selected((level3.type)+(d1.thermal)+(level3.numberWagon)+"des");
                }
            }
        }
    }

    Item {
        id: d2
        x: 297
        y: 343
        width: 27
        height: 34
        property string thermal: "55f3"

        Image {
            id: conD2
            x: 0
            y: 0
            width: 27
            height: 34
            fillMode: Image.PreserveAspectFit
            source: "../Source/images/perillas/termicas/Tecla3_Arriba.PNG"
            opacity: 1
        }
        Image {
            id: desD2
            x: 0
            y: 0
            width: 27
            height: 34
            fillMode: Image.PreserveAspectFit
            source: "../Source/images/perillas/termicas/Tecla3_Abajo.PNG"
            opacity: 0
        }

        MouseArea {
            id: mouseAreaD2
            width: 27
            height: 34
            onClicked: {
                if (conD2.opacity == 0){
                    conD2.opacity = 1;
                    desD2.opacity = 0;
                    level3.selected((level3.type)+(d2.thermal)+(level3.numberWagon)+"con");
                }else{
                    conD2.opacity = 0;
                    desD2.opacity = 1;
                    level3.selected((level3.type)+(d2.thermal)+(level3.numberWagon)+"des");
                }
            }
        }
    }

    Item {
        id: d3
        x: 261
        y: 477
        z: 1
        width: 69
        height: 29
        property string thermal: "36f4"

        Image {
            id: conD3
            width: 69
            height: 29
            fillMode: Image.PreserveAspectFit
            source: "../Source/images/perillas/termicas/Tecla1_Arriba.PNG"
            opacity: 1
        }
        Image {
            id: desD3
            width: 69
            height: 29
            fillMode: Image.PreserveAspectFit
            source: "../Source/images/perillas/termicas/Tecla1_Arriba.PNG"
            opacity: 0
        }

        MouseArea {
            id: mouseAreaD3
            width: 69
            height: 29
            z: 1
            opacity: 1
            onClicked: {
                if (conD3.opacity == 0){
                    conD3.opacity = 1;
                    desD3.opacity = 0;
                    level3.selected((level3.type)+(d3.thermal)+(level3.numberWagon)+"con");
                }else{
                    conD3.opacity = 0;
                    desD3.opacity = 1;
                    level3.selected((level3.type)+(d3.thermal)+(level3.numberWagon)+"des");
                }
            }
        }
    }

    Item {
        id: r1
        x: 230
        y: 600
        width: 112
        height: 26
        property string thermal: "switchRed"

        Image {
            id: conR1
            width: 112
            height: 26
            rotation: 90
            fillMode: Image.PreserveAspectFit
            source: "../Source/images/perillas/termicas/termicas_roja.PNG"
        }

        MouseArea {
            id: mouseAreaR1
            x: 0
            y: -37
            width: 112
            height: 97
            onClicked: {
                if (conR1.rotation == 0){
                    conR1.rotation = 90;
                    level3.selected((level3.type)+(r1.thermal)+(level3.numberWagon)+"con");
                }else{
                    conR1.rotation = 0;
                    level3.selected((level3.type)+(r1.thermal)+(level3.numberWagon)+"des");
                }
            }
        }
    }

    property int thermalIndex: 1
    property int cantThermal: 41
    property int cantOther: 3

    //Reseteo todo a CON + 90
    function resetThermal(op){
//        for (thermalIndex=1; thermalIndex <= cantThermal; thermalIndex ++){
//            (desT(thermalIndex)).opacity=0;
//            (conT(thermalIndex)).opacity=1;
//        }
//        for (thermalIndex=1; thermalIndex <= cantOther; thermalIndex ++){
//            (desD+(thermalIndex.toString())).opacity=0;
//            (conD+(thermalIndex.toString())).opacity=1;
//        }
//        conR1.rotation = 90;

    }

}//Rectangle

