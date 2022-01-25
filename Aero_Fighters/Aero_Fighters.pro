#-------------------------------------------------
#
# Project created by QtCreator 2017-12-28T09:59:49
#
#-------------------------------------------------

QT       += core gui \
         multimedia



greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Aero_Fighters
TEMPLATE = app


SOURCES += main.cpp \
    playerplane.cpp \
    gameenvironment.cpp \
    missile.cpp \
    enemyplane.cpp \
    playerhealth.cpp \
    playerscore.cpp \
    gameover.cpp

HEADERS  += \
    playerplane.h \
    gameenvironment.h \
    missile.h \
    enemyplane.h \
    playerhealth.h \
    playerscore.h \
    gameover.h

FORMS    +=

RESOURCES += \
    gameresources.qrc \
    gr3.qrc \
    bgsound.qrc \
    missile.qrc \
    missileimage.qrc \
    blast.qrc \
    enemyplane.qrc \
    splash.qrc
