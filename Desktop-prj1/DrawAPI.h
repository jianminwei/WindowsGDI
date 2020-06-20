#pragma once
#include "Draw.h"

#ifndef DRAWAPI_H_
#define DRAWAPI_H_

//This DrawAPI class id created to further abstract the detailed 
//drawing mechanics from users. All user needs to do is to put all
//the drawings in the draw() member function.
class DrawAPI
{
private:
	Draw &drawTool;

public:
	DrawAPI(Draw &d) : drawTool(d) {}
	Draw& getDraw() { return drawTool; }
	void draw();
};

#endif
