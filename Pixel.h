#pragma once
#ifndef PIXEL_H
#define PIXEL_H

#include "Vector3D.h"
#include <iostream>

class Pixel {
public:
	float dept;
	float color[3];

	Pixel() {
		dept = 100000;
		for (int i = 0; i < 3; i++) color[i] = 0;
	}
	Pixel(float color[]);
	Pixel(float dept, float color[]);

	Pixel operator=(const Pixel& other);

	void DrawPixel(int x, int y);
};

#endif  // VECTOR3D_H#pragma once
