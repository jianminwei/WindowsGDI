#pragma once
#include "pch.h"
#include "DrawAPI.h"
#include "Draw.h"

/************************************************
** This is the place to put user drawings and  **
** objects here when you need to draw them.    **
*************************************************/

void DrawAPI::draw() 
{
	Draw& draw = getDraw();

	draw.setColor(Draw::color::BLUE);
	draw.setThickness(3);
	draw.pixel(150, 60);

	draw.setColor(Draw::color::RED);
	draw.setThickness(2);
	draw.line(20, 20, 400, 20);

	draw.setColor(Draw::color::CYAN);
	draw.setThickness(1);
	draw.rectangle(100, 100, 200, 450);

	draw.setColor(Draw::color::GREEN);
	draw.setThickness(2);
	draw.triangle(50, 50, 300, 300, 150, 400);
}

