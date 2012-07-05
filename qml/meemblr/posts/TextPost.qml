import QtQuick 1.1
import com.nokia.meego 1.0
import QtWebKit 1.0

BasePost {
    height:title_text_field.height+blog_post.height+date_text_field.height+60

    date_text_value: date
    title_text_value: head

    Text{
        id :blog_post
        wrapMode: "Wrap"
        color: "#7e7b7b"
        font.pointSize: 20
        anchors.right: parent.right
        anchors.left:parent.left
        anchors.top: title_text_field.bottom
        anchors.topMargin: 10
        anchors.margins: 15
        text: body
        width:parent.width

//        settings.defaultFontSize : 20
//        settings.defaultFixedFontSize :20
    }
}


