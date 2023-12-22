#include "Pixel.h"
#include "GL/glut.h"


Pixel Pixel::operator=(const Pixel& other)
{
	this->dept = other.dept;
	//std::cout << this->dept << ";";
	for (int i = 0; i < 3; i++)
	{
		this->color[i] = other.color[i];
	}
	return *this;
}


Pixel::Pixel(float color[])
{
	dept = 100000;
	for (int i = 0; i < 3; i++)
	{
		this->color[i] = color[i];
	}
}

Pixel::Pixel(float dept, float color[])
{
	this->dept = dept;
	for (int i = 0; i < 3; i++)
	{
		this->color[i] = color[i];
	}
}

void Pixel::DrawPixel(int x, int y)
{
	glColor3f(color[0], color[1], color[2]);
	glBegin(GL_POINTS);
	glVertex2f(x, y);
}