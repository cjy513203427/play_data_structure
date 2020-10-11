/**
 * @Author: 谷天乐
 * @Date: 2020/8/21 15:38
 * @Description:
 */
public class BinaryTreeLink {
    public final int MAXSIZE = 100;
    public static String[] strArr = new String[24];

    public boolean visit(String c){
        System.out.print(c+" ");
        return true;
    }

    public boolean StrAssign(String[] T,String chars)
    {
        if (chars.length()>MAXSIZE)
            return false;
        else
        {
            T[0] = String.valueOf(chars.length());
            for (int i = 1; i <= Integer.parseInt(T[0]); i++)
                T[i] = chars.substring(i-1,i);
            return true;
        }
    }

    // Construct empty binary tree
    public boolean InitBiTree(BiTNode T)
    {
        // Direct to make Object null, is no use
        T = null;
        return true;
    }

    /*
        Condition: binary tree is exist
        Result: destroy binary tree
    */
    public void DestroyBiTree(BiTNode T)
    {
        if (T!=null)
        {
            // If tree has left child
            if (T.lchild!=null)
                // Destroy subtree of left child
                this.DestroyBiTree(T.lchild);
            // If tree has right child
            if (T.rchild!=null)
                // Destroy subtree of right child
                this.DestroyBiTree(T.rchild);
            // Relese root node
            T.data = "";
            T.lchild = null;
            T.rchild = null;
        }
    }

    int index = 1;
    // "#" means empty tree
    public boolean CreateBiTree(BiTNode T)
    {
        String ch;
        ch = strArr[index++];

        if (ch.equals("#"))
            T.data="";
        else
        {
            if (T==null)
                return false;
            // Generate root node
            T.data = ch;
            T.lchild = new BiTNode();
            T.rchild = new BiTNode();
            // Construct left subtree
            this.CreateBiTree(T.lchild);
            // Construct right subtree
            this.CreateBiTree(T.rchild);
        }
        return true;
    }

    /*
        Condition: binary tree is exist
        Result: If tree is empty, return true, otherwise return false
    */
    public boolean BiTreeEmpty(BiTNode T)
    {
        if (T!=null)
            return false;
        else
            return true;
    }

    /*
        Condition: binary tree is exist
        Result: return the length of tree
    */
    public int BiTreeDepth(BiTNode T)
    {
        int i, j;
        if (T==null)
            return 0;
        if (T.lchild!=null)
            i = BiTreeDepth(T.lchild);
        else
            i = 0;
        if (T.rchild!=null)
            j = BiTreeDepth(T.rchild);
        else
            j = 0;
        return i>j ? i + 1 : j + 1;
    }

    /*
        Condition: binary tree is exist
        Result: return root of the tree
    */
    public String Root(BiTNode T)
    {
        if (BiTreeEmpty(T))
            return "";
        else
            return T.data;
    }

    /*
        Condition: binary tree is exist, p points to a node of the tree
        result: return data, which is pointed by p
    */
    public String Value(BiTNode p)
    {
        return p.data;
    }

    // Assign value to node, which is pointed by p
    public void Assign(BiTNode p,String value)
    {
        p.data = value;
    }

    /*
        Condition: binary tree is exist
        Result: preorder traverse
    */
    public void PreOrderTraverse(BiTNode T)
    {
        if (T == null)
            return;
        System.out.printf("%s", T.data);
        PreOrderTraverse(T.lchild);
        PreOrderTraverse(T.rchild);
    }

    /*
        Condition: binary tree is exist
        Result: inorder traverse
    */
    public void InOrderTraverse(BiTNode T)
    {
        if (T == null)
            return;
        InOrderTraverse(T.lchild);
        System.out.printf("%s", T.data);
        InOrderTraverse(T.rchild);
    }

    /*
        Condition: binary tree is exist
        Result: postorder traverse
    */
    public void PostOrderTraverse(BiTNode T)
    {
        if (T == null)
            return;
        PostOrderTraverse(T.lchild);
        PostOrderTraverse(T.rchild);
        System.out.printf("%s", T.data);
    }

    /*
             A
           /   \
          B      C
         /  \   /  \
       D    E  F    G
      /       /      \
     H       I        J
      \
       K
    */

    public static void main(String[] args) {
        BiTNode binarTreeLink = new BiTNode();
        BinaryTreeLink btl = new BinaryTreeLink();
        btl.InitBiTree(binarTreeLink);

        btl.StrAssign(strArr, "ABDH#K###E##CFI###G#J##");

        btl.CreateBiTree(binarTreeLink);

        System.out.printf("After constructing empty binary tree, if the tree is empty? %b(1:true 0:false) depth of the tree is=%d\n", btl.BiTreeEmpty(binarTreeLink), btl.BiTreeDepth(binarTreeLink));
        String e1 = btl.Root(binarTreeLink);
        System.out.printf("Root of binary tree is: %s\n", e1);

        System.out.printf("\n Preorder traverse:");
        btl.PreOrderTraverse(binarTreeLink);
        System.out.printf("\n Inorder traverse:");
        btl.InOrderTraverse(binarTreeLink);
        System.out.printf("\n Postorder traverse:");
        btl.PostOrderTraverse(binarTreeLink);
        btl.DestroyBiTree(binarTreeLink);
        System.out.printf("\n After clearing binary tree, if the tree is empty? %b(1:true 0:false) depth of the tree is=%d\n", btl.BiTreeEmpty(binarTreeLink), btl.BiTreeDepth(binarTreeLink));
        String i = btl.Root(binarTreeLink);
        if (i=="")
            System.out.printf("Tree is empty, no root\n");
    }

}