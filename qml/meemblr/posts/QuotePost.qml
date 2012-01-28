import QtQuick 1.1
import com.nokia.meego 1.0

Rectangle {
    height:quote.height
    width:blog_posts.width


    Text{
        id: quote
        wrapMode: "Wrap"
        anchors.left:parent.left
        anchors.right:parent.right
        text:"« "+quotetext+" »"
        font.pointSize: 20
        font.italic: true
    }
}
