QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    loginwindow.cpp \
    mainwindow.cpp \
    serverselect.cpp

HEADERS += \
    ASIO-Networker/net_client.h \
    ASIO-Networker/net_common.h \
    ASIO-Networker/net_connection.h \
    ASIO-Networker/net_message.h \
    ASIO-Networker/net_server.h \
    ASIO-Networker/net_tsqueue.h \
    ASIO-Networker/olc_net.h \
    SWR_Base/Record.h \
    SWR_Base/SWEP1R.h \
    SWR_Base/UnixMem/Memory.h \
    SWR_Base/UnixMem/Memory.h \
    SWR_Base/WinMem/Memory.h \
    SWR_Base/WinMem/Memory.h \
    client.h \
    loginwindow.h \
    mainwindow.h \
    serverselect.h

FORMS += \
    loginwindow.ui \
    mainwindow.ui \
    serverselect.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    ASIO-Networker/LICENCE.md \
    ASIO-Networker/README.md \
    SWR_Base/README.md \
    SWR_Base/UnixMem/README.md \
    SWR_Base/WinMem/README.md
