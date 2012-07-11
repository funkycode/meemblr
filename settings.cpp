#include "settings.h"

Settings::Settings(QObject *parent)
    : QObject(parent)
{
    productName = QString("meemblr");
    configName = QString("config");
    sets = new QSettings(productName, configName, this);
}

void Settings::setUsername(QString username) {
    sets->setValue("username", username);
}

QVariant Settings::getUsername() {
    return sets->value("username","").toString();
}

void Settings::setThemeInverted(QVariant inverted) {
    sets->setValue("themeInverted", inverted);
}

QVariant Settings::getThemeInverted() {
    return sets->value("themeInverted", false);
}

void Settings::setAccessToken(QString token) {
    sets->setValue("token", token);
}

QString Settings::getAccessToken() {
    return sets->value("token", "").toString();
}

void Settings::setAccessTokenSecret(QString tokenSecret) {
    sets->setValue("tokenSecret", tokenSecret);
}

QString Settings::getAccessTokenSecret() {
    return sets->value("tokenSecret", "").toString();
}

QString Settings::getConsumerKey() {
    return "KhJM28EMcP1iEeUomSnFbpwI1YmzPVEYxh1xl07Rlr5AQfbKEj";
}
QString Settings::getConsumerSecret() {
    return "ouPTiEiAU7mUXbkRlDZkD3FlXEAOREWyffmtVuo5bQSanf7UFb";
}
