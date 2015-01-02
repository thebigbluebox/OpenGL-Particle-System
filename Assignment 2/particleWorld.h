#include <list>
#include "shapeObj.h"
using namespace std;
/*This class is where all particles are stored, created, updated,
and deleted. It holds all functionalities that dictate the special
functions to the regular behaviour of particles.
*/
class particleWorld{
private:
	list<shapeObj> theQueue;
public:
	particleWorld(void){}
	int currentshape = 1;
	bool friction = false;
	bool snow = false;
	bool cannon = false;
	bool wind = false;
	GLdouble size = 1;
	GLdouble speed = 1;
	GLdouble gravity = 0.5;


	void insertShape(
		GLdouble color1,
		GLdouble color2,
		GLdouble color3,
		GLdouble directionx,
		GLdouble directiony,
		GLdouble directionz,
		GLdouble normalx,
		GLdouble normaly,
		GLdouble normalz,
		int shapeType);

	void setLocation(GLdouble x , GLdouble y, GLdouble z);

	GLdouble getLocationx(void);
	GLdouble getLocationy(void);
	GLdouble getLocationz(void);

	void setPlane(GLdouble a, GLdouble b, GLdouble j, GLdouble w, GLdouble h, GLdouble d);
	
	void setTime(int timeval);	//sets the default time for erasing the particles

	void drawAll(void);		//draws all of the render queue

	void updateAll(void);	//updates the render queue with appropriate properties

	void setShape(int shape);
	
	void addShape(int shapeType);	//adds only of a specified shape type

	void addRandom(void);	//adds 1 random particle to the list

	void reset(void);	//clears and empties the list

	void decreaseSize(void);	//decreases the size drawn of the particles
	
	void increaseSize(void);	//decreases the size drawn of the particles

	void increaseSpeed(void);	//increases the size drawn of the particles

	void decreaseSpeed(void); 	//decreases the size drawn of the particles

	void frictionMode(void);	//toggles between the friction mode

	void snowMode(void);		//toggles between the snow mode

	void windMode(void);		//toggles between the wind mode
};
