#ifndef SETTINGS_H
#define SETTINGS_H

#include <QObject>
#include <QString>
#include <QSettings>

class Settings : public QObject
{
    Q_OBJECT

public:
    Settings(QObject *parent = 0);
    Q_INVOKABLE void setUsername(QString username);
    Q_INVOKABLE QVariant getUsername();
    Q_INVOKABLE void setThemeInverted(QVariant inverted);
    Q_INVOKABLE QVariant getThemeInverted();
    void setAccessToken(QString token);
    QString getAccessToken();
    void setAccessTokenSecret(QString tokenSecret);
    QString getAccessTokenSecret();
    QString getConsumerKey();
    QString getConsumerSecret();
    QString productName;
    QString configName;

private:
    QSettings *sets;

};

#endif // SETTINGS_H
