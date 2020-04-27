var MAXSIZE = 20

function SqDoubleStack(props){
    this.data = new Array(MAXSIZE)
    this.top1 = props.top1||-1
    this.top2 = props.top2||MAXSIZE
}

SqDoubleStack.prototype.visit = function(element){
    process.stdout.write(element + ' ')
    return true
}

// Construct an empty stack
SqDoubleStack.prototype.InitStack = function(){
	this.top1 = -1
	this.top2 = MAXSIZE
	return true
}

// Set S empty stack
SqDoubleStack.prototype.ClearStack = function() {
	this.top1 = -1;
	this.top2 = MAXSIZE
	return true
}


// If s is an empty stack,return true,otherwise return false
SqDoubleStack.prototype.StackEmpty = function() {
	if (this.top1 == -1 && this.top2 == MAXSIZE)
		return true
	else
		return false
}

// Return number of element,exactly is length of stack
SqDoubleStack.prototype.StackLength = function() {
	return (this.top1 + 1) + (MAXSIZE - this.top2)
}

// Insert e as new top element
SqDoubleStack.prototype.Push = function(e,stackNumber) {
	// If stack is full
    if (this.top1 + 1 == this.top2)
		return false;
	// Push element to stack1
	if (stackNumber == 1)
		this.data[++this.top1] = e
	// Push element to stack2
	else if (stackNumber == 2)
        this.data[--this.top2] = e
	return true;
}


// If stack is not empty,then delete top element of S,return deleted element and OK,otherwise return ERROR
SqDoubleStack.prototype.Pop = function(stackNumber) {
	if (stackNumber == 1)
	{
		// If stack1 is empty
		if (this.top1 == -1)
			return ERROR;
		// Pop element from stack1
		e = this.data[this.top1--];
	}
	else if (stackNumber == 2)
	{
		// If stack2 is empty
		if (this.top2 == MAXSIZE)
			return ERROR;
		// Pop element from stack2
		e = this.data[this.top2++];
	}
	return e;
}



SqDoubleStack.prototype.StackTraverse = function() {
	var i;
	i = 0;
	while (i <= this.top1)
	{
		this.visit(this.data[i++]);
	}
	i = this.top2;
	while (i<MAXSIZE)
	{
		this.visit(this.data[i++]);
	}
	console.log("");
	return true;
}

var ds = new SqDoubleStack({})
var j;
var e;
if (ds.InitStack() == true)
{
    for (j = 1; j <= 5; j++)
        ds.Push(j, 1);
    for (j = MAXSIZE; j >= MAXSIZE - 2; j--)
        ds.Push(j, 2);
}

console.log("Elements of stack are in turn:");
ds.StackTraverse();

console.log("Length of stack is:%d \n", ds.StackLength());

e = ds.Pop(2);
console.log("Popped element is e=%d\n", e);
console.log("If stack is empty:%d(1:Empty 0:Not empty)\n", ds.StackEmpty());

for (j = 6; j <= MAXSIZE - 2; j++)
    ds.Push(j, 1);

console.log("Elements of stack are in turn:");
ds.StackTraverse();

ds.Pop(1);
ds.Push(100, 1);
ds.StackTraverse();

ds.ClearStack();
console.log("After clearing stack,if stack is empty:%d(1:Empty 0:Not Empty)\n", ds.StackEmpty());