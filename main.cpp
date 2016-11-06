

#include <iostream>
#include "Modelo3D.h"
#include "GL/gl.h"
#include "GL/glu.h"
#include "GL/glut.h"
#include "Camera.h"
#include "World.h"
#include <stdio.h>
#include <iostream>
#include "light.h"
#include <fstream>
#include "QFile"
#include "QDomDocument"
using namespace std;

int x;
int y;  //posicion clic abrir menu
int window;
Modelo3D *modelo3D;
World *world;
Camera * camera;
vector <Light> lights;
void onMenu(int opcion) {
    //glutPostRedisplay();
    cout << "OPCION ELEGIDA EN MENU: " << opcion << endl;
    world->changeLights(opcion-5);
}
void creacionMenu(void) {
    int lightsMenu, menuPrincipal;
    int menuOffset = 5;
    lightsMenu = glutCreateMenu(onMenu);
    cout << "NUMERO DE LUCES PARSEADAS: " << lights.size() << endl;
    for (int i=0; i<lights.size(); i++) {
        glutAddMenuEntry((((Light)lights[i]).name).c_str(), menuOffset + i);
    }
    menuPrincipal = glutCreateMenu(onMenu);
    glutAddSubMenu("Menu luces", lightsMenu);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}

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
    if ( (button == GLUT_LEFT_BUTTON) & (state == GLUT_DOWN) ) {
        cout << "x" << x << "y"<< y <<endl;
        //x = x; y = y; //actualiza los valores de x,y
    }
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
    QFile xml ("planetario.json");
    xml.open(QIODevice::ReadOnly);
    QDomDocument *xmlTemporal = new QDomDocument();
    xmlTemporal->setContent(&xml);
    xml.close();
    QDomElement raiz = xmlTemporal->documentElement();
    QDomElement elemento = raiz.firstChild().toElement();
    glScalef(1,1,1);
    GLfloat mat_ambiente[4];// = {0.1,0.1,0.1,1};
    GLfloat mat_diffuse[4];// = {0.99, 0.72, 0.074, 1};
    GLfloat mat_specular[4];// = {0.8, 0.8, 0.8, 1.0};
    while (!elemento.isNull()) {
        if(elemento.tagName() == "lights") {
            QDomElement light = elemento.firstChild().toElement();
            glScalef(1,1,1);
            while (!light.isNull()) {
                if (light.tagName() == "light") {
                    Light *objLight = new Light();
                    objLight->name = light.attribute("name", "noname").toStdString();
                    QDomElement lightComponent = light.firstChildElement(); //load difusa component
                    setVector4(objLight->luzdifusa, lightComponent.attribute("x").toFloat(), lightComponent.attribute("y").toFloat(), lightComponent.attribute("z").toFloat(), lightComponent.attribute("a").toFloat());
                    lightComponent = lightComponent.nextSiblingElement(); //load difusa component
                    setVector4(objLight->luzambiente, lightComponent.attribute("x").toFloat(), lightComponent.attribute("y").toFloat(), lightComponent.attribute("z").toFloat(), lightComponent.attribute("a").toFloat());
                    lightComponent = lightComponent.nextSiblingElement(); //load difusa component
                    setVector4(objLight->luzspecular, lightComponent.attribute("x").toFloat(), lightComponent.attribute("y").toFloat(), lightComponent.attribute("z").toFloat(), lightComponent.attribute("a").toFloat());
                    lightComponent = lightComponent.nextSiblingElement(); //load difusa component
                    setVector4(objLight->posicion0, lightComponent.attribute("x").toFloat(), lightComponent.attribute("y").toFloat(), lightComponent.attribute("z").toFloat(), lightComponent.attribute("a").toFloat());

                    lights.push_back(*objLight);
                }
                light = light.nextSiblingElement();
            }
            world->lights = new Lights(lights);
        }

        if(elemento.tagName() == "planetas") {
            QDomElement planeta = elemento.firstChild().toElement();
            glScalef(1,1,1);
            while (!planeta.isNull()) {
                QString planetName = planeta.attribute("name", "noName");
                float radius = planeta.attribute("radius").toFloat();
                float t = planeta.attribute("t").toFloat();
                string model = planeta.attribute("model").toStdString();
                //string material = planeta.attribute("material").toStdString();
                double sunDistance = planeta.attribute("sunDistance").toDouble();
                char *c = const_cast<char*>(model.c_str());
                cout << planetName.toStdString() << radius << endl;
                /*Start mod*/
                QDomElement material = planeta.firstChildElement();
                if (material.tagName() == "material") {
                    QDomElement materialComponent = material.firstChildElement();
                    if (materialComponent.tagName() == "ambiente") {
                        setVector4(mat_ambiente, materialComponent.attribute("x").toFloat(), materialComponent.attribute("y").toFloat(), materialComponent.attribute("z").toFloat(), materialComponent.attribute("a").toFloat());
                    }
                    materialComponent = materialComponent.nextSiblingElement();
                    if (materialComponent.tagName() == "difuso") {
                        setVector4(mat_diffuse, materialComponent.attribute("x").toFloat(), materialComponent.attribute("y").toFloat(), materialComponent.attribute("z").toFloat(), materialComponent.attribute("a").toFloat());
                    }
                    materialComponent = materialComponent.nextSiblingElement();
                    if (materialComponent.tagName() == "especular") {
                        setVector4(mat_specular, materialComponent.attribute("x").toFloat(), materialComponent.attribute("y").toFloat(), materialComponent.attribute("z").toFloat(), materialComponent.attribute("a").toFloat());
                    }
                }

                /*End mod*/
                QDomElement satelite = material.nextSiblingElement();
                if (!satelite.isNull() && satelite.tagName()== "satelite") {
                    world->loadModels(c, sunDistance, radius, t, mat_ambiente, mat_diffuse, mat_specular);
                    cout << satelite.attribute("name", "").toStdString() << endl;
                    QDomElement materialComponent = satelite.firstChildElement();
                    if (materialComponent.tagName() == "ambiente") {
                        setVector4(mat_ambiente, materialComponent.attribute("x").toFloat(), materialComponent.attribute("y").toFloat(), materialComponent.attribute("z").toFloat(), materialComponent.attribute("a").toFloat());
                    }
                    materialComponent = materialComponent.nextSiblingElement();
                    if (materialComponent.tagName() == "difuso") {
                        setVector4(mat_diffuse, materialComponent.attribute("x").toFloat(), materialComponent.attribute("y").toFloat(), materialComponent.attribute("z").toFloat(), materialComponent.attribute("a").toFloat());
                    }
                    materialComponent = materialComponent.nextSiblingElement();
                    if (materialComponent.tagName() == "especular") {
                        setVector4(mat_specular, materialComponent.attribute("x").toFloat(), materialComponent.attribute("y").toFloat(), materialComponent.attribute("z").toFloat(), materialComponent.attribute("a").toFloat());
                    }
                    world->loadModels(c, sunDistance, radius, t, satelite.attribute("t").toFloat(), mat_ambiente, mat_diffuse, mat_specular);
                }
                else {
                    world->loadModels(c, sunDistance, radius, t, mat_ambiente, mat_diffuse, mat_specular);
                }
                setVector4(mat_ambiente, 0,0,0,0);
                setVector4(mat_diffuse, 0,0,0,0);
                setVector4(mat_specular, 0,0,0,0);
                planeta = planeta.nextSibling().toElement();
            }
        }
        elemento = elemento.nextSibling().toElement();
    }

}

void paso(int t) {
    glutTimerFunc(10, paso, 0);
    world->paso();
    glutPostRedisplay();
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
    //world->lights = new Lights(lights);
    glMatrixMode(GL_MODELVIEW);
    // world->loadModels(argv[1], 0);
   // world->loadModels(argv[1], 100);
     glutDisplayFunc(display);
     glutIdleFunc(display); // pinta cuando no esté haciendo nada
     glutMouseFunc(onMouse);// puntero a la función de eventos de teclado
     glutMotionFunc(onMotion);
     glutKeyboardFunc(keyPressed);
     glutTimerFunc(10, paso, 0);
     creacionMenu();
     glutMainLoop();
	return 0;
}
