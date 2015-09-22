import QtQuick 2.0

Rectangle {
    id: selector
    width: 100
    height: 100
    color: "#00000000"
    border.color: "#00000000"

    signal pos1();
    signal pos2();
    signal pos3();

    property int newRot: 0;
    property int nextRot: 0;

    property int pos1stPosition: 0;
    property int pos2ndPosition: -45;
    property int pos3rdPosition: -90;

    property int pos1LimitBounce: -23;
    property int pos2LimitBounce: -67;

    property int rotLimitDown: 0;
    property int rotLimitUp: -90;

    Image {
        id: bkg
        anchors.fill: parent
        source: "resources/selector_bkg.png"
        antialiasing: true
        smooth: true
    }

    Image {
        id: sel
        anchors.fill: parent
        rotation: pos1stPosition
        source: "resources/selector_handler.png"
        antialiasing: true
        smooth: true
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
            if(newRot > pos1LimitBounce){
                nextRot = pos1stPosition;
                selector.pos1();
            }else if(newRot > pos2LimitBounce){
                nextRot = pos2ndPosition;
                selector.pos2();
            }else{
                nextRot = pos3rdPosition;
                selector.pos3();
            }
            selectorBack.start();
        }

        onPositionChanged: {
            newRot = (-Math.atan2(mouse.x - selector.width/2 , mouse.y - selector.height/2) * 180/Math.PI ) - 45;
            //-45 porque la imagen esta a 45 grados, para normalizarla en 0

            if(newRot > rotLimitDown){
                newRot = rotLimitDown;
            }else if(newRot < rotLimitUp){
                newRot = rotLimitUp;
            }
            sel.rotation = newRot;
        }
    }

    function setPos1(){
        newRot = pos1stPosition;
        selectorBack.start();
        return ok
    }

    function setPos2(){
        newRot = pos2ndPosition;
        selectorBack.start();
        return ok
    }

    function setPos3(){
        newRot = pos3rdPosition;
        selectorBack.start();
        return ok
    }
}
