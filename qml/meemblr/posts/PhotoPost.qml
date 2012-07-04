import QtQuick 1.1
import com.nokia.meego 1.0
import com.nokia.extras 1.0

Rectangle {
    height:photo_title.height+photo_post.height+photo_date.height+60
    //width:photo_post.width-14
    radius:15
    color: "white"
//    border.width : 20
//    border.color: "white"


    Text{
        id:photo_title
        text:caption
        wrapMode: "Wrap"
        horizontalAlignment: Text.AlignHCenter
        anchors.top:parent.top
        anchors.left:parent.left
        anchors.margins: 20
        anchors.right:parent.right
        font.pointSize: 25

    }
    Text{
        id :photo_date
        wrapMode: "Wrap"
        color: "#7e7b7b"
        font.pointSize: 10
        anchors.right: parent.right
        anchors.top: photo_title.bottom
        anchors.margins: 5
        text: date



    }

    Image{

            //id:
            height: 160
            width: 160
            smooth: true
            source:  photo
            anchors.right: parent.right
            anchors.left:parent.left
            anchors.top: photo_date.bottom
            anchors.topMargin: 10
            anchors.margins: 15
//            text: "photo"
//            width:parent.width

           }
//    Text{
//        id :photo_post
//        wrapMode: "Wrap"
//        color: "#7e7b7b"
//        font.pointSize: 20


////        settings.defaultFontSize : 20
////        settings.defaultFixedFontSize :20



//    }
}
