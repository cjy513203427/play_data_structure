// define stack node
function StackNode(props){
    this.data = props.data || 0
    this.next = null
}

// define link stack
function LinkStack(props){
    this.count = 0
    this.top = new StackNode({})
}

LinkStack.prototype.visit=function(element){
    process.stdout.write(element + ' ')
}

// Construct an empty stack
LinkStack.prototype.InitStack = function(){
    this.top = new StackNode({})
	if (!this.top)
		return false
    this.top = null
    this.count = 0
	return true
}

// Set S an empty stack
LinkStack.prototype.ClearStack = function()
{
	var p, q
	p = this.top
	while (p)
	{
		q = p
        p = p.next
	}
	this.count = 0
	return true
}

// If stack is empty,return TRUE,otherwise return FALSE
LinkStack.prototype.StackEmpty = function()
{
	if (this.count == 0)
		return true
	else
		return false
}

// Return number of element,exactly is length of stack
LinkStack.prototype.StackLength = function()
{
	return this.count
}

// If stack is not empty,return top element of stack,then return OK,otherwise return FALSE
LinkStack.prototype.GetTop = function()
{
	if (this.top == null)
		return false
	else
		e = this.top.data
	return true
}

// Insert element as new top element of stack
LinkStack.prototype.Push = function(e)
{
	s = new StackNode({})
	s.data = e
	// Assign top element to next of new node
	s.next = this.top
	// Assign new node to the top pointer
	this.top = s
	this.count++
	return true
}

// If stack is not empty,delete top element of S,return deleted element,then return OK,otherwise return ERROR
LinkStack.prototype.Pop = function()
{
	var p
	if (ls.StackEmpty())
		return false
	e = this.top.data
	// Assign top node to pc
	p = this.topc
	// Let top pointer minus 1,it points to next node
	this.top = this.top.next
	this.count--
	return e;
}

LinkStack.prototype.StackTraverse = function()
{
	var p;
	p = this.top;
	while (p)
	{
		ls.visit(p.data);
		p = p.next;
	}
	console.log()
	return true;
}

var ls = new LinkStack({})
ls.InitStack()
var j
var e
if (ls.InitStack() == true)
	for (j = 1; j <= 10; j++)
		ls.Push(j)
console.log("Elements of stack are in turn：");
ls.StackTraverse(s)
ls.Pop()
console.log("Popped top element is e=%d\n", e)
console.log("If stack is empty:%d(1:Empty 0:Not Empty)\n", ls.StackEmpty())
ls.GetTop()
console.log("Top element is e=%d Length of stack is %d\n", e, ls.StackLength(s))
ls.ClearStack();
console.log("After clearing stack,if stack is empty:%d(1:Empty 0:Not Empty)\n", ls.StackEmpty(s))
