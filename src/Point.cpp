#include "Point.h"
#include <GL/freeglut.h>
#include "Shape.h"

Point::Point() {
    x = 0.0;
    y = 0.0;
    r = 0.0;
    g = 0.0;
    b = 0.0;
    size = 7;
}

Point::Point(float x, float y) : Point() {
    this->x = x;
    this->y = y;
    size = 7;
}

Point::Point(float x, float y, float r, float g, float b, int size) : Point(x, y) {
    this->r = r;
    this->g = g;
    this->b = b;
}

void Point::draw() {
    glColor3f(r, g, b);
    glPointSize(size);

    glBegin(GL_POINTS);
        glVertex2f(x, y);
    glEnd();
}

bool Point::contains(float mx, float my) {
    float halfSize = size / 2.0f;
    return (mx >= x - halfSize && mx <= x + halfSize &&my >= y - halfSize && my <= y + halfSize);
}

void Point::setColor(float r, float g, float b) {
    this->r = r;
    this->g = g;
    this->b = b;
}

void Point::changeSize(int sizeChange){
    size += sizeChange;
    if (size < 7){
        size = 7;
    }
}

void Point::dragShape(float dx, float dy){
    x += dx;
    y += dy;
}

void Point::setPosition(float newX , float newY){
    x = newX;
    y = newY;
}

void Point::setSize(int newSize){
    size = newSize;
}


float Point::getX() const {
    return x;
}

float Point::getY() const {
    return y;
}

float Point::getR() const {
    return r;
}

float Point::getG() const {
    return g;
}

float Point::getB() const {
    return b;
}

int Point::getSize() const {
    return size;
}
