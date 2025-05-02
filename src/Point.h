#ifndef POINT_H
#define POINT_H
#include "Shape.h"

class Point : public Shape {
    float x;
    float y;
    float r;
    float g;
    float b;
    int size;

public:
    Point();
    Point(float x, float y);
    Point(float x, float y, float r, float g, float b, int size);
    bool contains(float mx, float my);
    void setColor(float r, float g, float b);
    void changeSize(int sizeChange);
    void dragShape(float dx, float dy);
    void setPosition(float newX , float newY);
    void setSize(int newSize);

    void draw();

    float getX() const;
    float getY() const;
    float getR() const;
    float getG() const;
    float getB() const;
    int getSize() const;
};

#endif