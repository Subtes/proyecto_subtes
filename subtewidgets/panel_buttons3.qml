import QtQuick 2.0

Rectangle {
    width: 150
    height: 280
    color: "#00000000"
    border.color: "#00000000"

    id: panelButtons

    signal firstClicked()
    signal secondClicked()
    signal thirdClicked()

    Image {
        id: backgroud
        anchors.fill: parent
        sourceSize.height: 280
        sourceSize.width: 150
        source: "resources/BKG_botonera.png"
    }

    Column {
        id: column
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
            id: first
            objectName: "first"
            width: 150
            height: 65

            Image {
                id: firstOFF
                objectName: "firstOFF"
                anchors.fill: parent
                transformOrigin: Item.Center
                fillMode: Image.PreserveAspectFit
                source: "resources/blue.PNG"
                opacity: 1
            }

            Image {
                id: firstON
                objectName: "firstON"
                anchors.fill: parent
                transformOrigin: Item.Center
                fillMode: Image.PreserveAspectFit
                source: "resources/blueON.png"
                opacity: 0
            }

            states: [
                State {
                    name: "stateFirstOn";
                    PropertyChanges { target: firstON;opacity: 1}
                },
                State {
                    name: "stateFirstOff";
                    PropertyChanges { target: firstON; opacity: 0}
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

                    if (first.state == "stateFirstOn")
                        first.state = "stateFirstOff"
                    else
                        first.state = "stateFirstOn"
                    panelButtons.firstClicked()
                }
            }
        }

        Item {
            id: second
            objectName: "second"
            width: 150
            height: 65

            Image {
                id: secondOFF
                objectName: "secondOFF"
                anchors.fill: parent
                fillMode: Image.PreserveAspectFit
                source: "resources/green.PNG"
                opacity: 1
            }

            Image {
                id: secondON
                objectName: "secondON"
                anchors.fill: parent
                fillMode: Image.PreserveAspectFit
                source: "resources/greenON.png"
                opacity: 0
            }

            states: [
                State {
                    name: "stateSecondOn";
                    PropertyChanges { target: secondON;opacity: 1}
                },
                State {
                    name: "stateSecondOff";
                    PropertyChanges { target: secondON; opacity: 0}
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

                    if (second.state == "stateSecondOn")
                        second.state = "stateSecondOff"
                    else
                        second.state = "stateSecondOn"
                    panelButtons.secondClicked()
                }
            }
        }

        Item {
            id: third
            objectName: "third"
            width: 150
            height: 65

            Image {
                id: thirdOFF
                objectName: "thirdOFF"
                anchors.fill: parent
                fillMode: Image.PreserveAspectFit
                source: "resources/red.PNG"
                opacity: 1
            }

            Image {
                id: thirdON
                objectName: "thirdON"
                anchors.fill: parent
                fillMode: Image.PreserveAspectFit
                source: "resources/redON.png"
                opacity: 0
            }

            states: [
                State {
                    name: "stateThirdOn";
                    PropertyChanges { target: thirdON;opacity: 1}
                },
                State {
                    name: "stateThirdOff";
                    PropertyChanges { target: thirdON; opacity: 0}

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

                    if (third.state == "stateThirdOn")
                        third.state = "stateThirdOff"
                    else
                        third.state = "stateThirdOn"
                    panelButtons.thirdClicked()
                }
            }
        }
    }
}

