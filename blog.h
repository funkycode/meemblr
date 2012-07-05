#ifndef BLOG_H
#define BLOG_H


#include <QObject>
#include <QString>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <QByteArray>
#include <QtDebug>
#include <QtScript/QScriptEngine>
#include <QtScriptTools/QtScriptTools>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <signon-plugins/oauth1data.h>
#include <SignOn/Identity>
#include <SignOn/AuthSession>
#include <SignOn/AuthPluginInterface>
#include <SignOn/SessionData>
#include <SignOn/Error>

class Blog : public QObject
 {
     Q_OBJECT

 public:
     Blog(QObject *parent = 0);
     Q_INVOKABLE void blog_request(QString period);

signals:
     void blogresult(QString data);

public slots:
    void parser(QNetworkReply *reply);
    void onResponse(const SignOn::SessionData &sessionData);
    void onError(const SignOn::Error &error);

private:
   QNetworkAccessManager *nam;
   SignOn::Identity *m_identity;
   SignOn::AuthSession *m_session;

 };

#endif // BLOG_H
