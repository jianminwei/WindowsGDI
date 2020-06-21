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

	draw.setBrush(Draw::color::BLUE, 3);
	draw.pixel(150, 60);

	draw.setBrush(Draw::color::RED, 2);
	draw.line(20, 20, 600, 20);

	draw.setBrush(Draw::color::CYAN, 1);
	draw.rectangle(80, 80, 600, 250, Draw::fill::FILL);

	draw.setBrush(Draw::color::GREEN, 2);
	draw.triangle(50, 50, 300, 300, 150, 400);

	draw.setBrush(Draw::color::NAVY, 1);
	draw.circle(400, 200, 100);
}

