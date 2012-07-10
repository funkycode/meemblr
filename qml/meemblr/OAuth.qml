// import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
import QtQuick 1.1
import com.nokia.meego 1.0

Page {
    id: oauth_page
    tools: oauthTools

    ToolBarLayout {
        id: oauthTools

        ToolIcon {
            id: backIcon
            platformIconId: "toolbar-back"
            anchors.left: (parent === undefined) ? undefined : parent.left
            onClicked: {
                pageStack.pop();
            }
        }
    }

    Column {
        TextField {
            id: username
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.margins: 10
            font.pointSize: 25
        }
        Button {
            text: "Start OAuth"
            onClicked: {
                oauth.startAuthentication(username.text);
            }
        }
    }
}
