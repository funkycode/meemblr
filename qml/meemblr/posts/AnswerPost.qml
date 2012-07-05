import QtQuick 1.1
import com.nokia.meego 1.0
Component {
    id:answer
    BasePost {
        height:title_text_field.height+answer_text.height+date_text_field.height+60
        date_text_value: date
        title_text_value: caption

        Text{
            id: answer_text
            text:"answer"
            font.pointSize: 20
        }
    }
}
