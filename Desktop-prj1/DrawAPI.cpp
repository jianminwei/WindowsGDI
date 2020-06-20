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
	draw.line(20, 20, 400, 20);

	draw.setBrush(Draw::color::CYAN, 1);
	draw.rectangle(100, 100, 200, 450);

	draw.setBrush(Draw::color::GREEN, 2);
	draw.triangle(50, 50, 300, 300, 150, 400);
}

