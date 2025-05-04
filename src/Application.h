#ifndef APPLICATION_H
#define APPLICATION_H

#include <bobcat_ui/all.h>
#include <bobcat_ui/bobcat_ui.h>
#include <bobcat_ui/int_input.h>
#include "Toolbar.h"
#include "Canvas.h"
#include "RGBselector.h"

class Application : public bobcat::Application_ {
    bobcat::Window* window;
    Toolbar* toolbar;
    Canvas* canvas;
    RGBselector* rgbSelector;
    Shape* selectedShape;

    void onCanvasMouseDown(bobcat::Widget* sender, float mx, float my);
    void onCanvasMouseUp(bobcat::Widget* sender, float mx, float my);
    void onCanvasDrag(bobcat::Widget* sender, float mx, float my);
    void onToolbarChange(bobcat::Widget* sender);
    void onApplyColor(bobcat::Widget* sender);
    void updateApplyButtonState();
    void onRGBInputChange(bobcat::Widget* sender);

private:
    float lastMouseX;
    float lastMouseY;
    
public:
    Application();

    friend struct::AppTest;
};

#endif