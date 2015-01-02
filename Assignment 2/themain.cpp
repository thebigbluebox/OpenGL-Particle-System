#include "glutHeader.h"
#include "particleWorld.h"
#include "genplatformClass.h"
#include <stdio.h>
#include <time.h>

particleWorld render;
bool pause = true;	//boolean to pause whats currently being displayed
GLdouble camPos[3] = { 0, 5, 10 };
GLdouble origin[3] = { 0, 0, 0 };

void keyboard(unsigned char key, int x, int y)
{
	GLdouble point[3] = { render.getLocationx(), render.getLocationy(), render.getLocationz() };
	switch (key)
	{
	case 'q':
	case 27:
		exit(0);
		break;
	case 'p':
	case 'P':
		if (pause){
			pause = false;
		}
		else{
			pause = true;
		}
		break;
	case 'w':
	case 'W':
		point[2] += 1;
		render.setLocation(point[0],point[1],point[2]);
		break;	
	case 'a':
	case 'A':
		point[0] -= 1;
		render.setLocation(point[0], point[1], point[2]);
		break;
	case 's':
	case 'S':
		point[2] -= 1;
		render.setLocation(point[0], point[1], point[2]);
		break;
	case 'd':
	case 'D':
		
		point[0] += 1;
		render.setLocation(point[0], point[1], point[2]);
		break;
	case 'f':
	case 'F':
		render.frictionMode();
		break;
	case '=':
	case '+':
		render.increaseSize();
		break;
	case '-':
	case '_':
		render.decreaseSize();
		break;
	case '{':
	case '[':
		render.increaseSpeed();
		break;
	case '}':
	case ']':
		render.decreaseSpeed();
		break;
	case ' ':
		render.reset();
		break;
	case '1':
		render.setShape(1);
		break;
	case '2':
		render.setShape(2);
		break;
	case '3':
		render.setShape(3);
		break;
	case '4':
		render.setShape(4);
		break;
	case '5':
		render.snowMode();
		break;
	case '6':
		render.windMode();
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
	if(pause){
		render.addRandom();
		render.updateAll();
	}
	glutPostRedisplay();
	glutTimerFunc(30, timer, 0);
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
void printhelp(void)
{
	printf("Key | Function\n");
	printf("== == == == == == == == == =\n");
	printf("1 | Mode 1 Cubes\n");
	printf("2 | Mode 2 Spheres\n");
	printf("3 | Mode 3 Teapots\n");
	printf("4 | Mode 4 Torus\n");
	printf("5 | Toggle Snow Mode\n");
	printf("6 | Toggle Wind Mode\n");
	printf("- | Decrease size\n");
	printf("+ | Increase size\n");
	printf("[ | Decrease gravity\n");
	printf("] | Increase gravity\n");
	printf("q | Exit\n");
	printf("w | Moves Particle Gen up\n");
	printf("a | Moves Particle Gen left\n");
	printf("s | Moves Particle Gen down\n");
	printf("d | Moves Particle Gen right\n");
	printf("up | Moves camera up\n");
	printf("down | Moves camera left\n");
	printf("left | Moves camera down\n");
	printf("right | Moves camera right\n");
	printf("home | Moves camera height up\n");
	printf("end | Moves camera height down\n");
	printf("r | Reset / Clear\n");
	printf("SPACE | Clears Queue\n");
}
/* main function - program entry point */
int main(int argc, char** argv)
{
	printhelp();
	srand(time(NULL));
	for (int i = 0; i < 40; i++){
		render.addRandom();
	}
	
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
