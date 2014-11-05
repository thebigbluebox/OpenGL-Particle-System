#include <iostream>
#include <cstddef>
#include "shapeObj.h"

using std::cout;
using std::endl;

class Node
{
	friend class LinkedList;
private:
	shapeObj _data; 
	Node *_next;

public:
	Node(void): _next(NULL){ }

	Node(shapeObj val): _data(val), _next(NULL){ }

	Node(shapeObj val, Node* next): _data(val), _next(next){}

	shapeObj getValue(void)
	{
		return _data;
	}

	Node* getNext(void)
	{
		return _next;
	}
};

class LinkedList
{
private:
	Node *_pHead;
	Node *_pTail;

public:
	
	LinkedList(void);
	
	LinkedList(shapeObj val);

	~LinkedList(void);
	
	void deleteNode(Node ptr);
	
	void insert(shapeObj val);

};

LinkedList::LinkedList()
{
	_pHead = _pTail = NULL;
}

LinkedList::LinkedList(shapeObj val)
{
	_pHead = new Node(val);
	_pTail = _pHead;
}

void LinkedList::insert(shapeObj val)
{
	Node data = Node(val);
	data._next = _pHead;
}

void LinkedList::deleteNode(Node ptr){
	Node next = ptr.getNext;
	
}