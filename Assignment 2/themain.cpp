#include "glutHeader.h"
#include "particleWorld.h"
#include "genplatformClass.h"
#include <stdio.h>
#include <time.h>

particleWorld render;
struct Setting
{
	bool pause = true;	//boolean to pause whats currently being displayed
	double speedFactor = 1; //speed of the polygon
	int mode = 1;	//display mode in 1 2 or 3 defined by keyboard shortcuts to switch

	int windowSizeX = 600; //window size X
	int windowSizeY = 600; //window size Y
	GLdouble ptsize = 3;	//point size

	bool colormode = false;	//use mouse menu color mode or randomly given
	double red = 1;		//global colors
	double green = 1;
	double blue = 1;
} set;

GLdouble camPos[3] = { 0, 5, 10 };
GLdouble const origin[3] = { 0, 0, 0 };

void keyboard(unsigned char key, int x, int y)
{
		array<GLdouble,3> point = render.getLocation();
	switch (key)
	{
	case 'q':
	case 27:
		exit(0);
		break;
	case 'p':
	case 'P':
		if (set.pause){
			set.pause = FALSE;
		}
		else{
			set.pause = TRUE;
		}
		break;
	case 'w':
	case 'W':
		point[2] += 1;
		render.setLocation(point);
		break;	
	case 'a':
	case 'A':
		point[0] -= 1;
		render.setLocation(point);
		break;
	case 's':
	case 'S':
		point[2] -= 1;
		render.setLocation(point);
		break;
	case 'd':
	case 'D':
		
		point[0] += 1;
		render.setLocation(point);
		break;
	case 'r':
	case 'R':
		render.addRandom();
		break;
	}

	glutPostRedisplay();
}

void special(int key, int x, int y)
{
	/* arrow key presses move the camera */
	switch (key)
	{
	case GLUT_KEY_LEFT:
		camPos[0] -= 0.5;
		break;

	case GLUT_KEY_RIGHT:
		camPos[0] += 0.5;
		break;

	case GLUT_KEY_UP:
		camPos[2] -= 0.5;
		break;

	case GLUT_KEY_DOWN:
		camPos[2] += 0.5;
		break;

	case GLUT_KEY_HOME:
		camPos[1] += 0.5;
		break;

	case GLUT_KEY_END:
		camPos[1] -= 0.5;
		break;

	}
	glutPostRedisplay();
}

void init(void)
{
	glClearColor(0, 0, 0, 0);
	glColor3f(1, 1, 1);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45, 1, 1, 100);
}

void timer(int value)
{
	if(set.pause){
		render.updateAll();
		
	}
	glutPostRedisplay();
	glutTimerFunc(8, timer, 0);
}


/* display function - GLUT display callback function
*		clears the screen, sets the camera position, draws the ground plane and movable box
*/
void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	gluLookAt(camPos[0], camPos[1], camPos[2], 0, 0, 0, 0, 1, 0);
	glColor3f(1, 1, 1);
	
	render.drawAll();		//draws all particles in the particle queue
	genplatformClass::draw();
	glutSwapBuffers();
}

/* main function - program entry point */
int main(int argc, char** argv)
{
	for (int i = 0; i < 40; i++){
		render.addRandom();
	}
	srand(time(NULL));
	glutInit(&argc, argv);		//starts up GLUT

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Assignment 2");	//creates the window
	
	glutDisplayFunc(display);	//registers "display" as the display callback function
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(special);
	glutTimerFunc(8, timer, 0);	//timer function for the program
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	init();

	glutMainLoop();				//starts the event loop

	return(0);					//return may not be necessary on all compilers
}