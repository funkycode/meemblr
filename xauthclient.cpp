#include <xauthclient.h>

#include <QCoreApplication>
#include <QDebug>


OAuthClient::OAuthClient(const QString &clientId,
                         const QString &clientSecret,
                         QObject *parent):
    QObject(parent),
    m_clientId(""),
    m_clientSecret("key"),
    m_identity(0),
    m_session(0)
{
  m_identity = SignOn::Identity::newIdentity(SignOn::IdentityInfo(), this);
}

OAuthClient::~OAuthClient()
{
}

void OAuthClient::authenticate()
{

    SignOn::AuthSession *m_session = m_identity->createSession("xauth");
    QObject::connect(m_session, SIGNAL(response(const SignOn::SessionData &)),
                     this, SLOT(onResponse(const SignOn::SessionData &)));
    QObject::connect(m_session, SIGNAL(error(const SignOn::Error &)),
                     this, SLOT(onError(const SignOn::Error &)));

    SignOn::SessionData data;
    data.setUiPolicy(SignOn::NoUserInteractionPolicy);

    data.setRealm(QString("https://www.tumblr.com/oauth/access_token"));

    data.setUserName(QString("thezogg@gmail.com"));

    data.setSecret(QString(""));
//    data.setAuthorizationEndpoint("http://www.tumblr.com/oauth/authorize");
//    data.setRequestEndpoint("http://www.tumblr.com/oauth/request_token");
  \



    m_session->process(data, "HMAC-SHA1");


}

void OAuthClient::onResponse(const SignOn::SessionData &sessionData)
{

    qDebug() << "replay is given:";
//    qDebug() << "Access token:" << response.AccessToken();
//    qDebug() << "Expires in:" << response.ExpiresIn();


}

void OAuthClient::onError(const SignOn::Error &error)
{
    qDebug() << "Got error:" << error.message();


}


