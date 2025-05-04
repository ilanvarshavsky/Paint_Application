#include "Scribble.h"

void Scribble::addPoint(float x, float y, float r, float g, float b, int size){
    points.push_back(new Point(x, y, r, g, b, size));
}

void Scribble::draw(){
    for (unsigned int i = 0; i < points.size(); i++){
        points[i]->draw();
    }
}

bool Scribble::contains(float mx, float my) {
     if (points.empty()) return false;

    float minX = points[0]->getX();
    float maxX = points[0]->getX();
    float minY = points[0]->getY();
    float maxY = points[0]->getY();

    for (size_t i = 1; i < points.size(); ++i) {
        float px = points[i]->getX();
        float py = points[i]->getY();

        if (px < minX) minX = px;
        if (px > maxX) maxX = px;
        if (py < minY) minY = py;
        if (py > maxY) maxY = py;
    }
    return (mx >= minX && mx <= maxX && my >= minY && my <= maxY);

}

void Scribble::setColor(float r, float g, float b) {
    for (size_t i = 0; i < points.size(); i++){
        points[i]->setColor(r, g, b);
    }
}

void Scribble::changeSize(int sizeChange){
    for (size_t i = 0; i < points.size(); i++){
        int newSize = points[i]->getSize() + sizeChange;
        if (newSize < 1){
            newSize = 1;
        }
        points[i]->setSize(newSize);
    }
}

void Scribble::dragShape(float dx, float dy){
    for (size_t i = 0; i < points.size(); i++){
        float newX = points[i]->getX() + dx;
        float newY = points[i]->getY() + dy;
        points[i]->setPosition(newX, newY);
    }
}

Scribble::~Scribble(){
    for (unsigned int i = 0; i < points.size(); i++){
        delete points[i];
    }
    points.clear();
}