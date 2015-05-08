import QtQuick 2.0

Rectangle {
    id: button
    width: 65
    height: 65
    color: "#00000000"

    signal buttonClicked()

    property bool nestled: false
    property bool lighted: true    

    Image {
        id: offImage
        objectName: "offImage"
        anchors.fill: parent
        source: "resources/red.png"
        opacity: 1
    }

    Image {
        id: onImage
        objectName: "onImage"
        anchors.fill: parent
        source: "resources/redON.png"
        opacity: 0
    }

    Image {
        id: offImageNestled
        objectName: "offImageNestled"
        anchors.fill: parent
        source: "resources/red_encl.png"
        opacity: 0
    }

    Image {
        id: onImageNestled
        objectName: "onImageNestled"
        anchors.fill: parent
        source: "resources/redON_encl.png"
        opacity: 0
    }

    states: [
        State {
            name: "buttonOffState";
            PropertyChanges { target: offImage;      opacity: 1}
            PropertyChanges { target: onImage;       opacity: 0}
            PropertyChanges { target: offImageNestled; opacity: 0}
            PropertyChanges { target: onImageNestled;  opacity: 0}
        },
        State {
            name: "buttonOnState";
            PropertyChanges { target: offImage;      opacity: 1}
            PropertyChanges { target: onImage;       opacity: 1}
            PropertyChanges { target: offImageNestled; opacity: 0}
            PropertyChanges { target: onImageNestled;  opacity: 0}
        },
        State {
            name: "buttonOffStateNestled";
            PropertyChanges { target: offImage;      opacity: 1}
            PropertyChanges { target: onImage;       opacity: 0}
            PropertyChanges { target: offImageNestled; opacity: 1}
            PropertyChanges { target: onImageNestled;  opacity: 0}
        },
        State {
            name: "buttonOnStateNestled";
            PropertyChanges { target: offImage;      opacity: 1}
            PropertyChanges { target: onImage;       opacity: 0}
            PropertyChanges { target: offImageNestled; opacity: 1}
            PropertyChanges { target: onImageNestled;  opacity: 1}
        }
    ]

    state: "buttonOffState"

    transitions:[
        Transition {
            from: "*"
            to: "*"
            NumberAnimation { id:turningOnOff; properties: "opacity"; duration: 200  }
        }
    ]

    SequentialAnimation {
        id: blinkAnimation
        loops: Animation.Infinite

        PropertyAnimation {
            properties: "opacity"
            to: 0
            duration: 200
            target: onImage
        }
        PauseAnimation { duration: 400 }
        PropertyAnimation {
            properties: "opacity"
            to: 1
            duration: 200
            target: onImage
        }
        PauseAnimation { duration: 400 }
    }

    SequentialAnimation {
        id: blinkAnimationNestled
        loops: Animation.Infinite

        PropertyAnimation {
            properties: "opacity"
            to: 1
            duration: 200
            target: onImageNestled
        }
        PauseAnimation { duration: 400 }
        PropertyAnimation {
            properties: "opacity"
            to: 0
            duration: 200
            target: onImageNestled
        }
        PauseAnimation { duration: 400 }
    }

    MouseArea {
        anchors.fill: parent
        onClicked: {
            button.buttonClicked()
            if (button.state == "buttonOffState"){
                if (button.nestled){
                    if (button.lighted){
                        button.state = "buttonOnStateNestled"
                    }else{
                        button.state = "buttonOffStateNestled"
                    }
                }else{
                    if (button.lighted){
                        button.state = "buttonOnState"
                    }
                }
            }else{
                button.state = "buttonOffState"
            }
        }
    }

    function startBlink() {
        if (button.nestled){
            blinkAnimationNestled.start()
            blinkAnimation.stop()
        }else{
            blinkAnimationNestled.stop()
            blinkAnimation.start()
            }
    }

    function stopBlink() {
        blinkAnimationNestled.stop()
        blinkAnimation.stop()
    }
}
