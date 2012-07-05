#ifndef PROFILE_H
#define PROFILE_H

#include <QObject>
#include <QString>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <QByteArray>
#include <QtScript/QScriptEngine>
#include <QtScriptTools/QtScriptTools>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>


class Profile : public QObject
 {
     Q_OBJECT

 public:
     Profile(QObject *parent = 0);
     Q_INVOKABLE void profile_request(QString nick);

signals:
     void resultprofile(QString data);

public slots:
    void parser(QNetworkReply *reply);

private:
   QNetworkAccessManager *nam;

 };


#endif // PROFILE_H
