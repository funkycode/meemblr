// import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
import QtQuick 1.1
import com.nokia.meego 1.0

Page {
    id: settings_page
    tools: settingsTools

    ToolBarLayout {
        id: settingsTools

        ToolIcon {
            id: backIcon
            platformIconId: "toolbar-back"
            anchors.left: (parent === undefined) ? undefined : parent.left
            onClicked: {
                /* save values */
                settings.setUsername(settings_username_value.text);

                pageStack.pop();
            }
        }
    }

    Component.onCompleted: {
        /* text values */
        settings_username_value.text = settings.getUsername();

        /* switch values */
        settings_themeInverted_switch.checked = settings.getThemeInverted();
    }

    Column {
        anchors.fill: parent
        Row {
            anchors.left: parent.left
            anchors.right: parent.right
            Column {
                id: column1
                anchors.right: parent.right
                anchors.left: parent.left
                spacing: 5
                Label{
                    id: settings_username_label
                    text: "Username"
                    anchors.left:parent.left
                    anchors.right:parent.right
                    anchors.margins: 10
                    font.pointSize: 20
                }
                TextField {
                    id: settings_username_value
                    anchors.left: parent.left
                    anchors.right: parent.right
                    anchors.margins: 10
                    font.pointSize: 25
                }
                Label {
                    id: settings_videoplayback_label
                    text: "Open videos in"
                    anchors.left: parent.left
                    anchors.right: parent.right
                    anchors.margins: 10
                }
                ButtonRow {
                    id: settings_videoplayback_btnrow
                    anchors.horizontalCenter: parent.horizontalCenter

                    checkedButton: btn_video_browser

                    Button {
                        id: btn_video_browser
                        text: "Browser"
                    }
                }

                Row {
                    anchors.left: parent.left
                    anchors.right: parent.right

                    Label{
                        id: settings_themeInverted_label
                        text: "Invert theme"
                        anchors.left:parent.left
                        anchors.margins: 10
                        font.pointSize: 20
                    }
                    Switch {
                        id: settings_themeInverted_switch
                        checked: false
                        anchors.right: parent.right
                        anchors.margins: 10
                        onCheckedChanged: {
                            settings.setThemeInverted(checked);
                        }
                    }
                }

                Button {
                    id: btn_oauth
                    text: "Authenticate"
                    onClicked: {
                        pageStack.push(Qt.resolvedUrl("OAuth.qml"));
                    }
                }
            }
        }
    }
}
