
#include <iostream>
#include <cmath>
#include "Vector3D.h"
#include "Camera.h"
#include "World3D.h"
#include <GL/glut.h>
#include "Shape.h"
using namespace std;

int WINDOW_WIDTH = 600;
const int WINDOW_HEIGHT = 400;
// Hàm vẽ tam giác


// Hàm hiển thị
void display()
{
    // Tạo ba điểm A, B và C
    Vector3D PosCam(-2, 2, 2);
    Vector3D TarCam(0.0, 0.0, 0.0);
    

    std::vector<Vector3D> listpoint;
    Vector3D A(-1, 1, -1);
    Vector3D B(-1, 1, 1);
    Vector3D C(-1, -1, 1);
    Vector3D D(-1, -1, -1);
    Vector3D E(1, -1, 1);
    Vector3D F(1, -1, -1);
    Vector3D G(1, 1, -1);
    Vector3D H(1, 1, 1);

    listpoint.push_back(A);
    listpoint.push_back(B);
    listpoint.push_back(C);
    listpoint.push_back(D);
    listpoint.push_back(E);
    listpoint.push_back(F);
    listpoint.push_back(G);
    listpoint.push_back(H);

    World3D world(PosCam, TarCam);

    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0); // Màu trắng
    glLoadIdentity();

    glPointSize(1.0); // Đặt kích thước điểm

    Shape::drawCube(world, listpoint);

    glFlush();
    glutSwapBuffers();
}

void reshape(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-200, 300, -300, 200);
    glMatrixMode(GL_MODELVIEW);
}
struct Point {
    int x, y;
};

void ScanlineAlgorithm(Point p1, Point p2, Point p3) {
    // Sắp xếp các đỉnh theo tọa độ y tăng dần
    if (p1.y > p2.y) std::swap(p1, p2);
    if (p1.y > p3.y) std::swap(p1, p3);
    if (p2.y > p3.y) std::swap(p2, p3);

    // Tính số bước quét từ đỉnh p1 đến p3
    float steps = p3.y - p1.y;

    // Quét qua từng hàng pixel
    for (int y = p1.y; y <= p2.y; y++) {
        // Tính tọa độ x bắt đầu và kết thúc trên hàng pixel hiện tại
        float startX = p1.x + (y - p1.y) * (p3.x - p1.x) / steps;
        float endX = p2.x + (y - p2.y) * (p3.x - p2.x) / steps;

        // Vẽ các pixel từ tọa độ x bắt đầu đến tọa độ x kết thúc trên hàng pixel hiện tại
        for (int x = startX; x <= endX; x++) {
            std::cout << "Pixel (" << x << ", " << y << ")" << std::endl;
            // Vẽ pixel tại tọa độ (x, y) hoặc thực hiện các thao tác khác
        }
    }
}

int main() {
    Point p1 = { 0, 0 };
    Point p2 = { 4, 4 };
    Point p3 = { 2, 6 };

    ScanlineAlgorithm(p1, p2, p3);

    return 0;
}
