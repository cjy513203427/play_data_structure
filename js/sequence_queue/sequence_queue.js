var MAXSIZE = 5
function SqQueue(props) {
    this.data = new Array(MAXSIZE)
    this.front = props.front || 0
    this.rear = props.rear || 0
}

SqQueue.prototype.visit = function (element) {
    process.stdout.write(element + ' ')
    return true
}

// Initialize an empty queue
SqQueue.prototype.InitQueue = function () {
    this.front = 0
    this.rear = 0
    return true
}

// Clear Queue
SqQueue.prototype.ClearQueue = function () {
    this.front = this.rear = 0
    return true
}

// If queue is empty,return TRUE,otherwise return FALSE
SqQueue.prototype.QueueEmpty = function () {
    // If the queue is empty
    if (this.front == this.rear)
        return true
    else
        return false
}

// Return element count of queue,exactly is length of the queue
SqQueue.prototype.QueueLength = function () {
    return (this.rear - this.front + MAXSIZE) % MAXSIZE
}


// If queue is not empty,return head element of queue,otherwise return false
SqQueue.prototype.GetHead = function () {
    // If the queue is empty
    if (this.front == this.rear)
        return false
    e = this.data[this.front]
    return e
}

// If queue is not empty,insert element as new rear element of queue
SqQueue.prototype.EnQueue = function (e) {
    // If queue is full
    if ((this.rear + 1) % MAXSIZE == this.front)
        return false
    this.data[this.rear] = e
    // Rear++,if rear is more than last position,return to the first position
    this.rear = (this.rear + 1) % MAXSIZE
    return true
}

// If queue is not empty,then delete head element of queue,return deleted value
SqQueue.prototype.DeQueue = function()
{
	// If queue is empty
	if (this.front == this.rear)
		return false
	e = this.data[this.front]
	// Front++,if front is more than last position,return to the first position
	this.front = (this.front + 1) % MAXSIZE
	return true
}

// Traverse queue in turn
SqQueue.prototype.QueueTraverse = function()
{
	var i
	for (i =this.front;i < sq.QueueLength() + this.front;i++) {
		sq.visit(this.data[i%MAXSIZE])
	}
	console.log()
	return true
}

var sq = new SqQueue({})
sq.InitQueue()
console.log("After initializing queue,if queue is empty? %d(1:Empty 0:Not empty)\n", sq.QueueEmpty())
for (l = 1;l < 6;l++) {
    sq.EnQueue(l)
}
console.log("Traverse in order:\n")
sq.QueueTraverse()
console.log("Queue length is:%d\n", sq.QueueLength())
sq.DeQueue()
sq.DeQueue()
sq.DeQueue()
sq.EnQueue(1)
sq.EnQueue(2)
console.log("Traverse in order:\n")
sq.QueueTraverse()
d = sq.GetHead()
console.log("Head element is:%d\n", d)
console.log("Queue length is:%d\n", sq.QueueLength())
sq.ClearQueue()
console.log("After clearing queue,if queue is empty? %d(1:Empty 0:Not empty)\n", sq.QueueEmpty())
