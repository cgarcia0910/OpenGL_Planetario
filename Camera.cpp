#include "Camera.h"
using namespace std;
#include <iostream>
Camera::Camera()
{
    this->distCentro = 500.0f;
}
void Camera::loadCamera()
{
    if (this->idCamara != NULL) {
        switch (this->idCamara) {
        case 'z':
            gluLookAt(0.0f, -distCentro, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f);
            glMatrixMode(GL_PROJECTION);
            glLoadIdentity();
            gluPerspective(30.0f, 1, 0.1f, 1000.0f);
            break;
        case 'y':
            cout << "z" <<endl;
            //gluLookAt(1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 10.0f);
            gluLookAt(0.0f, 0.0f, distCentro, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
            glMatrixMode(GL_PROJECTION);
            glLoadIdentity();
            gluPerspective(30.0f, 1, 0.1f, 1000.0f);
            //glFrustum(-100.0f, +100.0f, -100.0f, +100.0f, +1.0f, +100.0f);
            //gluPerspective(30, 30, 10, 10);
            break;
        case 'x':
            gluLookAt(distCentro, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f);
            glMatrixMode(GL_PROJECTION);
            glLoadIdentity();
            gluPerspective(30.0f, 1, 0.1f, 1000.0f);
        default:
            break;
        }
    }
}
void Camera::chooseCamera(char id){
    switch (id) {
    case 'z':
        cout << "z" <<endl;
        this->idCamara = 'z';
        //gluLookAt(0.0f, 0.0f, 50.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
       // glFrustum(-100.0f, +100.0f, -100.0f, +100.0f, +1.0f, +100.0f);
        //gluPerspective(30, 30, 10, 10);
        break;
    case 'y':
        this->idCamara = 'y';
        //gluLookAt(0.0f, 50.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f);
        //glFrustum(-100.0f, +100.0f, -100.0f, +100.0f, +1.0f, +100.0f);
        break;
    case 'x':
        this->idCamara = 'x';
        //gluLookAt(50.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
        //glFrustum(-100.0f, +100.0f, -100.0f, +100.0f, +1.0f, +100.0f);
    default:
        break;
    }
}
