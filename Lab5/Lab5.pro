QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    logic\board.cpp \
    logic\enemycomputer.cpp \
    logic\fileworker.cpp \
    logic\gameboard.cpp \
    windows/downloadwindow.cpp \
    windows/savewindow.cpp \
    windows\gamewindow.cpp \
    main.cpp \
    windows\mainwindow.cpp \
    logic\paintercube.cpp \
    windows\presettingwindow.cpp \
    windows\windowsworker.cpp

HEADERS += \
    logic\board.h \
    logic\enemycomputer.h \
    logic\fileworker.h \
    logic\gameboard.h \
    windows/downloadwindow.h \
    windows/savewindow.h \
    windows\gamewindow.h \
    windows\mainwindow.h \
    logic\paintercube.h \
    windows\presettingwindow.h \
    windows\windowsworker.h

FORMS += \
    windows/downloadwindow.ui \
    windows/savewindow.ui \
    windows\gamewindow.ui \
    windows\mainwindow.ui \
    windows\presettingwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc
