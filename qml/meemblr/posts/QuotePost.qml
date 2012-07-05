import QtQuick 1.1
import com.nokia.meego 1.0

BasePost {
    height:quote.height+15


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
