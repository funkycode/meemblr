#ifndef OAUTH_H
#define OAUTH_H

#include <QObject>
#include <QString>
#include <QDebug>
#include <QUrl>
#include <settings.h>
#include <QPair>
#include <QList>

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
    void testCall(QString test);
    void setSettings(Settings *settings);
    void callApi(QUrl url, QList< QPair<QString, QString> >, QString method);


public slots:
    void onResponse(const SignOn::SessionData &sessionData);
    void onError(const SignOn::Error &error);
    void identityMethodsAvailable(const QStringList &);
    void onApiResponse(QByteArray response);
    void onApiError(QByteArray response);

private:
    SignOn::AuthService *authService;
    SignOn::IdentityInfo *m_info;

    KQOAuthManager *oauthManager;
    KQOAuthRequest *oauthRequest;
    Settings *m_sets;
};

#endif // OAUTH_H
