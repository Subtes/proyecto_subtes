import QtQuick 2.0

Rectangle {
    id: modeDriveBck
    width: 410
    height: 207
    color: "#00000000"
    border.color: "#00000000"

    signal selectedOption(int op);

    Image {
        id: image1
        x: 67
        y: 50
        width: 75
        height: 75
        source: "resources/perilla.png"
    }
    Image {
        id: image2
        x: 170
        y: 14
        width: 144
        height: 154
        source: "resources/MODO_BASE.png"
    }
    Image {
        id: image3
        x: 173
        y: 41
        width: 136
        height: 136
        rotation: 0
        source: "resources/MODO_cmc.png"
    }

    MouseArea {
        id: mouseArea1
        x: 170
        y: 14
        width: 144
        height: 154
        onClicked: {
            if ( modeDriveBck.state == "StateCL"){
                modeDriveBck.state = "StateCMC";
                selectedOption(0);
                console.log("selected CMC: 0");
            }
            else{
                modeDriveBck.state = "StateCL";
                selectedOption(1);
                console.log("selected CL: 1");
            }
        }
    }

    states: [
        State {
            name: "StateCL"

            PropertyChanges {
                target: image3
                rotation: 65
            }
        },
        State {
            name: "StateCMC"

            PropertyChanges {
                target: image3
                rotation: 0
            }
        }
    ]
}
