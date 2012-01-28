
#include "profile.h"


Profile::Profile(QObject *parent)
    : QObject(parent)


{
}





void Profile::parser(QNetworkReply *reply)      //parsing data due to request
{
    QString response = reply->readAll();
    QScriptValue sc;
    QScriptEngine engine;
    sc = engine.evaluate("("+ QString(response)+ ")");
    //emit profileresult(response);    //return whole json response



}





void Profile::profile_request(QString nick)
{

    QUrl url("");
    QNetworkAccessManager *networkManager = new QNetworkAccessManager(this);
    connect(networkManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(parser(QNetworkReply*)));
    networkManager->get(QNetworkRequest(url));

}
