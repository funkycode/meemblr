# Add more folders to ship with the application, here
folder_01.source = qml/meemblr
folder_01.target = qml
DEPLOYMENTFOLDERS = folder_01

# Additional import path used to resolve QML modules in Creator's code model
QML_IMPORT_PATH =

symbian:TARGET.UID3 = 0xE621F5FE

# Smart Installer package's UID
# This UID is from the protected range and therefore the package will
# fail to install if self-signed. By default qmake uses the unprotected
# range value if unprotected UID is defined for the application and
# 0x2002CCCF value if protected UID is given to the application
#symbian:DEPLOYMENT.installer_header = 0x2002CCCF

# Allow network access on Symbian
symbian:TARGET.CAPABILITY += NetworkServices

# If your application uses the Qt Mobility libraries, uncomment the following
# lines and add the respective components to the MOBILITY variable.
# CONFIG += mobility
# MOBILITY +=
QT += network
# Speed up launching on MeeGo/Harmattan when using applauncherd daemon
CONFIG += qdeclarative-boostable  \
          link_pkgconfig  \
          mobility
PKGCONFIG += libsignon-qt \
             signon-plugins\
             qdeclarative-boostable
# Add dependency to Symbian components
# CONFIG += qt-components

# The .cpp file which was generated for your project. Feel free to hack it.
SOURCES += main.cpp \
    blog.cpp \
    profile.cpp \
    settings.cpp \
    oauth.cpp \
    kqoauth/kqoauthmanager.cpp \
    kqoauth/kqoauthrequest.cpp \
    kqoauth/kqoauthutils.cpp \
    kqoauth/kqoauthrequest_xauth.cpp \
    kqoauth/kqoauthrequest_1.cpp \
    kqoauth/kqoauthauthreplyserver.cpp \
    tumblrapi.cpp

# Please do not modify the following two lines. Required for deployment.
include(qmlapplicationviewer/qmlapplicationviewer.pri)
qtcAddDeployment()

OTHER_FILES += \
    qtc_packaging/debian_harmattan/rules \
    qtc_packaging/debian_harmattan/manifest.aegis \
    qtc_packaging/debian_harmattan/copyright \
    qtc_packaging/debian_harmattan/control \
    qtc_packaging/debian_harmattan/compat \
    qtc_packaging/debian_harmattan/changelog \
    README \
    qml/meemblr/PhotoPost.qml \
    qml/meemblr/VideoPost.qml \
    qml/meemblr/QuotePost.qml \
    qml/meemblr/LinkPost.qml \
    qml/meemblr/AnswerPost.qml \
    qml/meemblr/AudioPost.qml

HEADERS += \
    blog.h \
    profile.h \
    settings.h \
    oauth.h \
    kqoauth/kqoauthmanager.h \
    kqoauth/kqoauthrequest.h \
    kqoauth/kqoauthutils.h \
    kqoauth/kqoauthrequest_xauth_p.h \
    kqoauth/kqoauthrequest_xauth.h \
    kqoauth/kqoauthrequest_p.h \
    kqoauth/kqoauthrequest_1.h \
    kqoauth/kqoauthmanager_p.h \
    kqoauth/kqoauthglobals.h \
    kqoauth/kqoauthauthreplyserver_p.h \
    kqoauth/kqoauthauthreplyserver.h \
    tumblrapi.h

RESOURCES +=
