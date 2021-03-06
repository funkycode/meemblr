import QtQuick 1.1
import com.nokia.meego 1.0

PageStackWindow {
    id: appWindow

    initialPage: blog_page

    Component.onCompleted: {
        theme.inverted = settings.getThemeInverted();
    }

    Blog {
        id: blog_page
    }

    ToolBarLayout {
        id: commonTools
        visible: true

        ToolIcon {
            id: homeIcon
            platformIconId: "toolbar-home"
            anchors.left: (parent === undefined) ? undefined : parent.left
            anchors.leftMargin: 10
            onClicked: {
                pageStack.pop(Qt.resolvedUrl("Blog.qml"));
            }
        }

        ToolIcon {
            id: refreshIcon
            platformIconId: "toolbar-refresh"
            anchors.right: (parent === undefined) ? undefined : parent.right
            onClicked:{
                if (settings.getUsername() !== "") {
                    blog_req.blog_request(settings.getUsername());
                }
            }
        }
        ToolIcon {
            id: settingsIcon
            platformIconId: "toolbar-settings"
            anchors.right: refreshIcon.left
            anchors.rightMargin: 20
            onClicked: {pageStack.push(Qt.resolvedUrl("Settings.qml"));}
        }
    }
}
