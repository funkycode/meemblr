import QtQuick 1.1
import com.nokia.meego 1.0
import QtMultimediaKit 1.1

BasePost {
    height:title_text_field.height+video_thumbnail.height+date_text_field.height+60

    title_text_value: caption
    date_text_value: date

    Image {
        id: video_thumbnail
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: title_text_field.bottom
        anchors.margins: 15

        width: 300
        smooth: true
        fillMode: Image.PreserveAspectFit

        source: videoThumb
        MouseArea {
            anchors.fill: parent
            onClicked: {
                Qt.openUrlExternally(videoPermalink);
            }
        }
    }
}
