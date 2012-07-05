// import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
import QtQuick 1.1

Rectangle {

    id: post

    property string title_text_value;
    property string date_text_value;
    property alias date_text_field: date_text;
    property alias title_text_field: title_text;

    width: blog_posts.width-14
    radius: 15
    color: "white"

    Text{
        id:title_text
        text: title_text_value
        wrapMode: "Wrap"
        horizontalAlignment: Text.AlignHCenter
        anchors.top:parent.top
        anchors.left:parent.left
        anchors.margins: 20
        anchors.right:parent.right
        font.pointSize: 25
    }

    Text{
        id :date_text
        wrapMode: "Wrap"
        color: "#7e7b7b"
        font.pointSize: 10
        anchors.right: parent.right
        anchors.top: parent.bottom
        anchors.margins: 5
        anchors.topMargin: -(date_text.height + 5) /* needs to be negative, because we're pushing "up" from the bottom */
        text: date_text_value
    }
}
