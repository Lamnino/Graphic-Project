#pragma once
#ifndef PIXEL_H
#define PIXEL_H

#include "Vector3D.h"
class Pixel {
public:
	Vector3D pos;
	float color[3];

	Pixel() {
		pos = Vector3D();
		for (int i = 0; i < 3; i++) color[i] = 0;
	}
	Pixel(int x, int y, float color[]);
	Pixel(int x, int y,int z, float color[]);
};

#endif  // VECTOR3D_H#pragma once
