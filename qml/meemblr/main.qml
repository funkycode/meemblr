import QtQuick 1.1
import com.nokia.meego 1.0

PageStackWindow {
    id: appWindow

    initialPage: blog_page

    Blog {
        id: blog_page
    }

    ToolBarLayout {
        id: commonTools
        visible: true
        ToolIcon {
            platformIconId: "toolbar-refresh"
            anchors.right: (parent === undefined) ? undefined : parent.right
            onClicked:{ blog_req.blog_request("zogg");

            }
        }
    }


}
