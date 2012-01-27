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
    QString key="your_api_key";
    QUrl url("http://api.tumblr.com/v2/blog/"+blog+".tumblr.com/info?api_key="+key);

    QByteArray postdata;

    //POST data

       postdata.append(QString("key=").toUtf8());
       postdata.append(QUrl::toPercentEncoding(key));

   //END POST data


     QNetworkAccessManager *networkManager = new QNetworkAccessManager(this);

     connect(networkManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(parser(QNetworkReply*)));
     networkManager->get(QNetworkRequest(url));

}



