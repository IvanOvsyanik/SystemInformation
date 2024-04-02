import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import Qt.labs.settings 1.1
import QtQuick.Layouts 1.15

ApplicationWindow {
    id: main
    title: qsTr("System information")
    color: '#333333'
    width: 1920
    height: 1024
    visible: true
    property int kolvo: -1

    Component.onCompleted: {
        mainbutton.clicked()
        stack.push(cpuinfo)
        stack.push(meminfo)
        stack.push(usbdevice)
        stack.push(portinfo)
        stack.push(changess)
        stack.pop()
        stack.pop()
        stack.pop()
        stack.pop()
        stack.pop()
        stack.pop()
    }

    StackView {
        id: stack
        initialItem: mainView
        anchors.fill: parent
    }

    Item {
        id: mainView
        Button {
            id: first
            text: qsTr("Device Information")
            contentItem: CustomizationText {}
            background: CustomizationButton {}
            x: 10
            y: 710
            onClicked: {
                stack.push(deviceinfo)
            }
        }

        Button {
            id: second
            text: "CPU Information"
            contentItem: CustomizationText {}
            background: CustomizationButton {}
            x: 10
            y: 760
            onClicked: {
                stack.push(deviceinfo)
                stack.push(cpuinfo)
            }
        }

        Button {
            id: third
            text: "Memmory Information"
            contentItem: CustomizationText {}
            background: CustomizationButton {}
            x: 10
            y: 810
            onClicked: {
                stack.push(deviceinfo)
                stack.push(cpuinfo)
                stack.push(meminfo)
            }
        }

        Button {
            id: fourht
            text: "USB Device Information"
            contentItem: CustomizationText {}
            background: CustomizationButton {}
            x: 10
            y: 860
            onClicked: {
                stack.push(deviceinfo)
                stack.push(cpuinfo)
                stack.push(meminfo)
                stack.push(usbdevice)
            }
        }

        Button {
            id: fifth
            text: "Port Information Guide"
            contentItem: CustomizationText {}
            background: CustomizationButton {}
            x: 10
            y: 910
            onClicked: {
                stack.push(deviceinfo)
                stack.push(cpuinfo)
                stack.push(meminfo)
                stack.push(usbdevice)
                stack.push(portinfo)
            }
        }

        Button {
            id: sixth
            text: "Change your indicators"
            contentItem: CustomizationText {}
            background: CustomizationButton {}
            x: 10
            y: 960
            onClicked: {
                stack.push(deviceinfo)
                stack.push(cpuinfo)
                stack.push(meminfo)
                stack.push(usbdevice)
                stack.push(portinfo)
                stack.push(changess)
            }
        }

        Button {
            id: kk
            text: "Change background"
            contentItem: CustomizationText {}
            background: CustomizationButton {}
            x: 880
            y: 960
            onClicked: main.color = Qt.rgba(Math.random(),Math.random(),Math.random());
        }

        Button {
            id: mainbutton
            text: "Next page"
            contentItem: CustomizationText {}
            background: CustomizationButton {}
            x: 1790
            y: 960
            onClicked: {
                kolvo += 1;
                stack.push(deviceinfo)
            }
        }
    }

    Rectangle {
        id: deviceinfo
        color: '#333333'
        ListView {
            width: parent.width / 1.1
            height: parent.height
            model: deviceInfo.devices
            delegate: Item {
                width: ListView.view.width
                height: 60

                Rectangle {
                    anchors.fill: parent
                    color: "gray"
                    Text {
                        anchors.fill: parent
                        text: {
                            if (modelData.length > 20) {
                                var splitIndex = Math.floor(modelData.length / 2)
                                var firstHalf = modelData.substring(0, splitIndex)
                                var secondHalf = modelData.substring(splitIndex)
                                return firstHalf + " " + secondHalf
                            } else {
                                return modelData
                            }
                        }
                        wrapMode: Text.Wrap
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                    }
                }
            }
        }

        Text {
            x:1760
            y:50
            text: "Device Information"
        }

        Button {
            x: 1790
            y: 860
            text: "Main page"
            contentItem: CustomizationText {}
            background: CustomizationButton {}
            onClicked: stack.pop()
        }

        Button {
            x: 1790
            y: 910
            text: "Back"
            contentItem: CustomizationText {}
            background: CustomizationButton {}
            onClicked: stack.pop()
        }

        Button {
            id: mainbutton2
            text: "Next page"
            contentItem: CustomizationText {}
            background: CustomizationButton {}
            x: 1790
            y: 960
            onClicked: {
                kolvo += 1;
                stack.push(cpuinfo)
            }
        }
    }

    Rectangle {
        id: cpuinfo
        color: '#333333'
        ListView {
            width: parent.width / 1.1
            height: parent.height
            model: cpuInfo.cpuInfo

            delegate: Item {
                width: ListView.view.width
                height: 60

                Rectangle {
                    anchors.fill: parent
                    color: "gray"

                    Text {
                        anchors.fill: parent
                        text: {
                            if (modelData.length > 20) {
                                var splitIndex = Math.floor(modelData.length / 2)
                                var firstHalf = modelData.substring(0, splitIndex)
                                var secondHalf = modelData.substring(splitIndex)
                                return firstHalf + " " + secondHalf
                            } else {
                                return modelData
                            }
                        }
                        wrapMode: Text.Wrap
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                    }
                }
            }
        }

        Text {
            x:1760
            y:50
            text: "CPU Information"
        }

        Button {
            x: 1790
            y: 860
            text: "Main page"
            contentItem: CustomizationText {}
            background: CustomizationButton {}
            onClicked: {
                stack.pop()
                stack.pop()
            }
        }

        Button {
            id: mainbutton3
            text: "Next page"
            contentItem: CustomizationText {}
            background: CustomizationButton {}
            x: 1790
            y: 960
            onClicked: {
                kolvo += 1;
                stack.push(meminfo)
            }
        }

        Button {
            x: 1790
            y: 910
            text: "Back"
            contentItem: CustomizationText {}
            background: CustomizationButton {}
            onClicked: stack.pop()
        }
    }

    Rectangle {
        id: meminfo
        color: '#333333'
        ListView {
            width: parent.width / 1.1
            height: parent.height
            model: memInfo.memInfo

            delegate: Item {
                width: ListView.view.width
                height: 60

                Rectangle {
                    anchors.fill: parent
                    color: "gray"

                    Text {
                        anchors.fill: parent
                        text: {
                            if (modelData.length > 20) {
                                var splitIndex = Math.floor(modelData.length / 2)
                                var firstHalf = modelData.substring(0, splitIndex)
                                var secondHalf = modelData.substring(splitIndex)
                                return firstHalf + " " + secondHalf
                            } else {
                                return modelData
                            }
                        }
                        wrapMode: Text.Wrap
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                    }
                }
            }
        }

        Text {
            x:1760
            y:50
            text: "Memory Information"
        }

        Button {
            x: 1790
            y: 860
            text: "Main page"
            contentItem: CustomizationText {}
            background: CustomizationButton {}
            onClicked: {
                stack.pop()
                stack.pop()
                stack.pop()
            }
        }

        Button {
            x: 1790
            y: 910
            text: "Back"
            contentItem: CustomizationText {}
            background: CustomizationButton {}
            onClicked: stack.pop()
        }

        Button {
            id: mainbutton4
            text: "Next page"
            contentItem: CustomizationText {}
            background: CustomizationButton {}
            x: 1790
            y: 960
            onClicked: {
                kolvo += 1;
                stack.push(usbdevice)
            }
        }
    }

    Rectangle {
        id: usbdevice
        color: '#333333'
        ListView {
            width: parent.width / 1.1
            height: parent.height
            model: usbDevice.usbdevices

            delegate: Item {
                width: ListView.view.width
                height: 60

                Rectangle {
                    anchors.fill: parent
                    color: "gray"

                    Text {
                        anchors.fill: parent
                        text: {
                            if (modelData.length > 20) {
                                var splitIndex = Math.floor(modelData.length / 2)
                                var firstHalf = modelData.substring(0, splitIndex)
                                var secondHalf = modelData.substring(splitIndex)
                                return firstHalf + " " + secondHalf
                            } else {
                                return modelData
                            }
                        }
                        wrapMode: Text.Wrap
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                    }
                }
            }
        }

        Text {
            x:1743
            y:50
            text: "USB Devices Information"
        }

        Button {
            x: 1790
            y: 860
            text: "Main page"
            contentItem: CustomizationText {}
            background: CustomizationButton {}
            onClicked: {
                stack.pop()
                stack.pop()
                stack.pop()
                stack.pop()
            }
        }

        Button {
            x: 1790
            y: 910
            text: "Back"
            contentItem: CustomizationText {}
            background: CustomizationButton {}
            onClicked: stack.pop()
        }

        Button {
            id: mainbutton5
            text: "Next page"
            contentItem: CustomizationText {}
            background: CustomizationButton {}
            x: 1790
            y: 960
            onClicked: {
                kolvo += 1;
                stack.push(portinfo)
            }
        }
    }

    Rectangle {
        id: portinfo
        color: '#333333'

        Rectangle {
            width: parent.width/1.1
            height: parent.height
            color: "gray"

            Text {
                anchors.centerIn: parent
                text: "
                Заданные, для изменения, параметры:
                    2400 скорость
                    отсутствие контроля по четности
                    2 стоп бита
                    7 бит длина

                Краткое руководство,для изменения нужных нам параметров:
                    1.В регистр ба+3 передаём 10000000 для использования регистра ба+0 в качестве приёмника для делителя частоты и передаём в регистр ба+0 110000(1843200/(2400*16)).
                    2.Записываем в регистр ба+3 0х25 (отсутствие контроля по четности, 2 стоп бита, длина слова 7 бит).
                    3.Проверяем, что в регистре ба+5 бит 5 равен 1.
                    4.Через ба+0 передаём данные.
                    5.Проверяем, что в регистре ба+5 бит 0 равен 1.
                    6.Считать из регистра ба+0 данные.


                Parameters specified for change:
                    2400 speed
                    no parity
                    2 stop bits
                    length 7 bits

                A quick guide to changing the parameters we need:
                    1. In the ba+3 register we transmit 10000000 to use the ba+0 register as a receiver for the frequency divider and in the ba+0 register we transmit 110000(1843200/(2400*16)).
                    2. Write 0x25 to the register ba+3 (no parity, 2 stop bits, word length 7 bits).
                    3. Check that in the ba+5 register bit 5 is equal to 1.
                    4.We transmit data via ba+0.
                    5. Check that in the ba+5 register bit 0 is equal to 1.
                    6.Read data from register ba+0."
            }
        }

        Text {
            x:1750
            y:50
            text: "Port Information Guide"
        }

        Button {
            x: 1790
            y: 860
            text: "Main page"
            contentItem: CustomizationText {}
            background: CustomizationButton {}
            onClicked: {
                stack.pop()
                stack.pop()
                stack.pop()
                stack.pop()
                stack.pop()
            }
        }

        Button {
            x: 1790
            y: 910
            text: "Back"
            contentItem: CustomizationText {}
            background: CustomizationButton {}
            onClicked: stack.pop()
        }

        Button {
            id: mainbutton6
            text: "Next page"
            contentItem: CustomizationText {}
            background: CustomizationButton {}
            x: 1790
            y: 960
            onClicked: {
                kolvo += 1;
                stack.push(changess)
            }
        }
    }

    Rectangle {
        id: changess
        color: '#333333'

        Text {
            x:50
            y:875
            text:"Enter one to blink the indicators for 3 seconds"
            font.pixelSize: 16
        }

        ColumnLayout {
            spacing: 10
            x:50
            y:910

            TextField {
                id: numberInput
                placeholderText: "Enter a number "
                background: Rectangle {
                    color: "gray"
                    radius: 5
                    border.width: 2
                    border.color: "black"
                }
                Layout.fillWidth: true
            }

            Button {
                text: "Check result"
                contentItem: CustomizationText {}
                background: CustomizationButton {}
                onClicked: {
                    var inputNumber = parseInt(numberInput.text)
                    changes.change(inputNumber)
                }
            }
        }

        Text {
            id: messageText
            anchors.centerIn: parent
            font.pixelSize: 16
        }

        Keys.onPressed: {
            if (event.key === Qt.Key_Down) {
                messageText.text = ""
            } else if (event.key === Qt.Key_Up) {
                messageText.text = "Press the power key of any keyboard light"
            } else {
                switch(event.key) {
                    case Qt.Key_CapsLock:
                        messageText.text = "CapsLock indicator is on"
                        break
                    case Qt.Key_NumLock:
                        messageText.text = "NumLock indicator is on"
                        break
                    case Qt.Key_ScrollLock:
                        messageText.text = "ScrollLock indicator is on"
                        break
                }
            }
        }

        Button {
            x: 1790
            y: 910
            text: "Main page"
            contentItem: CustomizationText {}
            background: CustomizationButton {}
            onClicked: {
                stack.pop()
                stack.pop()
                stack.pop()
                stack.pop()
                stack.pop()
                stack.pop()
            }
        }

        Button {
            x: 1790
            y: 960
            text: "Back"
            contentItem: CustomizationText {}
            background: CustomizationButton {}
            onClicked: stack.pop()
        }
    }

    Row {
        spacing: 1889
        Text {
            text: kolvo
        }

        Text {
            text: stack.depth
        }
    }
}

