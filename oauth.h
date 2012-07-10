#ifndef OAUTH_H
#define OAUTH_H

#include <QObject>
#include <QString>
#include <QDebug>
#include <QStringList>
#include <QMap>
#include <QUrl>
#include <QList>
#include <QPair>
#include <QCryptographicHash>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QNetworkAccessManager>
#include <QTime>
#include <QtAlgorithms>

#include <kqoauth/kqoauthmanager.h>
#include <kqoauth/kqoauthrequest.h>

#include <signon-plugins/oauth1data.h>
#include <signon-qt/SignOn/Identity>
#include <signon-qt/SignOn/AuthSession>
#include <signon-qt/SignOn/AuthService>

class Oauth : public QObject
{
    Q_OBJECT

public:
    Oauth(QObject *parent = 0);
    Q_INVOKABLE void startAuthentication(QString username);
    Q_INVOKABLE void testCall(QString test);


public slots:
    void onResponse(const SignOn::SessionData &sessionData);
    void onError(const SignOn::Error &error);
    void identityMethodsAvailable(const QStringList &);
    void onApiResponse(QByteArray response);

private:
    SignOn::AuthService *authService;
    SignOn::IdentityInfo *m_info;

    KQOAuthManager *oauthManager;
    KQOAuthRequest *oauthRequest;
};

#endif // OAUTH_H
