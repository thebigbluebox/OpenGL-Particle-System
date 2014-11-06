#include <array>
#include <list>
#include "shapeObj.h"
using namespace std;

class particleWorld{
private:
	list<shapeObj> theQueue;
public:
	particleWorld(void){}

	void insertShape(
		array<GLdouble,4> color,
		array<GLdouble,3> direction,
		array<GLdouble,3> normal,
		int shapeType);

	void setLocation(array<GLdouble, 3> coord);

	array<GLdouble, 3> getLocation(void);

	void setPlane(array<GLdouble, 3> a,
		array<GLdouble, 3> b,
		array<GLdouble, 3> c,
		array<GLdouble, 3> d);
	
	void setTime(int timeval);	//sets the default time for erasing the particles

	void drawAll();		//draws all of the render queue

	void updateAll();	//updates the render queue with appropriate properties

	void deleteParticle(shapeObj ref);
	
	void addShape(int shapeType);	//adds only of a specified shape type

	void addRandom();

	void reset();
};