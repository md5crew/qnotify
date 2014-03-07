#-------------------------------------------------
#
# Project created by QtCreator 2014-03-07T01:21:36
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = qnotify
CONFIG   += console
CONFIG   += c++11
CONFIG   -= app_bundle

TEMPLATE = app
LIBS = -linotifytools


SOURCES += main.cpp \
    fswatcher.cpp

HEADERS += \
    fswatcher.h
