#include <blog.h>


Blog::Blog(QObject *parent)
    : QObject(parent)


{
}





void Blog::parser(QNetworkReply *reply)      //parsing data due to request
{
    QString response = reply->readAll();
    qDebug()<<"response  - "<<response;
    QScriptValue sc;
    QScriptEngine engine;
    sc = engine.evaluate("("+ QString(response)+ ")");
    emit blogresult(response);    //return whole json response



}


void Blog::blog_request(QString blog) //gallery, for now period is not used, maybe in future we'll use it for time period
{
    QString key="api_key";
   // QUrl url("http://api.tumblr.com/v2/blog/"+blog+".tumblr.com/info?api_key="+key);

    QUrl url("http://api.tumblr.com/v2/blog/russialize.com/posts/text?api_key="+key); //just for begining i would use only my blog

     QNetworkAccessManager *networkManager = new QNetworkAccessManager(this);

     connect(networkManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(parser(QNetworkReply*)));
     networkManager->get(QNetworkRequest(url));
     //QUrl url("http:/api.tumblr.com/v2/blog/david.tumblr.com/avatar"); // for avatar




}



