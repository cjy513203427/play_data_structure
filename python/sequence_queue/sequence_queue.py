# -*- encoding: utf-8 -*-
'''
@File    :   sequence_queue.py    
@Modify Time      @Author       @Desciption
------------      -------       -----------
2020/4/21 16:50   Jonas           None
'''

import numpy as np

MAXSIZE = 5


class SqQueue(object):
    def __init__(self):
        self.data = np.zeros(MAXSIZE)
        self.front = 0
        self.rear = 0

    def visit(self, element):
        print(element, end=" ")

    # Initialize an empty queue
    def InitQueue(self):
        self.front = 0
        self.rear = 0
        return True

    # Clear Queue
    def ClearQueue(self):
        self.front = self.rear = 0
        return True

    # If queue is empty,return TRUE,otherwise return FALSE
    def QueueEmpty(self):
        # If the queue is empty
        if self.front == self.rear:
            return True
        else:
            return False

    # Return element count of queue,exactly is length of the queue
    def QueueLength(self):
        return (self.rear - self.front + MAXSIZE) % MAXSIZE

    # If queue is not empty,return head element of queue,otherwise return false
    def GetHead(self):
        # If the queue is empty
        if self.front == self.rear:
            return False
        else:
            e = self.data[self.front]
            return e

    # If queue is not empty,insert element as new rear element of queue
    def EnQueue(self, e):
        # If queue is full
        if (self.rear + 1) % MAXSIZE == self.front:
            return False
        self.data[self.rear] = e
        # Rear++,if rear is more than last position,return to the first position
        self.rear = (self.rear + 1) % MAXSIZE
        return True

    # If queue is not empty,then delete head element of queue,return deleted value
    def DeQueue(self):
        # If queue is empty
        if self.QueueEmpty():
            return False
        else:
            e = self.data[self.front]
            # Front++,if front is more than last position,return to the first position
            self.front = (self.front + 1) % MAXSIZE
            return e

    # Traverse queue in turn
    def QueueTraverse(self):
        for i in range(self.front, self.front+self.QueueLength(), ):
            self.visit(self.data[i % MAXSIZE])
        print("\n")
        return True


if __name__ == '__main__':
    sq = SqQueue()
    sq.InitQueue()
    print("After initializing queue,if queue is empty? %d(1:Empty 0:Not empty)\n" % sq.QueueEmpty())
    for l in range(1, 6):
        sq.EnQueue(l)
    print("Traverse in order:\n")
    sq.QueueTraverse()
    print("Queue length is:%d\n" % sq.QueueLength())
    sq.DeQueue()
    sq.DeQueue()
    sq.DeQueue()
    sq.EnQueue(1)
    sq.EnQueue(2)
    print("Traverse in order:\n")
    sq.QueueTraverse()
    d = sq.GetHead()
    print("Head element is:%d\n" % d)
    print("Queue length is:%d\n" % sq.QueueLength())
    sq.ClearQueue()
    print("After clearing queue,if queue is empty? %d(1:Empty 0:Not empty)\n" % sq.QueueEmpty())
