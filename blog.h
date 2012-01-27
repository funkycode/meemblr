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


 private:

 };



#endif // BLOG_H
