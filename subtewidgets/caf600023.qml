import QtQuick 2.0

Rectangle {
    z: 0
    id: formacion
    width: 1024
    height: 93

    signal selected(string s)

    Item {
        id: coche1
        anchors.fill: parent
        z: 1

        Image {
            id: coche1Image
            anchors.fill: parent
            source: "C1"
            opacity: 0
        }

        MouseArea {
            id: mouseAreaCoche1
            x: 20
            y: 0
            width: 160
            height: 93
            onClicked: {
                if (coche1Image.opacity == 0){
                    formacion.state = "formacionBackground";
                    coche1Image.opacity = 1;
                    selected("coche1");
                }else{
                    coche1Image.opacity = 0;
                    formacion.state = "formacionAll";
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
            id: coche2Image
            anchors.fill: parent
            source: "C2"
            opacity: 0
        }

        MouseArea {
            id: mouseAreaCoche2
            x: 181
            y: 0
            width: 160
            height: 93
            onClicked: {
                if (coche2Image.opacity == 0){
                    formacion.state = "formacionBackground";
                    coche2Image.opacity = 1;
                    selected("coche2");
                }else{
                    coche2Image.opacity = 0;
                    formacion.state = "formacionAll";
                }
                console.log("On Click, mouseAreaCoche2")
            }
        }
    }//Item2, coche2

    Image{
        id: bck
        z:0
        anchors.fill: parent
        source: "MM-MM-MM-BCK"
        opacity: 1
    }

    Image{
        id: bckGrey
        z:0
        opacity: 0
        anchors.fill: parent
        source: "MM-MM-MM-BCK-GREY"
    }

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
        }
    ]

    state: "formacionAll"
}//Rectangle
