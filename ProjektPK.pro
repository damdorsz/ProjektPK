QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets sql

CONFIG += c++17

# Include paths for MySQL Connector C
INCLUDEPATH += "C:/Program Files/MySQL/MySQL Connector C 6.1/include"

# Library paths for MySQL Connector C (jeśli potrzebne)
# LIBS += -L"path_to_library_directory"

SOURCES += \
    dodawaniestolika.cpp \
    main.cpp \
    mainmenu.cpp \
    mainwindow.cpp \
    stanstolikow.cpp \
    stolik.cpp \
    wyborstolika.cpp \
    zamowienie.cpp

HEADERS += \
    dodawaniestolika.h \
    mainmenu.h \
    mainwindow.h \
    stanstolikow.h \
    stolik.h \
    wyborstolika.h \
    zamowienie.h

FORMS += \
    dodawaniestolika.ui \
    mainmenu.ui \
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
