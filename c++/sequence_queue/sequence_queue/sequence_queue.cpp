#include"sequence_queue.h"

Status SqQueue::visit(QElemType c)
{
	cout<<c<<" ";
	return OK;
}

// Initialize an empty queue
Status SqQueue::InitQueue()
{
	this->front = 0;
	this->rear = 0;
	return  OK;
}


// Clear Queue
Status SqQueue::ClearQueue()
{
	this->front = this->rear = 0;
	return OK;
}

// If queue is empty,return TRUE,otherwise return FALSE
Status SqQueue::QueueEmpty()
{
	// If the queue is empty
	if (this->front == this->rear)
		return TRUE;
	else
		return FALSE;
}

// Return element count of queue,exactly is length of the queue
int SqQueue::QueueLength()
{
	return  (this->rear - this->front + MAXSIZE) % MAXSIZE;
}

// If queue is not empty,return head element of queue,then return OK,otherwise return ERROR
Status SqQueue::GetHead(QElemType *e)
{
	// If the queue is empty
	if (this->front == this->rear)
		return ERROR;
	*e = this->data[this->front];
	return OK;
}

// If queue is not empty,insert element as new rear element of queue
Status SqQueue::EnQueue(QElemType e)
{
	// If queue is full
	if ((this->rear + 1) % MAXSIZE == this->front)
		return ERROR;
	this->data[this->rear] = e;
	// Rear++,if rear is more than last position,return to the first position
	this->rear = (this->rear + 1) % MAXSIZE;
	return  OK;
}

// If queue is not empty,then delete head element of queue,return deleted value
Status SqQueue::DeQueue( QElemType *e)
{
	// If queue is empty
	if (this->front == this->rear)
		return ERROR;
	*e = this->data[this->front];
	// Front++,if front is more than last position,return to the first position
	this->front = (this->front + 1) % MAXSIZE;
	return  OK;
}

// Traverse queue in turn
Status SqQueue::QueueTraverse()
{
	int i;
	i = this->front;
	for (i = this->front; i < QueueLength() + this->front; i++) {
		visit(this->data[i%MAXSIZE]);
	}
	cout << endl;
	return OK;
}

int main()
{
	Status j;
	int i = 0, l;
	QElemType d;
	SqQueue Q;
	Q.InitQueue();
	printf("After initializing queue,if queue is empty? %u(1:Empty 0:Not empty)\n", Q.QueueEmpty());
	for (l = 1; l < 6; l++) {
		Q.EnQueue(l);
	}
	printf("Traverse in order:\n");
	Q.QueueTraverse();
	printf("After EnQueue,if queue is empty? %u(1:Empty 0:Not empty)\n", Q.QueueEmpty());
	printf("Queue length is:%d\n", Q.QueueLength());
	Q.DeQueue(&d);
	Q.DeQueue(&d);
	Q.DeQueue(&d);
	Q.EnQueue(1);
	Q.EnQueue(2);
	printf("Traverse in order:\n");
	Q.QueueTraverse();
	Q.GetHead(&d);
	printf("Head element is:%d\n", d);
	printf("Queue length is:%d\n", Q.QueueLength());
	Q.ClearQueue();
	printf("After clearing queue,if queue is empty? %u(1:Empty 0:Not empty)\n", Q.QueueEmpty());
	system("pause");
	return 0;
}