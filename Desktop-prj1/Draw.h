#include "DrawAPI.h"

#pragma once

#ifndef DRAW_H_
#define DRAW_H_

class Draw
{
private:
    HDC& myHdc;
    HBRUSH brush;
    int lineThick;
 
public:
    enum color { BLACK,WHITE,RED,LIME,BLUE,YELLOW,CYAN,MAGENTA,
                 SILVER,GRAY,MAROON,OLIVE,GREEN,PURPLE,TEAL,NAVY};
    Draw(HDC& hdc);
    void setColor(color theColor);
    void setThickness(int thinkness);
    void setBrush(color theColor, int thinkness);
    void pixel(int x, int y);
    void line(int x1, int y1, int x2, int y2);
    void rectangle(int x1, int y1, int x2, int y2);
    void triangle(int x1, int y1, int x2, int y2, int x3, int y3);
    void circle(int x, int y, int radius);
    void draw();
};

#endif 

