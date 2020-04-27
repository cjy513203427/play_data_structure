# -*- encoding: utf-8 -*-
'''
@File    :   static_link_list.py    
@Modify Time      @Author       @Desciption
------------      -------       -----------
2020/3/23 11:20   Jonas           None
'''

MAXSIZE = 1000
StaticLinkList = []
# define node
class Node(object):
    def __init__(self,data,cur):
        self.data = data
        # Cursor,if the value is equal to zero,it means pointless
        self.cur = cur

# define static link list
class StaticLinkedList(object):
    def visit(self,element):
        print(element,end=' ')

    # Initialize array to alternate link list,space[0].cur is head pointer,"0" means null pointer
    def InitList(self):
        i = 0
        for i in range(0,MAXSIZE-1):
            StaticLinkList.append(Node(data=None,cur=i+1))

        # for now link list is null,the cursor of last element is 0
        StaticLinkList.append(Node(data=None,cur=0))
        return True

    # If static link list is null,then return index of distributed element
    def Malloc_SSL(self):
        # Get index of free element
        i = StaticLinkList[0].cur
        if(i):
            # Use next element as alternate element
            StaticLinkList[0].cur = StaticLinkList[i].cur
            return i

    def Free_SSL(self,k):
        # Link deleted element to an alternate link list
        # Let free element become the second element of alternate link list
        StaticLinkList[k].cur = StaticLinkList[0].cur
        # Let the deleted element become the first element of alternate link list
        StaticLinkList[0].cur = k

    # Condition:static link list is exist
    # Return number of element
    def ListLength(self):
        j = 0
        # Get index of the first element with value
        i = StaticLinkList[MAXSIZE-1].cur
        while(i):
            i = StaticLinkList[i].cur
            j+=1

        return j

    # Insert new element in index i
    def ListInsert(self,i,e):
        # k is the index of the last element
        k = MAXSIZE-1
        if(i<0 or i>self.ListLength()):
            return False
        # Get index of free element
        j = self.Malloc_SSL()
        if(j):
            StaticLinkList[j].data = e
            # Find the element,who is in front of the ith element
            for l in range(0,i):
                k = StaticLinkList[k].cur
            # s->next = p->next
            StaticLinkList[j].cur = StaticLinkList[k].cur
            # p->next = s
            StaticLinkList[k].cur = j
            return True

        return False

    # Delete the ith element
    def ListDelete(self,i):
        if(i<0 or i>self.ListLength()-1):
            return False

        k = MAXSIZE-1
        # Find the element,who is in front of the ith element
        for j in range(0,i):
            k = StaticLinkList[k].cur
        # q = p->next
        j = StaticLinkList[k].cur
        # p->next = q->next
        StaticLinkList[k].cur = StaticLinkList[j].cur
        self.Free_SSL(j)
        return True

    def ListTraverse(self):
        j = 0
        i = StaticLinkList[MAXSIZE-1].cur
        while(i):
            self.visit(StaticLinkList[i].data)
            i = StaticLinkList[i].cur
            j+=1

        return True


if __name__ == '__main__':
    sll = StaticLinkedList()
    sll.InitList()
    print("After we initialize L:L.length=%d" %sll.ListLength())
    i = sll.ListInsert(0,'F')
    i = sll.ListInsert(0, 'E')
    i = sll.ListInsert(0, 'D')
    i = sll.ListInsert(0, 'B')
    i = sll.ListInsert(0, 'A')

    print("After we insert FEDBA in the head of L:\nL.data=")
    sll.ListTraverse()

    i = sll.ListInsert(2,'C')
    print("\nAfter we insert 'C' between 'B' and 'D' in L:\nL.data=")
    sll.ListTraverse()

    i = sll.ListDelete(0)
    print("\nAfter we delete 'A' in L:\nL.data=")

    i = sll.ListTraverse()
    print("\n")