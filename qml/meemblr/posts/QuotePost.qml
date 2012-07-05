import QtQuick 1.1
import com.nokia.meego 1.0

BasePost {
    height:title_text_field.height+quote.height+date_text_field.height+60

    date_text_value: date
    title_text_value: caption

    Text{
        id: quote
        wrapMode: "Wrap"
        anchors.left:parent.left
        anchors.right:parent.right
        anchors.top: title_text_field.bottom
        text:"« "+quotetext+" »"
        font.pointSize: 20
        font.italic: true
    }
}
