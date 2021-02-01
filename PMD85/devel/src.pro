#CONFIG  += qt debug
QT      += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport
QMAKE_CXXFLAGS += -std=c++11

VPATH = . ../cpu ../common

TARGET   = simul
TEMPLATE = app

SOURCES  = main.cpp
SOURCES += mainwindow.cpp
SOURCES += imageview.cpp
SOURCES += worker.cpp
SOURCES += ChipCpu8080.cpp ChipMemory.cpp ChipPIO8255.cpp ChipUSART8251.cpp ChipPIT8253.cpp SystemPIO.cpp
SOURCES += IifGPIO.cpp IifTape.cpp IifTimer.cpp RomModule.cpp Pmd32.cpp
SOURCES += PMD85v2A.cpp
SOURCES += ff.c
SOURCES += diskopsbase.cpp diskopsfile.cpp

HEADERS  = mainwindow.h
HEADERS += imageview.h
HEADERS += worker.h
HEADERS += Globals.h ChipCpu8080.h ChipMemory.h macros8080.h ChipPIO8255.h ChipUSART8251.h ChipPIT8253.h SystemPIO.h
HEADERS += IifGPIO.h IifTape.h IifTimer.h RomModule.h Pmd32.h
HEADERS += PMD85v2A.h
HEADERS += ff.h diskio.h ffconf.h
HEADERS += diskopsbase.h diskopsfile.h

FORMS    = mainwindow.ui

INCLUDEPATH += ../cpu ../common
#LIBS        += 
RESOURCES   += src.qrc

MOC_DIR     = moc
OBJECTS_DIR = obj
DESTDIR     = ../bin

unix {
    DEFINES    += UNIX
}

win32 {
    DEFINES    += QT_DLL WIN32
}
