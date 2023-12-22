#include "Vector3D.h"
#include "cmath"
#include <iostream>

const float Vector3D::PI = 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679;
std::ostream& operator<<(std::ostream& os, const Vector3D& vec) {
	os << "(" << vec.x << ", " << vec.y << ", " << vec.z << ")";
	return os;
}

Vector3D Vector3D::operator*(const Vector3D& other) const
{
	Vector3D result;
	result.x = y * other.z - other.y * z;
	result.y = z * other.x - other.z * x;
	result.z = x * other.y - other.z * y;
	return result;
}

Vector3D Vector3D::operator*(float num) const
{
	return Vector3D(x * num, y * num, z * num);
}

Vector3D Vector3D::operator-(const Vector3D& other) const {
	return Vector3D(x - other.x, y - other.y, z - other.z);
}

Vector3D Vector3D::operator+(const Vector3D& other) const {
	return Vector3D(x + other.x, y + other.y, z + other.z);
}

Vector3D Vector3D::operator=(const Vector3D& other) {
	x = other.x; y = other.y; z = other.z;
	return *this;
}

float Vector3D::length(const Vector3D& A, const Vector3D& B)
{
	Vector3D AB(B.x - A.x, B.y - A.y, B.z - A.z);
	return std::sqrt(AB.x * AB.x + AB.y * AB.y + AB.z * AB.z);
}

float Vector3D::length(const Vector3D& A)
{
	return std::sqrt(A.x * A.x + A.y * A.y + A.z * A.z);
}

float Vector3D::dot(const Vector3D& A, const Vector3D& B)
{
	return A.x * B.x + A.y * B.y + A.z * B.z;
}

float Vector3D::angle3Point(const Vector3D& B, const Vector3D& C) const
{
	Vector3D AB(B.x - x, B.y - y, B.z - z);
	Vector3D AC(C.x - x, C.y - y, C.z - z);

	float LengthAB = sqrt(AB.x * AB.x + AB.y * AB.y + AB.z * AB.z);
	float LengthAC = sqrt(AC.x * AC.x + AC.y * AC.y + AC.z * AC.z);

	float dotProduct = dot(AB, AC);

	float angle = std::acos(dotProduct / (LengthAB * LengthAC));

	return angle;
}

Vector3D Vector3D::normalize(const Vector3D& B)
{
	float length = Vector3D::length(B);
	return Vector3D(B.x / length, B.y / length, B.z / length);
}

void Vector3D::swap(Vector3D& A, Vector3D& B)
{
	Vector3D medium = A;
	A = B; B = A;
}

