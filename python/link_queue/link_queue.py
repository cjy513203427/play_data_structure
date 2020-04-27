# -*- encoding: utf-8 -*-
'''
@File    :   link_queue.py    
@Modify Time      @Author       @Desciption
------------      -------       -----------
2020/4/27 17:14   Jonas           None
'''


class QNode(object):
    def __init__(self):
        self.data = 0
        self.next = None


class LinkQueue(object):
    def __init__(self):
        self.front = QNode()
        self.rear = QNode()

    def visit(self, element):
        print(element, end=" ")

    # Construct an empty queue
    def InitQueue(self):
        self.front = self.rear = QNode()
        if self.front is not None:
            return False
        self.front.next = None
        return True

    # Destroy queue
    def DestroyQueue(self):
        while self.front:
            self.rear = self.front.next
            self.front = self.rear
        return True

    # Clear queue
    def ClearQueue(self):
        self.rear = self.front
        p = self.front.next
        self.front.next = None
        while p is not None:
            q = p
            p = p.next
            q = None
        return True

    # If it is empty queue,return TRUE,otherwise return FALSE
    def QueueEmpty(self):
        if self.front == self.rear:
            return True
        else:
            return False

    # Get the length of queue
    def QueueLength(self):
        i = 0
        p = self.front
        while self.rear != p:
            i += 1
            p = p.next
        return i

    # If queue is not empty,return head element of queue and return OK,otherwise return ERROR
    def GetHead(self):
        if self.front == self.rear:
            return False
        p = self.front.next
        e = p.data
        return e

    # Insert element as new rear element
    def EnQueue(self, e):
        s = QNode()
        if s is None:
            return False
        s.data = e
        s.next = None
        # Assign new node to next of former rear node
        self.rear.next = s
        # Assign s to rear node
        self.rear = s
        return True

    # If queue is not empty,delete head element of queue,then return deleted value,otherwise return false
    def DeQueue(self):
        if self.front == self.rear:
            return False
        p = self.front.next
        e = p.data
        self.front.next = p.next
        # Judge if the first node is rear
        if self.rear == p:
            self.rear = self.front
        return e

    # Traverse every element from front to rear in turn
    def QueueTraverse(self):
        p = self.front.next
        while p:
            self.visit(p.data)
            p = p.next
        print("\n")
        return True


if __name__ == '__main__':
    lq = LinkQueue()
    i = lq.InitQueue()
    if i is not None:
        print("Construct an empty queue!\n")
    print("If queue is empty? %d \n" % lq.QueueEmpty())
    print("Queue length is %d\n" % lq.QueueLength())
    lq.EnQueue(-5)
    lq.EnQueue(5)
    lq.EnQueue(10)
    print("After inserting 3 element(-5,5,10),Queue length is %d\n" % lq.QueueLength())
    print("If queue is empty? %d\n" % lq.QueueEmpty())
    print("Elements of queue are in order:")
    lq.QueueTraverse()
    d = lq.GetHead()
    if i is not None:
        print("Head element of queue is:%d\n" % d)
    dq = lq.DeQueue()
    print("After deleting head element of queue,deleted element is %d\n" % dq)
    i = lq.GetHead()
    if i is not None:
        print("New head element of queue is:%d\n" % d)
    lq.ClearQueue()
    print("After clearing queue,q.front=%s q.rear=%s q.front->next=%s\n" %(lq.front,lq.rear,lq.front.next))
    print("Queue length is %d\n" %lq.QueueLength())
    lq.DestroyQueue()
    print("After destroying,q.front=%s q.rear=%s\n" %(lq.front, lq.rear))
    print("Queue length is %d\n" %lq.QueueLength())
