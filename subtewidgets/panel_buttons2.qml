import QtQuick 2.0

Rectangle {
    width: 100
    height: 150

    id: panelButtons2

    signal blueClicked()
    signal redClicked()

    Image {
        id: image1
        anchors.fill: parent
        source: "resources/BKG_botonera_HM.png"

        Column {
            id: column1
            anchors.fill: parent

            Item {
                id: red
                y: 0
                width: 100
                height: 75

                Image {
                    id: redOFF
                    x: 0
                    y: 0
                    width: 65
                    height: 65
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.verticalCenter: parent.verticalCenter
                    source: "resources/red.PNG"
                    opacity: 1
                }

                Image {
                    id: redON
                    x: 0
                    y: 0
                    width: 65
                    height: 65
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.verticalCenter: parent.verticalCenter
                    source: "resources/redON.png"
                    opacity: 0
                }

                states: [
                    State {
                        name: "stateRedOn";
                        PropertyChanges { target: redON;opacity: 1}
                    },
                    State {
                        name: "stateRedOff";
                        PropertyChanges { target: redON; opacity: 0}

                    }
                ]

                transitions:[
                    Transition {
                        from: "*"
                        to: "*"
                        NumberAnimation { properties: "opacity"; duration: 200  }
                    }
                ]

                MouseArea {
                    anchors.fill: parent
                    onClicked: {

                        if (red.state == "stateRedOn")
                            red.state = "stateRedOff"
                        else
                            red.state = "stateRedOn"
                        panelButtons2.blueClicked()
                    }
                }
            }

            Item {
                id: blue
                y: 75
                width: 100
                height: 75
                transformOrigin: Item.Center
                anchors.horizontalCenter: parent.horizontalCenter

                Image {
                    id: blueOFF
                    x: 0
                    y: 0
                    width: 65
                    height: 65
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.verticalCenter: parent.verticalCenter
                    source: "resources/blue.PNG"
                    opacity: 1
                }

                Image {
                    id: blueON
                    x: 0
                    y: 0
                    width: 65
                    height: 65
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.verticalCenter: parent.verticalCenter
                    source: "resources/blueON.png"
                    opacity: 0
                }

                states: [
                    State {
                        name: "stateBlueOn";
                        PropertyChanges { target: blueON;opacity: 1}
                    },
                    State {
                        name: "stateBlueOff";
                        PropertyChanges { target: blueON; opacity: 0}

                    }
                ]

                transitions:[
                    Transition {
                        from: "*"
                        to: "*"
                        NumberAnimation { properties: "opacity"; duration: 200  }
                    }
                ]

                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        if (blue.state == "stateBlueOn")
                            blue.state = "stateBlueOff"
                        else
                            blue.state = "stateBlueOn"
                        panelButtons2.blueClicked()
                    }
                }
            }
        }
    }
}

