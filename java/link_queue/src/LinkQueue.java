/**
 * @Author: 谷天乐
 * @Date: 2020/4/27 18:14
 * @Description:
 */
public class LinkQueue {
    public QNode front;
    public QNode rear;

    // Construct an empty queue
    public boolean InitQueue(){
        this.front = this.rear = new QNode();
        if (this.front == null)
            return false;
        this.front.next = null;
        return true;
    }

    public boolean visit(int c){
        System.out.printf(c+ " ");
        return true;
    }

    // Destroy queue
    public boolean DestroyQueue()
    {
        while (this.front!=null)
        {
            this.rear = this.front.next;
            this.front = null;
            this.front = this.rear;
        }
        return true;
    }

    // Clear queue
    public boolean ClearQueue()
    {
        QNode p;
        QNode q;
        this.rear = this.front;
        p = this.front.next;
        this.front.next = null;
        while (p!=null)
        {
            q = p;
            p = p.next;
            q = null;
        }
        return true;
    }

    // If Q is empty queue,return TRUE,otherwise return FALSE
    public boolean QueueEmpty()
    {
        if (this.front == this.rear)
            return true;
        else
            return false;
    }


    // Get the length of queue
    public int QueueLength()
    {
        int i = 0;
        QNode p;
        p = this.front;
        while (this.rear != p)
        {
            i++;
            p = p.next;
        }
        return i;
    }

    // If queue is not empty,return head element of queue and return OK,otherwise return ERROR
    public int GetHead()
    {
        QNode p;
        if (this.front == this.rear)
            return -1;
        p = this.front.next;
	    int e = p.data;
        return e;
    }

    // Insert element as new rear element
    public boolean EnQueue(int e)
    {
        QNode s = new QNode();
        if (s==null)
            return false;
        s.data = e;
        s.next = null;
        // Assign new node to next of former rear node
        this.rear.next = s;
        // Assign s to rear node
        this.rear = s;
        return true;
    }

    // If queue is not empty,delete head element of queue,then return deleted value and return OK,otherwise return ERROR
    public int DeQueue()
    {
        QNode p;
        if (this.front == this.rear)
            return -1;
        p = this.front.next;
	    int e = p.data;
        this.front.next = p.next;
        // Judge if the first node is rear
        if (this.rear == p)
            this.rear = this.front;
        p = null;
        return e;
    }

    // Traverse every element from front to rear in turn
    public boolean QueueTraverse()
    {
        QNode p;
        p = this.front.next;
        while (p!=null)
        {
            this.visit(p.data);
            p = p.next;
        }
        System.out.printf("\n");
        return true;
    }


    public static void main(String[] args) {
        LinkQueue lq = new LinkQueue();
        boolean i = lq.InitQueue();
        if (i)
            System.out.printf("Construct an empty queue!\n");
        System.out.printf("If queue is empty? \n", lq.QueueEmpty());
        System.out.printf("Queue length is %d\n", lq.QueueLength());
        lq.EnQueue(-5);
        lq.EnQueue(5);
        lq.EnQueue(10);
        System.out.printf("After inserting 3 element(-5,5,10),Queue length is %d\n" ,lq.QueueLength());
        System.out.printf("If queue is empty?\n", lq.QueueEmpty());
        System.out.printf("Elements of queue are in order:");
        lq.QueueTraverse();
        int d = lq.GetHead();
        if (i == true)
            System.out.printf("Head element of queue is:%d\n", d);
        int dq = lq.DeQueue();
        System.out.printf("After deleting head element of queue,deleted element is %d\n", dq);
        int head = lq.GetHead();
        if (head != -1)
            System.out.printf("New head element of queue is:%d\n", head);
        lq.ClearQueue();
        System.out.printf("After clearing queue,q.front=%s q.rear=%s q.front->next=%s\n", lq.front, lq.rear, lq.front.next);
        System.out.printf("Queue length is %d\n", lq.QueueLength());
        lq.DestroyQueue();
        System.out.printf("After destroying,q.front=%s q.rear=%s\n", lq.front, lq.rear);
        System.out.printf("Queue length is %d\n", lq.QueueLength());
    }
}