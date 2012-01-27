import QtQuick 1.1
import com.nokia.meego 1.0

Page {
    tools: commonTools



    TextField{
        id:blog_name
        text:"zogg"
        anchors.left:parent.left
        width:200
       // height:200
        font.pointSize: 30
       // anchors.right:parent.right
        anchors.margins:5


    }
    Button{
        text:"get"
        anchors.left:blog_name.right
        anchors.right:parent.right
        onClicked: {
            blog_req.blog_request(blog_name.text);
        }
    }


    Text{

        id:title
        text:""
        anchors.left:parent.left
        anchors.right:parent.right
        anchors.top:blog_name.bottom
        font.pointSize: 20
    }

    Text{
        id:name
        text:""
        anchors.left:parent.left
        anchors.right:parent.right
        anchors.top:title.bottom
        font.pointSize: 20
    }

    Text{
        id:posts
        text:""
        anchors.left:parent.left
        anchors.right:parent.right
        anchors.top:name.bottom
        font.pointSize: 20
    }



    Connections{
        target:blog_req
        onBlogresult: {

            var result = JSON.parse(data);
            title.text= "Blog title - "+result.response.blog.title;
            name.text= "Blogger - "+result.response.blog.name;
            posts.text= "Posts: "+result.response.blog.posts;

        }
    }
}


