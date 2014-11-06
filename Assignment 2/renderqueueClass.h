#include <array>
#include <list>
#include <vector>
#include "shapeObj.h"


class renderqueueClass{
	list<shapeObj> theRenderQueue;
public:
	renderqueueClass();

	void add(array<int, 3> coord, array<int, 4> color, array<int, 3> direction, int shapeType);

	//std::list<shapeObj::iterator begin(void);
	
	/*array<int, 3> getLocation(int index);

	void setLocation(int index, array<int, 3> coord);

	array<int, 3> getDirection(int index);

	void setDirection(int index, array<int, 3> direction);
	
	array<int, 4> getColor(int index);
	
	void setColor(int index, array<int, 4> color);
	
	int getSpeed(int index);
	
	void setSpeed(int index, int speed);
	
	int getSShape(int index);
	
	void setShape(int index, int shapeType);
	
	array<int, 3> getNormal(int index);
	
	void setNormal(int index, array<int, 3> normal);
	
	int size(){ return theRenderQueue.size(); };
	
	bool isEmpty(){ return theRenderQueue.empty(); };*/
	
	void clear();
};