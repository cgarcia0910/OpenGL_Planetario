#include "Modelo3D.h"
#include <math.h>
#include <GL/freeglut_ext.h>

using namespace std;
const int MOUSE_SCROLL_UP = 3;
const int MOUSE_SCROLL_DOWN = 4;

void Modelo3D::setVector4(GLfloat *v, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3)
{
    v[0] = v0;
    v[1] = v1;
    v[2] = v2;
    v[3] = v3;
}
Modelo3D::Modelo3D(double sunDistance, char *model, float radius, float w, GLfloat mat_ambiente[4], GLfloat mat_diffuse[4], GLfloat mat_specular[4]) {
    this->sunDistance = sunDistance;
    NFaces = 0;
    NVertex = 0;
    zoom = 0;
    this->radius = radius;
    this->w = w;
    this->satelite = false;
    setVector4(this->mat_ambiente, mat_ambiente[0], mat_ambiente[1], mat_ambiente[2],mat_ambiente[3]);
    setVector4(this->mat_diffuse, mat_diffuse[0], mat_diffuse[1], mat_diffuse[2],mat_diffuse[3]);
    setVector4(this->mat_specular, mat_specular[0], mat_specular[1], mat_specular[2],mat_specular[3]);
    Load_Model(model);
}
Modelo3D::Modelo3D(double planetDistance, char *model, float radius, float wParent, float w, GLfloat mat_ambiente[4], GLfloat mat_diffuse[4], GLfloat mat_specular[4]) {
    this->sunDistance = planetDistance;
    NFaces = 0;
    NVertex = 0;
    zoom = 0;
    this->radius = radius;
    this->w = w;
    this->wParent = wParent;
    this->satelite = true;
    setVector4(this->mat_ambiente, mat_ambiente[0], mat_ambiente[1], mat_ambiente[2],mat_ambiente[3]);
    setVector4(this->mat_diffuse, mat_diffuse[0], mat_diffuse[1], mat_diffuse[2],mat_diffuse[3]);
    setVector4(this->mat_specular, mat_specular[0], mat_specular[1], mat_specular[2],mat_specular[3]);
    Load_Model(model);
}

Modelo3D::Modelo3D() {
	NFaces = 0;
	NVertex = 0;
    zoom = 0;
}
int Modelo3D::getCaras() {
	return NFaces;
}
int Modelo3D::getVertices() {
	return NVertex;
}
void Modelo3D::setCaras(int NFaces) {
	this->NFaces = NFaces;
}
void Modelo3D::setVertices(int NVertex) {
	this->NVertex = NVertex;
}
void Modelo3D::zoomIn() {
	zoom++;
}
void Modelo3D::zoomOut() {
	if(zoom >= -10) zoom--;
}

void Modelo3D::onMouse(int button, int state, int x, int y)
{
	if( button == MOUSE_SCROLL_UP )
		zoomIn();
	if( button == MOUSE_SCROLL_DOWN )
		zoomOut();
}

// Model Loader from file in ASC format
bool Modelo3D::Load_Model(char *nombre) {

	FILE *fich;
	int NVertex, NFaces, VertexNumber, FaceNumber, N, A, B, C;
	float X, Y, Z, ax, ay, az, bx, by, bz, len;
	TNormal Normal;

	char cad1[20], cad2[20], cad3[20], cad4[20],cad5[20];
	char cadena[100]; // Lo suf. larga para leer una línea

	if ((fich = fopen(nombre, "r")) == NULL) // open for reading  // open for reading
	{
		cout << " Error en la apertura. Es posible que el fichero no exista \n "
				<< endl;
		exit(1);
	}
	cout << "Opened File....." << endl;
	while (fgets(cadena, 100, fich) != NULL) {
		if (strncmp(cadena, "Named", 5) == 0) // Nvertex and NFaces in file
		{
			fscanf(fich, "%[Tri-mesh A-Za-z:-,: ]%d%[ ]%[Faces]:%d\n", cad1,
					&NVertex, cad2, cad3, &NFaces);
			this->setCaras(NFaces);
			this->setVertices(NVertex);
		}
		ListaCaras.resize(getCaras());
		ListaPuntos3D.resize(getVertices());
		if (strncmp(cadena, "Vertex list:", 12) == 0) // Vertex List in file
			for (N = 1; N <= NVertex; N++) {
				fscanf(fich, "%[A-Za-z ]%d: %[X:] %f %[Y:] %f %[Z:] %f    \n",
						cad1, &VertexNumber, cad2, &X, cad3, &Y, cad4, &Z);
				ListaPuntos3D[VertexNumber].setX(X);
				ListaPuntos3D[VertexNumber].setY(Y);
				ListaPuntos3D[VertexNumber].setZ(Z);
			}
		if (strncmp(cadena, "Face list:", 10) == 0) { // Face List in model file

			for (N = 0; N < NFaces; N++) {
				fgets(cadena, 100, fich);
				if (strncmp(cadena, "Face", 4) == 0) {
					sscanf(cadena,
							"%[Face]%d: %[A:]%d %[B:]%d %[C:]%d %[^\n]%*c",cad1, &FaceNumber, cad2, &A, cad3, &B, cad4, &C,cad5);
					// Cálculo del vector normal a cada cara (Nx,Ny,Nz)........NEW¡¡¡¡
					ListaCaras[FaceNumber] = Cara(A, B, C, Normal);
					ax =
							ListaPuntos3D[ListaCaras[FaceNumber].getA()].getX()
									- ListaPuntos3D[ListaCaras[FaceNumber].getB()].getX(); //  X[A] - X[B];
					ay =
							ListaPuntos3D[ListaCaras[FaceNumber].getA()].getY()
									- ListaPuntos3D[ListaCaras[FaceNumber].getB()].getY(); //  Y[A] - Y[B];
					az =
							ListaPuntos3D[ListaCaras[FaceNumber].getA()].getZ()
									- ListaPuntos3D[ListaCaras[FaceNumber].getB()].getZ(); //  Z[A] - Z[B];
					bx =
							ListaPuntos3D[ListaCaras[FaceNumber].getB()].getX()
									- ListaPuntos3D[ListaCaras[FaceNumber].getC()].getX(); //  X[B] - X[C];
					by =
							ListaPuntos3D[ListaCaras[FaceNumber].getB()].getY()
									- ListaPuntos3D[ListaCaras[FaceNumber].getC()].getY(); //  Y[B] - Y[C];
					bz =
							ListaPuntos3D[ListaCaras[FaceNumber].getB()].getZ()
									- ListaPuntos3D[ListaCaras[FaceNumber].getC()].getZ(); //  Z[B] - Z[C];
					Normal.x = (ay * bz) - (az * by);
					Normal.y = (az * bx) - (ax * bz);
					Normal.z = (ax * by) - (ay * bx);
					len = sqrt(
							(Normal.x * Normal.x) + (Normal.y * Normal.y)
									+ (Normal.z * Normal.z));
					Normal.x = Normal.x / len;
					Normal.y = Normal.y / len;
                    Normal.z = Normal.z / len;
					ListaCaras[FaceNumber] = Cara(A, B, C, Normal);
				} else {
					N--;
				}

			}
			}
	}
	fclose(fich);

}
void Modelo3D::InitGL(float Width,float Height)
{
    glDepthMask(GL_TRUE);
    glDepthFunc(GL_LESS);
}
void Modelo3D::drawCircle()
{
    glDisable(GL_LIGHTING);
    glBegin(GL_POINTS);
    for(float i = 0.0; i < 10; i+=0.0001)
    {
        float theta = 2.0f * 3.1415926f * i;
        float x = sunDistance * cosf(theta);
        float z = sunDistance * sinf(theta);

        glVertex3f(x ,z, 0);
    }
    glEnd();
    glEnable(GL_LIGHTING);
}
void Modelo3D::DrawGLScene(look_type look, float t) {
    drawCircle();
    glColor3f(0.5f,0.8f,1.0f);
    /*
    mat_ambiente = {0.1,0.1,0.1,1};
    mat_diffuse = {0.99, 0.72, 0.074, 1};
    mat_specular = {0.8, 0.8, 0.8, 1.0};*/
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambiente);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glPushMatrix();
    glMatrixMode(GL_MODELVIEW);
    if(!this->satelite)
        glTranslatef(sunDistance*cos(w*t), sunDistance*sin(w*t), 0);
    if(this->satelite) {
        glTranslatef((sunDistance)*cos(wParent*t), (sunDistance)*sin(wParent*t), 0);
        glTranslatef(50*cos(w*t), 50*sin(w*t), 0);
    }
    glScalef(radius,radius,radius);
    switch (look) {
        case WIRE:
            glDisable(GL_LIGHTING);
            glBegin(GL_LINES);
            for (int i = 0; i < getCaras(); i++) {
                glVertex3f(
                        ListaPuntos3D[ListaCaras[i].getA()].getX(),
                        ListaPuntos3D[ListaCaras[i].getA()].getY(),
                        ListaPuntos3D[ListaCaras[i].getA()].getZ());
                glVertex3f(
                        ListaPuntos3D[ListaCaras[i].getB()].getX(),
                        ListaPuntos3D[ListaCaras[i].getB()].getY(),
                        ListaPuntos3D[ListaCaras[i].getB()].getZ());
                glVertex3f(
                        ListaPuntos3D[ListaCaras[i].getC()].getX(),
                        ListaPuntos3D[ListaCaras[i].getC()].getY(),
                        ListaPuntos3D[ListaCaras[i].getC()].getZ());
                glVertex3f(
                        ListaPuntos3D[ListaCaras[i].getA()].getX(),
                        ListaPuntos3D[ListaCaras[i].getA()].getY(),
                        ListaPuntos3D[ListaCaras[i].getA()].getZ());
            }
            glEnd();
            glEnable(GL_LIGHTING);
            break;
        case SOLID:
            glDisable(GL_LIGHTING);
            glBegin(GL_POLYGON);
            for (int i = 0; i < getCaras(); i++) {
                glVertex3f(
                        ListaPuntos3D[ListaCaras[i].getA()].getX(),
                        ListaPuntos3D[ListaCaras[i].getA()].getY(),
                        ListaPuntos3D[ListaCaras[i].getA()].getZ());
                glVertex3f(
                        ListaPuntos3D[ListaCaras[i].getB()].getX(),
                        ListaPuntos3D[ListaCaras[i].getB()].getY(),
                        ListaPuntos3D[ListaCaras[i].getB()].getZ());
                glVertex3f(
                        ListaPuntos3D[ListaCaras[i].getC()].getX(),
                        ListaPuntos3D[ListaCaras[i].getC()].getY(),
                        ListaPuntos3D[ListaCaras[i].getC()].getZ());
            }
            glEnd();
            glEnable(GL_LIGHTING);
            break;
            case FLAT:                
                glEnable(GL_LIGHTING);
                glShadeModel(GL_FLAT);
                glBegin(GL_TRIANGLES);
                for (int i = 0; i < getCaras(); i++) {

                    glNormal3f(ListaCaras[i].getNormal().x,
                               ListaCaras[i].getNormal().y,
                               ListaCaras[i].getNormal().z);

                    glVertex3f(
                            ListaPuntos3D[ListaCaras[i].getA()].getX(),
                            ListaPuntos3D[ListaCaras[i].getA()].getY(),
                            ListaPuntos3D[ListaCaras[i].getA()].getZ());
                    glVertex3f(
                            ListaPuntos3D[ListaCaras[i].getB()].getX(),
                            ListaPuntos3D[ListaCaras[i].getB()].getY(),
                            ListaPuntos3D[ListaCaras[i].getB()].getZ());
                    glVertex3f(
                            ListaPuntos3D[ListaCaras[i].getC()].getX(),
                            ListaPuntos3D[ListaCaras[i].getC()].getY(),
                            ListaPuntos3D[ListaCaras[i].getC()].getZ());
                 }
                 glEnd();
                 break;
            case SMOOTH:
                glEnable(GL_LIGHTING);
                glShadeModel(GL_SMOOTH);
                glBegin(GL_TRIANGLES);
                for (int i = 0; i < getCaras(); i++) {
                    glNormal3f(ListaPuntos3D[ListaCaras[i].getA()].getX(),
                               ListaPuntos3D[ListaCaras[i].getA()].getY(),
                               ListaPuntos3D[ListaCaras[i].getA()].getZ());
                    glVertex3f(
                            ListaPuntos3D[ListaCaras[i].getA()].getX(),
                            ListaPuntos3D[ListaCaras[i].getA()].getY(),
                            ListaPuntos3D[ListaCaras[i].getA()].getZ());
                    glNormal3f(ListaPuntos3D[ListaCaras[i].getB()].getX(),
                               ListaPuntos3D[ListaCaras[i].getB()].getY(),
                               ListaPuntos3D[ListaCaras[i].getB()].getZ());
                    glVertex3f(
                            ListaPuntos3D[ListaCaras[i].getB()].getX(),
                            ListaPuntos3D[ListaCaras[i].getB()].getY(),
                            ListaPuntos3D[ListaCaras[i].getB()].getZ());
                    glNormal3f(ListaPuntos3D[ListaCaras[i].getC()].getX(),
                               ListaPuntos3D[ListaCaras[i].getC()].getY(),
                               ListaPuntos3D[ListaCaras[i].getC()].getZ());

                    glVertex3f(
                            ListaPuntos3D[ListaCaras[i].getC()].getX(),
                            ListaPuntos3D[ListaCaras[i].getC()].getY(),
                            ListaPuntos3D[ListaCaras[i].getC()].getZ());
                }
                glEnd();
                break;
    }

    glPopMatrix();
    /**************************************************************/


}
