import QtQuick 1.1
import com.nokia.meego 1.0

Page {
    id: blog_page
    tools: commonTools
    //    property string post_title: ""
    //    property string post_url: ""
    //    property string post_type: ""
    //    property string post_tags: ""
    //    property string post_date: ""
    //    property string post_body: ""



    ListModel {
        id:blogmodel
    }

    Connections{
        target:blog_req
        onBlogresult: {

            blog_posts.model.clear();
            var result = JSON.parse(data);
            title.text= result.response.blog.title;
            for (var i in result.response["posts"]) {
                var output = result.response["posts"][i];


                blogmodel.append({
                                     head: output.title,
                                     body: output.body,
                                     date: output.date,

                                 });
            }
        }
    }


    ListView

    {
        id: blog_posts


        anchors.top:header.bottom
        height:parent.height-commonTools.height
        width:parent.width



        Component{
            id:blog_items
            Item{
                height:blog_title.height+blog_post.height+blog_date.height+60
                width: parent.width


                Text{
                    id:blog_title
                    text:head
                    wrapMode: "Wrap"
                    horizontalAlignment: Text.AlignHCenter
                    anchors.left:parent.left
                    anchors.right:parent.right
                    anchors.margins: 10
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



                }
            }
        }



        model: blogmodel
        delegate:blog_items


    }
    Rectangle{
        id:header
        color: "gray"
        width:parent.width
        height:title.height+20

        Text{

            id:title
            text:""
            horizontalAlignment: Text.AlignHCenter
            anchors.left:parent.left
            anchors.right:parent.right
            anchors.top:parent.top
            font.pointSize: 30
            anchors.margins: 10
        }
    }


}


