TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    Cara.cpp \
    Modelo3D.cpp \
    Punto3D.cpp \
    World.cpp

DISTFILES += \
    ejemplo4 \
    proyectoPlanetario.pro.user \
    Esfera.asc

HEADERS += \
    Cara.h \
    Modelo3D.h \
    Punto3D.h \
    World.h
