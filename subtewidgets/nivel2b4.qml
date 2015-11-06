import QtQuick 2.0

Rectangle {
    id: level2
    objectName: "panelLevel2"
    x: 0
    y: 0
    width: 124
    height: 675

    signal selected(string s)

    Item{
        id: b1
        x: parent.x
        y: parent.y
        objectName: "button1"
        width: level2.width
        height: level2.height / 4

        Image{
            id: button1Image
            objectName: "button1Image"
            anchors.fill: parent
            source: "N2-b-grifos"
            opacity: 1
        }

        MouseArea{
            id: mouseAreaButton1
            anchors.fill: parent
            onClicked: {
                level2.selected("B1;"+button1Image.objectName);
                console.log("On Click, Mouse Area Button 1")
            }
        }

    }
}
