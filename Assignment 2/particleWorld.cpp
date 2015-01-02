#include "glutHeader.h"
#include "particleWorld.h"
#include <list>

using namespace std;
GLdouble planeCoord[4][3] = { { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 } };
GLdouble particlePoint[3] = { 0, 10, 0 };
GLdouble defaultNorm[3] = { 0, 1, 0 };
GLdouble defaultTime = 300;

void particleWorld::increaseSize(void){
	size+=0.2;
}

void particleWorld::decreaseSize(void){
	
	if (size -= 0.2 >= 0){
		size -= 0.2;
	}
	else{ size = 0.1; }
}

void particleWorld::increaseSpeed(void){
	speed += 0.2;
}

void particleWorld::decreaseSpeed(void){
	if (speed -= 0.2 <= 0){
		speed = 0.1;
	}
	else{ speed -= 0.2; }
}

void particleWorld::setShape(int s){
	currentshape = s;
}

void particleWorld::frictionMode(void){
	if (friction == true){
		friction = false;
	}
	else{
		friction = true;
	}
}

void particleWorld::windMode(void){
	if (wind == true){
		wind = false;
	}
	else{
		wind = true;
	}
}

void particleWorld::snowMode(void){
	if (snow == true){
		snow = false;
	}
	else{
		snow = true;
	}
}

void particleWorld::insertShape(
	GLdouble color1,
	GLdouble color2,
	GLdouble color3,
	GLdouble directionx,
	GLdouble directiony,
	GLdouble directionz,
	GLdouble normalx,
	GLdouble normaly,
	GLdouble normalz,
	int shapeType){
	
	if (theQueue.size()>400){
		return;
	}
	else{
		theQueue.push_back(shapeObj());
		//sets the inital position of the particle to where it should start off at
		/*snow function is defined by allowing the inital coordinates to be
		randomized across a plane, and setting the color and size to match its effect*/
		if (snow == true){
			theQueue.back().coordinatex = rand()%20 -10;
			theQueue.back().coordinatey = 20;
			theQueue.back().coordinatez = rand()%20 - 10;
			theQueue.back().color1 = 1;
			theQueue.back().color2 = 1;
			theQueue.back().color3 = 1;
			theQueue.back().directionx = rand()%4 - 2;
			theQueue.back().directiony = -1;
			theQueue.back().directionz = rand() % 4 - 2;
			size = 0.2;
		}
		else{
			theQueue.back().coordinatex = particlePoint[0];
			theQueue.back().coordinatey = particlePoint[1];
			theQueue.back().coordinatez = particlePoint[2];
			theQueue.back().color1 = color1;
			theQueue.back().color2 = color2;
			theQueue.back().color3 = color3;
			theQueue.back().directionx = directionx;
			theQueue.back().directiony = directiony;
			theQueue.back().directionz = directionz;
		}
		
		theQueue.back().normalx = defaultNorm[0];
		theQueue.back().normaly = defaultNorm[1];
		theQueue.back().normalz = defaultNorm[2];
		theQueue.back().shapeType = shapeType;
		theQueue.back().time = defaultTime;
	}
}

	//sets the drop off point of the particles
void particleWorld::setLocation(GLdouble x, GLdouble y, GLdouble z){
	particlePoint[0] = x; particlePoint[1] = y; particlePoint[2] = z;
}
GLdouble particleWorld::getLocationx(void){
	return particlePoint[0];
}

GLdouble particleWorld::getLocationy(void){
	return particlePoint[1];
}

GLdouble particleWorld::getLocationz(void){
	return particlePoint[2];
}

void setPlane(GLdouble a, GLdouble b, GLdouble j, GLdouble w, GLdouble h, GLdouble d){
	GLdouble c[3] = { a, b, j };
	GLdouble planeCoordtemp[4][3] = { { c[0] + w / 2, c[1] + h / 2, c[2] + d / 2 },
	{ c[0] + w / 2, c[1] + h / 2, c[2] - d / 2 },
	{ c[0] - w / 2, c[1] + h / 2, c[2] - w / 2 },
	{ c[0] - w / 2, c[1] + h / 2, c[2] + w / 2 } };
	for (int i = 0; i < 4; i++){
		for (int i2 = 0; i2 < 3; i2++){
			planeCoord[i][i2] = planeCoordtemp[i][i2];
		}
	}
}

void setTime(int timeval){
	defaultTime = timeval;
}



void particleWorld::drawAll(void){
	list<shapeObj>::iterator count;
	for (count = theQueue.begin(); count != theQueue.end(); ++count)
	{
		glColor3d(count->color1, count->color2, count->color3);
		glPushMatrix();
		glTranslated(count->coordinatex,count->coordinatey,count->coordinatez);
		GLdouble turnt = count->degree + count->speed; //calculates individual roate speed
		glRotated(turnt, count->normalx, count->normaly, count->normalz);
		
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
			glutSolidTorus(size/2, size ,20, 20);
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
		int windfactor = 1; //wind is defined as a scalar multiple in the x z direction and is toggled between 5 and no change
		if (wind == true){ windfactor = -5; }
		else{ windfactor = 1; }
			//the caclulated direction depends on a slowing factor of 0.005 times the speed and windfactor, the reason I didn't
			//normalize the speed is because I want every particle to exhibit their own unique speed to be more natural
			count->coordinatex += count->directionx*0.005*speed*windfactor;
			count->normalx += count->directionx*10; 
			count->coordinatey += count->directiony*0.005*speed;
			count->normaly += count->directiony * 10;
			count->coordinatez += count->directionz*0.005*speed*windfactor;
			count->normalz += count->directionz * 10;
		
			if (friction == true){ //once the particle has reached the plane the particle is given no speed which is defined for friction
				if ((count->coordinatey + count->directiony*0.005) < 0.5 && (count->coordinatex) >-10 && (count->coordinatex) < 10
					&& (count->coordinatez) <10 && (count->coordinatez) >-10){
					count->directionx = 0;
					count->directiony = 0;
					count->directionz = 0;
					count->coordinatey += 0.5;
				}
			}
			if (friction == false){
				if ((count->coordinatey + count->directiony*0.005) < 0.5 && (count->coordinatex) >-10 && (count->coordinatex) < 10
					&& (count->coordinatez) <10 && (count->coordinatez) >-10){
					count->directiony = (-1) * count->directiony;
					count->coordinatey += 0.5;
				}
				/*gravity is triggered by if the current direction of the y is down or up, from that we add speed if its down and decrease
				if it is up, and if the magnitude of y reaches a threashold then we switch directions to go down*/
				if ((count->directiony) > 0){   //articial gravity
					if ((count->directiony) < 0.1){
						count->directiony = -1;
					}
					else{
						count->directiony *= 0.9*gravity;
					}
				}
				if ((count->directiony) < 0){
					count->directiony *= 1.1;
				}
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
//adds 1 random particle per call, and it is generated through the srand(time(null)) defined in themain.cpp
void particleWorld::addRandom(){
	GLdouble color[3] = { (rand() % 100)*0.01, (rand() % 100)*0.01, (rand() % 100)*0.01 };
	GLdouble direction[3] = { rand() % 100, -1 * rand() % 100, rand() % 100 };
	GLdouble normal[3] = { rand(), rand(), rand() };
	int shapeType;
	if (currentshape > 0){
		shapeType = currentshape;
	}
	else{
		shapeType = rand() % 4 + 1;
	}
	insertShape(color[0], color[1], color[2],
		direction[0], direction[1], direction[2],
		normal[0], normal[1], normal[2], shapeType);
}
//clears the render queue
void particleWorld::reset(){
	theQueue.clear();
}
