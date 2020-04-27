/**
 * @Author: 谷天乐
 * @Date: 2020/4/21 17:46
 * @Description:
 */
public class SqQueue {
    public final int MAXSIZE = 20;
    public int []data = new int[MAXSIZE];
    // Front pointer
    public int front;
    // Rear pointer
    public int rear;

    public boolean visit(int e){
        System.out.printf(e+" ");
        return true;
    }

    // Construct an empty stack
    public boolean InitQueue()
    {
        this.front = 0;
        this.rear = 0;
        return true;
    }

    // Clear Queue
    public boolean ClearQueue()
    {
        this.front = this.rear = 0;
        return true;
    }


    // If queue is empty,return TRUE,otherwise return FALSE
    public boolean QueueEmpty()
    {
        // If the queue is empty
        if (this.front == this.rear)
            return true;
        else
            return false;
    }

    // Return element count of queue,exactly is length of the queue
    public int QueueLength()
    {
        return  (this.rear - this.front + MAXSIZE) % MAXSIZE;
    }

    // If queue is not empty,return head element of queue,otherwise return -1
    public int GetHead()
    {
        // If the queue is empty
        if (this.front == this.rear)
            return -1;
	    int e = this.data[this.front];
        return e;
    }

    // If queue is not empty,insert element as new rear element of queue
    public boolean EnQueue(int e)
    {
        // If queue is full
        if ((this.rear + 1) % MAXSIZE == this.front)
            return false;
        this.data[this.rear] = e;
        // Rear++,if rear is more than last position,return to the first position
        this.rear = (this.rear + 1) % MAXSIZE;
        return true;
    }

    // If queue is not empty,then delete head element of queue,return deleted value
    public int DeQueue()
    {
        // If queue is empty
        if (this.front == this.rear)
            return -1;
	    int e = this.data[this.front];
        // Front++,if front is more than last position,return to the first position
        this.front = (this.front + 1) % MAXSIZE;
        return e;
    }

    // Traverse queue in turn
    public boolean QueueTraverse()
    {
        int i;
        i = this.front;
        for (i = this.front; i < QueueLength() + this.front; i++) {
            visit(this.data[i%MAXSIZE]);
        }
        System.out.println();
        return true;
    }

    public static void main(String[] args) {
        int l;
        SqQueue Q = new SqQueue();
        Q.InitQueue();
        System.out.printf("After initializing queue,if queue is empty? %b\n", Q.QueueEmpty());
        for (l = 1; l < 6; l++) {
            Q.EnQueue(l);
        }
        System.out.printf("Traverse in order:\n");
        Q.QueueTraverse();
        System.out.printf("After EnQueue,if queue is empty? %b\n", Q.QueueEmpty());
        System.out.printf("Queue length is:%d\n", Q.QueueLength());
        Q.DeQueue();
        Q.DeQueue();
        Q.DeQueue();
        Q.EnQueue(1);
        Q.EnQueue(2);
        System.out.printf("Traverse in order:\n");
        Q.QueueTraverse();
        int d = Q.GetHead();
        System.out.printf("Head element is:%d\n", d);
        System.out.printf("Queue length is:%d\n", Q.QueueLength());
        Q.ClearQueue();
        System.out.printf("After clearing queue,if queue is empty? %b\n", Q.QueueEmpty());
    }

}