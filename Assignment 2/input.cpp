#include "glutHeader.h"
#ifndef platform
#define platform
using namespace std;
#endif

class genshapeClass{

public:
	genshapeClass(void){}

	void  static drawBox(float* c, float w, float h, float d);

	void  static cube(float v[8][3]);

	void  static drawPolygon(int a, int b, int c, int d, float v[8][3]);
};
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

	case 'y':
	case 'Y':
		if (headRot[1] < 85)
			headRot[1] += 1;
		break;

	case 'u':
	case 'U':
		if (headRot[1] > -85)
			headRot[1] -= 1;
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