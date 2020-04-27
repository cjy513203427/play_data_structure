function QNode(props){
    this.data = props.data
    this.next = props.next
}

function LinkQueue(props){
    this.front = new QNode({})
    this.rear = new QNode({})
}

LinkQueue.prototype.visit=function(element){
    process.stdout.write(element + ' ')
}

// Construct an empty queue
LinkQueue.prototype.InitQueue = function(){
    this.front = this.rear = new QNode({})
	if (!this.front)
		return false
    this.front.next = null
    return true
}

// Destroy queue
LinkQueue.prototype.DestroyQueue = function()
{
	while (this.front)
	{
		this.rear = this.front.next
		this.front = this.rear
	}
	return true
}

// Clear queue
LinkQueue.prototype.ClearQueue = function()
{
	var p, q
	this.rear = this.front
	p = this.front.next
	this.front.next = null
	while (p)
	{
		q = p
		p = p.next
		q = null
	}
	return true
}

// If it is empty queue,return TRUE,otherwise return FALSE
LinkQueue.prototype.QueueEmpty = function()
{
	if (this.front == this.rear)
		return true
	else
		return false
}

// Get the length of queue
LinkQueue.prototype.QueueLength = function()
{
	var i = 0
	var p
	p = this.front
	while (this.rear != p)
	{
		i++
		p = p.next
	}
	return i
}

// If queue is not empty,return head element of queue and return OK,otherwise return ERROR
LinkQueue.prototype.GetHead = function()
{
	var p
	if (this.front == this.rear)
		return false
	p = this.front.next
	e = p.data
    return e
}

// Insert element as new rear element
LinkQueue.prototype.EnQueue = function(e)
{
	var s = new QNode({})
	if (!s)
		return false
	s.data = e
	s.next = null
	// Assign new node to next of former rear node
	this.rear.next = s
	// Assign s to rear node
	this.rear = s
	return true
}

// If queue is not empty,delete head element of queue,then return deleted value,otherwise return false
LinkQueue.prototype.DeQueue = function(e)
{
	var p
	if (this.front == this.rear)
		return false
	p = this.front.next
	e = p.data
	this.front.next = p.next
	// Judge if the first node is rear
	if (this.rear == p)
        this.rear = this.front
	return e
}

// Traverse every element from front to rear in turn
LinkQueue.prototype.QueueTraverse = function()
{
	var p
	p = this.front.next
	while (p)
	{
		this.visit(p.data)
		p = p.next
	}
    console.log()
	return true
}

var lq = new LinkQueue({})
var i = lq.InitQueue()
if (i)
    console.log("Construct an empty queue!\n")
console.log("If queue is empty? \n", lq.QueueEmpty())
console.log("Queue length is %d\n", lq.QueueLength())
lq.EnQueue(-5)
lq.EnQueue(5)
lq.EnQueue(10)
console.log("After inserting 3 element(-5,5,10),Queue length is %d\n" ,lq.QueueLength())
console.log("If queue is empty?\n", lq.QueueEmpty())
console.log("Elements of queue are in order:")
lq.QueueTraverse()
d = lq.GetHead()
if (i == true)
    console.log("Head element of queue is:%d\n", d)
dq = lq.DeQueue()
console.log("After deleting head element of queue,deleted element is %d\n", dq)
i = lq.GetHead()
if (i == true)
    console.log("New head element of queue is:%d\n", d)
lq.ClearQueue()
console.log("After clearing queue,q.front=%d q.rear=%d q.front->next=%d\n", lq.front, lq.rear, lq.front.next)
console.log("Queue length is %d\n", lq.QueueLength())
lq.DestroyQueue()
console.log("After destroying,q.front=%d q.rear=%d\n", lq.front, lq.rear)
console.log("Queue length is %d\n", lq.QueueLength())