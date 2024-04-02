import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import Qt.labs.settings 1.1
import QtQuick.Layouts 1.15

Rectangle {
    Gradient {
        id: normalGradient
        GradientStop { position: 0.0; color: "black" }
        GradientStop { position: 0.5; color: "darkgrey" }
        GradientStop { position: 1.0; color: "gray" }
    }
    Gradient {
        id: hoveredGradient
        GradientStop { position: 0.0; color: "black" }
        GradientStop { position: 0.5; color: "darkgrey" }
        GradientStop { position: 1.0; color: "gray" }
    }
    Gradient {
        id: pressedGradient
        GradientStop { position: 0.0; color: "black" }
        GradientStop { position: 0.5; color: "darkgrey" }
        GradientStop { position: 1.0; color: "gray" }
    }
    implicitWidth: 100
    implicitHeight: 50
    gradient: testButton.pressed ? pressedGradient :
                                   testButton.hovered ? hoveredGradient :
                                                        normalGradient
    radius: 10
    border.width: 2.0
    border.color: "#000000"
}
