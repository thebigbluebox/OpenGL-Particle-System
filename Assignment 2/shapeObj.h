#ifndef shapeObjs
#define shapeObjs
using namespace std;

struct shapeObj{
	array<int, 3> coordinate;
	array<int, 4> color;
	array<int, 3> direction;
	array<int, 3> normal = { { 1, 1, 1 } }; //object's up
	float speed = 1;
	bool visible;
	int shapeType = 0;
};
#endif