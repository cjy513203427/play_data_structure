# -*- encoding: utf-8 -*-
'''
@File    :   sequence_stack.py    
@Modify Time      @Author       @Description
------------      -------       -----------
2020/3/31 16:45   Jonas           None
'''
import numpy as np

MAXSIZE = 20


class SqStack(object):
    def __init__(self):
        self.data = np.zeros(MAXSIZE)
        self.top = -1

    def visit(self, element):
        print(element, end=" ")
        return True

    # Construct an empty stack
    def InitStack(self):
        self.top = -1
        return True

    # Clear stack
    def ClearStack(self):
        self.top = -1
        return True

    # If stack is empty stack,then return true,otherwise return false
    def StackEmpty(self):
        if self.top == -1:
            return True
        else:
            return False

    # Return number of element,exactly it is length of stack
    def StackLength(self, S):
        return S.top + 1

    # If stack is not empty,return top element of stack,then return OK,otherwise return ERROR
    def GetTop(self):
        if self.top == -1:
            return False
        else:
            e = self.data[self.top]
            return e

    # Insert new element
    def Push(self, e):
        # If stack is full
        if self.top == MAXSIZE - 1:
            return False
        else:
            # Stack top plus 1
            self.top += 1
            # Assign value to element of stack top
            self.data[self.top] = e
            return True

    # If Stack is not empty,then delete element of stack top,return deleted element and OK,otherwise return ERROR
    def Pop(self):
        if self.top == -1:
            return False

        else:
            # Assign element of stack top to e
            e = self.data[self.top]
            # Stack top minus 1
            self.top -= 1
            return e

    # Traverse element from bottom of stack to top of stack
    def StackTraverse(self):
        i = 0
        while i <= self.top:
            self.visit(self.data[i])
            i += 1
        print()
        return True


if __name__ == '__main__':
    ss = SqStack()
    if ss.InitStack() == True:
        for j in range(1,11):
            ss.Push(j)

    print("Elements of stack are:")
    ss.StackTraverse()
    e = ss.Pop()
    print("Popped element of stack top is e=%d" %e);
    print("If Stack is empty:%d(1:Empty 0:Not empty)" %ss.StackEmpty());
    ss.GetTop();
    print("Element of stack top is e=%d\nLength of stack is %d" %(e, ss.StackLength(ss)));
    ss.ClearStack();
    print("After Clearing stack,If Stack is empty:%d(1:Empty 0:Not empty)" %ss.StackEmpty());