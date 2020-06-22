## A simple C++ graphics library starting with a pixel

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

- Draw a line 

```
// draw a line with red color and 2 thickness at location (20, 20) to (600, 20)
void DrawAPI::draw() 
{
	Draw& draw = getDraw();
	
	draw.setBrush(Draw::color::RED, 2);
	draw.line(20, 20, 600, 20);
}

```

- Draw a rectangle

```
//draw a filled rectangle with color CYAN at location upper left (80, 80) and (600, 250) lower right locations.
void DrawAPI::draw() 
{
	Draw& draw = getDraw();

	draw.setBrush(Draw::color::CYAN, 1);
	draw.rectangle(80, 80, 600, 250, Draw::fill::FILL);
}

```

- Draw a circle

```
//draw a circle with NAVY color and 1 thickness at (400, 200) center and 100 radius.
void DrawAPI::draw() 
{
	Draw& draw = getDraw();

	draw.setBrush(Draw::color::NAVY, 1);
	draw.circle(400, 200, 100);
}
```

- Draw a triangle

```
//Draw a triangle with GREEN color and 2 thickness at locations (50,50), (300,300) and (150, 400)
void DrawAPI::draw() 
{
	Draw& draw = getDraw();

	draw.setBrush(Draw::color::GREEN, 2);
	draw.triangle(50, 50, 300, 300, 150, 400);
}
```



