#include "pch.h"
#include "Draw.h"
#include "DrawAPI.h"
#include <cmath>  //for std::sqrt() function

Draw::Draw(HDC& hdc) : myHdc(hdc) { 
	brush = CreateSolidBrush(RGB(0, 0, 0)); //create a default black brush
	lineThick = 1;                          //set the default lineThick = 1
} 

void Draw::setColor(color theColor) {
	//BLACK, WHITE, RED, LIME, BLUE, YELLOW, CYAN, MAGENTA,
	//SILVER, GRAY, MAROON, OLIVE, GREEN, PURPLE, TEAL, NAVY
	switch (theColor) {
	case BLACK:
		brush = CreateSolidBrush(RGB(0, 0, 0));
		break;
	case WHITE:
		brush = CreateSolidBrush(RGB(255, 255, 255));
		break;
	case RED:
		brush = CreateSolidBrush(RGB(255, 0, 0));
		break;
	case LIME:
		brush = CreateSolidBrush(RGB(0, 255, 0));
		break;
	case BLUE:
		brush = CreateSolidBrush(RGB(0, 0, 255));
		break;
	case YELLOW:
		brush = CreateSolidBrush(RGB(255, 255, 0));
		break;
	case CYAN:
		brush = CreateSolidBrush(RGB(0, 255, 255));
		break;
	case MAGENTA:
		brush = CreateSolidBrush(RGB(255, 0, 255));
		break;
	case SILVER:
		brush = CreateSolidBrush(RGB(192, 192, 192));
		break;
	case GRAY:
		brush = CreateSolidBrush(RGB(128, 128, 128));
		break;
	case MAROON:
		brush = CreateSolidBrush(RGB(128, 0, 0));
		break;
	case OLIVE:
		brush = CreateSolidBrush(RGB(128, 128, 0));
		break;
	case GREEN:
		brush = CreateSolidBrush(RGB(0, 128, 0));
		break;
	case PURPLE:
		brush = CreateSolidBrush(RGB(128, 0, 128));
		break;
	case TEAL:
		brush = CreateSolidBrush(RGB(0, 128, 128));
		break;
	case NAVY:
		brush = CreateSolidBrush(RGB(0, 0, 128));
		break;
	default:
		//brush = CreateSolidBrush(RGB(0, 0, 0));
		break;
	}

}

void Draw::setThickness(int thick) {
	lineThick = thick;
}

void Draw::setBrush(color theColor, int thinkness) {
	setColor(theColor);
	lineThick = thinkness;
}

/******** Draw a pixel logic using the GDI RECT mimicing a pixel
HBRUSH brush = CreateSolidBrush(RGB(0, 0, 0));
RECT rect = { 20, 20, 22, 22 };
FillRect(hdc, &rect, brush);
**********/

void Draw::pixel(int x, int y) {
    RECT rect = { x, y, x + lineThick, y + lineThick };
    FillRect(myHdc, &rect, brush);
}

void Draw::line(int x1, int y1, int x2, int y2) {
	int xAbsLength = x2 >= x1 ? x2 - x1 : x1 - x2;
	int yAbsLength = y2 >= y1 ? y2 - y1 : y1 - y2;

	int maxXorY = xAbsLength >= yAbsLength ? xAbsLength : yAbsLength;

	if (maxXorY == 0)  //the line has no length
		return;

	if (x2 >= x1) {
		if (y2 >= y1) {
			if (xAbsLength >= yAbsLength) {
				for (int i = 0; i <= maxXorY; i++)
					pixel(x1 + i, y1 + (int) (i * (float) yAbsLength / maxXorY));
			}
			else {
				for (int i = 0; i <= maxXorY; i++)
					pixel(x1 + (int)(i * ((float)xAbsLength / maxXorY)), y1 + i);
			}
		}
		else {
			if (xAbsLength >= yAbsLength) {
				for (int i = 0; i <= maxXorY; i++)
					pixel(x1 + i, y1 - (int)(i * (float)yAbsLength / maxXorY));
			}
			else {
				for (int i = 0; i <= maxXorY; i++)
					pixel(x1 + (int)(i * ((float)xAbsLength / maxXorY)), y1 - i);
			}
		}
	}
	else {
		if (y2 >= y1) {
			if (xAbsLength >= yAbsLength) {
				for (int i = 0; i <= maxXorY; i++)
					pixel(x1 - i, y1 + (int)(i * (float)yAbsLength / maxXorY));
			}
			else {
				for (int i = 0; i <= maxXorY; i++)
					pixel(x1 - (int)(i * ((float)xAbsLength / maxXorY)), y1 + i);
			}
		}
		else {
			if (xAbsLength >= yAbsLength) {
				for (int i = 0; i <= maxXorY; i++)
					pixel(x1 - i, y1 - (int)(i * (float)yAbsLength / maxXorY));
			}
			else {
				for (int i = 0; i <= maxXorY; i++)
					pixel(x1 - (int)(i * ((float)xAbsLength / maxXorY)), y1 - i);
			}
		}
	}
}

void Draw::rectangle(int x1, int y1, int x2, int y2) {
	line(x1, y1, x2, y1);
	line(x2, y1, x2, y2);
	line(x2, y2, x1, y2);
	line(x1, y2, x1, y1);
}

void Draw::triangle(int x1, int y1, int x2, int y2, int x3, int y3) {
	line(x1, y1, x2, y2);
	line(x2, y2, x3, y3);
	line(x3, y3, x1, y1);
}

void Draw::circle(int xCenter, int yCenter, int radius) {

	// 1. Draw the circle from (0, 0). We can then move it to the center of (x,y) position.
	// 2. In order to get the best accurate result, before 45 degree, use X for calculation
	//    after 45 degree, use y for calculation. 
    // 3. Math formula: cos(45 degree) = sin(45 degree) = 0.70710678118

	int xDegree45 = (int) (radius * 0.70710678118);
	int yDegree45 = (int) (radius * 0.70710678118);

	// Formular: y = sqrt(radius^2 - x^2); x = sqrt(radius^2 - y^2)
	for (int i = 0; i <= xDegree45; i++) {
		int y = (int) std::sqrt(radius * radius - i * i);

		//when draw the pixel, needs to adjust the (x,y) center.
		pixel(xCenter - i, yCenter - y);

		//draw above mirror image.
		pixel(xCenter - i, yCenter + y);

		//draw right mirror image.
		pixel(xCenter + i, yCenter - y);

		//draw right above mirror image.
		pixel(xCenter + i, yCenter + y);
	}

	for (int i = 0; i <= yDegree45; i++) {
		int x = (int)std::sqrt(radius * radius - i * i);

		//when draw the pixel, needs to adjust the (x,y) center.
		pixel(xCenter - x, yCenter - i);

		//draw above mirror image.
		pixel(xCenter - x, yCenter + i);

		//draw right mirror image.
		pixel(xCenter + x, yCenter - i);

		//draw right above mirror image.
		pixel(xCenter + x, yCenter + i);
	}
}

void Draw::draw() {
	DrawAPI drawAPI(*this);

	drawAPI.draw();  //draw everything defined in drawAPI
}
