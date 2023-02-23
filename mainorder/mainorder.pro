#-------------------------------------------------
#
# Project created by QtCreator 2021-11-19T10:03:21
#
#-------------------------------------------------

QT       += core gui
QT += network \
    sql \
    script
TARGET = mainorder
TEMPLATE = app


SOURCES += main.cpp\
        logindialog.cpp \
    registerdialog.cpp \
    dishdialog.cpp \
    manadialog.cpp \
    mainorderdialog.cpp \
    welcomedialog.cpp \
    chat_client.cpp \
    dishitem.cpp

HEADERS  += logindialog.h \
    mainorderdialog.h \
    registerdialog.h \
    dishdialog.h \
    manadialog.h \
    welcomedialog.h \
    chat_client.h \
    commom.h \
    data_struct.h \
    dishitem.h

FORMS    += logindialog.ui \
    mainorderdialog.ui \
    registerdialog.ui \
    dishdialog.ui \
    manadialog.ui \
    welcomedialog.ui \
    dishitem.ui

RESOURCES += \
    order.qrc
