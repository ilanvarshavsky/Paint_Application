#include "Polygon.h"
#include <GL/freeglut.h>
#include <algorithm>
#include <cmath>

Polygon::Polygon() {
    x = 0.0;
    y = 0.0;
    sides = 6;
    length = 0.1;
    r = 0.0;
    g = 0.0;
    b = 0.0;
}

Polygon::Polygon(float x, float y, float r, float g, float b) {
    this->x = x;
    this->y = y;
    sides = 6;
    length = 0.1;
    this->r = r;
    this->g = g;
    this->b = b;
}

void Polygon::draw() {
    glColor3f(r, g, b);
    
    glBegin(GL_POLYGON);
        float inc = 2 * M_PI / sides;
        for (float theta = 0; theta <= 2 * M_PI; theta += inc) {
            glVertex2f(x + length * cos(theta), y + length * sin(theta));
        }
    glEnd();
}

bool Polygon::contains(float mx, float my) {
    float r = length / (2.0f * sinf(M_PI / sides));
    return (mx >= x - r && mx <= x + r && my >= y - r && my <= y + r);
}

void Polygon::setColor(float r, float g, float b) {
    this->r = r;
    this->g = g;
    this->b = b;
}

void Polygon::changeSize(int sizeChange){
    length += sizeChange * 0.01;
    if (length < 0.01f){
        length = 0.01f;
    }
}

void Polygon::dragShape(float dx, float dy){
    x += dx;
    y += dy;
}