#include "glutHeader.h"
#include "genshapeClass.h"

float cols[6][3] = { { 1, 0, 0 }, { 0, 1, 1 }, { 1, 1, 0 }, { 0, 1, 0 }, { 0, 0, 1 }, { 1, 0, 1 } };

void genshapeClass::drawPolygon(int a, int b, int c, int d, float v[8][3]){
	glBegin(GL_POLYGON);
	glVertex3fv(v[a]);
	glVertex3fv(v[b]);
	glVertex3fv(v[c]);
	glVertex3fv(v[d]);
	glEnd();
}

//draws the cube given the vertices
//corrected for back face culling
void genshapeClass::cube(float v[8][3])
{
	glColor3fv(cols[1]);
	drawPolygon(0, 3, 2, 1, v);

	glColor3fv(cols[2]);
	drawPolygon(5 ,4, 0, 1, v);

	glColor3fv(cols[3]);
	drawPolygon(5, 1, 2, 6, v);

	glColor3fv(cols[4]);
	drawPolygon(2, 3, 7, 6, v);

	glColor3fv(cols[5]);
	drawPolygon(7, 4, 5, 6, v);

	glColor3fv(cols[0]);
	drawPolygon(7, 3, 0, 4, v); 
}

//generates vertices given the origin and the dimensions
void genshapeClass::drawBox(float* c, float w, float h, float d)
{
	float vertices[8][3] = { { c[0] - w / 2, c[1] - h / 2, c[2] + d / 2 },
	{ c[0] - w / 2, c[1] + h / 2, c[2] + d / 2 },
	{ c[0] + w / 2, c[1] + h / 2, c[2] + d / 2 },
	{ c[0] + w / 2, c[1] - h / 2, c[2] + d / 2 },
	{ c[0] - w / 2, c[1] - h / 2, c[2] - d / 2 },
	{ c[0] - w / 2, c[1] + h / 2, c[2] - d / 2 },
	{ c[0] + w / 2, c[1] + h / 2, c[2] - d / 2 },
	{ c[0] + w / 2, c[1] - h / 2, c[2] - d / 2 } };

	cube(vertices);
}
