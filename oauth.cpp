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

/* test function to get a profile */
QString Oauth::testCall() {
    /* try to get followers, as we need oauth for that */
    QString url = "api.tumblr.com/v2/blog/niwakame.tumblr.com/followers";
    int methodType = 0; /* get */
    /* set up request parameters */
    QList< QPair<QString, QString> > requestParameters;
    requestParameters.append(qMakePair(QString("limit"), QString("5")));

    QString headers = Oauth::signRequest(url, methodType, requestParameters);
}

bool sortParameter(const QPair<QString, QString> &left, const QPair<QString, QString> &right) {
    QString keyLeft = left.first;
    QString valueLeft = left.second;
    QString keyRight = right.first;
    QString valueRight = right.second;

    if(keyLeft == keyRight) {
        return (valueLeft < valueRight);
    } else {
        return (keyLeft < keyRight);
    }
}

/* Method type 0 is GET, type 1 is POST */
QString Oauth::signRequest(QUrl url, int methodType, QList< QPair<QString, QString> > requestParameters) {
    QString aToken = "yadda";
    QString tSecret = "yadda";
    QString consumerKey = "KhJM28EMcP1iEeUomSnFbpwI1YmzPVEYxh1xl07Rlr5AQfbKEj";
    QString consumerSecret = "ouPTiEiAU7mUXbkRlDZkD3FlXEAOREWyffmtVuo5bQSanf7UFb";

    QByteArray baseString;

    if (methodType == 0) {
        baseString.append("GET&");
    } else {
        baseString.append("POST&");
    }
    baseString.append(QUrl::toPercentEncoding(url.toString()));

    QList< QPair<QString, QString> > baseStringParameters;

    /* request parameters */
    for (int i=0;i<requestParameters.size();++i) {
        baseStringParameters.append(requestParameters.at(i));
    }

    /* additional parameters */
    QList<QString> addKeys;
    QList<QString> addValues;

    QString timestamp = QString::number(QDateTime::currentDateTimeUtc().toTime_t());
    QString nonce = QString::number(qrand());
    addKeys.append("oauth_consumer_key");
    addValues.append(consumerKey);
    addKeys.append("oauth_nonce");
    addValues.append(nonce);
    addKeys.append("oauth_signature_method");
    addValues.append("HMAC-SHA1");
    addKeys.append("oauth_timestamp");
    addValues.append(timestamp);
    addKeys.append("oauth_version");
    addValues.append("1.0");
    for (int i=0; i<addKeys.size(); ++i) {
        QPair<QString, QString> tmpPair = qMakePair(addKeys.at(i), addValues.at(i));
        baseStringParameters.append(tmpPair);
    }

    qSort(baseStringParameters.begin(), baseStringParameters.end(), sortParameter);

    baseString.append(encodedParameterList(baseStringParameters));

    /* here we have everything ready and can sign the request */
    QString secretString = QString(QUrl::toPercentEncoding(consumerSecret))+"&"+QString(QUrl::toPercentEncoding(tSecret));
    QString signature = encodeHMACSHA1(baseString, secretString);
    baseStringParameters.append(qMakePair(QString("oauth_key_signature"), signature));

    QList<QByteArray> returnParameterList;
    QPair<QString, QString> params;
    QString param;
    QString val;
    foreach (params, baseStringParameters) {
        param = params.first;
        val = params.second;
        if (param != "oauth_key_signature") {
            val = QUrl::toPercentEncoding(val);
        }
        returnParameterList.append(QString(param+"=\""+val+"\"").toUtf8());
    }

    /* actual sending is done here */
    QNetworkRequest req;
    req.setUrl(url);
    QByteArray authenticationHeader;

    bool start = true;
    foreach (const QByteArray header, returnParameterList) {
        if (!start) {
            authenticationHeader.append(", "+header);
        } else {
            authenticationHeader.append("OAuth "+header);
        }
    }
    req.setRawHeader("Authorization",authenticationHeader);

    if (methodType == 0) { /* GET */
        QUrl fullUrl = url;
        fullUrl.setQueryItems(requestParameters);
        req.setUrl(fullUrl);
    } else {
        /* TODO: POST LATER */
    }

    QNetworkReply *reply = nam.get(req);
    connect(nam, SIGNAL(finished(QNetworkReply*)), this, SLOT(onApiResponse(QNetworkReply*)));
    //connect(nam, SIGNAL(error(QNetworkReply::NetworkError *)), this, SLOT(onApiError(QNetworkReply::NetworkError *)));

}

void Oauth::onApiResponse(QNetworkReply *reply) {
    qDebug() << reply->readAll();
    reply->deleteLater();
}
void Oauth::onApiError(QNetworkReply::NetworkError *error) {
    QNetworkReply *reply = qobject_cast<QNetworkReply *>(sender());
    qDebug() << "Error: " << reply->readAll();
    reply->deleteLater();
}



QByteArray Oauth::encodedParameterList(const QList< QPair<QString, QString> > &parameters) {
    QByteArray returnString;
    bool start = true;

    QPair<QString, QString> param;
    foreach (param, parameters) {
        if (!start) {
            returnString.append("&");
        } else {
            start = false;
        }
    }

    returnString.append( QUrl::toPercentEncoding(param.first) + "=" + QUrl::toPercentEncoding(param.second));
    return QUrl::toPercentEncoding(returnString);
}

QString Oauth::encodeHMACSHA1(const QString &body, const QString &key) {
    QByteArray key_in_bytes = key.toAscii();
    int key_length = key_in_bytes.size();

    const int blocksize = 64;

    if (key_length > blocksize) {
        QCryptographicHash hash(QCryptographicHash::Sha1);
        hash.addData(key_in_bytes);
        key_in_bytes = hash.result();
    }

    QByteArray ipad;
    QByteArray opad;

    ipad.fill(0, blocksize);
    opad.fill(0, blocksize);

    ipad.replace(0, key_in_bytes.length(), key_in_bytes);
    opad.replace(0, key_in_bytes.length(), key_in_bytes);

    for (int i=0; i<64; i++) {
        ipad[i] = ipad[i] ^ 0x36;
        opad[i] = opad[i] ^ 0x5c;
    }

    QByteArray workArray;
    workArray.clear();

    workArray.append(ipad, 64);
    workArray.append(body.toAscii());

    QByteArray sha1 = QCryptographicHash::hash(workArray, QCryptographicHash::Sha1);
    workArray.clear();
    workArray.append(opad, 64);
    workArray.append(sha1);

    sha1.clear();
    sha1 = QCryptographicHash::hash(workArray, QCryptographicHash::Sha1);

    return QString(sha1.toBase64());
}
