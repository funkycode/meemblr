#include "settings.h"

Settings::Settings(QObject *parent)
    : QObject(parent)
{
    sets = new QSettings("meemblr", "cyrus-ZogG-niwakame");
}

void Settings::setUsername(QString username) {
    sets->setValue("username", username);
}

QVariant Settings::getUsername() {
    return sets->value("username","");
}

void Settings::setThemeInverted(QVariant inverted) {
    sets->setValue("themeInverted", inverted);
}

QVariant Settings::getThemeInverted() {
    return sets->value("themeInverted", false);
}
