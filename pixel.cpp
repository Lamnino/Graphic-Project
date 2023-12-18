#include "Pixel.h"


Pixel::Pixel(int x, int y, float color[])
{
	pos = Vector3D(x, y, 0);
	for (int i = 0; i < 3; i++)
	{
		this->color[i] = color[i];
	}
}

Pixel::Pixel(int x, int y, int z, float color[])
{
	pos = Vector3D(x, y, z);
	for (int i = 0; i < 3; i++)
	{
		this->color[i] = color[i];
	}
}