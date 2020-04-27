#include"link_queue.h"

Status LinkQueue::visit(QElemType c) {
	cout << c << " ";
	return OK;
}

// Construct an empty queue
Status LinkQueue::InitQueue() {
	this->front = this->rear = new QNode();
	if (!this->front)
		exit(OVERFLOW);
	this->front->next = NULL;
	return OK;
}

// Destroy queue
Status LinkQueue::DestroyQueue()
{
	while (this->front)
	{
		this->rear = this->front->next;
		free(this->front);
		this->front = this->rear;
	}
	return OK;
}

// Clear queue
Status LinkQueue::ClearQueue()
{
	QNode * p;
	QNode * q;
	this->rear = this->front;
	p = this->front->next;
	this->front->next = NULL;
	while (p)
	{
		q = p;
		p = p->next;
		free(q);
	}
	return OK;
}

// If Q is empty queue,return TRUE,otherwise return FALSE
Status LinkQueue::QueueEmpty()
{
	if (this->front == this->rear)
		return TRUE;
	else
		return FALSE;
}

// Get the length of queue
int LinkQueue::QueueLength()
{
	int i = 0;
	QNode * p;
	p = this->front;
	while (this->rear != p)
	{
		i++;
		p = p->next;
	}
	return i;
}


// If queue is not empty,return head element of queue and return OK,otherwise return ERROR
Status LinkQueue::GetHead(QElemType *e)
{
	QNode * p;
	if (this->front == this->rear)
		return ERROR;
	p = this->front->next;
	*e = p->data;
	return OK;
}

// Insert element as new rear element
Status LinkQueue::EnQueue(QElemType e)
{
	QNode* s = new QNode();
	if (!s)
		exit(OVERFLOW);
	s->data = e;
	s->next = NULL;
	// Assign new node to next of former rear node
	this->rear->next = s;
	// Assign s to rear node
	this->rear = s;
	return OK;
}

// If queue is not empty,delete head element of queue,then return deleted value and return OK,otherwise return ERROR
Status LinkQueue::DeQueue(QElemType *e)
{
	QNode* p;
	if (this->front == this->rear)
		return ERROR;
	p = this->front->next;
	*e = p->data;
	this->front->next = p->next;
	// Judge if the first node is rear
	if (this->rear == p)
		this->rear = this->front;
	free(p);
	return OK;
}

// Traverse every element from front to rear in turn
Status LinkQueue::QueueTraverse()
{
	QNode* p;
	p = this->front->next;
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
	i = q.InitQueue();
	if (i)
		printf("Construct an empty queue!\n");
	printf("If queue is empty? %d(1:Empty 0:Not Empty)\n", q.QueueEmpty());
	printf("Queue length is %d\n", q.QueueLength());
	q.EnQueue(-5);
	q.EnQueue(5);
	q.EnQueue(10);
	printf("After inserting 3 element(-5,5,10),Queue length is %d\n", q.QueueLength());
	printf("If queue is empty?%d(1:Empty 0:Not Empty)\n", q.QueueEmpty());
	printf("Elements of queue are in order:");
	q.QueueTraverse();
	i = q.GetHead(&d);
	if (i == OK)
		printf("Head element of queue is:%d\n", d);
	q.DeQueue(&d);
	printf("After deleting head element of queue%d\n", d);
	i = q.GetHead(&d);
	if (i == OK)
		printf("New head element of queue is:%d\n", d);
	q.ClearQueue();
	printf("After clearing queue,q.front=%u q.rear=%u q.front->next=%u\n", q.front, q.rear, q.front->next);
	printf("Queue length is %d\n", q.QueueLength());
	q.DestroyQueue();
	printf("After destroying,q.front=%u q.rear=%u\n", q.front, q.rear);
	printf("Queue length is %d\n", q.QueueLength());
	system("pause");
	return 0;
}