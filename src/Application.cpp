#include "Application.h"
#include "Enums.h"
#include "RGBselector.h"
#include <bobcat_ui/bobcat_ui.h>
#include <algorithm>
#include <bobcat_ui/return_button.h>

using namespace bobcat;
using namespace std;

void Application::onCanvasMouseDown(bobcat::Widget* sender, float mx, float my) {
    TOOL tool = toolbar->getTool();

    int r = rgbSelector->getR();
    int g = rgbSelector->getG();
    int b = rgbSelector->getB();

    if (tool == PENCIL) {
        canvas->startScribble();
        canvas->updateScribble(mx, my, r / 255.0f, g / 255.0f, b / 255.0f, 7);
        canvas->redraw();
    }
    else if (tool == ERASER) {
        canvas->startScribble();
        canvas->updateScribble(mx, my, 1.0, 1.0, 1.0, 14);
        canvas->redraw();
    }
    else if (tool == RECTANGLE) {
        canvas->addRectangle(mx, my, r / 255.0f, g / 255.0f, b / 255.0f);
        canvas->redraw();
    }
    else if (tool == CIRCLE) { 
        canvas->addCircle(mx, my, r / 255.0f, g / 255.0f, b / 255.0f);
        canvas->redraw();
    }
    else if (tool == TRIANGLE) { 
        canvas->addTriangle(mx, my, r / 255.0f, g / 255.0f, b / 255.0f);
        canvas->redraw();
    }
    else if (tool == POLYGON) { 
        canvas->addPolygon(mx, my, r / 255.0f, g / 255.0f, b / 255.0f);
        canvas->redraw();
    }
    else if (tool == MOUSE) {
        selectedShape = canvas->getSelectedShape(mx, my);
        lastMouseX = mx;
        lastMouseY = my;
    }

}

void Application::onCanvasMouseUp(bobcat::Widget* sender, float mx, float my) {
    canvas->endScribble();
}

void Application::onCanvasDrag(bobcat::Widget* sender, float mx, float my) {
    TOOL tool = toolbar->getTool();
    
    int r = rgbSelector->getR();
    int g = rgbSelector->getG();
    int b = rgbSelector->getB();
    

    if (tool == PENCIL) {
        canvas->updateScribble(mx, my, r / 255.0f, g / 255.0f, b / 255.0f, 7);
        canvas->redraw();
    }
    else if (tool == ERASER) {
        canvas->updateScribble(mx, my, 1.0, 1.0, 1.0, 14);
        canvas->redraw();
    }
    else if (tool == MOUSE && selectedShape){

        float dx = mx - lastMouseX;
        float dy = my - lastMouseY;

        selectedShape->dragShape(dx, dy);

        lastMouseX = mx;
        lastMouseY = my;

        canvas->redraw();
    }
}

void Application::onToolbarChange(bobcat::Widget* sender) {
    ACTION action = toolbar->getAction();

    if (action == CLEAR) {
        canvas->clear();
        canvas->redraw();
    }
    else if (action == SENDBACK){
        canvas->sendToBack(selectedShape);
        canvas->redraw();
    }
    else if (action == SENDFRONT){
        canvas->sendToFront(selectedShape);
        canvas->redraw();
    }
    else if (action == PLUS){
        canvas->increaseSize(selectedShape);
        canvas->redraw();
    }
    else if (action == MINUS){
        canvas->decreaseSize(selectedShape);
        canvas->redraw();
    }
    else if (action == UNDO){
        canvas->undo();
        canvas->redraw();
    }
}

void Application::updateApplyButtonState() {
        int r = rgbSelector->getR();
        int g = rgbSelector->getG();
        int b = rgbSelector->getB();

        bool validColor(r >= 0 && g >= 0 && b >=0 && r <= 255 && g <= 255 && b <= 255);

        if (validColor){
            rgbSelector->getApplyButton()->activate();
        }
        else {
            rgbSelector->getApplyButton()->deactivate();
        }
}

void Application::onRGBInputChange(bobcat::Widget* sender){
    updateApplyButtonState();
}

void Application::onApplyColor(bobcat::Widget* sender) {
        int r = static_cast<int>(rgbSelector->getR());
        int g = static_cast<int>(rgbSelector->getG());
        int b = static_cast<int>(rgbSelector->getB());
        

        r = std::max(0,std::min(r,255));
        g = std::max(0,std::min(g,255));
        b = std::max(0,std::min(b,255));

        if (selectedShape){
            selectedShape->setColor(r / 255.0f, g / 255.0f, b / 255.0f);
            canvas->redraw();
        }
        rgbSelector->getRInput()->value(0);
        rgbSelector->getGInput()->value(0);
        rgbSelector->getBInput()->value(0);
        rgbSelector->getRInput()->take_focus();
}

Application::Application() {
    window = new Window(25, 75, 410, 655, "Paint App");

    selectedShape = nullptr;
    lastMouseX = 0.0f;
    lastMouseY = 0.0f;

    toolbar = new Toolbar(0, 0, 60, 655);
    canvas = new Canvas(60, 0, 350, 605);
    rgbSelector = new RGBselector(60,600,350,50);


    window->add(toolbar);
    window->add(canvas);
    window->add(rgbSelector);
   

    ON_MOUSE_DOWN(canvas, Application::onCanvasMouseDown);
    ON_MOUSE_UP(canvas, Application::onCanvasMouseUp);
    ON_DRAG(canvas, Application::onCanvasDrag);
    ON_CHANGE(toolbar, Application::onToolbarChange);
    ON_CLICK(rgbSelector->getApplyButton(), Application::onApplyColor);
    ON_CHANGE(rgbSelector->getRInput(), Application::onRGBInputChange);
    ON_CHANGE(rgbSelector->getGInput(), Application::onRGBInputChange);
    ON_CHANGE(rgbSelector->getBInput(), Application::onRGBInputChange);
    

    window->show();
}