## A simple C++ graphics library starting with a pixcel

This repository contains a simple C++ graphics library for writing/practicing C++ purpose. This package is not created for implementing
real graphics application, rather it gives you the simple capability of plot a pixel on a screen. It also has line, rectangle and circle
functions based on the pixel. This should be good enough for practicing your C++ skills. 

It implemented on windows based on Windows GDI+. But it is not for teaching  Windows GDI+, rather using it to create a simple graphics
package.

### Code Examples

- Draw a single pixel
```
// draw a pixel with blue color and 3 thickness at location (150, 60)
void DrawAPI::draw() 
{
	Draw& draw = getDraw();

	draw.setBrush(Draw::color::BLUE, 3);
	draw.pixel(150, 60);
}
```
