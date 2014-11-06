#ifndef shapeObjs
#define shapeObjs
using namespace std;

struct shapeObj{
	array<GLdouble, 3> coordinate;
	array<GLdouble, 4> color;
	array<GLdouble, 3> direction;
	array<GLdouble, 3> normal; //object's up
	GLdouble speed = 1;
	GLdouble degree = 0;
	bool visible;
	int shapeType = 0;
	GLdouble time;
};
#endif