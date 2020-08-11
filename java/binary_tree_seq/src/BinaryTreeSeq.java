/**
 * @Author: 谷天乐
 * @Date: 2020/8/11 15:06
 * @Description:
 */
public class BinaryTreeSeq {

    public final int MAX_TREE_SIZE = 1000;
    public int[] SqBiTree;

    public BinaryTreeSeq() {
        SqBiTree = new int[MAX_TREE_SIZE];
    }

    public boolean visit(int c){
        System.out.print(c+ " ");
        return true;
    }

    // Construct empty binary tree
    public boolean InitBiTree()
    {
        int i;
        for (i = 0; i<MAX_TREE_SIZE; i++)
            // Initial value is null
            SqBiTree[i] = 0;
        return true;
    }

    // In sequencial order generate binary tree nodes, construct sequential binary tree
    public boolean CreateBiTree()
    {
        int i = 0;
        System.out.printf("In sequencial order generate binary tree nodes, 0 is null node, until 99 is over. Number of nodes≤%d:\n", MAX_TREE_SIZE);
        while (i<10)
        {
            SqBiTree[i] = i + 1;
            // If this node is not null and not root node, has no parents
            if (i != 0 && SqBiTree[(i + 1) / 2 - 1] == 0 && SqBiTree[i] != 0)
            {
                System.out.printf("Nodes, which are no root node and have not parents node, appear %d\n", SqBiTree[i]);
                return false;
            }
            i++;
        }
        while (i<MAX_TREE_SIZE)
        {
            // Assign null to node after T node
            SqBiTree[i] = 0;
            i++;
        }

        return true;
    }

    /*
        Condition: Binary tree is exist
        Result: If T is empty binary tree, return TRUE, otherwise return FALSE
    */
    public boolean BiTreeEmpty()
    {
        // If root node is null, binary tree is empty
        if (SqBiTree[0] == 0)
            return true;
        else
            return false;
    }

    /*
        Condition: Binary tree is exist
        Result: Return depth of tree
    */
    public int BiTreeDepth()
    {
        int i, j = -1;
        // Find the last node
        for (i = MAX_TREE_SIZE - 1; i >= 0; i--)
            if (SqBiTree[i] != 0)
                break;
        i++;
        do
            j++;
            // Calculate 2^j
        while (i >= Math.pow(2, j));
        return j;
    }

    /*
        Condition: Binary tree is exist
        Result: Return root
    */
    public int Root()
    {
        if (BiTreeEmpty())
            return -1;
        else
        {
		    int e = SqBiTree[0];
            return e;
        }
    }

    /*
        Condition: Binary tree is exist, e is the node of tree
        Result: Return value of node, which locates in the postion e(layer, serial number in this layer)
    */
    public int Value(Position e)
    {
        return SqBiTree[(int)Math.pow(2, e.level - 1) + e.order - 2];
    }

    /*
        Condition: Binary tree is exist, e is the node of tree
        Result: Assign new value to node, which locates in the position e
    */
    public boolean Assign(Position e, int value)
    {
        // Converse layer, serial number of this layer to serial number of matrix
        int i = (int)Math.pow(2, e.level - 1) + e.order - 2;
        // If we assign value to leaves nodes, whose parents nodes are empty
        if (value != 0 && SqBiTree[(i + 1) / 2 - 1] == 0)
            return false;
            // If we assign null value to parents nodes, whose leaves nodes are not empty
        else if (value == 0 && (SqBiTree[i * 2 + 1] != 0 || SqBiTree[i * 2 + 2] != 0))
            return false;
        SqBiTree[i] = value;
        return true;
    }

    /*
        Condition: Binary tree is exist, e is the node of tree
        Result: If e ist not the root node of tree, return its parents, otherwise return null
    */
    public int Parent(int e)
    {
        int i;
        // If this is an empty tree
        if (SqBiTree[0] == 0)
            return 0;
        for (i = 1; i <= MAX_TREE_SIZE - 1; i++)
            if (SqBiTree[i] == e)
                return SqBiTree[(i + 1) / 2 - 1];
        return 0;
    }

    /*
        Condition: Binary tree is exist, e is the node of tree
        Result: Return left child of e, if e has not left child, return "null"
    */
    public int LeftChild(int e)
    {
        int i;
        // If this is an empty tree
        if (SqBiTree[0] == 0)
            return 0;
        for (i = 0; i <= MAX_TREE_SIZE - 1; i++)
            if (SqBiTree[i] == e)
                return SqBiTree[i * 2 + 1];
        return 0;
    }

    /*
        Condition: Binary tree is exist, e is the node of tree
        Result: Return right child of e, if e has not right child, return "null"
    */
    public int RightChild(int e)
    {
        int i;
        // If this is an empty tree
        if (SqBiTree[0] == 0)
            return 0;
        for (i = 0; i <= MAX_TREE_SIZE - 1; i++)
            if (SqBiTree[i] == e)
                return SqBiTree[i * 2 + 2];
        return 0;
    }

    /*
        Condition: Binary tree is exist, e is the node of tree
        Result: Return left sibling of e. If e is left child of tree or has no left siblings, then return "null"
    */
    public int LeftSibling(int e)
    {
        int i;
        // If this is an empty tree
        if (SqBiTree[0] == 0)
            return 0;
        for (i = 1; i <= MAX_TREE_SIZE - 1; i++)
            if (SqBiTree[i] == e && i % 2 == 0)
                return SqBiTree[i - 1];
        return 0;
    }

    /*
        Condition: Binary tree is exist, e is the node of tree
        Result: Return right sibling of e. If e is right child of tree or has no right siblings, then return "null"
    */
    public int RightSibling(int e)
    {
        int i;
        // If this is an empty tree
        if (SqBiTree[0] == 0)
            return 0;
        for (i = 1; i <= MAX_TREE_SIZE - 1; i++)
            if (SqBiTree[i] == e && i % 2==1)
                return SqBiTree[i + 1];
        return 0;
    }

    public void PreTraverse(int e)
    {
        visit(SqBiTree[e]);
        if (SqBiTree[2 * e + 1] != 0)
            PreTraverse(2 * e + 1);
        if (SqBiTree[2 * e + 2] != 0)
            PreTraverse(2 * e + 2);
    }

    public boolean PreOrderTraverse()
    {
        if (!BiTreeEmpty())
            PreTraverse(0);
        System.out.printf("\n");
        return true;
    }

    public void InTraverse(int e)
    {
        if (SqBiTree[2 * e + 1] != 0)
            InTraverse(2 * e + 1);
        visit(SqBiTree[e]);
        if (SqBiTree[2 * e + 2] != 0)
            InTraverse(2 * e + 2);
    }

    public boolean InOrderTraverse()
    {
        if (!BiTreeEmpty())
            InTraverse(0);
        System.out.printf("\n");
        return true;
    }

    public void PostTraverse(int e)
    {
        if (SqBiTree[2 * e + 1] != 0)
            PostTraverse(2 * e + 1);
        if (SqBiTree[2 * e + 2] != 0)
            PostTraverse(2 * e + 2);
        visit(SqBiTree[e]);
    }

    public boolean PostOrderTraverse()
    {
        if (!BiTreeEmpty())
            PostTraverse(0);
        System.out.printf("\n");
        return true;
    }

    // Sequence traverse binary tree
    public void LevelOrderTraverse()
    {
        int i = MAX_TREE_SIZE - 1, j;
        // From the root node, traverse binary tree sequencial
        for (j = 0; j <= i; j++)
            if (SqBiTree[j] != 0)
                visit(SqBiTree[j]);
        System.out.printf("\n");
    }

    // Print binary tree according to serial number
    public void Print()
    {
        int j, k;
        Position p = new Position();
        int e;
        for (j = 1; j <= BiTreeDepth(); j++)
        {
            System.out.printf("%dth layer: ", j);
            for (k = 1; k <= Math.pow(2, j - 1); k++)
            {
                p.level = j;
                p.order = k;
                e = Value(p);
                if (e != 0)
                    System.out.printf("%d:%d ", k, e);
            }
            System.out.printf("\n");
        }
    }

/*
			     1
			/        \
		  2		        3
		/   \          /  \
	   4     5		  6    7
	  / \    /
	 8   9  10
*/
public static void main(String[] args) {
    int i;
    Position p = new Position();
    int e;
    BinaryTreeSeq bts = new BinaryTreeSeq();
    bts.InitBiTree();
    bts.CreateBiTree();
    System.out.printf("After constructing binary tree, if tree is empty?%b(1:true 0:false) depth of tree=%d\n", bts.BiTreeEmpty(), bts.BiTreeDepth());
    i = bts.Root();
    if (i!=0)
        System.out.printf("Root of the binary tree:%d\n", i);
    else
        System.out.printf("Tree is empty, no root\n");
    System.out.printf("LevelOrderTraverse:\n");
    bts.LevelOrderTraverse();
    System.out.printf("PreOrderTraverse:\n");
    bts.PreOrderTraverse();
    System.out.printf("InOrderTraverse:\n");
    bts.InOrderTraverse();
    System.out.printf("PostOrderTraverse:\n");
    bts.PostOrderTraverse();
    System.out.printf("Change node, whose layer is 3 and serial number of this layer is 2\n");
    p.level = 3;
    p.order = 2;
    e = bts.Value(p);
    System.out.printf("", e);
    System.out.printf("Node to be modified is %d please input new value: 50 \n", e);
    e = 50;
    bts.Assign(p, e);
    System.out.printf("Preorder:\n");
    bts.PreOrderTraverse();
    System.out.printf("Node %d's parents are %d, left and right child are ", e, bts.Parent(e));
    System.out.printf("%d,%d,left and right siblings are ", bts.LeftChild(e), bts.RightChild(e));
    System.out.printf("%d,%d\n", bts.LeftSibling(e), bts.RightSibling(e));
    bts.InitBiTree();
    System.out.printf("After clearing binary tree, if tree is empty?%b(1:true 0:false) depth of tree=%d\n", bts.BiTreeEmpty(), bts.BiTreeDepth());
    i = bts.Root();
    if (i!=0)
        System.out.printf("Root of binary tree is:%d\n", e);
    else
        System.out.printf("Tree is empty, no root\n");

}

}