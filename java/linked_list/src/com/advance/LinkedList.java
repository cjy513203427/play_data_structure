package com.advance;

public class LinkedList {

    public Node LinkList = new Node();

    public boolean visit(int c){
        System.out.print(c+ " ");
        return true;
    }

    // Init link list
    public boolean InitList(){
        // generate head node,L points to head node
        Node L = new Node();
        // when memory allocation fails
        if(L == null)
            return false;
        // pointer field = NULL
        L.next = null;
        return true;
    }

    // Condition:link list is exist
    // judge if link list is empty
    public boolean ListEmpty(){
        // judge if the first node have value
        if (LinkList.next == null)
            return true;
        else
            return false;
    }

    // Condition:link list is exist
    // Let link list be a empty link list
    public boolean ClearList(){
        Node p,q;
        // assign p first node
        p = LinkList.next;
        while(p!=null){
            // save next node
            q = p.next;
            p = q;
        }
        // pointer domain of head node is NULL
        LinkList.next = null;
        return true;

    }

    // Condition:link list is exist
    // return length of link list
    public int ListLength(){
        int i = 0;
        // assign p first node
        Node p = LinkList.next;
        while (p!=null){
            i++;
            p = p.next;
        }
        return i;
    }

    // Condition:link list is exist
    // return value of index i
    public int GetElem(int i){
        int j;
        Node p;
        // assign p first node
        p = LinkList.next;
        j=1;
        // search node according to index i with traverse
        while(p!=null&&j<i){
            p = p.next;
            ++j;
        }
        // when the ith element is not exist
        if(p==null||j>i)
            return 0;
        int e = p.data;
        return e;
    }

    // Condition:link list is exist,1≤i≤ListLength(L)
    // return index of element
    public int LocateElem(int e){
        int i = 0;
        Node p = LinkList.next;
        while(p!=null){
            i++;
            if(p.data==e)
                return i;
            p = p.next;
        }
        return 0;
    }

    // Condition:link list is exist,1≤i≤ListLength(L)
    // Insert element in index i,length plus 1
    public boolean ListInsert(int i,int e){
        int j;
        Node p = LinkList;
        Node s;
        j=1;
        // search node according to index i with traverse
        while(p!=null&&j<i){
            p = p.next;
            ++j;
        }
        // when the ith element is not exist
        if(p==null||j>i){
            return false;
        }
        // generate new node
        s = new Node();
        s.data = e;
        s.next = p.next;
        p.next = s;
        return true;
    }

    // Condition:link list is exist,1≤i≤ListLength(L)
    // Delete element according to index i,return deleted value,length minus 1
    public int ListDelete(int i){
        int j;
        Node p;
        Node q;
        p = LinkList;
        j=1;
        // search node according to index i with traverse
        while(p!=null&&j<i){
            p = p.next;
            ++j;
        }
        // when the ith element is not exist
        if(p.next==null||j>i){
            return 0;
        }
        q = p.next;
        p.next = q.next;
        int e = q.data;
        return e;
    }

    // Condition:link list is exist,1≤i≤ListLength(L)
    // Traverse every element
    public boolean ListTraverse(){
        Node p = LinkList.next;
        while (p!=null){
            visit(p.data);
            p = p.next;
        }
        System.out.println();
        return true;
    }

    // Generate values for n elements
    // Build a single linked list with head node,insert from head
    public void CreateListHead(int n){
        Node p;
        int i;
        Node L = LinkList;
        // build a single link list with head node
        L.next = null;
        for (i=0;i<n;i++){
            // generate new node
            p = new Node();
            // generate number within 100
            p.data = i;
            p.next = L.next;
            L.next = p;
        }
    }

    // Generate values for n elements
    // Build a single linked list with head node,insert from tail
    public void CreateListTail(int n){
        Node p = null;
        Node r = null;
        int i;
        // L is whole link list
        Node L = LinkList;
        r = L;
        for (i = 0;i<n;i++){
            // generate new node
            p = new Node();
            // generate number within 100
            p.data = i;
            r.next = p;
            r = p;

        }
    }

    public static void main(String[] args) {
        Node L;
        int e;
        boolean staus;
        int j,k;
        LinkedList ll = new LinkedList();
        ll.InitList();
        System.out.printf("After L initialized:ListLength(L) =%d \n",ll.ListLength());
        for (j=1;j<=5;j++){
            ll.ListInsert(1,j);
        }
        System.out.println("After we insert 1-5 in head of L in order:L.data = ");
        ll.ListTraverse();

        System.out.printf("ListLength()=%d\n",ll.ListLength());
        staus = ll.ListEmpty();
        System.out.printf("If L is empty：i=%b\n",staus);
        ll.ClearList();
        System.out.printf("After we clear L：ListLength()=%d\n",ll.ListLength());
        staus = ll.ListEmpty();
        System.out.printf("If L is empty：i=%b\n",staus);
        for (j = 1; j <= 10; j++)
            ll.ListInsert(j, j);

        System.out.println("after we insert 1-10 in tail of L in order：L.data=");
        ll.ListTraverse();

        System.out.printf("ListLength()=%d\n",ll.ListLength());
        ll.ListInsert(1, 10);
        System.out.printf("After we insert 10 in head of L：L.data=");
        ll.ListTraverse();
        System.out.printf("ListLength(L)=%d\n",ll.ListLength());
        e = ll.GetElem(5);
        System.out.printf("The 5th element is：%d\n",e);

        for (j = 3; j <= 4; j++) {
            k = ll.LocateElem(j);
            if (k!=0)
                System.out.printf("The %dth element is %d\n",k,j);
            else
                System.out.printf("There is not element,whose value is %d\n",j);
        }
        k = ll.ListLength();
        for (j = k + 1; j >= k; j--)
        {
            e = ll.ListDelete(j);
            if (e == 0)
                System.out.printf("Deleting %dth element failed\n",j);
            else
                System.out.printf("Deleted %dth element is:%d\n",j,e);
        }
        System.out.println("Traverse L in order：");

        ll.ListTraverse();
        j = 5;
        e = ll.ListDelete(j);
        System.out.printf("Deleted %dth element is\n",e);
        System.out.println("Traverse L in order：");
        ll.ListTraverse();

        ll.ClearList();
        System.out.printf("After we clear L：ListLength(L)=%d\n",ll.ListLength());
        ll.CreateListHead(20);
        System.out.println("Create the elements of L as a whole (CreateListHead)：");
        ll.ListTraverse();
        ll.ClearList();
        System.out.printf("After we clear L：ListLength(L)=%d\n",ll.ListLength());
        ll.CreateListTail(20);
        System.out.println("Create the elements of L as a whole (CreateListTail)：");
        ll.ListTraverse();
    }
}

