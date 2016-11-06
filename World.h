#ifndef WORLD_H
#define WORLD_H

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "Modelo3D.h"
#include "lights.h"
#include "Camera.h"
#include "math.h"

class World
{
    private:

        vector<Modelo3D> models;
        Camera* cameras;
        const int MOUSE_SCROLL_UP = 3;
        const int MOUSE_SCROLL_DOWN = 4;
        void zoomIn();
        void zoomOut();
        int zoom;
        bool lightStatus[8] = {false, false, false, false, false, false, false, false};
    public:
        int button, state, x, y;
        //float angulo;
        float time;
        World();
        look_type displayStyle;
        void onMouse(int button, int state, int x, int y);
        void loadModels(char *descModel, double sunDistance, float radius, float w, GLfloat mat_ambiente[4], GLfloat mat_diffuse[4], GLfloat mat_specular[4]);
        void loadModels(char *descModel, double sunDistance, float radius, float wParent, float w, GLfloat mat_ambiente[4], GLfloat mat_diffuse[4], GLfloat mat_specular[4]);
        void display(void);
        void changeCamera(char axis);
        void changeLights(short idLight);
        void paso();
        Lights * lights;
};

#endif // WORLD_H
