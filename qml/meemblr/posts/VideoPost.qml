import QtQuick 1.1
import com.nokia.meego 1.0
import QtMultimediaKit 1.1

BasePost {
    height: title.height+video_thumbnail.height+video_date.height+60

    Text{
        id: title
        text:"video"
        font.pointSize: 20
    }

    Text{
        id :video_date
        wrapMode: "Wrap"
        color: "#7e7b7b"
        font.pointSize: 10
        anchors.right: parent.right
        anchors.top: title.bottom
        anchors.margins: 5
        text: date
    }

    Image {
        id: video_thumbnail
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: video_date.bottom
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
