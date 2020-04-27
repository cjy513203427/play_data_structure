# -*- encoding: utf-8 -*-
'''
@File    :   double_stack.py    
@Modify Time      @Author       @Desciption
------------      -------       -----------
2020/4/8 18:50   Jonas           None
'''
import numpy as np

MAXSIZE = 20


class SqDoubleStack(object):
    def __init__(self):
        self.data = np.zeros(MAXSIZE)
        self.top1 = -1
        self.top2 = MAXSIZE

    def visit(self, element):
        print(element, end=' ')
        return True

    # Construct an empty stack
    def InitStack(self):
        self.top1 = -1
        self.top2 = MAXSIZE
        return True

    # Set S empty stack
    def ClearStack(self):
        self.top1 = -1
        self.top2 = MAXSIZE
        return True

    # If s is an empty stack,return True,otherwise return False
    def StackEmpty(self):
        if self.top1 == -1 and self.top2 == MAXSIZE:
            return True
        else:
            return False

    # Return number of element,exactly is length of stack
    def StackLength(self):
        return (self.top1 + 1) + (MAXSIZE - self.top2)

    # Insert e as new top element
    def Push(self, e, stackNumber):
        # If stack is full
        if self.top1 + 1 == self.top2:
            return False
        # Push element to stack1
        if stackNumber == 1:
            self.top1 += 1
            self.data[self.top1] = e
        # Push element to stack2
        elif stackNumber == 2:
            self.top2 -= 1
            self.data[self.top2] = e
        return True;

    # If stack is not empty,then delete top element of S,return deleted element,otherwise return False
    def Pop(self, stackNumber):
        if stackNumber == 1:
            # If stack1 is empty
            if self.top1 == -1:
                return False
            # Pop element from stack1
            e = self.data[self.top1]
            self.top1 -= 1
        elif stackNumber == 2:
            # If stack2 is empty
            if self.top2 == MAXSIZE:
                return False
            # Pop element from stack2
            e = self.data[self.top2]
            self.top2 += 1

        return e

    def StackTraverse(self):
        i = 0;
        while i <= self.top1:
            self.visit(self.data[i])
            i += 1

        i = self.top2;
        while i < MAXSIZE:
            self.visit(self.data[i])
            i += 1

        print("\n")
        return True;


if __name__ == '__main__':
    ds = SqDoubleStack()
    if ds.InitStack():
        for j in range(1, 6):
            ds.Push(j, 1)
        for j in range(MAXSIZE, MAXSIZE - 3, -1):
            ds.Push(j, 2)

    print("Elements of stack are in turn:")
    ds.StackTraverse()

    print("Length of stack is:%d \n" % ds.StackLength())

    e = ds.Pop(1);
    print("Popped element is e=%d\n" % e)
    print("If stack is empty:%d(1:Empty 0:Not empty)\n" % ds.StackEmpty())

    for j in range(6, MAXSIZE - 1):
        ds.Push(j, 1)

    print("Elements of stack are in turn:");
    ds.StackTraverse();

    ds.Pop(2);
    ds.Push(100, 2);
    ds.StackTraverse();

    ds.ClearStack();
    print("After clearing stack,if stack is empty:%d(1:Empty 0:Not Empty)\n" % ds.StackEmpty());
