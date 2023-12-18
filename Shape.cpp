#include <GL/glut.h>
#include <vector>
#include "Vector3D.h"
#include "Shape.h"
#include "World3D.h"
#include <iostream>

void Shape::drawTriangle(World3D world, const std::vector<Vector3D>& listpoint,float color[])
{
    if (listpoint.size() != 4)
    {
        std::cout << "it not quadtri";
        return;
    }
    glColor3fv(color);
    std::vector<Vector3D> s = world.triangleTo2D(listpoint, world.cam);
    glBegin(GL_TRIANGLES);
    for (int i = 0; i < s.size(); i++)
    {
        glVertex2i(s[i].z, s[i].y);
    }
    glEnd();
}
void Shape::drawQuadtri(World3D world, const std::vector<Vector3D>& listpoint, float color[])
{
    if (listpoint.size() != 4)
    {
        std::cout << "it not quadtri";
        return;
    }
    glColor3fv(color);
    std::vector<Vector3D> s = world.polygonTo2D(listpoint, world.cam);
    glBegin(GL_QUADS);
    for (int i = 0; i < s.size(); i++)
    {
        glVertex2i(s[i].z, s[i].y);
    }
    glEnd();
}
void Shape::drawPolygon(World3D world, const std::vector<Vector3D>& listpoint, float color[])
{
    if (listpoint.size() < 3)
    {
        std::cout << "Invalid polygon!";
        return;
    }

    glColor3fv(color);
    std::vector<Vector3D> s = world.polygonTo2D(listpoint, world.cam);

    glBegin(GL_POLYGON);
    for (int i = 0; i < s.size(); i++)
    {
        glVertex2i(s[i].z, s[i].y);
    }
    glEnd();
}

void Shape::drawCube(World3D world, const std::vector<Vector3D>& listpoint)
{
    float red[3] = { 1.0, 0.0, 0.0 };
    float green[3] = { 0.0, 1.0, 0.0 };
    float blue[3] = { 0.0, 0.0, 1.0 };
    float yellow[3] = { 1.0, 1.0, 0.0 };
    float purple[3] = { 1.0, 0.0, 1.0 };
    float orange[3] = { 1.0, 0.5, 0.0 };
    
    std::vector<Vector3D> point;
    //back
    for (int i = 4; i < 8; i++) { point.push_back(listpoint[i]); }
    drawQuadtri(world, point, green);
    point.clear();

    //left
    point.push_back(listpoint[3]);
    point.push_back(listpoint[5]);
    point.push_back(listpoint[6]);
    point.push_back(listpoint[0]);
    drawQuadtri(world, point, purple);
    point.clear();

    //bottom
    point.push_back(listpoint[2]);
    point.push_back(listpoint[4]);
    point.push_back(listpoint[5]);
    point.push_back(listpoint[3]);
    drawQuadtri(world, point, yellow);
    point.clear();

    //right
    point.push_back(listpoint[2]);
    point.push_back(listpoint[4]);
    point.push_back(listpoint[7]);
    point.push_back(listpoint[1]);
    drawQuadtri(world, point, blue);
    point.clear();

    // front
 
    for (int i = 0; i < 4; i++) { point.push_back(listpoint[i]); }
    drawQuadtri(world, point, red);
    point.clear();
}

