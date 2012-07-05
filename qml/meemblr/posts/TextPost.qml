import QtQuick 1.1
import com.nokia.meego 1.0
import QtWebKit 1.0

BasePost {
    height:blog_title.height+blog_post.height+blog_date.height+60
    //width:blog_post.width-14
    //color: "white"
//    border.width : 20
//    border.color: "white"


    Text{
        id:blog_title
        text:head
        wrapMode: "Wrap"
        horizontalAlignment: Text.AlignHCenter
        anchors.top:parent.top
        anchors.left:parent.left
        anchors.margins: 20
        anchors.right:parent.right
        font.pointSize: 25

    }
    Text{
        id :blog_date
        wrapMode: "Wrap"
        color: "#7e7b7b"
        font.pointSize: 10
        anchors.right: parent.right
        anchors.top: blog_title.bottom
        anchors.margins: 5
        text: date



    }

    Text{
        id :blog_post
        wrapMode: "Wrap"
        color: "#7e7b7b"
        font.pointSize: 20
        anchors.right: parent.right
        anchors.left:parent.left
        anchors.top: blog_date.bottom
        anchors.topMargin: 10
        anchors.margins: 15
        text: body
        width:parent.width

//        settings.defaultFontSize : 20
//        settings.defaultFixedFontSize :20



    }
}


