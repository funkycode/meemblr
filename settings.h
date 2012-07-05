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
private:
    QSettings *sets;

};

#endif // SETTINGS_H
