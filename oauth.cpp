#include "oauth.h"

Oauth::Oauth(QObject *parent) : QObject(parent)
{
    /* seed random generator */
    qsrand(QTime::currentTime().msec());
}

void Oauth::startAuthentication(QString username) {

    /* query auth Service for available methods */
    authService = new SignOn::AuthService();
    connect(authService, SIGNAL(methodsAvailable(const QStringList&)),
                    this, SLOT(identityMethodsAvailable(const QStringList&)));
    authService->queryMethods();

    SignOn::Identity *m_identity;
    OAuth2PluginNS::OAuth1PluginData data;

    /* choose oauth2 as method for authentication */
    QMap<SignOn::MethodName, SignOn::MechanismsList>  methods;
    methods.insert("oauth2", QStringList());

    m_info = new SignOn::IdentityInfo("Meetumblr", username, methods);
    m_identity = SignOn::Identity::newIdentity(*m_info);

    SignOn::AuthSession *m_session = m_identity->createSession("oauth2");

    data.setRealm("http://api.tumblr.com/v2/");
    data.setAuthorizationEndpoint("http://www.tumblr.com/oauth/authorize");
    data.setRequestEndpoint("http://www.tumblr.com/oauth/request_token");
    data.setTokenEndpoint("http://www.tumblr.com/oauth/access_token");


    /* Please read this! ###############
     * these are actually our keys ! if you wish to use this code, please register your key / application at: http://www.tumblr.com/oauth/apps
    */

    /* ZogG's keys */
    //data.setConsumerKey("7zSQ06s60K8PHwXYK1Hw2fTSqgQQkLzPPS14BQQjsXRvQMMWyP");
    //data.setConsumerSecret("8rRNTXMWxe6p5AYumqnZYSDDfofBehF1cjuT05w7nqMHpGy0YZ");
    /* Niwakame's keys */
    data.setConsumerKey("KhJM28EMcP1iEeUomSnFbpwI1YmzPVEYxh1xl07Rlr5AQfbKEj");
    data.setConsumerSecret("ouPTiEiAU7mUXbkRlDZkD3FlXEAOREWyffmtVuo5bQSanf7UFb");


    data.setCallback("http://www.tumblr.com/oauth/access_token");
    data.setDisplayCallback("true");

    connect(m_session, SIGNAL(response(const SignOn::SessionData &)), this, SLOT(onResponse(const SignOn::SessionData &)));
    connect(m_session, SIGNAL(error(const SignOn::Error &)), this, SLOT(onError(const SignOn::Error &)));

    m_session->process(data, QString("HMAC-SHA1"));
}

void Oauth::identityMethodsAvailable(const QStringList &methodList) {
    for (int i=0; i < methodList.size(); ++i) {
        qDebug() << "Method available: " << methodList.at(i).toLocal8Bit().constData();
    }
}

void Oauth::onError(const SignOn::Error &error)
{
    qDebug() << "Got error:" << error.message();
}

void Oauth::onResponse(const SignOn::SessionData &sessionData)
{
    OAuth2PluginNS::OAuth1PluginTokenData response = sessionData.data<OAuth2PluginNS::OAuth1PluginTokenData>();
    qDebug() << "Access token: " << response.AccessToken();
    qDebug() << "Toke nSecret: " << response.TokenSecret();

}

void Oauth::onApiResponse(QByteArray response) {
    qDebug() << response;
}


/* test function to get a profile */
void Oauth::testCall(QString test) {
    oauthRequest = new KQOAuthRequest;
    oauthManager = new KQOAuthManager;
    oauthRequest->setEnableDebugOutput(true);

    //oauthRequest->initRequest(KQOAuthRequest::AuthorizedRequest, QUrl("http://api.tumblr.com/v2/user/info"));
    oauthRequest->initRequest(KQOAuthRequest::AuthorizedRequest, QUrl("http://api.tumblr.com/v2/blog/niwakame.tumblr.com/post"));
    oauthRequest->setConsumerKey("KhJM28EMcP1iEeUomSnFbpwI1YmzPVEYxh1xl07Rlr5AQfbKEj");
    oauthRequest->setConsumerSecretKey("ouPTiEiAU7mUXbkRlDZkD3FlXEAOREWyffmtVuo5bQSanf7UFb");
    oauthRequest->setToken("");
    oauthRequest->setTokenSecret("");
    oauthRequest->setHttpMethod(KQOAuthRequest::POST);

    KQOAuthParameters params;
    params.insert("type", "text");
    params.insert("body", "This is a testpost from Meemblr. Fear us :>");
    oauthRequest->setAdditionalParameters(params);

    connect(oauthManager, SIGNAL(requestReady(QByteArray)), this, SLOT(onApiResponse(QByteArray)));

    oauthManager->executeRequest(oauthRequest);
}
