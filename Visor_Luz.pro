QT       += core gui opengl xml

TARGET = visorLuz
TEMPLATE = app



SOURCES += main.cpp \
    Modelo3D.cpp \
    Punto3D.cpp \
    World.cpp \
    Cara.cpp \
    lights.cpp \
    Camera.cpp \
    jsmn.c

HEADERS += \
    Modelo3D.h \
    Punto3D.h \
    World.h \
    Cara.h \
    lights.h \
    Camera.h \
    jsmn.h




LIBS += -L/usr/local/lib  -lGL -lGLU -lglut

INCLUDEPATH += -I/usr/local/include

