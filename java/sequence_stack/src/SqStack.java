/**
 * @Author: 谷天乐
 * @Date: 2020/3/31 17:35
 * @Description:
 */
public class SqStack {
    public final int MAXSIZE = 20;
    public int data[];
    public int top;

    public boolean visit(int e){
        System.out.printf(e+" ");
        return true;
    }

    // Construct an empty stack
    public boolean InitStack(){
        data = new int[MAXSIZE];
        this.top = -1;
        return true;
    }

    // Clear stack
    public boolean ClearStack(){
        this.top = -1;
        return true;
    }

    // If stack is empty stack,then return true,otherwise return false
    public boolean StackEmpty(){
        if (this.top == -1)
            return true;
        else
            return false;
    }

    // Return number of element,exactly it is length of stack
    public int StackLength() {
        return this.top + 1;
    }

    // If stack is not empty,return top element of stack
    public int GetTop(){
        int e;
        if (this.top == -1)
            return -1;
        else
            e = this.data[this.top];
        return e;
    }

    // Insert new element
    public boolean Push (int e) {
        // If stack is full
        if (this.top == MAXSIZE - 1)
            return false;

        // Stack top plus 1
        this.top++;
        // Assign value to element of stack top
        this.data[this.top] = e;
        return true;
    }

    // If Stack is not empty,then delete element of stack top,return deleted element
    public int Pop(){
        if (this.top == -1)
            return -1;

        // Assign element of stack top to e
        int e = this.data[this.top];
        // Stack top minus 1
        this.top--;
        return e;
    }

    // Traverse element from bottom of stack to top of stack
    public boolean StackTraverse() {
        int i;
        i = 0;
        while (i<=this.top)
        {
            this.visit(this.data[i++]);
        }
        System.out.println();
        return true;
    }

    public static void main(String[] args) {
        SqStack ss = new SqStack();
        int j,e;
        if(ss.InitStack() == true)
            for(j=1;j<=10;j++)
                ss.Push(j);
        System.out.printf("Elements of stack are:");
        ss.StackTraverse();
        e = ss.Pop();
        System.out.printf("Popped element of stack top is e=%d\n" ,e);
        System.out.printf("If Stack is empty:%b\n", ss.StackEmpty());
        ss.GetTop();
        System.out.printf("Element of stack top is e=%d\nLength of stack is %d\n", e, ss.StackLength());
        ss.ClearStack();
        System.out.printf("After Clearing stack,If Stack is empty:%b\n", ss.StackEmpty());
    }
}