QT       += core gui
QT       +=sql
QT       +=serialport
QT       +=core gui sql network multimedia multimediawidgets charts printsupport widgets axcontainer

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    arduino.cpp \
    connection.cpp \
    dialog_stats.cpp \
    employe.cpp \
    exportexcelobject.cpp \
    login.cpp \
    main.cpp \
    mainwindow.cpp \
    res.cpp \
    reservation.cpp \
    smtp.cpp \
    spons.cpp \
    sponsor.cpp \
    trans.cpp \
    transport.cpp

HEADERS += \
    WebAxWidget.h \
    arduino.h \
    connection.h \
    dialog_stats.h \
    employe.h \
    exportexcelobject.h \
    login.h \
    mainwindow.h \
    res.h \
    reservation.h \
    smtp.h \
    spons.h \
    sponsor.h \
    trans.h \
    transport.h

FORMS += \
    dialog_stats.ui \
    login.ui \
    mainwindow.ui \
    res.ui \
    spons.ui \
    trans.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
