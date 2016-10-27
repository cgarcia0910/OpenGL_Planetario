#ifndef CAMERA_H
#define CAMERA_H

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
class Camera
{
public:
    Camera();
    char idCamara;
    void loadCamera();
    float distCentro;
    void chooseCamera(char id);
};

#endif // CAMERA_H
