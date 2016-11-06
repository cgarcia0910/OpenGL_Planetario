
#ifndef MODELO3D_H_
#define MODELO3D_H_

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <cstring>
#include "Cara.h"
#include "Punto3D.h"
#include <unistd.h>

using namespace std;

enum look_type { WIRE , SOLID , FLAT , SMOOTH };

class Modelo3D {
private:
        void setVector4(GLfloat *v, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
	vector<Cara> ListaCaras;
	vector<Punto3D> ListaPuntos3D;
	int NFaces, NVertex;
    int zoom;
    double sunDistance;
    float radius;
    int getVertices();
    void setCaras(int NFaces);
    void setVertices(int NVertex);
    void drawCircle();
    float w;
    float wParent;
    GLfloat mat_ambiente[4];
    GLfloat mat_diffuse[4];
    GLfloat mat_specular[4];
public:
    Modelo3D();
    Modelo3D(double sunDistance, char *model, float radius, float w, GLfloat mat_ambiente[4], GLfloat mat_diffuse[4], GLfloat mat_specular[4]);
    Modelo3D(double planetDistance, char *model, float radius, float wParent, float w, GLfloat mat_ambiente[4], GLfloat mat_diffuse[4], GLfloat mat_specular[4]);
    bool satelite;
    int getCaras();
    void InitGL(float Width,float Height);
    bool Load_Model(char *model);
    void DrawGLScene(look_type look , float angulo);
	void zoomIn();
	void zoomOut();
    void onMotion(int x, int y);
    void onMouse(int button, int state, int x, int y);
};


#endif /* MODELO3D_H_ */
