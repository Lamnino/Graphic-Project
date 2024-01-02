
#include <iostream>
#include <cmath>
#include "Vector3D.h"
#include "Camera.h"
#include "World3D.h"
#include <GL/glut.h>
#include "Shape.h"
#include <string>

using namespace std;

int WINDOW_WIDTH = 600;
const int WINDOW_HEIGHT = 400;
// Hàm vẽ tam giác


// Hàm hiển thị
void display()
{
    // Init camera inform
    Vector3D PosCam(-3, 3, 3);
    Vector3D TarCam(0.0, 0.0, 0.0);

    std::vector<Vector3D> listpoint1;
    std::vector<Vector3D> listpoint2;

    Vector3D A(-1, 1, -1);
    Vector3D B(-1, 1, 1);
    Vector3D C(-1, -1, 1);
    Vector3D D(-1,-1, -1);
    Vector3D E(1, -1, -1);
    Vector3D F(1, -1, 1);
    Vector3D G(1, 1, 1);
    Vector3D H(1, 1, -1);

    listpoint1.push_back(A);
    listpoint1.push_back(B);
    listpoint1.push_back(C);
    listpoint1.push_back(D);
    listpoint1.push_back(E);
    listpoint1.push_back(F);
    listpoint1.push_back(G);
    listpoint1.push_back(H);

    // Init 3d World
    World3D world(PosCam, TarCam);

    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0); 
    glLoadIdentity();

    glPointSize(1.0); 
    float red[3] = { 1.0, 0.0, 0.0 };
    float blue[3] = { 0.0, 0.0, 1.0 };
    Shape::drawCube(world, listpoint1);

    glFlush();
    glEnd();
    glutSwapBuffers();
}

void reshape(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-300, 300, -200, 200);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    glutCreateWindow("Z-buffer - cube");

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    glutMainLoop();

    return 0;
}
