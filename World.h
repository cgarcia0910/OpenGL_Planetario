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
        Lights * lights;
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
        float angulo;
        World();
        look_type displayStyle;
        void onMouse(int button, int state, int x, int y);
        void loadModels(char *descModel, double sunDistance, float radius);
        void display(void);
        void changeCamera(char axis);
        void changeLights(short idLight);
        void paso();
};

#endif // WORLD_H
