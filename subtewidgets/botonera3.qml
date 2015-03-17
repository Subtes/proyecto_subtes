import QtQuick 2.0

Rectangle {
    width: 150
    height: 280
    color: "#00000000"
    border.color: "#00000000"

    id: botonera
    signal blueClicked()
    signal redClicked()
    signal greenClicked()

    Image {
        id: image1
        anchors.fill: parent
        sourceSize.height: 280
        sourceSize.width: 150
        source: "resources/BKG_botonera.png"
    }

    Column {
        id: column1
        x: 0
        y: 26
        width: 150
        height: 264
        anchors.topMargin: 26
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        anchors.top: parent.top
        scale: 1
        spacing: 10

        Item {
            id: blue
            width: 150
            height: 65

            Image {
                id: blueOFF
                anchors.fill: parent
                transformOrigin: Item.Center
                fillMode: Image.PreserveAspectFit
                source: "resources/blue.PNG"
                opacity: 1
            }

            Image {
                id: blueON
                anchors.fill: parent
                fillMode: Image.PreserveAspectFit
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
                    botonera.blueClicked()
                }
            }

        }

        Item {
            id: green
            width: 150
            height: 65

            Image {
                id: greenOFF
                anchors.fill: parent
                fillMode: Image.PreserveAspectFit
                source: "resources/green.PNG"
                opacity: 1
            }

            Image {
                id: greenON
                anchors.fill: parent
                fillMode: Image.PreserveAspectFit
                source: "resources/greenON.png"
                opacity: 0
            }

            states: [
                State {
                    name: "stateGreenOn";
                    PropertyChanges { target: greenON;opacity: 1}
                },
                State {
                    name: "stateGreenOff";
                    PropertyChanges { target: greenON; opacity: 0}

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

                    if (green.state == "stateGreenOn")
                        green.state = "stateGreenOff"
                    else
                        green.state = "stateGreenOn"
                    botonera.greenClicked()
                }
            }

        }

        Item {
            id: red
            width: 150
            height: 65

            Image {
                id: redOFF
                anchors.fill: parent
                fillMode: Image.PreserveAspectFit
                source: "resources/red.PNG"
                opacity: 1
            }

            Image {
                id: redON
                anchors.fill: parent
                fillMode: Image.PreserveAspectFit
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
                    botonera.redClicked()
                }
            }
        }
    }
}

