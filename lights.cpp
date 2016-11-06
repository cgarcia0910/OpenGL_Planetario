#include "lights.h"

Lights::Lights()
{
    glEnable(GL_LIGHTING);
}

Lights::Lights(vector<Light> &lights) {
    this->lights = &lights;
    cout << ((Light)((*this->lights)[1])).luzambiente[0] << ((Light)((*this->lights)[1])).luzambiente[1] << ((Light)((*this->lights)[1])).luzambiente[2] << ((Light)((*this->lights)[1])).luzambiente[3];
}
void Lights::switchLight(int id) {
    //cout << "luz encendida" << endl;
    /*
    setVector4(luzdifusa, 1.0, 0.1, 0.1, 1.0);
    setVector4(luzambiente, 0.50, 0.50, 0.50, 1.0);
    setVector4(luzspecular, 0.20, 0.20, 0.20, 1.0);
    setVector4(posicion0, 100, 100, -100, 1.0);
    */
    switch (id) {
        case 0:
        setVector4(luzambiente, ((Light)((*this->lights)[0])).luzambiente[0], ((Light)((*this->lights)[0])).luzambiente[1], ((Light)((*this->lights)[0])).luzambiente[2], ((Light)((*this->lights)[0])).luzambiente[3]);
        setVector4(luzdifusa, ((Light)((*this->lights)[0])).luzdifusa[0], ((Light)((*this->lights)[0])).luzdifusa[1], ((Light)((*this->lights)[0])).luzdifusa[2], ((Light)((*this->lights)[0])).luzdifusa[3]);
        setVector4(luzspecular, ((Light)((*this->lights)[0])).luzspecular[0], ((Light)((*this->lights)[0])).luzspecular[1], ((Light)((*this->lights)[0])).luzspecular[2], ((Light)((*this->lights)[0])).luzspecular[3]);
        setVector4(posicion0, ((Light)((*this->lights)[0])).posicion0[0], ((Light)((*this->lights)[0])).posicion0[1], ((Light)((*this->lights)[0])).posicion0[2], ((Light)((*this->lights)[0])).posicion0[3]);
        glLightfv(GL_LIGHT0, GL_DIFFUSE, luzdifusa);
        glLightfv(GL_LIGHT0, GL_AMBIENT, luzambiente);
        glLightfv(GL_LIGHT0, GL_SPECULAR, luzspecular);
        glLightfv(GL_LIGHT0, GL_POSITION, posicion0);
        glEnable(GL_LIGHT0);
        //cout << lights[0]
        //Light luz = (Light)(this->lights[0]);
        //Light luz = (Light)this->lights[0];
        //cout << "PRUEBA" << ((Light)(this->lights[0])).name << endl;
        //setVector4(this->luzdifusa, ((Light)this->lights[0]).luzambiente[0], ((Light)this->lights[0]).luzambiente[1], ((Light)this->lights[0]).luzambiente[2], ((Light)this->lights[0]).luzambiente[3]);
        //this->luzdifusa = ((Light)*this->lights[0]).luzambiente;
        //glLightfv(GL_LIGHT0, GL_DIFFUSE, ((Light)this->lights[id]).((Light)((*this->lights)[0])));
        //glLightfv(GL_LIGHT0, GL_AMBIENT, ((Light)this->lights[id]).((Light)((*this->lights)[0])).luzambiente);
        //glLightfv(GL_LIGHT0, GL_SPECULAR, ((Light)this->lights[id]).luzdifusa);
        //glLightfv(GL_LIGHT0, GL_POSITION, ((Light)this->lights[id]).luzdifusa);
        //glEnable(GL_LIGHT0);
            /*
            glLightfv(GL_LIGHT0, GL_DIFFUSE, ((Light)this->lights[id]).luzambiente);
            glLightfv(GL_LIGHT0, GL_AMBIENT, ((Light)this->lights[id]).luzdifusa);
            glLightfv(GL_LIGHT0, GL_SPECULAR, ((Light)this->lights[id]).luzdifusa);
            glLightfv(GL_LIGHT0, GL_POSITION, ((Light)this->lights[id]).luzdifusa);
            glEnable(GL_LIGHT0);*/
        break;
    case 1:
        cout << ((Light)((*this->lights)[1])).luzambiente[0] << ((Light)((*this->lights)[1])).luzambiente[1] << ((Light)((*this->lights)[1])).luzambiente[2] << ((Light)((*this->lights)[1])).luzambiente[3] << endl;
        cout << ((Light)((*this->lights)[0])).luzambiente[0] << ((Light)((*this->lights)[0])).luzambiente[1] << ((Light)((*this->lights)[0])).luzambiente[2] << ((Light)((*this->lights)[0])).luzambiente[3] << endl;
        cout << "entra en case 1" << endl;
        setVector4(luzambiente, ((Light)((*this->lights)[1])).luzambiente[0], ((Light)((*this->lights)[1])).luzambiente[1], ((Light)((*this->lights)[1])).luzambiente[2], ((Light)((*this->lights)[1])).luzambiente[3]);
        setVector4(luzdifusa, ((Light)((*this->lights)[1])).luzdifusa[0], ((Light)((*this->lights)[1])).luzdifusa[1], ((Light)((*this->lights)[1])).luzdifusa[2], ((Light)((*this->lights)[1])).luzdifusa[3]);
        setVector4(luzspecular, ((Light)((*this->lights)[1])).luzspecular[0], ((Light)((*this->lights)[1])).luzspecular[1], ((Light)((*this->lights)[1])).luzspecular[2], ((Light)((*this->lights)[1])).luzspecular[3]);
        setVector4(posicion0, ((Light)((*this->lights)[1])).posicion0[0], ((Light)((*this->lights)[1])).posicion0[1], ((Light)((*this->lights)[1])).posicion0[2], ((Light)((*this->lights)[1])).posicion0[3]);
        glLightfv(GL_LIGHT1, GL_DIFFUSE, luzdifusa);
        glLightfv(GL_LIGHT1, GL_AMBIENT, luzambiente);
        glLightfv(GL_LIGHT1, GL_SPECULAR, luzspecular);
        glLightfv(GL_LIGHT1, GL_POSITION, posicion0);
        glEnable(GL_LIGHT1);
    break;
    case 2:
        setVector4(luzambiente, ((Light)((*this->lights)[2])).luzambiente[0], ((Light)((*this->lights)[2])).luzambiente[1], ((Light)((*this->lights)[2])).luzambiente[2], ((Light)((*this->lights)[2])).luzambiente[3]);
        setVector4(luzdifusa, ((Light)((*this->lights)[2])).luzdifusa[0], ((Light)((*this->lights)[2])).luzdifusa[1], ((Light)((*this->lights)[2])).luzdifusa[2], ((Light)((*this->lights)[2])).luzdifusa[3]);
        setVector4(luzspecular, ((Light)((*this->lights)[2])).luzspecular[0], ((Light)((*this->lights)[2])).luzspecular[1], ((Light)((*this->lights)[2])).luzspecular[2], ((Light)((*this->lights)[2])).luzspecular[3]);
        setVector4(posicion0, ((Light)((*this->lights)[2])).posicion0[0], ((Light)((*this->lights)[2])).posicion0[1], ((Light)((*this->lights)[2])).posicion0[2], ((Light)((*this->lights)[2])).posicion0[3]);
        glLightfv(GL_LIGHT2, GL_DIFFUSE, luzdifusa);
        glLightfv(GL_LIGHT2, GL_AMBIENT, luzambiente);
        glLightfv(GL_LIGHT2, GL_SPECULAR, luzspecular);
        glLightfv(GL_LIGHT2, GL_POSITION, posicion0);
        glEnable(GL_LIGHT2);
    break;
    case 3:
        setVector4(luzambiente, ((Light)((*this->lights)[3])).luzambiente[0], ((Light)((*this->lights)[3])).luzambiente[1], ((Light)((*this->lights)[3])).luzambiente[2], ((Light)((*this->lights)[3])).luzambiente[3]);
        setVector4(luzdifusa, ((Light)((*this->lights)[3])).luzdifusa[0], ((Light)((*this->lights)[3])).luzdifusa[1], ((Light)((*this->lights)[3])).luzdifusa[2], ((Light)((*this->lights)[3])).luzdifusa[3]);
        setVector4(luzspecular, ((Light)((*this->lights)[3])).luzspecular[0], ((Light)((*this->lights)[3])).luzspecular[1], ((Light)((*this->lights)[3])).luzspecular[2], ((Light)((*this->lights)[3])).luzspecular[3]);
        setVector4(posicion0, ((Light)((*this->lights)[3])).posicion0[0], ((Light)((*this->lights)[3])).posicion0[1], ((Light)((*this->lights)[3])).posicion0[2], ((Light)((*this->lights)[3])).posicion0[3]);
        glLightfv(GL_LIGHT3, GL_DIFFUSE, luzdifusa);
        glLightfv(GL_LIGHT3, GL_AMBIENT, luzambiente);
        glLightfv(GL_LIGHT3, GL_SPECULAR, luzspecular);
        glLightfv(GL_LIGHT3, GL_POSITION, posicion0);
        glEnable(GL_LIGHT3);
    break;
    case 4:
        setVector4(luzambiente, ((Light)((*this->lights)[4])).luzambiente[0], ((Light)((*this->lights)[4])).luzambiente[1], ((Light)((*this->lights)[4])).luzambiente[2], ((Light)((*this->lights)[4])).luzambiente[3]);
        setVector4(luzdifusa, ((Light)((*this->lights)[4])).luzdifusa[0], ((Light)((*this->lights)[4])).luzdifusa[1], ((Light)((*this->lights)[4])).luzdifusa[2], ((Light)((*this->lights)[4])).luzdifusa[3]);
        setVector4(luzspecular, ((Light)((*this->lights)[4])).luzspecular[0], ((Light)((*this->lights)[4])).luzspecular[1], ((Light)((*this->lights)[4])).luzspecular[2], ((Light)((*this->lights)[4])).luzspecular[3]);
        setVector4(posicion0, ((Light)((*this->lights)[4])).posicion0[0], ((Light)((*this->lights)[4])).posicion0[1], ((Light)((*this->lights)[4])).posicion0[2], ((Light)((*this->lights)[4])).posicion0[3]);
        glLightfv(GL_LIGHT4, GL_DIFFUSE, luzdifusa);
        glLightfv(GL_LIGHT4, GL_AMBIENT, luzambiente);
        glLightfv(GL_LIGHT4, GL_SPECULAR, luzspecular);
        glLightfv(GL_LIGHT4, GL_POSITION, posicion0);
        glEnable(GL_LIGHT4);
    break;
    case 5:
        setVector4(luzambiente, ((Light)((*this->lights)[5])).luzambiente[0], ((Light)((*this->lights)[5])).luzambiente[1], ((Light)((*this->lights)[5])).luzambiente[2], ((Light)((*this->lights)[5])).luzambiente[3]);
        setVector4(luzdifusa, ((Light)((*this->lights)[5])).luzdifusa[0], ((Light)((*this->lights)[5])).luzdifusa[1], ((Light)((*this->lights)[5])).luzdifusa[2], ((Light)((*this->lights)[5])).luzdifusa[3]);
        setVector4(luzspecular, ((Light)((*this->lights)[5])).luzspecular[0], ((Light)((*this->lights)[5])).luzspecular[1], ((Light)((*this->lights)[5])).luzspecular[2], ((Light)((*this->lights)[5])).luzspecular[3]);
        setVector4(posicion0, ((Light)((*this->lights)[5])).posicion0[0], ((Light)((*this->lights)[5])).posicion0[1], ((Light)((*this->lights)[5])).posicion0[2], ((Light)((*this->lights)[5])).posicion0[3]);
        glLightfv(GL_LIGHT5, GL_DIFFUSE, luzdifusa);
        glLightfv(GL_LIGHT5, GL_AMBIENT, luzambiente);
        glLightfv(GL_LIGHT5, GL_SPECULAR, luzspecular);
        glLightfv(GL_LIGHT5, GL_POSITION, posicion0);
        glEnable(GL_LIGHT5);
    break;
    case 6:
        setVector4(luzambiente, ((Light)((*this->lights)[6])).luzambiente[0], ((Light)((*this->lights)[6])).luzambiente[1], ((Light)((*this->lights)[6])).luzambiente[2], ((Light)((*this->lights)[6])).luzambiente[3]);
        setVector4(luzdifusa, ((Light)((*this->lights)[6])).luzdifusa[0], ((Light)((*this->lights)[6])).luzdifusa[1], ((Light)((*this->lights)[6])).luzdifusa[2], ((Light)((*this->lights)[6])).luzdifusa[3]);
        setVector4(luzspecular, ((Light)((*this->lights)[6])).luzspecular[0], ((Light)((*this->lights)[6])).luzspecular[1], ((Light)((*this->lights)[6])).luzspecular[2], ((Light)((*this->lights)[6])).luzspecular[3]);
        setVector4(posicion0, ((Light)((*this->lights)[6])).posicion0[0], ((Light)((*this->lights)[6])).posicion0[1], ((Light)((*this->lights)[6])).posicion0[2], ((Light)((*this->lights)[6])).posicion0[3]);
        glLightfv(GL_LIGHT6, GL_DIFFUSE, luzdifusa);
        glLightfv(GL_LIGHT6, GL_AMBIENT, luzambiente);
        glLightfv(GL_LIGHT6, GL_SPECULAR, luzspecular);
        glLightfv(GL_LIGHT6, GL_POSITION, posicion0);
        glEnable(GL_LIGHT6);
    break;
    case 7:
        setVector4(luzambiente, ((Light)((*this->lights)[7])).luzambiente[0], ((Light)((*this->lights)[7])).luzambiente[1], ((Light)((*this->lights)[7])).luzambiente[2], ((Light)((*this->lights)[7])).luzambiente[3]);
        setVector4(luzdifusa, ((Light)((*this->lights)[7])).luzdifusa[0], ((Light)((*this->lights)[7])).luzdifusa[1], ((Light)((*this->lights)[7])).luzdifusa[2], ((Light)((*this->lights)[7])).luzdifusa[3]);
        setVector4(luzspecular, ((Light)((*this->lights)[7])).luzspecular[0], ((Light)((*this->lights)[7])).luzspecular[1], ((Light)((*this->lights)[7])).luzspecular[2], ((Light)((*this->lights)[7])).luzspecular[3]);
        setVector4(posicion0, ((Light)((*this->lights)[7])).posicion0[0], ((Light)((*this->lights)[7])).posicion0[1], ((Light)((*this->lights)[7])).posicion0[2], ((Light)((*this->lights)[7])).posicion0[3]);
        glLightfv(GL_LIGHT7, GL_DIFFUSE, luzdifusa);
        glLightfv(GL_LIGHT7, GL_AMBIENT, luzambiente);
        glLightfv(GL_LIGHT7, GL_SPECULAR, luzspecular);
        glLightfv(GL_LIGHT7, GL_POSITION, posicion0);
        glEnable(GL_LIGHT7);
    break;
}
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
