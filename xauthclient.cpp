//#include "oauthclient.h"
//#include "oauth2data.h"
//#include <QCoreApplication>
//#include <QDebug>

//// using namespace OAuth2PluginNS;

//OAuthClient::OAuthClient(const QString &clientId,
//                         const QString &clientSecret,
//                         QObject *parent):
//    QObject(parent),
//    m_clientId(clientId),
//    m_clientSecret(clientSecret),
//    m_identity(0),
//    m_session(0)
//{
//    m_identity = SignOn::Identity::newIdentity(SignOn::IdentityInfo(), this);
//}

//OAuthClient::~OAuthClient()
//{
//}

//void OAuthClient::authenticate()
//{
//    SignOn::AuthSession *m_session = m_identity->createSession("xauth");
//    QObject::connect(m_session, SIGNAL(response(const SignOn::SessionData &)),
//                     this, SLOT(onResponse(const SignOn::SessionData &)));
//    QObject::connect(m_session, SIGNAL(error(const SignOn::Error &)),
//                     this, SLOT(onError(const SignOn::Error &)));

//    OAuth2PluginData data;
//    data.setHost("https://www.tumblr.com");
//    data.setAuthPath("/oauth/access_token");
//    data.setRedirectUri("api.tumblr.com/v2/blog/zogg.tumblr.com/followers");
//    data.setClientId(m_clientId);
//    data.setClientSecret(m_clientSecret);

//    m_session->process(data, "user_agent");
//}

//void OAuthClient::onResponse(const SignOn::SessionData &sessionData)
//{
//    OAuth2PluginTokenData response = sessionData.data<OAuth2PluginTokenData>();
//    qDebug() << "Access token:" << response.AccessToken();
//    qDebug() << "Expires in:" << response.ExpiresIn();

//    QCoreApplication::quit();
//}

//void OAuthClient::onError(const SignOn::Error &error)
//{
//    qDebug() << "Got error:" << error.message();

//    QCoreApplication::quit();
//}

//int main(){
//OAuthClient client("213156715390803",
//                   "bf89c2d9de5e929fe5c5921e9a1f2924");

//client.authenticate();


//}
