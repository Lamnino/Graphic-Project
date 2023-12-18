#pragma once
#ifndef WORLD3D_H
#define WORLD3D_H

#include "Camera.h"
#include "Vector3D.h"
#include <vector>
class World3D {
public:
    Camera cam;

    World3D(Vector3D pos, Vector3D tar);

    Vector3D PointTo2D(Vector3D point, Camera cam);
    std::vector<Vector3D> triangleTo2D(std::vector<Vector3D> listPoint, Camera cam);
    std::vector<Vector3D> polygonTo2D(std::vector<Vector3D> listPoint, Camera cam);

};


#endif  // VECTOR3D_H
