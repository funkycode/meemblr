#include <QtGui/QApplication>
#include <QDebug>
#include <qmlapplicationviewer.h>
#include <QtDeclarative>
#include <QIcon>
#include <QLibraryInfo>

#include <blog.h>
#include <profile.h>


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
        app.setApplicationName("meemblr");
        app.setApplicationVersion("0.0.1");
        app.setOrganizationName("cyrus and ZogG");
        Profile profile_req;
        Blog blog_req;

        QmlApplicationViewer viewer;
        viewer.setOrientation(QmlApplicationViewer::ScreenOrientationLockPortrait);
        viewer.rootContext()->setContextProperty("profile_req",&profile_req);
        viewer.rootContext()->setContextProperty("blog_req",&blog_req);
        viewer.setMainQmlFile(QLatin1String("qml/meemblr/main.qml"));
        viewer.showExpanded();
        return app.exec();
}
