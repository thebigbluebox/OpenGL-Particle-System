#include "genplatformClass.h"
#include "genshapeClass.h"

using namespace std;

void genplatformClass::draw(void){
	float coord[3] = { 0, 0, 0 };	
	genshapeClass::drawBox(coord, 20, 1, 20);
}

