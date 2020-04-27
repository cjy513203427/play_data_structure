#include "stdio.h"    
#include "stdlib.h"   
#include "io.h"  
#include "math.h"  
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
// Initialize capacity
#define MAXSIZE 5

typedef int Status;
// Data type
typedef int QElemType;

// Sequence structure of round-robin queue
typedef struct
{
	QElemType data[MAXSIZE];
	// Front pointer
	int front;
	// Rear pointer
	int rear;
}SqQueue;

Status visit(QElemType c)
{
	printf("%d ", c);
	return OK;
}

// Initialize an empty queue
Status InitQueue(SqQueue *Q)
{
	Q->front = 0;
	Q->rear = 0;
	return  OK;
}

// Clear Queue
Status ClearQueue(SqQueue *Q)
{
	Q->front = Q->rear = 0;
	return OK;
}

// If queue is empty,return TRUE,otherwise return FALSE
Status QueueEmpty(SqQueue Q)
{
	// If the queue is empty
	if (Q.front == Q.rear)
		return TRUE;
	else
		return FALSE;
}

// Return element count of queue,exactly is length of the queue
int QueueLength(SqQueue Q)
{
	return  (Q.rear - Q.front + MAXSIZE) % MAXSIZE;
}

// If queue is not empty,return head element of queue,then return OK,otherwise return ERROR
Status GetHead(SqQueue Q, QElemType *e)
{
	// If the queue is empty
	if (Q.front == Q.rear)
		return ERROR;
	*e = Q.data[Q.front];
	return OK;
}

// If queue is not empty,insert element as new rear element of queue
Status EnQueue(SqQueue *Q, QElemType e)
{
	// If queue is full
	if ((Q->rear + 1) % MAXSIZE == Q->front)
		return ERROR;
	Q->data[Q->rear] = e;
	// Rear++,if rear is more than last position,return to the first position
	Q->rear = (Q->rear + 1) % MAXSIZE;
	return  OK;
}

// If queue is not empty,then delete head element of queue,return deleted value
Status DeQueue(SqQueue *Q, QElemType *e)
{
	// If queue is empty
	if (Q->front == Q->rear)
		return ERROR;
	*e = Q->data[Q->front];
	// Front++,if front is more than last position,return to the first position
	Q->front = (Q->front + 1) % MAXSIZE;
	return  OK;
}

// Traverse queue in turn
Status QueueTraverse(SqQueue Q)
{
	int i;
	i = Q.front;
	for (i =Q.front; i < QueueLength(Q) + Q.front; i++) {
		visit(Q.data[i%MAXSIZE]);
	}
	printf("\n");
	return OK;
}

int main()
{
	Status j;
	int i = 0,l;
	QElemType d;
	SqQueue Q;
	InitQueue(&Q);
	printf("After initializing queue,if queue is empty? %u(1:Empty 0:Not empty)\n", QueueEmpty(Q));
	for (l = 1; l < 6; l++) {
		EnQueue(&Q,l);
	}
	printf("Traverse in order:\n");
	QueueTraverse(Q);
	printf("Queue length is:%d\n", QueueLength(Q));
	DeQueue(&Q, &d);
	DeQueue(&Q, &d);
	DeQueue(&Q, &d);
	EnQueue(&Q, 1);
	EnQueue(&Q, 2);
	printf("Traverse in order:\n");
	QueueTraverse(Q);
	GetHead(Q, &d);
	printf("Head element is:%d\n", d);
	printf("Queue length is:%d\n", QueueLength(Q));
	ClearQueue(&Q);
	printf("After clearing queue,if queue is empty? %u(1:Empty 0:Not empty)\n", QueueEmpty(Q));
	system("pause");
	return 0;
}
