import QtQuick 1.1
import com.nokia.meego 1.0

Page {
    id: blog_page
    tools: commonTools
    property  string blogname: ""


    Rectangle{
        width:parent.width
        height:parent.height
        color:"#9BB7DE"
        ListModel {
            id:blogmodel
        }

        Connections{
            target:blog_req
            onBlogresult: {

                blog_posts.model.clear();
                var result = JSON.parse(data);
                blogname= result.response.blog.title;

                for (var i in result.response["posts"]) {
                    var output = result.response["posts"][i];

                     for (var j in result.response["posts"][i]["photos"]) {
                         var photo_sets = result.response["posts"][i]["photos"][j];
                         if (photo_sets !== null)
                             var photo_url = photo_sets.original_size.url;
                         else
                             photo_url = "";
                         console.log(photo_sets.original_size.url);




                     }

                    blogmodel.append({

                                         typepost: output.type,
                                         head: output.title,
                                         body: output.body,
                                         date: output.date,
                                         quotetext: output.text,
                                         caption: output.caption,
                                        // photo: (photo_sets !== null) ? photo_sets.original_size.url : "",
                                         photo: photo_url,


                                     });
                    //                }
                }

            }
        }


        ListView

        {
            id: blog_posts


            Component {
                id:textpost


                Rectangle {
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




            anchors.top:parent.top
            height:parent.height-commonTools.height
            spacing: 15
            width:parent.width
            model: blogmodel


            delegate:
                Loader {
                id: displaytype
                source: if (typepost==="text") "posts/TextPost.qml"
                        else if(typepost==="quote") "posts/QuotePost.qml"
                        else if(typepost==="link") "posts/LinkPost.qml"
                        else if(typepost==="answer") "posts/AnswerPost.qml"
                        else if(typepost==="photo") "posts/PhotoPost.qml"
                        else if(typepost==="video") "posts/VideoPost.qml"
                        else "posts/AudioPost.qml"
                anchors.left:parent.left
                anchors.right:parent.right
                anchors.margins: 7



            }




            header:


                Component{
                id:header


                Rectangle{
                    id:rect
                    color: "gray"
                    width:parent.width
                    height:title.height+20

                    Text{

                        id:title
                        text:blogname
                        horizontalAlignment: Text.AlignHCenter
                        anchors.left:parent.left
                        anchors.right:parent.right
                        font.pointSize: 30
                        anchors.margins: 20

                    }
                }
            }

        }

    }
}


