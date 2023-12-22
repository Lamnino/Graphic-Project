#include "Camera.h"
#include <iostream>
#include "Vector3D.h"
#include <cmath>

Camera::Camera() { pos = Vector3D(); tar = Vector3D(); dis = 0; heigth = 0; width = 0; }
Camera::Camera(Vector3D pos, Vector3D tar)
{
	this->pos = pos;
	this->tar = tar;
	dis = 500;
	heigth = 600;
	width = 400;
	screen.resize(heigth, std::vector<Pixel>(width));
}

Camera::Camera(Vector3D pos, Vector3D tar,float heigth, float width)
{
	this->pos = pos;
	this->tar = tar;
	this->dis = (heigth+ width)/2;
	this->heigth = heigth;
	this->width = width;
	screen.resize(heigth, std::vector<Pixel>(width));
}

Vector3D Camera::look()
{
	return tar - pos;
}

Vector3D Camera::up() 
{
	Vector3D pointToUp = pos + Vector3D(0.0f, 1.0f, 0.0f);
	float angle = pos.angle3Point(tar, pointToUp);
	if (angle < Vector3D::PI/2)
	{
		float lengthAE = std::cos(angle) * Vector3D::length(pos, pointToUp);
		Vector3D AC = Vector3D::normalize(Vector3D(pos, tar));
		Vector3D AE = AC * lengthAE;
		return Vector3D(pos, pointToUp + (AE * -1));
	}
	else if (angle > Vector3D::PI / 2)
	{
		float lengthAE = std::cos(Vector3D::PI - angle) * Vector3D::length(pos, pointToUp);
		Vector3D AC = Vector3D::normalize(Vector3D(pos, tar));
		Vector3D AE = AC * lengthAE;
		return Vector3D(pos, pointToUp + AE);
	}
	else 
	{
		return look();
	}
	return Vector3D(0, 0, 0);
}

Vector3D Camera::center() 
{
	return pos + (Vector3D::normalize(Vector3D(pos, tar)) * dis);
}