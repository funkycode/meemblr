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


#include <signon-plugins/oauth1data.h>
#include <signon-qt/SignOn/Identity>
#include <signon-qt/SignOn/AuthSession>
#include <signon-qt/SignOn/AuthService>

/*#include <SignOn/Identity>
#include <SignOn/AuthSession>
#include <SignOn/AuthPluginInterface>
#include <SignOn/SessionData>
#include <SignOn/Error>*/

class Oauth : public QObject
{
    Q_OBJECT

public:
    Oauth(QObject *parent = 0);
    Q_INVOKABLE void startAuthentication(QString username);
    //bool sortParameter(const QPair<QString, QString> &left, const QPair<QString, QString> &right);
    QString testCall();
    QString signRequest(QUrl url, int methodType, QList< QPair<QString, QString> > requestParameters);


public slots:
    void onResponse(const SignOn::SessionData &sessionData);
    void onError(const SignOn::Error &error);
    void identityMethodsAvailable(const QStringList &);
    void onApiResponse(QNetworkReply *reply);
    void onApiError(QNetworkReply::NetworkError* error);

private:
    QByteArray encodedParameterList(const QList< QPair<QString, QString> > &parameters);
    QString encodeHMACSHA1(const QString &body, const QString &key);

    SignOn::AuthService *authService;
    SignOn::IdentityInfo *m_info;
    QNetworkAccessManager nam;
};

#endif // OAUTH_H
