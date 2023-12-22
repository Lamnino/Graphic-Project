#pragma once
#ifndef VECTOR3D_H
#define VECTOR3D_H
#include <iostream>

class Vector3D {
    
public:
    float x, y, z;
    static const float PI;

    Vector3D() { x = 0; y = 0; z = 0; }
    Vector3D(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}
    Vector3D(Vector3D A, Vector3D B) { x = B.x - A.x; y = B.y - A.y; z = B.z - A.z; }

    friend std::ostream& operator<<(std::ostream& os, const Vector3D& vec);
    Vector3D operator-(const Vector3D& other) const;
    Vector3D operator*(const Vector3D& other) const;
    Vector3D operator*(float num) const;
    Vector3D operator+(const Vector3D& other) const;
    Vector3D operator=(const Vector3D& other);
    
    static Vector3D normalize(const Vector3D& B);
    float angle3Point(const Vector3D& B, const Vector3D& C) const;
    static float length(const Vector3D& A, const Vector3D& B);
    static float length(const Vector3D& A);
    static float dot(const Vector3D& A, const Vector3D& B);
    static void swap(Vector3D& A, Vector3D& B);
};

#endif  // VECTOR3D_H