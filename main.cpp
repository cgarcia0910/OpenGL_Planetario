

#include <iostream>
#include "Modelo3D.h"
#include "GL/gl.h"
#include "GL/glu.h"
#include "GL/glut.h"
#include "Camera.h"
#include "World.h"
#include <stdio.h>
#include <iostream>
#include "jsmn.h"
#include <fstream>
#include "QFile"
#include "QDomDocument"
using namespace std;

//int x0, y0;
int window;
Modelo3D *modelo3D;
World *world;
Camera * camera;
void keyPressed(unsigned char key, int x , int y )
{   
    switch ( key) {
    case 49:
        world->changeLights(1);
        break;
    case 50:
        world->changeLights(2);
        break;
    case 51:
        world->changeLights(3);
        break;
    case 52:
        world->changeLights(4);
        break;
    case 53:
        world->changeLights(5);
        break;
    case 54:
        world->changeLights(6);
        break;
    case 55:
        world->changeLights(7);
        break;
    case 56:
        world->changeLights(8);
        break;
    case 27:
        glutDestroyWindow(window);
        exit(0);
        break;
    case 97:
        world->displayStyle = WIRE;
        //modelo3D->changeDisplay('W');
        break;
    case 115:
        //world->displayStyle = 'S';
        world->displayStyle = SOLID;
        //modelo3D->changeDisplay('S');
        break;
    case 100:
        world->displayStyle = FLAT;
        //modelo3D->changeDisplay('F');
        break;
    case 102:
        world->displayStyle = SMOOTH;
        //modelo3D->changeDisplay('H');
        break;
    case 88 | 120:
        world->changeCamera('x');
        //camera->chooseCamera('x');
        cout << "vista x" << endl;
        break;
    case 89 | 121:
        world->changeCamera('y');
        //camera->chooseCamera('y');
        cout << "vista y" << endl;
        break;
    case 90 | 122:
        world->changeCamera('z');
        //camera->chooseCamera('z');
        cout << "vista z" << endl;
        break;
    case 32:
        world->paso();
    }
glutPostRedisplay();
}

void onMouse(int button, int state, int x, int y){
    //modelo3D->onMouse(button,state,x,y);
    world->onMouse(button,state,x,y);
}

void onMotion(int x, int y) {
    //modelo3D->onMotion(x,y);
    cout << x << "--" << y << endl;
    // world->onMotion(x, y);

    }

void display(void) {
   // modelo3D->DrawGLScene();
    world->display();
}
void setVector4(GLfloat *v, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3)
{
    v[0] = v0;
    v[1] = v1;
    v[2] = v2;
    v[3] = v3;
}
void loadJSON(char *nombre) {
    /*
    ifstream myReadFile;
     myReadFile.open("planetario.json");
     char output[100];
     if (myReadFile.is_open()) {
         while (!myReadFile.eof()) {
            myReadFile >> output;
            cout<<output;
         }
    }
    myReadFile.close();
    jsmn_parser parser;
    jsmntok_t tokens[10];
    jsmn_init(&parser);
    jsmn_parse(&parser, output, strlen(output), tokens, 10);*/
    QFile xml ("planetario.json");
    xml.open(QIODevice::ReadOnly);
    QDomDocument *xmlTemporal = new QDomDocument();
    xmlTemporal->setContent(&xml);
    xml.close();
    QDomElement raiz = xmlTemporal->documentElement();
    QDomElement planetas = raiz.firstChild().toElement();
    glScalef(1,1,1);
    while (!planetas.isNull()) {
        cout << "planetas" <<endl;
        if(planetas.tagName() == "planeta") {
            QDomElement planeta = planetas.firstChild().toElement();
            glScalef(1,1,1);
            while (!planeta.isNull()) {
                QString planetName = planeta.attribute("name", "noName");
                float radius = planeta.attribute("radius").toFloat();
                float t = planeta.attribute("t").toFloat();
                string model = planeta.attribute("model").toStdString();
                string material = planeta.attribute("material").toStdString();
                double sunDistance = planeta.attribute("sunDistance").toDouble();
                char *c = const_cast<char*>(model.c_str());
                cout << planetName.toStdString() << radius << endl;
                world->loadModels(c, sunDistance, radius);
                planeta = planeta.nextSibling().toElement();
            }
        }
        planetas = planetas.nextSibling().toElement();
    }

}

int main(int argc, char **argv) {

    cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(1024, 768);
    glutInitWindowPosition(100, 100);
    camera = new Camera();
    world = new World();
    loadJSON("planetario.json");
    glMatrixMode(GL_MODELVIEW);
    // world->loadModels(argv[1], 0);
   // world->loadModels(argv[1], 100);
     glutDisplayFunc(display);
     glutIdleFunc(display); // pinta cuando no esté haciendo nada
     glutMouseFunc(onMouse);// puntero a la función de eventos de teclado
     glutMotionFunc(onMotion);
     glutKeyboardFunc(keyPressed);
     glutMainLoop();
	return 0;
}
