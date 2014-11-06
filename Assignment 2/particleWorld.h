#include <array>
#include <list>
#include "shapeObj.h"
using namespace std;

class particleWorld{
private:
	list<shapeObj> theQueue;
public:
	particleWorld(void){}

	void insertShape(array<GLdouble, 3> coord,
		array<GLdouble,4> color,
		array<GLdouble,3> direction,
		array<GLdouble,3> normal,
		int shapeType);

	void setLocation(array<GLdouble, 3> coord);

	void drawAll();

	void updateAll();

	void addRandom();

	void reset();

	void create(int shapeType);
};