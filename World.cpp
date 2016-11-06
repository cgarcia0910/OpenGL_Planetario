#include "World.h"

World::World()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(40.0f, 1.0f, 0.01f, 50.0f);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_RGBA | GLUT_DEPTH );
    glutInitWindowSize(1000,1000);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Planetario");
    glEnable(GL_LIGHTING); glEnable(GL_NORMALIZE); glEnable(GL_CULL_FACE);
    glEnable(GL_DEPTH_TEST);
    //this->lights = new Lights();
    this->cameras = new Camera();
    this->displayStyle = WIRE;
    this->cameras->chooseCamera('x');
    zoom = 10;
    this->time = 0;
}

void World::paso() {
   this->time = this->time + 0.1;
}

void World::onMouse(int button, int state, int x, int y)
{
    if( button == MOUSE_SCROLL_UP )
        cameras->distCentro = cameras->distCentro +100;
        zoomIn();

    if( button == MOUSE_SCROLL_DOWN )
        if (cameras->distCentro -100 >0)
            cameras->distCentro = cameras->distCentro -100;
        zoomOut();
}

void World::zoomIn() {
    zoom++;
}
void World::zoomOut() {
    if(zoom >= -10) zoom--;
}
void World::display(void) {

    glClearColor(0.f, 0.f, 0.0f, 0.f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    this->cameras->loadCamera();

    float scale_from_editor = 0.005 + double( (float)(zoom)/(float)3000);
    glScalef(scale_from_editor, scale_from_editor, scale_from_editor);
    for (int i=0; i<this->models.size(); i++)
    {
        glPushMatrix();
        ((Modelo3D)this->models[i]).onMouse(button, state, x, y);
        ((Modelo3D)this->models[i]).DrawGLScene(displayStyle, time);
        glPopMatrix();
    }
    glFlush();
    glutSwapBuffers();
}
void World::loadModels(char *descModel, double sunDistance, float radius, float w, GLfloat mat_ambiente[4], GLfloat mat_diffuse[4], GLfloat mat_specular[4]){
    Modelo3D *modelo3D = new Modelo3D(sunDistance, descModel, radius, w, mat_ambiente, mat_diffuse, mat_specular);
    modelo3D->InitGL(1024, 768);
    this->models.push_back(*modelo3D);
}
void World::loadModels(char *descModel, double sunDistance, float radius, float w, float wParent, GLfloat mat_ambiente[4], GLfloat mat_diffuse[4], GLfloat mat_specular[4]){
    Modelo3D *modelo3D = new Modelo3D(sunDistance, descModel, radius, wParent, w, mat_ambiente, mat_diffuse, mat_specular);
    modelo3D->InitGL(1024, 768);
    this->models.push_back(*modelo3D);
}
void World::changeCamera(char axis){
    this->cameras->chooseCamera(axis);
}

void World::changeLights(short idLight) {
    if(idLight <= 8 && idLight >= 0 && !lightStatus[idLight]) {
        /*
        if(idLight == 1)
            lights->startLight1();
        if(idLight == 2)
            lights->startLight2();
        if(idLight == 3)
            lights->startLight3();
        if(idLight == 4)
            lights->startLight4();
        if(idLight == 5)
            lights->startLight5();
        if(idLight == 6)
            lights->startLight6();
        if(idLight == 7)
            lights->startLight7();
        if(idLight == 8)
            lights->startLight8();*/
        lightStatus[idLight] = true;
        lights->switchLight(idLight);
    }
    else if(idLight <= 8 && idLight >= 0 && lightStatus[idLight]) {
        idLight ++;
        if(idLight == 1)
            glDisable(GL_LIGHT0);
        if(idLight == 2)
            glDisable(GL_LIGHT1);
        if(idLight == 3)
            glDisable(GL_LIGHT2);
        if(idLight == 4)
            glDisable(GL_LIGHT3);
        if(idLight == 5)
            glDisable(GL_LIGHT4);
        if(idLight == 6)
            glDisable(GL_LIGHT5);
        if(idLight == 7)
            glDisable(GL_LIGHT6);
        if(idLight == 8)
            glDisable(GL_LIGHT7);
        lightStatus[idLight-1] = false;
    }
}

