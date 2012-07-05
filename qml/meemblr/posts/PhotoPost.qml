import QtQuick 1.1
import com.nokia.meego 1.0
import com.nokia.extras 1.0

BasePost {
    height:title_text_field.height+photo_post.height+date_text_field.height+60

    /* has been moved to BasePost.qml */
    title_text_value: caption
    date_text_value: date

    AnimatedImage{
            id:photo_post
            //height: 160
            width: 160
            smooth: true
            source:  photo
            fillMode: Image.PreserveAspectFit
            anchors.right: parent.right
            anchors.left:parent.left
            anchors.top: title_text_field.bottom
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
