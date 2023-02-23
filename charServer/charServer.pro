# -------------------------------------------------
# Project created by QtCreator 2021-11-18T02:27:48
# -------------------------------------------------
QT += network \
    sql
QT += script
QT -= gui
TARGET = charServer
CONFIG += console
CONFIG -= app_bundle
TEMPLATE = app
SOURCES += main.cpp \
    chat_server.cpp \
    my_socket.cpp \
    user_helper.cpp
HEADERS += chat_server.h \
    my_socket.h \
    user_helper.h \
    data_struct.h \
    commom.h
