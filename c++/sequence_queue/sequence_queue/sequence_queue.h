#ifndef SEQUENCE_QUEUE_H
#define SEQUENCE_QUEUE_H
#include<iostream>
using namespace std;
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
// Initialize capacity
#define MAXSIZE 5

typedef int Status;
// Data type
typedef int QElemType;

class SqQueue {
public:
	QElemType data[MAXSIZE];
	// Front pointer
	int front;
	// Rear pointer
	int rear;

	Status visit(QElemType c);
	// Initialize an empty queue
	Status InitQueue();
	// Clear Queue
	Status ClearQueue();
	// If queue is empty,return TRUE,otherwise return FALSE
	Status QueueEmpty();
	// Return element count of queue,exactly is length of the queue
	int QueueLength();
	// If queue is not empty,return head element of queue,then return OK,otherwise return ERROR
	Status GetHead(QElemType *e);
	// If queue is not empty,insert element as new rear element of queue
	Status EnQueue(QElemType e);
	// If queue is not empty,then delete head element of queue,return deleted value
	Status DeQueue(QElemType *e);
	// Traverse queue in turn
	Status QueueTraverse();

};

#endif