/**
 * @Author: 谷天乐
 * @Date: 2020/4/16 16:30
 * @Description:
 */
public class LinkStack {
    public StackNode top;
    public int count;

    public boolean visit(int element){
        System.out.printf("%d ", element);
        return true;
    }

    // Construct an empty stack
    public boolean InitStack(){
        this.top = new StackNode();
        if (this.top==null)
            return false;
        this.top = null;
        this.count = 0;
        return true;
    }

    // Set S an empty stack
    public boolean ClearStack(){
        StackNode p;
        StackNode q;
        p = this.top;
        while (p!=null)
        {
            p = p.next;
        }
        this.count = 0;
        return true;
    }

    // If stack is empty,return TRUE,otherwise return FALSE
    public boolean StackEmpty()
    {
        if (this.count == 0)
            return true;
	    else
            return false;
    }

    // Return number of element,exactly is length of stack
    public int StackLength()
    {
        return this.count;
    }

    // If stack is not empty,return top element of stack,then return OK,otherwise return FALSE
    public int GetTop()
    {
        int e;
        if (this.top == null)
            return -1;
        else
            e = this.top.data;
        return e;
    }

    // Insert element as new top element of stack
    public boolean Push(int e)
    {
        StackNode s = new StackNode();
        s.data = e;
        // Assign top element to next of new node
        s.next = this.top;
        // Assign new node to the top pointer
        this.top = s;
        this.count++;
        return true;
    }

    // If stack is not empty,delete top element of S,return deleted element,then return OK,otherwise return ERROR
    public int Pop()
    {
        StackNode p;
        if (StackEmpty())
            return -1;
	    int e = this.top.data;
        // Let top pointer minus 1,it points to next node
        this.top = this.top.next;
        this.count--;
        return e;
    }

    public boolean StackTraverse()
    {
        StackNode p;
        p = this.top;
        while (p!=null)
        {
            this.visit(p.data);
            p = p.next;
        }
        System.out.printf("\n");
        return true;
    }

    public static void main(String[] args) {
        int j;
        LinkStack s = new LinkStack();
        int e;
        if (s.InitStack())
            for (j = 1; j <= 10; j++)
                s.Push(j);
        System.out.printf("Elements of stack are in turn:");
        s.StackTraverse();
        e = s.Pop();
        System.out.printf("Popped top element is e=%d\n", e);
        System.out.printf("If stack is empty:%b(true:Empty false:Not Empty)\n", s.StackEmpty());
        int e1 = s.GetTop();
        System.out.printf("Top element is e=%d Length of stack is %d\n", e1,s.StackLength());
        s.ClearStack();
        System.out.printf("After clearing stack,if stack is empty:%b(true:Empty false:Not Empty)\n", s.StackEmpty());
    }
}