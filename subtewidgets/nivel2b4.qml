import QtQuick 2.0

Rectangle {
    id: level2
    objectName: "panelLevel2"
    x: 0
    y: 0
    width: 124
    height: 675

    signal selected(string s)

    property  int  index: 0
    //Recursos asociados a los botones que seran instanciados segun configuracion del coche.
    property variant buttonsResources: []

    Column {
        id: column1
        x: 0
        y: 0
        width: 124
        height: 675

        Item{
            id: b0
            width: 119
            height: 92
            objectName: "button0"

            Image{
                id: buttonImage0
                x: 0
                y: 0
                width: 119
                height: 92
                fillMode: Image.PreserveAspectFit
                anchors.leftMargin: 3
                anchors.topMargin: 3
                anchors.rightMargin: -3
                anchors.bottomMargin: -3
                anchors.fill: parent

                objectName: "buttonImage0"
                source: "NO-OPTION"
                opacity: 1

            }

            MouseArea{
                id: mouseAreaButton0
                width: 119
                height: 92
                anchors.fill: parent
                onClicked: {
                    level2.selected(buttonsResources[0]);
                    console.log("LEVEL 2: On Click, Mouse Area Button: ",b0.objectName)
                }
            }

        }

        Item {
            id: b1
            width: 119
            height: 92
            objectName: "button1"

            Image {
                id: buttonImage1
                x: 0
                y: 0
                width: 119
                height: 92
                anchors.leftMargin: 3
                anchors.rightMargin: -3
                anchors.topMargin: 3
                anchors.fill: parent
                fillMode: Image.PreserveAspectFit
                anchors.bottomMargin: -3

                objectName: "buttonImage1"
                source: "NO-OPTION"
                opacity: 1
            }

            MouseArea {
                id: mouseAreaButton1
                width: 119
                height: 92
                anchors.fill: parent
                onClicked: {
                    level2.selected(buttonsResources[1]);
                    console.log("LEVEL 2: On Click, Mouse Area Button: ",b1.objectName)
                }
            }
        }

        Item {
            id: b2
            width: 119
            height: 92
            objectName: "button2"

            Image {
                id: buttonImage2
                x: 0
                y: 0
                width: 119
                height: 92
                anchors.leftMargin: 3
                anchors.rightMargin: -3
                anchors.topMargin: 3
                anchors.fill: parent
                fillMode: Image.PreserveAspectFit
                anchors.bottomMargin: -3

                objectName: "buttonImage2"
                source: "NO-OPTION"
                opacity: 1
            }

            MouseArea {
                id: mouseAreaButton2
                width: 119
                height: 92
                anchors.fill: parent
                onClicked: {
                    level2.selected(buttonsResources[2]);
                    console.log("LEVEL 2: On Click, Mouse Area Button 2 ", b2.objectName)
                }
            }
        }

        Item {
            id: b3
            width: 119
            height: 92
            objectName: "button3"

            Image {
                id: buttonImage3
                x: 0
                y: 0
                width: 119
                height: 92
                anchors.leftMargin: 3
                anchors.rightMargin: -3
                anchors.topMargin: 3
                anchors.fill: parent
                fillMode: Image.PreserveAspectFit
                anchors.bottomMargin: -3

                objectName: "buttonImage3"
                source: "NO-OPTION"
                opacity: 1
            }

            MouseArea {
                id: mouseAreaButton3
                width: 119
                height: 92
                anchors.fill: parent
                onClicked: {
                    level2.selected(buttonsResources[3]);
                    console.log("LEVEL 2: On Click, Mouse Area Button 3 ",b3.objectName)
                }
            }
        }
    }

    function setResourceButton(aliasButton,tipoRecurso,resourceButton){
        console.log("setResourceButton: ......",aliasButton,"--",tipoRecurso,"--",resourceButton);
        buttonsResources[aliasButton] = tipoRecurso+";"+resourceButton;
    }

    property  int  indice: 0

    function resetResourceButton(resourceButton){
        for(indice=0; indice<4; indice ++){
            buttonsResources[indice] = resourceButton;
//            console.log("setResourceButton Button "+(indice+1).toString()+" : --->",resourceButton);
        }
    }
}
