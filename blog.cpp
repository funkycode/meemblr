#include <blog.h>

Blog::Blog(QObject *parent)
    : QObject(parent),
     nam(new QNetworkAccessManager(this))



{

}





void Blog::parser(QNetworkReply *reply)      //parsing data due to request
{
    QString response = reply->readAll();
    QScriptValue sc;
    QScriptEngine engine;
    sc = engine.evaluate("("+ QString(response)+ ")");
    emit blogresult(response);    //return whole json response



}


void Blog::blog_request(QString blog) //gallery, for now period is not used, maybe in future we'll use it for time period
{


    QString key="key";
    //QUrl url("http://api.tumblr.com/v2/blog/"+blog+".tumblr.com/info?api_key="+key);

    QUrl url("http://api.tumblr.com/v2/blog/russialize.com/posts?api_key="+key+"&limit=10"); //just for begining i would use only my blog



     connect(nam, SIGNAL(finished(QNetworkReply*)), this, SLOT(parser(QNetworkReply*)));
     nam->get(QNetworkRequest(url));
//     QUrl url("http:/api.tumblr.com/v2/blog/david.tumblr.com/avatar"); // for avatar




}



