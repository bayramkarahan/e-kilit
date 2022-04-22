#-------------------------------------------------
#
# Project created by QtCreator 2020-09-12T21:58:42
#
#-------------------------------------------------

QT       += core gui
#QT       += webenginewidgets
#sudo apt install qtwebengine5-dev
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = e-kilit
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
        qrcodegen.cpp

HEADERS += \
        mainwindow.h \
    menu.h \
    filecrud.h \
    qrcodegen.hpp


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc


target.path = /usr/bin

desktop_file.files = e-kilit.desktop
desktop_file.path = /usr/share/applications/

icon.files = icons/e-kilit.svg
icon.path = /usr/share/e-kilit


e-kilitetcxdgautostart.files = e-kilitetcxdgautostart.desktop
e-kilitetcxdgautostart.path = /etc/xdg/autostart/

e-kilitxdglink.files = e-kilitxdglink.sh
e-kilitxdglink.path = /usr/bin/



INSTALLS += target desktop_file icon e-kilitetcxdgautostart e-kilitxdglink


DISTFILES += \
    e-kilit.svg\
    e-kilit.desktop\
    e-kilitetcxdgautostart.desktop\
    e-kilitxdglink.sh\



