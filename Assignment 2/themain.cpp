#include "glutHeader.h"
#include "renderqueueClass.h"
#include "genplatformClass.h"
#include <stdio.h>
#include <time.h>

renderqueueClass render;
struct Setting
{
	bool pause = true;	//boolean to pause whats currently being displayed
	double speedFactor = 1; //speed of the polygon
	int mode = 1;	//display mode in 1 2 or 3 defined by keyboard shortcuts to switch

	int windowSizeX = 600; //window size X
	int windowSizeY = 600; //window size Y
	float ptsize = 3;	//point size

	bool colormode = false;	//use mouse menu color mode or randomly given
	double red = 1;		//global colors
	double green = 1;
	double blue = 1;
} set;
float pos[3] = { 0, 1, 0 };
float rot[3] = { 0, 1, 0 };
float camPos[3] = { 0, 5, 10 };

void keyboard(unsigned char key, int x, int y)
{

	/* key presses move the cube, if it isn't at the extents (hard-coded here) */
	switch (key)
	{
	case 'q':
	case 27:
		exit(0);
		break;

	case 'a':
	case 'A':
		if (pos[0] > -4.4)
			pos[0] -= 0.1;
		rot[1] = -90;
		break;

	case 'w':
	case 'W':
		if (pos[2] > -4.4)
			pos[2] -= 0.1;
		rot[1] = 180;
		break;

	case 'd':
	case 'D':
		if (pos[0] < 4.4)
			pos[0] += 0.1;
		rot[1] = 90;
		break;

	case 's':
	case 'S':
		if (pos[2] < 4.4)
			pos[2] += 0.1;
		rot[1] = 0;
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
	if (set.pause == false)
	{
		
	}
	glutTimerFunc(8, timer, 0);
	glutPostRedisplay();
}


/* display function - GLUT display callback function
*		clears the screen, sets the camera position, draws the ground plane and movable box
*/
void display(void)
{
	float origin[3] = { 0, 0, 0 };
	float origin2[3] = { 1, 2, 3 };
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	gluLookAt(camPos[0], camPos[1], camPos[2], 0, 0, 0, 0, 1, 0);
	glColor3f(1, 1, 1);
	
	genplatformClass stuff;
	stuff.draw();
	
	glutSwapBuffers();
}

/* main function - program entry point */
int main(int argc, char** argv)
{
	srand(time(NULL));
	glutInit(&argc, argv);		//starts up GLUT

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);


	glutInitWindowSize(800, 800);
	glutInitWindowPosition(100, 100);

	glutCreateWindow("Assignment 2");	//creates the window

	glutDisplayFunc(display);	//registers "display" as the display callback function
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(special);
	glutTimerFunc(8, timer, 0);
	glEnable(GL_DEPTH_TEST);
	init();

	glutMainLoop();				//starts the event loop

	return(0);					//return may not be necessary on all compilers
}