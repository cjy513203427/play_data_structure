package com.advance;

public class StaticLinkedList<T> {
    public final int MAXSIZE = 1000;
    public Node<T>[] StaticLinkList;

    public boolean visit(T c){
        System.out.print(c+" ");
        return true;
    }

    // Initialize array to alternate link list,space[0].cur is head pointer,"0" means null pointer
    public boolean InitList(){
        StaticLinkList = new Node[MAXSIZE];
        int i;
        for (i=0;i<MAXSIZE-1;i++)
            // If we use StaticLinkList[i].cur = i + 1,then throw NullPointerException
            StaticLinkList[i] = new Node<T>(null,i+1);
        // for now link list is null,the cursor of last element is 0
        StaticLinkList[MAXSIZE-1] = new Node<>(null,0);
        return true;
    }


    // If static link list is null,then return index of distributed element
    public int Malloc_SSL(){
        // Get index of free element
        int i = StaticLinkList[0].cur;

        if(StaticLinkList[0].cur!=0)
            // Use next element as alternate element
            StaticLinkList[0].cur = StaticLinkList[i].cur;
        return i;
    }

    // Recycle free element to alternate link list
    public void Free_SSL(int k){
        // Link deleted element to a alternate link list
        // Let free element become the second element of alternate link list
        StaticLinkList[k].cur = StaticLinkList[0].cur;
        // Let the deleted element become the first element of alternate link list
        StaticLinkList[0].cur = k;
    }

    // Condition: static link list is exist.
    // Return number of element
    public int ListLength(){
        int j = 0;
        // Get index of the first element with value
        int i = StaticLinkList[MAXSIZE-1].cur;
        while (i!=0)
        {
            i = StaticLinkList[i].cur;
            j++;
        }
        return j;
    }

    // Insert new element in index i
    public boolean ListInsert(int i,T e){
        int j,k,l;
        // k is the index of the last element
        k = MAXSIZE-1;
        if(i<0||i>ListLength())
            return false;
        // Get index of free element
        j = Malloc_SSL();
        // If malloc success
        if(j!=0)
        {
            StaticLinkList[j].data = e;
            // Find the element,who is in front of the ith element
            for (l = 0; l < i; l++)
                k = StaticLinkList[k].cur;
            // s->next = p->next
            StaticLinkList[j].cur = StaticLinkList[k].cur;
            // p->next = s
            StaticLinkList[k].cur = j;
            return true;
        }
        return false;
    }

    // Delete the ith element
    public boolean ListDelete(int i) {
        int j, k;
        if (i<0 || i>ListLength() - 1)
            return false;
        k = MAXSIZE - 1;
        // Find the element,who is in front of the ith element
        for(j=0;j<i;j++)
            k = StaticLinkList[k].cur;
        // q = p->next
        j = StaticLinkList[k].cur;
        // p->next = q->next
        StaticLinkList[k].cur = StaticLinkList[j].cur;
        Free_SSL(j);
        return true;
    }

    public boolean ListTraverse() {
        int i = StaticLinkList[MAXSIZE - 1].cur;
        while (i!=0)
        {
            visit(StaticLinkList[i].data);
            i = StaticLinkList[i].cur;
        }
        System.out.println();
        return true;
    }

    public static void main(String[] args) {
        boolean i;
        StaticLinkedList sll = new StaticLinkedList();
        sll.InitList();
        System.out.printf("After we initialize L：L.length=%d",sll.ListLength());
        i = sll.ListInsert(0, 'F');
        i = sll.ListInsert(0, 'E');
        i = sll.ListInsert(0, 'D');
        i = sll.ListInsert(0, 'B');
        i = sll.ListInsert(0, 'A');
        System.out.printf("After we insert FEDBA in the head of L：\nL.data=");
        sll.ListTraverse();

        i = sll.ListInsert(2, 'C');
        System.out.printf("After we insert 'C' between 'B' and 'D' in L：\nL.data=");
        sll.ListTraverse();

        i = sll.ListDelete(0);
        System.out.printf("After we delete 'A' in L：\nL.data=");
        sll.ListTraverse();

        System.out.println();
    }
}
