import QtQuick 2.0
//import QtMultimedia 5.4

Rectangle {
    id: pedal
    width: 150
    height: 214
    color: "#00000000"
    border.color: "#00000000"
    focus: true

    signal pedalPressed
    signal pedalReleased
//MMB
//    SoundEffect {
//        id: horn
//        source: "resources/train.wav"
//        }

    function press() {
        horn.play();
        down.opacity = 1;
        up.opacity = 0;
        pedal.pedalPressed();
    }

    function release() {
        horn.stop();
        down.opacity = 0;
        up.opacity = 1;
        pedal.pedalReleased();
    }

    Image {
        id: up
        anchors.fill: parent
        fillMode: Image.PreserveAspectFit
        source: "resources/bocina_up.png"
        opacity: 1
    }

    Image {
        id: down
        height: 205
        anchors.fill: parent
        fillMode: Image.PreserveAspectFit
        source: "resources/bocina_down.png"
        opacity: 0
    }

    MouseArea {
        anchors.fill: parent
        onPressed: press()
        onReleased: release()
    }


    //Keys.onPressed: {
    //    if (event.key == Qt.Key_B)
    //        press()
    //}

    //Keys.onReleased: {
    //    if (event.key == Qt.Key_B)
    //        release()
    //}
}
