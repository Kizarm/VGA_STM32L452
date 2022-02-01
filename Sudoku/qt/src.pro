#CONFIG  += qt debug
QT      += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport
QMAKE_CXXFLAGS += -std=c++11

TARGET   = sudoku
TEMPLATE = app


SOURCES  = main.cpp
SOURCES += mainwindow.cpp
SOURCES += imageview.cpp
SOURCES += ../fmath.cpp
SOURCES += ../canvas.cpp
SOURCES += ../sudoku.cpp
SOURCES += ../indicator.cpp
SOURCES += ../common/Atari8x16SystemFont.c

HEADERS  = mainwindow.h
HEADERS += imageview.h
HEADERS += ../fmath.h
HEADERS += ../canvas.h
HEADERS += ../font.h
HEADERS += ../sudoku.h
HEADERS += ../init.h
HEADERS += ../indicator.h

FORMS    = mainwindow.ui

INCLUDEPATH += ../
#LIBS        += 
RESOURCES   += src.qrc

MOC_DIR     = moc
OBJECTS_DIR = obj
DESTDIR     = ./bin

unix {
    DEFINES    += UNIX
}

win32 {
    DEFINES    += QT_DLL WIN32
}


