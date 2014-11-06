#include <vector>
#include <array>
#include "renderqueueClass.h"

renderqueueClass::renderqueueClass(void){};

void renderqueueClass::add(array<int, 3> coord, array<int, 4> color, array<int, 3> direction, int shapeType){
	theRenderQueue.push_back(shapeObj());
	theRenderQueue.back().coordinate = coord;
	theRenderQueue.back().color = color;
	theRenderQueue.back().direction = direction;
	theRenderQueue.back().shapeType = shapeType;
}



//array<int, 3> renderqueueClass::getLocation(int index){
//	return theRenderQueue[index].coordinate;;
//}
//
//void renderqueueClass::setLocation(int index, array<int, 3> coord){
//	theRenderQueue[index].coordinate = coord;
//}
//
//array<int, 3> renderqueueClass::getDirection(int index){
//	return theRenderQueue[index].direction;;
//}
//
//void renderqueueClass::setDirection(int index, array<int, 3> direction){
//	theRenderQueue[index].direction = direction;
//}
//
//void renderqueueClass::setColor(int index, array<int, 4> color){
//	theRenderQueue[index].color = color;
//}
//
//array<int, 4> renderqueueClass::getColor(int index){
//	return theRenderQueue[index].color;
//}
//
//void renderqueueClass::setSpeed(int index, int speed){
//	theRenderQueue[index].speed = speed;
//}
//
//int renderqueueClass::getSpeed(int index){
//	return theRenderQueue[index].speed;
//}
//
//void renderqueueClass::setShape(int index, int shapeType){
//	theRenderQueue[index].shapeType = shapeType;
//}
//
//int renderqueueClass::getSShape(int index){
//	return theRenderQueue[index].shapeType;
//}
//
//void renderqueueClass::setNormal(int index, array<int, 3> normal){
//	theRenderQueue[index].normal = normal;
//}
//
//array<int, 3> renderqueueClass::getNormal(int index){
//	return theRenderQueue[index].normal;
//}
//
//void renderqueueClass::clear(void){
//	theRenderQueue.clear();
//}