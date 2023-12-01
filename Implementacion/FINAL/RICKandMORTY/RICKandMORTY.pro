QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    NIVEL1.cpp \
    arma.cpp \
    main.cpp \
    mainwindow.cpp \
    modelo.cpp \
    morty.cpp

HEADERS += \
    NIVEL1.h \
    arma.h \
    mainwindow.h \
    modelo.h \
    morty.h

FORMS += \
    mainwindow.ui

RC_ICONS =logo.ico

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    img.qrc

DISTFILES +=
