#include <GL/glut.h>
#include <vector>
#include "Vector3D.h"
#include "Shape.h"
#include "World3D.h"
#include <iostream>
#include <algorithm>

void sortVector(std::vector<Vector3D>& listpoint)
{
    for (int i = 0; i < listpoint.size()-1; i++) {
        for (int j = i + 1; j < listpoint.size(); j++) {
            if (listpoint[i].x > listpoint[j].x) {
                std::swap(listpoint[i], listpoint[j]);
            }
            
        }
    }
}
float dept(int locaction, float deptstart, float deptend, float locateStart, float locateEnd)
{
    int distance = std::abs(locateEnd- locateStart);
    return deptstart + ((locaction-locateStart)) * (deptend - deptstart) / distance;
}
bool isInsidePolygon(const std::vector<Vector3D>& polygon, int x, int y) {
    int numVertices = polygon.size();
    int i, j = numVertices - 1;
    bool inside = false;

    for (i = 0; i < numVertices; i++) {
        if ((polygon[i].y < y && polygon[j].y >= y) || (polygon[j].y < y && polygon[i].y >= y)) {
            if (polygon[i].x + (y - polygon[i].y) / (polygon[j].y - polygon[i].y) * (polygon[j].x - polygon[i].x) < x) {
                inside = !inside;
            }
        }
        j = i;
    }

    return inside;
}
void Shape::drawTriangle(World3D& world, const std::vector<Vector3D>& listpoint, float color[])
{
    std::vector<Vector3D> sortedPoints = world.triangleTo2D(listpoint, world.cam);
    sortVector(sortedPoints);
    const Vector3D& p1 = sortedPoints[0];
    const Vector3D& p2 = sortedPoints[1];
    const Vector3D& p3 = sortedPoints[2];
    float black[3] = { 0,0,0 };
        float startY = 0, endY = 0;
        float heigthhaft = world.cam.heigth / 2;
        float widthhaft = world.cam.width / 2;
        if (p1.x != p2.x)
        {
            for (int x = p1.x; x <= p2.x; x++)
            {
                if (x > -heigthhaft && x < heigthhaft)
                {
                    startY = (x - p1.x) * ((p1.y - p2.y) / (p1.x - p2.x)) + p1.y;
                    endY = (x - p1.x) * ((p1.y - p3.y) / (p1.x - p3.x)) + p1.y;
                    float deptStart = dept(x, p1.z, p2.z, float(p1.x), float(p2.x));
                    float deptEnd = dept(x, p1.z, p3.z,float(p1.x), float(p3.x));
                    if (startY > endY)
                    { 
                        float t = startY; startY = endY; endY = t; 
                        t = deptStart; deptStart = deptEnd; deptEnd = t;
                    }
                    //std::cout << deptStart << "," << deptEnd << ";";
                    for (int y = static_cast<int>(startY); y <= static_cast<int>(endY); y++)
                    {
                        if (y > -widthhaft && y < widthhaft)
                        {
                            float deptt = dept(y, deptStart, deptStart, float(startY), float(endY));
                            //if (world.cam.screen[x + world.cam.heigth / 2][y + world.cam.width / 2].dept <1000)
                            
                            if (deptt < world.cam.screen[x + heigthhaft][y + world.cam.width / 2].dept)
            
                            {
                                //std::cout << world.cam.screen[x + world.cam.heigth / 2][y + world.cam.width / 2].dept<<","<< deptt<<";";
                                world.cam.screen[x + heigthhaft][y + widthhaft] = Pixel(deptt, color);
                                //std::cout << world.cam.screen[x + world.cam.heigth / 2][y + world.cam.width / 2].dept << ";";
                                world.cam.screen[x + heigthhaft][y + widthhaft].DrawPixel(x, y);
                            }
                        }
                    }
                }
            }
        }
        if (p2.x != p3.x)
        {
            for (int x = p2.x+1; x <= p3.x; x++)
            {
                startY = (x - p2.x) * ((p2.y - p3.y) / (p2.x - p3.x)) + p2.y;
                endY = (x - p1.x) * ((p1.y - p3.y) / (p1.x - p3.x)) + p1.y; 
                float deptStart = dept(x, p2.z, p3.z, float(p2.x), float(p3.x));
                float deptEnd = dept(x, p1.z, p3.z, float(p1.x), float(p3.x));
                if (startY > endY) 
                { 
                    float t = startY; startY = endY; endY = t; 
                    t = deptStart; deptStart = deptEnd; deptEnd = t;
                }
                for (int y = static_cast<int>(startY); y <= static_cast<int>(endY); y++)
                {
                    if (x > -300 && x<300 && y>-200 && y < 200)
                    {
                        float deptt = dept(y, deptStart, deptStart, float(startY), float(endY));
                        if (deptt < world.cam.screen[x + heigthhaft][y + widthhaft].dept)
                        {
                            world.cam.screen[x + heigthhaft][y + widthhaft] = Pixel(deptt, color);
                            world.cam.screen[x + heigthhaft][y + widthhaft].DrawPixel(x, y);
                        }
                    }
                }
            }
        }
        
}
void Shape::drawPolygon(World3D &world, const std::vector<Vector3D>& listpoint, float color[])
{    
    for (int i = 1; i < listpoint.size() - 1; i++)
    {
        std::vector<Vector3D> listpointt;
        listpointt.push_back(listpoint[0]);
        listpointt.push_back(listpoint[i]);
        listpointt.push_back(listpoint[i + 1]);
        drawTriangle(world, listpointt, color);
    }
}

void Shape::drawCube(World3D &world, const std::vector<Vector3D>& listpoint)
{
    float red[3] = { 1.0, 0.0, 0.0 };
    float green[3] = { 0.0, 1.0, 0.0 };
    float blue[3] = { 0.0, 0.0, 1.0 };
    float yellow[3] = { 1.0, 1.0, 0.0 };
    float purple[3] = { 1.0, 0.0, 1.0 };
    float orange[3] = { 1.0, 0.5, 0.0 };
    std::vector<Vector3D> point;

    // front

    for (int i = 0; i < 4; i++) { point.push_back(listpoint[i]); }
    drawPolygon(world, point, red);
    point.clear();

   

    //right
    point.push_back(listpoint[2]);
    point.push_back(listpoint[5]);
    point.push_back(listpoint[6]);
    point.push_back(listpoint[1]);
    drawPolygon(world, point, blue);
    point.clear();

    

    //left
    point.push_back(listpoint[3]);
    point.push_back(listpoint[4]);
    point.push_back(listpoint[7]);
    point.push_back(listpoint[0]);
    drawPolygon(world, point, purple);
    point.clear();

    //bottom
    point.push_back(listpoint[2]);
    point.push_back(listpoint[5]);
    point.push_back(listpoint[4]);
    point.push_back(listpoint[3]);
    drawPolygon(world, point, yellow);
    point.clear();

    

    

    // up
    point.push_back(listpoint[0]);
    point.push_back(listpoint[1]);
    point.push_back(listpoint[6]);
    point.push_back(listpoint[7]);
    drawPolygon(world, point, orange);
    point.clear();
    //back
    for (int i = 4; i < 8; i++) { point.push_back(listpoint[i]); }
    drawPolygon(world, point, green);
    point.clear();
}

