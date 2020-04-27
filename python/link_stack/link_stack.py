# -*- encoding: utf-8 -*-
'''
@File    :   link_stack.py    
@Modify Time      @Author       @Desciption
------------      -------       -----------
2020/4/14 19:05   Jonas           None
'''



class StackNode(object):
    def __init__(self):
        self.data = 0
        self.next = None


class LinkStack(object):
    # define link stack
    def __init__(self):
        self.count = 0
        self.top = StackNode()

    def visit(self, element):
        print(element,end=" ")

    # Construct an empty stack
    def InitStack(self):
        self.top = StackNode()
        if self.top is None:
            return False

        self.top = None
        self.count = 0
        return True

    # Set S an empty stack
    def ClearStack(self):
        p = self.top
        while p:
            p = p.next
        self.count = 0
        return True

    # If stack is empty,return TRUE,otherwise return FALSE
    def StackEmpty(self):
        if self.count == 0:
            return True
        else:
            return False

    # Return number of element,exactly is length of stack
    def StackLength(self):
        return self.count

    # If stack is not empty,return top element of stack,then return True,otherwise return False
    def GetTop(self):
        if self.top is None:
            return False
        else:
            e = self.top.data
        return e

    # Insert element as new top element of stack
    def Push(self, e):
        s = StackNode()
        s.data = e
        # Assign top element to next of new node
        s.next = self.top
        # Assign new node to the top pointer
        self.top = s
        self.count += 1
        return True

    # If stack is not empty,delete top element of S,return deleted element,then return OK,otherwise return ERROR
    def Pop(self):
        if self.StackEmpty():
            return False
        e = self.top.data
        # Let top pointer minus 1,it points to next node
        self.top = self.top.next
        self.count -= 1
        return e

    def StackTraverse(self):
        p = self.top
        while p:
            self.visit(p.data)
            p = p.next
        print("\n")
        return True


if __name__ == '__main__':
    ls = LinkStack()
    ls.InitStack()
    if ls.InitStack():
        for j in range(1, 11):
            ls.Push(j)
    print("Elements of stack are in turn：");
    ls.StackTraverse()
    e = ls.Pop()
    print("Popped top element is e=%d\n" %e)
    print("If stack is empty:%d(1:Empty 0:Not Empty)\n" %ls.StackEmpty())
    e1 = ls.GetTop()
    print("Top element is e=%d Length of stack is %d\n" %(e1, ls.StackLength()))
    ls.ClearStack()
    print("After clearing stack,if stack is empty:%d(1:Empty 0:Not Empty)\n" %ls.StackEmpty())
