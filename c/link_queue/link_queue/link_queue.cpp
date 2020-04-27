#include "stdio.h"    
#include "stdlib.h"   
#include "io.h"  
#include "math.h"  
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
// Define capacity
#define MAXSIZE 20

typedef int Status;
// Define data type
typedef int QElemType;

typedef struct QNode
{
	QElemType data;
	struct QNode *next;
}QNode, *QueuePtr;

typedef struct
{
	QueuePtr front, rear; 
}LinkQueue;

Status visit(QElemType c)
{
	printf("%d ", c);
	return OK;
}

// Construct an empty queue
Status InitQueue(LinkQueue *Q)
{
	Q->front = Q->rear = (QueuePtr)malloc(sizeof(QNode));
	if (!Q->front)
		exit(OVERFLOW);
	Q->front->next = NULL;
	return OK;
}

// Destroy queue
Status DestroyQueue(LinkQueue *Q)
{
	while (Q->front)
	{
		Q->rear = Q->front->next;
		free(Q->front);
		Q->front = Q->rear;
	}
	return OK;
}

// Clear queue
Status ClearQueue(LinkQueue *Q)
{
	QueuePtr p, q;
	Q->rear = Q->front;
	p = Q->front->next;
	Q->front->next = NULL;
	while (p)
	{
		q = p;
		p = p->next;
		free(q);
	}
	return OK;
}

// If Q is empty queue,return TRUE,otherwise return FALSE
Status QueueEmpty(LinkQueue Q)
{
	if (Q.front == Q.rear)
		return TRUE;
	else
		return FALSE;
}

// Get the length of queue
int QueueLength(LinkQueue Q)
{
	int i = 0;
	QueuePtr p;
	p = Q.front;
	while (Q.rear != p)
	{
		i++;
		p = p->next;
	}
	return i;
}

// If queue is not empty,return head element of queue and return OK,otherwise return ERROR
Status GetHead(LinkQueue Q, QElemType *e)
{
	QueuePtr p;
	if (Q.front == Q.rear)
		return ERROR;
	p = Q.front->next;
	*e = p->data;
	return OK;
}

// Insert element as new rear element
Status EnQueue(LinkQueue *Q, QElemType e)
{
	QueuePtr s = (QueuePtr)malloc(sizeof(QNode));
	if (!s)
		exit(OVERFLOW);
	s->data = e;
	s->next = NULL;
	// Assign new node to next of former rear node
	Q->rear->next = s;
	// Assign s to rear node
	Q->rear = s;
	return OK;
}

// If queue is not empty,delete head element of queue,then return deleted value and return OK,otherwise return ERROR
Status DeQueue(LinkQueue *Q, QElemType *e)
{
	QueuePtr p;
	if (Q->front == Q->rear)
		return ERROR;
	p = Q->front->next;		
	*e = p->data;
	Q->front->next = p->next;
	// Judge if the first node is rear
	if (Q->rear == p)
		Q->rear = Q->front;
	free(p);
	return OK;
}

// Traverse every element from front to rear in turn
Status QueueTraverse(LinkQueue Q)
{
	QueuePtr p;
	p = Q.front->next;
	while (p)
	{
		visit(p->data);
		p = p->next;
	}
	printf("\n");
	return OK;
}

int main()
{
	int i;
	QElemType d;
	LinkQueue q;
	i = InitQueue(&q);
	if (i)
		printf("Construct an empty queue!\n");
	printf("If queue is empty? %d(1:Empty 0:Not Empty)\n", QueueEmpty(q));
	printf("Queue length is %d\n", QueueLength(q));
	EnQueue(&q, -5);
	EnQueue(&q, 5);
	EnQueue(&q, 10);
	printf("After inserting 3 element(-5,5,10),Queue length is %d\n", QueueLength(q));
	printf("If queue is empty?%d(1:Empty 0:Not Empty)\n", QueueEmpty(q));
	printf("Elements of queue are in order:");
	QueueTraverse(q);
	i = GetHead(q, &d);
	if (i == OK)
		printf("Head element of queue is:%d\n", d);
	DeQueue(&q, &d);
	printf("After deleting head element of queue%d\n", d);
	i = GetHead(q, &d);
	if (i == OK)
		printf("New head element of queue is:%d\n", d);
	ClearQueue(&q);
	printf("After clearing queue,q.front=%u q.rear=%u q.front->next=%u\n", q.front, q.rear, q.front->next);
	printf("Queue length is %d\n", QueueLength(q));
	DestroyQueue(&q);
	printf("After destroying,q.front=%u q.rear=%u\n", q.front, q.rear);
	printf("Queue length is %d\n", QueueLength(q));
	system("pause");
	return 0;
}