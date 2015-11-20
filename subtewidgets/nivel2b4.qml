import QtQuick 2.0

Rectangle {
    id: level2
    objectName: "panelLevel2"
    x: 0
    y: 0
    width: 124
    height: 675

    signal selected(string s)
    property alias rb1 : buttonImage1.resourceButton
    property alias rb2 : buttonImage2.resourceButton
    property alias rb3 : buttonImage3.resourceButton
    property alias rb4 : buttonImage4.resourceButton

    Column {
        id: column1
        x: 0
        y: 0
        width: 124
        height: 675

        Item{
            id: b1
            width: 119
            height: 92
            objectName: "button1"

            Image{
                id: buttonImage1
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

                objectName: "buttonImage1"
                property string resourceButton:"NO-OPTION"
                //Text: "NO-OPTION"
                source: "NO-OPTION"
                opacity: 1

            }

            MouseArea{
                id: mouseAreaButton1
                width: 119
                height: 92
                anchors.fill: parent
                onClicked: {
                    level2.selected(buttonImage1.resourceButton.toString());
                    console.log("On Click, Mouse Area Button 1")
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
                property string resourceButton:"NO-OPTION"
                source: "NO-OPTION"
                opacity: 1
            }

            MouseArea {
                id: mouseAreaButton2
                width: 119
                height: 92
                anchors.fill: parent
                onClicked: {
                    level2.selected(buttonImage2.resourceButton.toString());
                    console.log("On Click, Mouse Area Button 2")
                }
            }
        }

        Item {
            id: b3
            width: 119
            height: 92
            objectName: "button1"
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
                property string resourceButton:"NO-OPTION"
                source: "NO-OPTION"
                opacity: 1
            }

            MouseArea {
                id: mouseAreaButton3
                width: 119
                height: 92
                anchors.fill: parent
                onClicked: {
                    level2.selected("B3;"+buttonImage3.objectName);
                    console.log("On Click, Mouse Area Button 3")
                }
            }
        }

        Item {
            id: b4
            width: 119
            height: 92
            objectName: "button1"
            Image {
                id: buttonImage4
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

                objectName: "buttonImage4"
                property string resourceButton:"NO-OPTION"
                source: "NO-OPTION"
                opacity: 1
            }

            MouseArea {
                id: mouseAreaButton4
                width: 119
                height: 92
                anchors.fill: parent
                onClicked: {
                    level2.selected("B4;"+buttonImage4.objectName);
                    console.log("On Click, Mouse Area Button 4")
                }
            }
        }



    }

    function setResourceButton(aliasButton,resourceButton){
        console.log("setResourceButton ANTES",aliasButton," ",resourceButton);
        aliasButton = resourceButton;
        console.log("setResourceButton DESPUES ",aliasButton," ",resourceButton);
    }
}
