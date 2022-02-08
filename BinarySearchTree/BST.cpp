#include <iostream>

using namespace std;

template <class T1>
class TreeNode
{
public:
    TreeNode<T1> *lchild;
    T1 data;
    TreeNode<T1> *rchild;
};

template <class T>
class BST
{
public:
    TreeNode<T> *root;
    BST()
    {
        root=NULL;
    };
    void insert(T key)
    {
        TreeNode<T> *p,*t,*tail;
        if(root==NULL)
        {
            t=new TreeNode<T>();
            t->data=key;
            t->lchild=t->rchild=NULL;
            root=t;
            return;
        }
        p=root;
        while(p)
        {
            tail=p;
            if(p->data==key)
                return;
            else if(key<p->data)
                p=p->lchild;
            else
                p=p->rchild;
        }
        t=new TreeNode<T>();
        t->data=key;
        t->lchild=t->rchild=NULL;
        if(key<tail->data)
            tail->lchild=t;
        else    
            tail->rchild=t;
    };
    void inOrder(TreeNode<T> *p)
    {
        if(p)
        {
            inOrder(p->lchild);
            cout<<p->data<<" ";
            inOrder(p->rchild);
        }
    }
};

int main()
{
    BST<int> myBST=BST<int>();
    myBST.insert(30);
    myBST.insert(10);
    myBST.insert(20);
    myBST.insert(40);
    myBST.insert(50);
    myBST.insert(60);

    myBST.inOrder(myBST.root);

    return 0;
}