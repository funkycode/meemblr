#include <blog.h>

Blog::Blog(QObject *parent)
    : QObject(parent),
      nam(new QNetworkAccessManager(this)),
      m_identity(0),
      m_session(0)
{
    m_identity = SignOn::Identity::newIdentity(SignOn::IdentityInfo(), this);
}

void Blog::parser(QNetworkReply *reply)      //parsing data due to request
{
    QString response = reply->readAll();
    QScriptValue sc;
    QScriptEngine engine;
    sc = engine.evaluate("("+ QString(response)+ ")");
   // qDebug() << "the response: "<< response;
    emit blogresult(response);    //return whole json response
}

void Blog::onResponse(const SignOn::SessionData &sessionData)
{
    OAuth2PluginNS::OAuth1PluginTokenData response = sessionData.data<OAuth2PluginNS::OAuth1PluginTokenData>();
    qDebug() << "Access token: " << response.AccessToken();

    qDebug() << "Toke nSecret: " << response.TokenSecret();
}

void Blog::onError(const SignOn::Error &error)
{
    qDebug() << "Got error:" << error.message();
}

void Blog::blog_request(QString blog) //gallery, for now period is not used, maybe in future we'll use it for time period
{


//    SignOn::AuthSession *m_session = m_identity->createSession("oauth2");

//   OAuth2PluginNS::OAuth1PluginData data;


//   data.setRealm("api.tumblr.com/v2/blog/russialize.com/followers");
//   data.setAuthorizationEndpoint("http://www.tumblr.com/oauth/authorize");
//   data.setConsumerKey("sP9NTklBBvwxiIie3lwjpGGwqMor4P6yb2eVWxkaMM0ZaLaafR");
//   data.setConsumerSecret("RzMz3iTkVTPIBhqwQc9JJ4Uog2fM4LxvwFoxViMjq11FcKWjwr");
////    data.setCallback("http://api.imgur.com/2/account.json");
////    data.setDisplayCallback("true");
//   data.setTokenEndpoint("http://www.tumblr.com/oauth/access_token");
//   data.setRequestEndpoint("http://www.tumblr.com/oauth/request_token");
//   data.setUserName("thezogg@gmail.com");


//   m_session->process(data, QString("HMAC-SHA1"));

    QString key="7zSQ06s60K8PHwXYK1Hw2fTSqgQQkLzPPS14BQQjsXRvQMMWyP";
    //QUrl url("http://api.tumblr.com/v2/blog/"+blog+".tumblr.com/info?api_key="+key);

    QUrl url("http://api.tumblr.com/v2/blog/"+blog+".tumblr.com/posts?api_key="+key+"&limit=10"); //just for begining i would use only my blog

    connect(nam, SIGNAL(finished(QNetworkReply*)), this, SLOT(parser(QNetworkReply*)));
    nam->get(QNetworkRequest(url));
    //     QUrl url("http:/api.tumblr.com/v2/blog/david.tumblr.com/avatar"); // for avatar
}
