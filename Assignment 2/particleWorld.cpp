#include "glutHeader.h"
#include "particleWorld.h"
#include <list>

using namespace std;

array<GLdouble, 3> particlePoint = { 0, 10, 0 };
array<GLdouble, 3> defaultNorm = { 0, 1, 0 };
GLdouble size = 1;
void particleWorld::insertShape(array<GLdouble, 3> coord,
	array<GLdouble, 4> color,
	array<GLdouble, 3> direction,
	array<GLdouble,3> normal,
	int shapeType){

	theQueue.push_back(shapeObj());
	if (coord.empty())
	{
		theQueue.back().coordinate = particlePoint;
	}
	else
	{
		theQueue.back().coordinate = coord;
	}
	theQueue.back().color = color;
	theQueue.back().direction = direction;
	if (normal.empty())
	{
		theQueue.back().normal = defaultNorm;
	}
	else
	{
		theQueue.back().normal = normal;
	}
	theQueue.back().shapeType = shapeType;
}


void particleWorld::drawAll(void){
	list<shapeObj>::iterator count;
	for (count = theQueue.begin(); count != theQueue.end(); ++count)
	{
		glPushMatrix();
		glTranslated(count->coordinate[0],count->coordinate[1],count->coordinate[2]);
		
		switch (count->shapeType)
		{
		case 1:
			glutSolidCube(size);
			break;
		case 2:
			glutSolidSphere(size,360,360);
			break;
		case 3:
			glutSolidTeapot(size);
			break;
		case 4:
			glutSolidTorus(size / 2, size, 1, 1);
			break;
		}
		glPopMatrix();
		
	}
	
	
}

void particleWorld::updateAll(){
	list<shapeObj>::iterator count;
	for (count = theQueue.begin(); count != theQueue.end(); ++count)
	{
		for (size_t i = 0; i < count->direction.size(); i++)
		{
			count->coordinate[i] += count->direction[i];
			
		}
	}
}

void particleWorld::addRandom(){

}

void particleWorld::reset(){
	theQueue.clear();
}

void create(int shapeType){

}