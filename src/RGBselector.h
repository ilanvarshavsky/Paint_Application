#ifndef RGB_SELECTOR_H
#define RGB_SELECTOR_H

#include <bobcat_ui/all.h>
#include <bobcat_ui/int_input.h>
#include <bobcat_ui/return_button.h>

class RGBselector : public bobcat::Group {   

public:
    bobcat::IntInput* rInput;
    bobcat::IntInput* gInput;
    bobcat::IntInput* bInput;
    bobcat::ReturnButton* applyButton;
    bobcat::TextBox* colorPreview;

    RGBselector(int x, int y, int w, int h);

    int getR() const;
    int getG() const;
    int getB() const;

    bobcat::IntInput* getRInput() const {
        return rInput;
    }

    bobcat::IntInput* getGInput() const {
        return gInput;
    }

    bobcat::IntInput* getBInput() const {
        return bInput;
    }

    bobcat::ReturnButton* getApplyButton() const {
        return applyButton;
    }

};















#endif