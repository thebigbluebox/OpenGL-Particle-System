using namespace std;
//this class defines the functions needed to create the platform of particle world
class genshapeClass{

public:
	genshapeClass(void){}

	void  static drawBox(float* c, float w, float h, float d);

	void  static cube(float v[8][3]);

	void  static drawPolygon(int a, int b, int c, int d, float v[8][3]);
};
