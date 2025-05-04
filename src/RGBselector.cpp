#include "RGBselector.h"
#include <FL/Enumerations.H>
#include <bobcat_ui/return_button.h>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <bobcat_ui/all.h>
using namespace bobcat;

RGBselector::RGBselector(int x, int y, int w, int h) : Group(x, y, w, h){
    rInput = new IntInput(70, 625, 50, 25, "R:");
    gInput = new IntInput(140, 625, 50, 25, "G:");
    bInput = new IntInput(210, 625, 50, 25, "B:");
    applyButton = new ReturnButton(290,615,70,35, "Apply");

    applyButton->deactivate();

    rInput->value(0);
    gInput->value(0);
    bInput->value(0);
    this->add(applyButton);
}



int RGBselector::getR() const {
    try {
        return (rInput->value());
    } catch (...) {
        return -1; // Return an invalid value to disable the button
    }
}

int RGBselector::getG() const {
    try {
        return (gInput->value());
    } catch (...) {
        return -1; 
    }
}

int RGBselector::getB() const {
    try {
        return (bInput->value());
    } catch (...) {
        return -1; 
    }
}


