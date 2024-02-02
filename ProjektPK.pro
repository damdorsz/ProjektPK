QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    dodawaniestolika.cpp \
    logowanie.cpp \
    main.cpp \
    mainwindow.cpp \
    stanstolikow.cpp \
    stolik.cpp \
    wyborstolika.cpp \
    zamowienie.cpp

HEADERS += \
    dodawaniestolika.h \
    logowanie.h \
    mainwindow.h \
    stanstolikow.h \
    stolik.h \
    wyborstolika.h \
    zamowienie.h

FORMS += \
    dodawaniestolika.ui \
    logowanie.ui \
    mainwindow.ui \
    stanstolikow.ui \
    stolik.ui \
    wyborstolika.ui \
    zamowienie.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc
