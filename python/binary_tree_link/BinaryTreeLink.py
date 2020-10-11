# -*- encoding: utf-8 -*-
'''
@File    :   BinaryTreeLink.py    
@Modify Time      @Author       @Desciption
------------      -------       -----------
2020/8/20 11:54   Jonas           None
'''


class BiTNode(object):
    def __init__(self):
        self.data = 0
        self.lchild = None
        self.rchild = None


MAXSIZE = 100

strArr = []


class BinaryTreeLink(object):
    def visit(self, element):
        print(element, end=" ")

    def StrAssign(self, T, chars):
        if len(chars) > MAXSIZE:
            return False
        else:
            # T[0] = chars.length
            T.append(len(chars))
            for i in range(1, T[0] + 1):
                T.append(chars[i - 1])
            return True

    # Construct empty binary tree
    def InitBiTree(self, T):
        T = None
        return True

    '''
        Condition: binary tree is exist
        Result: destroy binary tree
    '''

    def DestroyBiTree(self, T):
        if T:
            # If tree has left child
            if T.lchild:
                # Destroy subtree of left child
                self.DestroyBiTree(T.lchild)
            # If tree has right child
            if T.rchild:
                # Destroy subtree of right child
                self.DestroyBiTree(T.rchild)
            # Relese root node
            T.data = None
            T.lchild = None
            T.rchild = None

    # "#" means empty tree
    def CreateBiTree(self, T, index):
        ch = strArr[index]
        index += 1
        if ch == '#':
            T = None
        else:
            if T is None:
                return False
            # Generate root node
            T.data = ch
            T.lchild = BiTNode()
            T.rchild = BiTNode()
            # Construct left subtree
            self.CreateBiTree(T.lchild, index)
            # Construct right subtree
            self.CreateBiTree(T.rchild, index)

    '''
        Condition: binary tree is exist
	    Result: If tree is empty, return true, otherwise return false
    '''

    def BiTreeEmpty(self, T):
        if T.data != None:
            return False
        else:
            return True

    '''
        Condition: binary tree is exist
        Result: return the length of tree
    '''

    def BiTreeDepth(self, T):
        if T is None:
            return 0
        if T.lchild:
            i = self.BiTreeDepth(T.lchild)
        else:
            i = 0;
        if T.rchild:
            j = self.BiTreeDepth(T.rchild)
        else:
            j = 0
        return i + 1 if i > j else j + 1

    '''
        Condition: binary tree is exist
	    Result: return root of the tree
    '''

    def Root(self, T):
        if self.BiTreeEmpty(T):
            return 0
        else:
            return T.data

    '''
        Condition: binary tree is exist, p points to a node of the tree
	    result: return data, which is pointed by p
    '''

    def Value(self, p):
        return p.data

    # Assign value to node, which is pointed by p
    def Assign(self, p, value):
        p.data = value

    '''
        Condition: binary tree is exist
	    Result: inorder traverse
    '''

    def PreOrderTraverse(self, T):
        if T is None:
            return False
        print("%s" % T.data)
        self.PreOrderTraverse(T.lchild)
        self.PreOrderTraverse(T.rchild)

    '''
        Condition: binary tree is exist
	    Result: inorder traverse
    '''

    def InOrderTraverse(self, T):
        if T is None:
            return False
        self.InOrderTraverse(T.lchild)
        print("%s" % T.data)
        self.InOrderTraverse(T.rchild)

    '''
        Condition: binary tree is exist
        Result: postorder traverse
    '''

    def PostOrderTraverse(self, T):
        if T is None:
            return False
        self.PostOrderTraverse(T.lchild)
        self.PostOrderTraverse(T.rchild)
        print("%s" % T.data)

'''
		 A
	   /   \
	  B      C
	 /  \   /  \
   D    E  F    G
  /       /      \
 H       I        J
  \
   K
'''
if __name__ == '__main__':
    btl = BinaryTreeLink()
    BinarTreeLink = BiTNode()
    btl.InitBiTree(BinarTreeLink)

    btl.StrAssign(strArr, "ABDH#K###E##CFI###G#J##")

    btl.CreateBiTree(BinarTreeLink,1)

    print(
        "After constructing empty binary tree, if the tree is empty? %d(1:true 0:false) depth of the tree is=%d\n"
        %(btl.BiTreeEmpty(BinarTreeLink), btl.BiTreeDepth(BinarTreeLink)))
    e1 = btl.Root(BinarTreeLink)
    print("Root of binary tree is: %c\n" %e1)

    print("\n Preorder traverse:")
    btl.PreOrderTraverse(BinarTreeLink)
    print("\n Inorder traverse:")
    btl.InOrderTraverse(BinarTreeLink)
    print("\n Postorder traverse:")
    btl.PostOrderTraverse(BinarTreeLink)
    btl.DestroyBiTree(BinarTreeLink)
    print("\n After clearing binary tree, if the tree is empty? %d(1:true 0:false) depth of the tree is=%d\n"
                %(btl.BiTreeEmpty(BinarTreeLink), btl.BiTreeDepth(BinarTreeLink)))
    i = btl.Root(BinarTreeLink)
    if i is None:
        print("Tree is empty, no root\n")