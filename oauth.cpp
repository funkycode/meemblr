#include "oauth.h"

Oauth::Oauth(QObject *parent) : QObject(parent) {
    oauthRequest = new KQOAuthRequest;
    oauthManager = new KQOAuthManager;
    oauthRequest->setEnableDebugOutput(true);
}

void Oauth::setSettings(Settings *settings) {
    m_sets = settings;
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
    data.setConsumerKey(m_sets->getConsumerKey());
    data.setConsumerSecret(m_sets->getConsumerSecret());

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

    m_sets->setAccessToken(response.AccessToken());
    m_sets->setAccessTokenSecret(response.TokenSecret());
}

void Oauth::onApiResponse(QByteArray response) {
    qDebug() << response;
}
void Oauth::onApiError(QByteArray response) {

}

/* test function to get a profile */
void Oauth::testCall(QString test) {
    oauthRequest->initRequest(KQOAuthRequest::AuthorizedRequest, QUrl("http://api.tumblr.com/v2/user/info"));
    //oauthRequest->initRequest(KQOAuthRequest::AuthorizedRequest, QUrl("http://api.tumblr.com/v2/blog/niwakame.tumblr.com/post"));

    oauthRequest->setConsumerKey(m_sets->getConsumerKey());
    oauthRequest->setConsumerSecretKey(m_sets->getConsumerSecret());
    oauthRequest->setToken(m_sets->getAccessToken());
    oauthRequest->setTokenSecret(m_sets->getAccessTokenSecret());
    //oauthRequest->setHttpMethod(KQOAuthRequest::POST);

    /*KQOAuthParameters params;
    params.insert("type", "text");
    params.insert("body", "This is a testpost from Meemblr. Fear us :>");
    oauthRequest->setAdditionalParameters(params);*/

    connect(oauthManager, SIGNAL(requestReady(QByteArray)), this, SLOT(onApiResponse(QByteArray)));

    oauthManager->executeRequest(oauthRequest);
}

void Oauth::callApi(QUrl url, QList< QPair<QString, QString> > params, QString method) {
    oauthRequest->initRequest(KQOAuthRequest::AuthorizedRequest, url);
    oauthRequest->setConsumerKey(m_sets->getConsumerKey());
    oauthRequest->setConsumerSecretKey(m_sets->getConsumerSecret());
    oauthRequest->setToken(m_sets->getAccessToken());
    oauthRequest->setTokenSecret(m_sets->getAccessTokenSecret());

    if (method == "POST") {
        oauthRequest->setHttpMethod(KQOAuthRequest::POST);
    } else {
        oauthRequest->setHttpMethod(KQOAuthRequest::GET);
    }

    if (params.size() > 0) {
        KQOAuthParameters parameters;
        QPair<QString, QString> pair;
        foreach(pair, params) {
            QString key = pair.first;
            QString val = pair.second;
            parameters.insert(key, val);
        }
        oauthRequest->setAdditionalParameters(parameters);
    }

    connect(oauthManager, SIGNAL(requestReady(QByteArray)), this, SLOT(onApiResponse(QByteArray)));
    oauthManager->executeRequest(oauthRequest);
}
