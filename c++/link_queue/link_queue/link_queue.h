#ifndef LINK_QUEUE_H
#define LINK_QUEUE_H
#include<iostream>
#include "node.h"
using namespace std;
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
// Define capacity
#define MAXSIZE 20

typedef int Status;
// Define data type
typedef int QElemType;

class LinkQueue {
public:
	QNode * front;
	QNode * rear;
	Status visit(QElemType c);
	// Construct an empty queue
	Status InitQueue();
	// Destroy queue
	Status DestroyQueue();
	// Clear queue
	Status ClearQueue();
	// If Q is empty queue,return TRUE,otherwise return FALSE
	Status QueueEmpty();
	// Get the length of queue
	int QueueLength();
	// If queue is not empty,return head element of queue and return OK,otherwise return ERROR
	Status GetHead(QElemType *e);
	// Insert element as new rear element
	Status EnQueue(QElemType e);
	// If queue is not empty,delete head element of queue,then return deleted value and return OK,otherwise return ERROR
	Status DeQueue(QElemType *e);
	// Traverse every element from front to rear in turn
	Status QueueTraverse();
};

#endif