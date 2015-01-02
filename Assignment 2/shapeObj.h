#ifndef shapeObjs
#define shapeObjs
using namespace std;
//Struct for the shapeobj which holds the property of every particle
struct shapeObj{
	GLdouble coordinatex; //coordinate x y z contains where the particle is located
	GLdouble coordinatey;
	GLdouble coordinatez;
	GLdouble color1; //color 1 2 3 contains the cooresponding rgb values of the particle
	GLdouble color2;
	GLdouble color3;
	GLdouble directionx; //direction x y z contains the direction of the particle
	GLdouble directiony;
	GLdouble directionz;
	GLdouble normalx;   //normal x y z contains the normal of each object for calculations on the rotation
	GLdouble normaly;
	GLdouble normalz;
	GLdouble speed = 1; //used for calculating individual rotation speed
	GLdouble degree = 0;
	int shapeType = 0; //the shape type corresponding to the values in the draw all function
	GLdouble time; //the time out time
};
#endif
