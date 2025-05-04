#ifndef POLYGON_H
#define POLYGON_H

#include "Shape.h"

class Polygon : public Shape {
    float x;
    float y;
    int sides;
    float length;
    float r;
    float g;
    float b;

public:
    Polygon();
    Polygon(float x, float y, float r, float g, float b);

    void draw();
    bool contains(float mx, float my);
    void setColor(float r, float g, float b);
    void changeSize(int sizeChange);
    void dragShape(float dx, float dy);

};

#endif