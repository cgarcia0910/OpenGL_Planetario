#ifndef LIGHT_H
#define LIGHT_H
#include <stdio.h>
#include <iostream>
#include "GL/gl.h"

using namespace std;

class Light
{
public:
    Light();
    string name;
    GLfloat luzdifusa[4], luzambiente[4], luzspecular[4], posicion0[4];
private:

};

#endif // LIGHT_H
