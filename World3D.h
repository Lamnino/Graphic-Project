#pragma once
#ifndef WORLD3D_H
#define WORLD3D_H

#include "Camera.h"
#include "Vector3D.h"
#include <vector>
#include <string.h>
class World3D {
public:
    Camera cam;

    World3D(Vector3D pos, Vector3D tar);
    World3D(Vector3D pos, Vector3D tar, std::string nameWindows, float width, float height );

    Vector3D PointTo2D(Vector3D point, Camera cam);
    std::vector<Vector3D> triangleTo2D(std::vector<Vector3D> listPoint, Camera cam);
    std::vector<Vector3D> polygonTo2D(std::vector<Vector3D> listPoint, Camera cam);
    static void translateObject(std::vector<Vector3D> listPoint, Vector3D direc);
    static void rotateObject(std::vector<Vector3D> listPoint, Vector3D centre, float angle);
};


#endif  // WORLD3D_H
