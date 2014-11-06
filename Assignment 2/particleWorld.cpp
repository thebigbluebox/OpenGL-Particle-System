#include "glutHeader.h"
#include "particleWorld.h"
#include <list>

using namespace std;

array<GLdouble, 3> particlePoint = { 0, 10, 0 };
array<GLdouble, 3> defaultNorm = { 0, 1, 0 };
array<array<GLdouble,3>,4> planeCoord;
GLdouble size = 0.1;
GLdouble defaultTime = 100;

void particleWorld::insertShape(
	array<GLdouble, 4> color,
	array<GLdouble, 3> direction,
	array<GLdouble,3> normal,
	int shapeType){
	
	if (theQueue.size()>20){
		return;
	}
	else{
		theQueue.push_back(shapeObj());
		//sets the inital position of the particle to where it should start off at
		theQueue.back().coordinate = particlePoint;
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
		theQueue.back().time = defaultTime;
	}
}

	//sets the drop off point of the particles
void particleWorld::setLocation(array<GLdouble, 3> coord){
	particlePoint = coord;
}
array<GLdouble, 3> particleWorld::getLocation(void){
	return particlePoint;
}

void setPlane(array<GLdouble,3> c, float w, float h, float d){
	array<GLdouble, 3> a = { c[0] + w / 2, c[1] + h / 2, c[2] + d / 2 };
	array<GLdouble, 3> b = { c[0] + w / 2, c[1] + h / 2, c[2] - d / 2 };
	array<GLdouble, 3> e = { c[0] - w / 2, c[1] + h / 2, c[2] - w / 2 };
	array<GLdouble, 3> f = { c[0] - w / 2, c[1] + h / 2, c[2] + w / 2 };
	array<array<GLdouble, 3>, 4> givenCoord = { a, b, e, f };
	planeCoord = givenCoord;
}

void setTime(int timeval){
	defaultTime = timeval;
}


void particleWorld::drawAll(void){
	list<shapeObj>::iterator count;
	for (count = theQueue.begin(); count != theQueue.end(); ++count)
	{
		glColor3d(count->color[0], count->color[1], count->color[2]);
		glPushMatrix();
		glTranslated(count->coordinate[0],count->coordinate[1],count->coordinate[2]);
		GLdouble turnt = count->degree + count->speed; //calculates individual roate speed
		glRotated(turnt, count->normal[0], count->normal[1], count->normal[2]);
		
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
		count->degree = turnt; //saves the rotated object
	}
	
	
}
//updates the value of the following
//coordinates
//timeout duration
//spin?
//deletes uneeded particles from the list
void particleWorld::updateAll(){
	list<shapeObj>::iterator count;
	for (count = theQueue.begin(); count != theQueue.end();)
	{
		for (size_t i = 0; i < count->direction.size(); i++)
		{
			count->coordinate[i] += count->direction[i]*0.005; // way too fast
			count->normal[i] += count->direction[i]*10; //changing the orientation position
			//count->coordinate[i] += -0.1;// this also makes all particles go the same direction.
		}

		if (count->time < 0){
			count = theQueue.erase(count);
		}
		else{
			count->time -= 1;
			++count;
		}
		
	}
}

void particleWorld::addShape(int shapeType){
	array<GLdouble, 4> color = { rand(), rand(), rand(), rand() };
	array<GLdouble, 3> direction = { rand(), rand(), rand() };
	array<GLdouble, 3> normal = { rand(), rand(), rand() };

	insertShape(color, direction, normal, shapeType);
}

void particleWorld::addRandom(){
	array<GLdouble, 4> color = { (rand() % 100)*0.01, (rand() % 100)*0.01, (rand() % 100)*0.01, rand() };
	array<GLdouble, 3> direction = { rand() % 100, -1*rand() % 100, rand() % 100 };
	array<GLdouble, 3> normal = { rand(), rand(), rand() };
	int shapeType = rand() % 4 + 1;

	insertShape(color, direction, normal, shapeType);
}

void particleWorld::reset(){
	theQueue.clear();
}