
public class SqList {
    public static final int MAXSIZE = 20;
    private int length;
    private int []data = new int[MAXSIZE];

    public boolean visit(int c){
        System.out.print(c+" ");
        return true;
    }

    //init sequence list
    public boolean InitList(){
        this.length = 0;
        return true;
    }

    //judge if list empty is
    public boolean ListEmpty(){
        if(this.length == 0)
            return true;
        else
            return false;
    }

    //clear sequence list
    public boolean ClearList(){
        this.length = 0;
        return true;
    }

    // return list length
    public int ListLength(){
        return this.length;
    }

    /*Condition:0≤i≤ListLength
    according to index return element
    */
    public int GetElem(int i){
        int et;
        if(i<0 | i>this.length-1)
            return -1;
        else
            et = this.data[i];
            return et;
    }

    /*Condition:ListLength>0
    according to element return element's index
    */
    public int LocateElem(int et){
        int i;
        if(this.length == 0)
            return 0;
        for(i=0;i<this.length;i++){
            if(et == this.data[i])
                break;
        }
        return i;
    }

    /*Condition: !=MAXSIZE; 0≤i≤ListLength
    insert element in position i
    */
    public boolean ListInsert(int i,int et){
        if(this.length == MAXSIZE)
            return false;
        if(i<0||i>this.length)
            return false;
        //not final position
        if(i<this.length){
            for(int k = length-1;k>=i;k--){
                this.data[k+1] = this.data[k];
            }
        }
        this.data[i] = et;
        this.length++;
        return true;
    }


    /*Condition:ListLength!=0; 0≤i≤ListLength
    delete element according to index
    return deleted element
    */
    public int ListDelete(int i){
        if(this.length == 0)
            return -1;
        if(i<0||i>this.length-1)
            return -1;
        int et = this.data[i];
        //not final position
        if(i<this.length-1){
            for(int k = i;k<this.length-1;k++){
                this.data[k] = this.data[k+1];
            }
        }
        this.length--;
        return et;
    }

    public boolean ListTraverse(){
        for(int i = 0;i<this.length;i++)
            visit(this.data[i]);
        System.out.println();
        return true;
    }

    public static void main(String[] args) {
        SqList sl = new SqList();
        sl.InitList();
        System.out.println("after Initialization:sl.length="+sl.length);
        for (int j = 0; j <= 5; j++)
            sl.ListInsert(0, j);
        System.out.println("after we insert from 0 to 5:sl.data=");
        sl.ListTraverse();
        boolean i = sl.ListEmpty();
        System.out.println("if L is null:i="+i);
        sl.ClearList();
        System.out.println("after clear:sl.length="+sl.length);
        i = sl.ListEmpty();
        System.out.println("if L is null:i="+i);
        for (int j = 0; j <= 10; j++) {
            sl.ListInsert( j, j);
        }
        System.out.println("after we insert from 0 to 10:sl.data=");
        sl.ListTraverse();
        System.out.println("sl.length="+sl.length);

        sl.ListInsert(0,0);
        System.out.println("after we insert 0 in head:sl.data=");
        sl.ListTraverse();
        System.out.println("sl.length="+sl.length);

        int et = sl.GetElem(4);
        System.out.println("the 4th element is "+et);

        for (int j = 3; j <= 4; j++) {
            int k = sl.LocateElem(j);
            boolean ret=(k==0)?false:true;
            if (ret)
                System.out.println("the "+k+"th element is "+j);
            else
                System.out.println("without "+j+"th element ");
        }

        et = sl.ListDelete(5);
        System.out.println("delete "+5+"th element is "+et);
        System.out.println("output element ");
        sl.ListTraverse();
        System.out.println("sl.length="+sl.length);



    }
}
