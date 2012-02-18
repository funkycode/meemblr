#ifndef XAUTHCLIENT_H
#define XAUTHCLIENT_H

#include <QDebug>

#include <SignOn/AuthPluginInterface>
#include <SignOn/SessionData>
#include <SignOn/Error>
#include <SignOn/Identity>
#include <signon-plugins/SignOn/UiSessionData>


#include <QNetworkReply>
#include <QtCore>
#include <QSslError>


#include <QObject>

class OAuthClient:  public QObject
{
    Q_OBJECT
   // Q_INTERFACES(AuthPluginInterface)

public:
    OAuthClient(const QString &clientId,
                const QString &clientSecret,
                QObject *parent = 0);
    ~OAuthClient();

public Q_SLOTS:
    void authenticate();

private Q_SLOTS:
    void onResponse(const SignOn::SessionData &sessionData);
    void onError(const SignOn::Error &error);

private:
    QString m_clientId;
    QString m_clientSecret;
    SignOn::Identity *m_identity;
    SignOn::AuthSession *m_session;
};

#endif // XAUTHCLIENT_H
