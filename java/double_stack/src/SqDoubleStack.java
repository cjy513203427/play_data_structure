/**
 * @Author: 谷天乐
 * @Date: 2020/4/9 16:51
 * @Description:
 */
public class SqDoubleStack {
    public final static int MAXSIZE = 20;
    public int []data = new int[MAXSIZE];
    // Top of stack1
    public int top1;
    // Top of stack2
    public int top2;

    public boolean visit(int element){
        System.out.printf(element+" ");
        return true;
    }

    // Construct an empty stack
    public boolean InitStack(){
        this.top1 = -1;
        this.top2 = MAXSIZE;
        return true;
    }

    // Set S empty stack
    public boolean ClearStack() {
        this.top1 = -1;
        this.top2 = MAXSIZE;
        return true;
    }

    // If s is an empty stack,return true,otherwise return false
    public boolean StackEmpty() {
        if (this.top1 == -1 && this.top2 == MAXSIZE)
        return true;
	else
        return false;
    }

    // return number of element,exactly is length of stack
    public int StackLength() {
        return (this.top1 + 1) + (MAXSIZE - this.top2);
    }

    // Insert e as new top element
    public boolean Push(int e, int stackNumber) {
        // If stack is full
        if (this.top1 + 1 == this.top2)
            return false;
        // Push element to stack1
        if (stackNumber == 1)
            this.data[++this.top1] = e;
        // Push element to stack2
        else if (stackNumber == 2)
            this.data[--this.top2] = e;
        return true;
    }

    // If stack is not empty,then delete top element of S,return deleted element and OK,otherwise return ERROR
    public int Pop(int stackNumber) {
        int e = 0;
        if (stackNumber == 1)
        {
            // If stack1 is empty
            if (this.top1 == -1)
                return -1;
            // Pop element from stack1
            e = this.data[this.top1--];
        }
        else if (stackNumber == 2)
        {
            // If stack2 is empty
            if (this.top2 == MAXSIZE)
                return -1;
            // Pop element from stack2
            e = this.data[this.top2++];
        }
        return e;
    }

    public boolean StackTraverse() {
        int i;
        i = 0;
        while (i <= this.top1)
        {
            visit(this.data[i++]);
        }
        i = this.top2;
        while (i<MAXSIZE)
        {
            visit(this.data[i++]);
        }
        System.out.printf("\n");
        return true;
    }

    public static void main(String[] args) {
        int j;
        SqDoubleStack s = new SqDoubleStack();
        int e;
        if (s.InitStack())
        {
            for (j = 1; j <= 5; j++)
                s.Push(j, 1);
            for (j = MAXSIZE; j >= MAXSIZE - 2; j--)
                s.Push(j, 2);
        }

        System.out.printf("Elements of stack are in turn:");
        s.StackTraverse();

        System.out.printf("Length of stack is:%d \n", s.StackLength());

        e = s.Pop(2);
        System.out.printf("Popped element is e=%d\n", e);
        System.out.printf("If stack is empty:%b\n", s.StackEmpty());

        for (j = 6; j <= MAXSIZE - 2; j++)
            s.Push(j, 1);

        System.out.printf("Elements of stack are in turn:");
        s.StackTraverse();

        s.Push(100, 1);


        s.ClearStack();
        System.out.printf("After clearing stack,if stack is empty:%b\n", s.StackEmpty());

    }
}