#pragma once
#ifndef CAMERA_H
#define CAMERA_H

#include "Pixel.h"
#include "Vector3D.h"
#include <vector>
#include <string>

class Camera {
public:
    Vector3D pos;
    Vector3D tar;
    float dis;
    float heigth;
    float width;
    std::vector<std::vector<Pixel>> screen;

    Camera();
    Camera(Vector3D pos, Vector3D tar);
    Camera(Vector3D pos, Vector3D tar,float height, float width);
    Vector3D look();
    Vector3D up();
    Vector3D center();
};

#endif  // CAMERA_H#pragma once
