# -*- encoding: utf-8 -*-
'''
@File    :   linked_list.py    
@Modify Time      @Author       @Desciption
------------      -------       -----------
2020/3/7 21:57   Jonas           None
'''


# define node
class Node(object):
    def __init__(self):
        self.data = 0
        self.next = None


# define link list
class LinkedList(object):
    def __init__(self):
        self.LinkList = Node()

    def visit(self, element):
        print(element, end=" ")

    # Init link list
    def InitList(self):
        # generate head Node,L points to head Node
        L = Node()
        # when memory allocation fails
        if L is None:
            return False
        # pointer field = NULL
        L.next = None
        return True

    # Condition:link list is exist
    # Judge if link list is empty
    def ListEmpty(self):
        # judge if the first Node has value
        if self.LinkList.next:
            return False
        else:
            return True

    # Condition:link list is exist
    # Let link list be a empty link list
    def ClearList(self):
        # assign p first Node
        p = self.LinkList.next
        while p:
            # save next Node
            q = p.next
            p = q
        # pointer domin of head Node is NULL
        self.LinkList.next = None
        return True

    # Condition:link list is exist
    # Return length of link list
    def ListLength(self):
        i = 0
        # assign p first Node
        p = self.LinkList.next
        while p:
            i += 1
            p = p.next

        return i

    # Condition:link list is exist
    # return value of index i
    def GetElem(self, i):
        # assign p first Node
        p = self.LinkList.next
        j = 1
        # search Node according to index i with traverse
        while p and j < i:
            p = p.next
            j += 1
        # when the ith element is not exist
        if (not p) or (j > i):
            return False

        e = p.data
        return e

    # Condition:link list is exist,1≤i≤ListLength(L)
    # return index of element
    def LocateElem(self, e):
        i = 0
        p = self.LinkList.next
        while p:
            i += 1
            if p.data == e:
                return i
            p = p.next

        return False

    # Condition:link list is exist,1≤i≤ListLength(L)
    # Insert element in index i,length plus 1
    def ListInsert(self, i, e):
        p = self.LinkList
        j = 1
        # search Node according to index i with traverse
        while p and (j < i):
            p = p.next
            j += 1
        # when the ith element is not exist
        if (not p) or (j > i):
            return False
        # generate new Node
        s = Node()
        s.data = e
        s.next = p.next
        p.next = s

        return True

    # Condition:link list is exist,1≤i≤ListLength(L)
    # Delete element according to index i,return deleted value,length minus 1
    def ListDelete(self, i):
        p = self.LinkList
        j = 1
        # search Node according to index i with traverse
        while p.next and (j < i):
            p = p.next
            j += 1
        # when the ith element is not exist
        if (not p.next) or (j > i):
            return False

        q = p.next
        p.next = q.next
        e = q.data
        return e

    # Condition:link list is exist,1≤i≤ListLength(L)
    # Traverse every element
    def ListTraverse(self):
        p = self.LinkList.next
        while p:
            self.visit(p.data)
            p = p.next
        print()
        return True

    # Randomly generate values for n elements
    # Build a single linked list with head Node,insert from head
    def CreateListHead(self, n):
        L = self.LinkList
        # build a single linked list with head Node
        L.next = None
        for i in range(0, n):
            # generate new Node
            p = Node()
            # generate number within 100
            p.data = i
            p.next = L.next
            L.next = p

    # Randomly generate values for n elements
    # Build a single linked list with head Node,insert from tail
    def CreateListTail(self, n):
        # L is whole linked list
        L = self.LinkList
        # r points to tail
        r = L
        for i in range(0, n):
            # generate new Node
            p = Node()
            # generate number within 100
            p.data = i
            r.next = p
            r = p


if __name__ == '__main__':
    ll = LinkedList()
    ll.InitList()
    print("After L initialized ：ListLength() = %d" % ll.ListLength())
    for j in range(1, 6):
        ll.ListInsert(1, j)
    print("After we insert 1~5 in head of L in order：L.data=")
    ll.ListTraverse()
    print("ListLength() = %d" % ll.ListLength())

    i = ll.ListEmpty();
    print("If L is empty：i=%d" % i)
    ll.ClearList();
    print("After we clear L：ListLength()=%d" % ll.ListLength())
    i = ll.ListEmpty();
    print("If L is empty：i=%d" % i)
    for j in range(1, 11):
        ll.ListInsert(j, j)
    print("after we insert 1~10 in tail of L in order：L.data=")
    ll.ListTraverse()
    print("ListLength()=%d" % ll.ListLength())
    ll.ListInsert(1, 10)
    print("After we insert 10 in head of L：L.data=")
    ll.ListTraverse()
    print("ListLength(L)=%d" % ll.ListLength())
    e = ll.GetElem(5)
    print("The 5th element is：%d" % e)

    for j in range(3, 5):
        k = ll.LocateElem(j)
        if k:
            print("The %d th element is %d" % (k, j))
        else:
            print("There is not element,whose value is %d" % j)

    k = ll.ListLength()

    for j in range(k + 1, k - 1, -1):
        i = ll.ListDelete(j)
        if not i:
            print("Deleting %dth element failed " % j)
        else:
            print("Deleted %dth element is: %d" % (j, i))
    print("Traverse L in order：")
    ll.ListTraverse()

    j = 5;
    e = ll.ListDelete(j);
    print("Deleted %d th element is:  %d" %(j,e))
    print("Deleted %d th element is:  %d" %(j,e))
    ll.ListTraverse();

    i = ll.ClearList();

    print("After we clear L：ListLength(L)=%d" %ll.ListLength())
    ll.CreateListHead(20);
    print("Create the elements of L as a whole (CreateListHead)：")
    ll.ListTraverse();
    i = ll.ClearList();
    print("After we clear L：ListLength(L)= %d" %ll.ListLength())
    ll.CreateListTail(20);
    print("Create the elements of L as a whole (CreateListTail)：")
    ll.ListTraverse();