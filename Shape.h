#pragma once
#ifndef SHAPE_H
#define SHAPE_H
#include <vector>
#include "Vector3D.h"
#include <GL/freeglut.h>
#include <iostream>
#include "World3D.h"

class Shape 
{
public:
	//2D form
	static void drawTriangle(World3D world, const std::vector<Vector3D>& listpoint, float color[3]);
	static void drawQuadtri(World3D world, const std::vector<Vector3D>& listpoint, float color[3]);
	static void drawPolygon(World3D world, const std::vector<Vector3D>& listpoint, float color[]);

	//3D form
	static void drawCube(World3D world, const std::vector<Vector3D>& listpoint);
};

#endif