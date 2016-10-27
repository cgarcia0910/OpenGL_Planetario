#include "lights.h"

Lights::Lights()
{
    glEnable(GL_LIGHTING);
}
void Lights::startLight1(){
    cout << "luz encendida" << endl;
    setVector4(luzdifusa, 1.0, 0.1, 0.1, 1.0);
    setVector4(luzambiente, 0.50, 0.50, 0.50, 1.0);
    setVector4(luzspecular, 0.20, 0.20, 0.20, 1.0);
    setVector4(posicion0, 100, 100, -100, 1.0);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, luzdifusa);
    glLightfv(GL_LIGHT0, GL_AMBIENT, luzambiente);
    glLightfv(GL_LIGHT0, GL_SPECULAR, luzspecular);
    glLightfv(GL_LIGHT0, GL_POSITION, posicion0);
    glEnable(GL_LIGHT0);
}
void Lights::startLight2(){
    setVector4(luzdifusa, 1.0, 0.1, 0.1, 1.0);
    setVector4(luzambiente, 0.50, 0.50, 0.50, 1.0);
    setVector4(luzspecular, 0.20, 0.20, 0.20, 1.0);
    setVector4(posicion0, -100, -100, +100, 1.0);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, luzdifusa);
    glLightfv(GL_LIGHT1, GL_AMBIENT, luzambiente);
    glLightfv(GL_LIGHT1, GL_SPECULAR, luzspecular);
    glLightfv(GL_LIGHT1, GL_POSITION, posicion0);
    glEnable(GL_LIGHT1);
}
void Lights::startLight3(){
    setVector4(luzdifusa, 1.0, 0.1, 0.1, 1.0);
    setVector4(luzambiente, 0.50, 0.50, 0.50, 1.0);
    setVector4(luzspecular, 0.20, 0.20, 0.20, 1.0);
    setVector4(posicion0, 100, 100, 100, 1.0);
    glLightfv(GL_LIGHT2, GL_DIFFUSE, luzdifusa);
    glLightfv(GL_LIGHT2, GL_AMBIENT, luzambiente);
    glLightfv(GL_LIGHT2, GL_SPECULAR, luzspecular);
    glLightfv(GL_LIGHT2, GL_POSITION, posicion0);
    glEnable(GL_LIGHT2);
}
void Lights::startLight4(){
    setVector4(luzdifusa, 1.0, 0.1, 0.1, 1.0);
    setVector4(luzambiente, 0.50, 0.50, 0.50, 1.0);
    setVector4(luzspecular, 0.20, 0.20, 0.20, 1.0);
    setVector4(posicion0, 100, 100, -100, 1.0);
    glLightfv(GL_LIGHT3, GL_DIFFUSE, luzdifusa);
    glLightfv(GL_LIGHT3, GL_AMBIENT, luzambiente);
    glLightfv(GL_LIGHT3, GL_SPECULAR, luzspecular);
    glLightfv(GL_LIGHT3, GL_POSITION, posicion0);
    glEnable(GL_LIGHT3);
}
void Lights::startLight5(){
    setVector4(luzdifusa, 1.0, 0.1, 0.1, 1.0);
    setVector4(luzambiente, 0.50, 0.50, 0.50, 1.0);
    setVector4(luzspecular, 0.20, 0.20, 0.20, 1.0);
    setVector4(posicion0, 100, 100, -100, 1.0);
    glLightfv(GL_LIGHT4, GL_DIFFUSE, luzdifusa);
    glLightfv(GL_LIGHT4, GL_AMBIENT, luzambiente);
    glLightfv(GL_LIGHT4, GL_SPECULAR, luzspecular);
    glLightfv(GL_LIGHT4, GL_POSITION, posicion0);
    glEnable(GL_LIGHT4);
}
void Lights::startLight6(){
    setVector4(luzdifusa, 1.0, 0.1, 0.1, 1.0);
    setVector4(luzambiente, 0.50, 0.50, 0.50, 1.0);
    setVector4(luzspecular, 0.20, 0.20, 0.20, 1.0);
    setVector4(posicion0, 100, 100, -100, 1.0);
    glLightfv(GL_LIGHT5, GL_DIFFUSE, luzdifusa);
    glLightfv(GL_LIGHT5, GL_AMBIENT, luzambiente);
    glLightfv(GL_LIGHT5, GL_SPECULAR, luzspecular);
    glLightfv(GL_LIGHT5, GL_POSITION, posicion0);
    glEnable(GL_LIGHT5);
}
void Lights::startLight7(){
    setVector4(luzdifusa, 1.0, 0.1, 0.1, 1.0);
    setVector4(luzambiente, 0.50, 0.50, 0.50, 1.0);
    setVector4(luzspecular, 0.20, 0.20, 0.20, 1.0);
    setVector4(posicion0, 100, 100, -100, 1.0);
    glLightfv(GL_LIGHT6, GL_DIFFUSE, luzdifusa);
    glLightfv(GL_LIGHT6, GL_AMBIENT, luzambiente);
    glLightfv(GL_LIGHT6, GL_SPECULAR, luzspecular);
    glLightfv(GL_LIGHT6, GL_POSITION, posicion0);
    glEnable(GL_LIGHT6);
}
void Lights::startLight8(){
    setVector4(luzdifusa, 1.0, 0.1, 0.1, 1.0);
    setVector4(luzambiente, 0.50, 0.50, 0.50, 1.0);
    setVector4(luzspecular, 0.20, 0.20, 0.20, 1.0);
    setVector4(posicion0, 100, 100, -100, 1.0);
    glLightfv(GL_LIGHT7, GL_DIFFUSE, luzdifusa);
    glLightfv(GL_LIGHT7, GL_AMBIENT, luzambiente);
    glLightfv(GL_LIGHT7, GL_SPECULAR, luzspecular);
    glLightfv(GL_LIGHT7, GL_POSITION, posicion0);
    glEnable(GL_LIGHT7);
}
void Lights::setVector4(GLfloat *v, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3)
{
    v[0] = v0;
    v[1] = v1;
    v[2] = v2;
    v[3] = v3;
}
