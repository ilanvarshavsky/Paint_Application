#include "Triangle.h"
#include <GL/freeglut.h>
#include <algorithm>

Triangle::Triangle() {
    x = 0.0;
    y = 0.0;
    base = 0.2;
    height = 0.2;
    r = 0.0;
    g = 0.0;
    b = 0.0;
}

Triangle::Triangle(float x, float y, float r, float g, float b) {
    this->x = x;
    this->y = y;
    base = 0.2;
    height = 0.2;
    this->r = r;
    this->g = g;
    this->b = b;
}

void Triangle::draw() {
    glColor3f(r, g, b);
    
    glBegin(GL_POLYGON);
        glVertex2f(x - base/2, y - height/2);
        glVertex2f(x, y + height/2);
        glVertex2f(x + base/2, y - height/2);
    glEnd();
}

bool Triangle::contains(float mx, float my) {
    float x1 = x;                     
    float y1 = y - height / 2;

    float x2 = x - base / 2;       
    float y2 = y + height / 2;

    float x3 = x + base / 2;        
    float y3 = y + height / 2;

    float denominator = ((y2 - y3)*(x1 - x3) + (x3 - x2)*(y1 - y3));
    float a = ((y2 - y3)*(mx - x3) + (x3 - x2)*(my - y3)) / denominator;
    float b = ((y3 - y1)*(mx - x3) + (x1 - x3)*(my - y3)) / denominator;
    float c = 1.0f - a - b;
    if (denominator == 0.0f) return false;

    return (a >= 0) && (b >= 0) && (c >= 0);
}

void Triangle::setColor(float r, float g, float b) {
    this->r = r;
    this->g = g;
    this->b = b;
}

void Triangle:: changeSize(int sizeChange){
    base += sizeChange * 0.01f;
    height += sizeChange * 0.01f;
    if( base < 0.01f){
        base = 0.01f;
    }
    if (height < 0.01f){
        height = 0.01f;
    }
}

void Triangle::dragShape(float dx, float dy){
    x += dx;
    y += dy;
}