var MAXSIZE = 20

function SqStack(props) {
    this.data = new Array(MAXSIZE)
    this.top =  -1 || props.top
}

SqStack.prototype.visit = function (element) {
    process.stdout.write(element + ' ')
    return true
}

// Construct an empty stack
SqStack.prototype.InitStack = function (S) {
    S.top = -1
    return true
}

// Clear stack
SqStack.prototype.ClearStack = function (S) {
    S.top = -1
    return true
}

// If stack is empty stack,then return true,otherwise return false
SqStack.prototype.StackEmpty = function (S) {
    if (S.top == -1)
        return true
    else
        return false
}

// Return number of element,exactly it is length of stack
SqStack.prototype.StackLength = function (S) {
    return S.top + 1
}

// If stack is not empty,return top element of stack,then return OK,otherwise return ERROR
SqStack.prototype.GetTop = function (S) {
    if (S.top == -1)
        return false
    else
        e = S.data[S.top]
    return e;
}

// Insert new element
SqStack.prototype.Push = function (S, e) {
    // If stack is full
    if (S.top == MAXSIZE - 1)
        return false

    // Stack top plus 1
    S.top++
    // Assign value to element of stack top
    S.data[S.top] = e
    return true;
}

// If Stack is not empty,then delete element of stack top,return deleted element and OK,otherwise return ERROR
SqStack.prototype.Pop = function (S) {
    if (S.top == -1)
        return ERROR

    // Assign element of stack top to e
    e = S.data[S.top]
    // Stack top minus 1
    S.top--
    return e;
}

// Traverse element from bottom of stack to top of stack
SqStack.prototype.StackTraverse=function(S) {
	var i
	i = 0
	while (i<=S.top)
	{
		ss.visit(S.data[i++])
	}
	return true
}

var ss = new SqStack()

    
var j,e
if(ss.InitStack(ss) == true)
    for(j=1;j<=10;j++)
        ss.Push(ss,j)
console.log("Elements of stack are:")
ss.StackTraverse(ss)
ss.Pop(ss)
console.log("Popped element of stack top is e=%d\n", e);
console.log("If Stack is empty:%d(1:Empty 0:Not empty)\n", ss.StackEmpty(ss));
ss.GetTop(ss);
console.log("Element of stack top is e=%d Length of stack is %d\n", e, ss.StackLength(ss));
ss.ClearStack(ss);
console.log("After Clearing stack,If Stack is empty:%d(1:Empty 0:Not empty)\n", ss.StackEmpty(ss));