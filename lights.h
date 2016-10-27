#ifndef LIGHTS_H
#define LIGHTS_H
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>


using namespace std;
class Lights
{
public:
    Lights();
    void startLight1();
    void startLight2();
    void startLight3();
    void startLight4();
    void startLight5();
    void startLight6();
    void startLight7();
    void startLight8();
private:
    void setVector4(GLfloat *v, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
GLfloat luzdifusa[4], luzambiente[4], luzspecular[4], posicion0[4];
};


#endif // LIGHTS_H
