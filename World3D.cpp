#include "World3D.h"
#include "Vector3D.h"
#include "Camera.h"
#include <iostream>
#include "cmath"

World3D::World3D(Vector3D pos, Vector3D tar)
{
	cam = Camera(pos, tar);
}

Vector3D World3D::PointTo2D(Vector3D point, Camera cam)
{
	Vector3D center = cam.center();
	Vector3D projectionVector = Vector3D::normalize(Vector3D(cam.pos, point));
	Vector3D projectionpoint = cam.pos + (projectionVector * (cam.dis / (std::cos(cam.pos.angle3Point(point, center)))));
	float dept = Vector3D::length(Vector3D(cam.pos, point));
	projectionpoint = projectionpoint - center;
	projectionpoint.x = projectionpoint.z;
	projectionpoint.z = dept;
	//std::cout << projectionpoint <<";";
	return projectionpoint;
}

std::vector<Vector3D> World3D::triangleTo2D(std::vector<Vector3D> listPoint, Camera cam)
{
	std::vector<Vector3D> point2D;
	for (int i = 0; i < 3; i++)
	{
		point2D.push_back(PointTo2D(listPoint[i], cam));
	}
	return point2D;
}

std::vector<Vector3D> World3D::polygonTo2D(std::vector<Vector3D> listPoint, Camera cam)
{
	std::vector<Vector3D> point2D;
	for (int i = 0; i < listPoint.size(); i++)
	{
		point2D.push_back(PointTo2D(listPoint[i], cam));
	}
	return point2D;
}


