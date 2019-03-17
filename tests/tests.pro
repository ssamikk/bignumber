QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

INCLUDEPATH+= $$quote(../bignumberimpl/)

SOURCES += \ 
    tst_bignumber.cpp \
    ../bignumberimpl/bignumber.cpp

HEADERS += \
    ../bignumberimpl/bignumber.h
