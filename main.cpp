#include <QtGui/QApplication>
#include <QDebug>
#include <qmlapplicationviewer.h>
#include <QtDeclarative>
#include <QIcon>
#include <QLibraryInfo>

#include <blog.h>
#include <profile.h>
#include <settings.h>
#include <oauth.h>


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
        app.setApplicationName("meemblr");
        app.setApplicationVersion("0.0.1");
        app.setOrganizationName("cyrus and ZogG");

        Profile profile_req;
        Blog blog_req;
        Settings settings;
        Oauth oauth;


        /* DEBUG VALUES */
        if (settings.getUsername() == "") {
            settings.setUsername("zogg");
        }

        QmlApplicationViewer viewer;
        viewer.setOrientation(QmlApplicationViewer::ScreenOrientationLockPortrait);
        viewer.rootContext()->setContextProperty("profile_req",&profile_req);
        viewer.rootContext()->setContextProperty("blog_req",&blog_req);
        viewer.rootContext()->setContextProperty("settings",&settings);
        viewer.rootContext()->setContextProperty("oauth",&oauth);
        viewer.setMainQmlFile(QLatin1String("qml/meemblr/main.qml"));
        viewer.showExpanded();
        return app.exec();
}
