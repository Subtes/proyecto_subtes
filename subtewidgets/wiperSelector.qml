import QtQuick 2.0


Rectangle {
    id: selector
    width: 100
    height: 100
    color: "#00000000"
    border.color: "#00000000"

    signal washer();
    signal wiper();
    signal off();

    property int newRot: 0;
    property int nextRot: 0;

    Image {
        id: bkg
        width: 100
        height: 100
        anchors.fill: parent
        source: "resources/selector_bkg.png"
    }

    Image {
        id: sel
        width: 45
        height: 79
        rotation: -45
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        source: "resources/selector_handler.png"
    }

    PropertyAnimation {
        id: selectorBack;
        target: sel;
        properties: "rotation";
        to: selector.nextRot;
        duration: 60
        easing {
            type: "Linear"
        }
    }

    MouseArea {
        anchors.fill: parent

        onReleased: {
            if(sel.rotation <= -15){
                selector.off();
                selector.nextRot = -45;
            }else{
                selector.wiper();
                selector.nextRot = 0;
            }
            selectorBack.start();

        }

        onPositionChanged: {
            newRot = -180 * Math.atan2(mouse.x - 50,mouse.y - 50) / Math.PI;
            if(newRot < -45){
                newRot = -45;
            }else if(newRot > 45){
                newRot = 45;
                selector.washer();
            }else{
                sel.rotation = newRot;
            }
        }
    }
}

