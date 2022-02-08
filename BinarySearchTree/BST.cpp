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
    };
    TreeNode<T>* search(T key)
    {
        TreeNode<T>* p=root;
        while(p)
        {
            if(key==p->data)
                return p;
            else if(key<p->data)
                p=p->lchild;
            else    
                p=p->rchild;
        }
        return NULL;
    };
    TreeNode<T>* Rsearch(TreeNode<T>* p, T key)
    {   
        if(p==NULL)
            return NULL; //Not found
        if(key==p->data)
            return p;
        if(key<p->data)
            Rsearch(p->lchild,key);
        else    
            Rsearch(p->rchild,key);
    };
    TreeNode<T>* Rinsert(TreeNode<T>* p, T key)
    {
        TreeNode<T>* t;
        if(p==NULL)
        {
            t=new TreeNode<T>();
            t->data=key;
            t->lchild=t->rchild=NULL;
            if(root==NULL)  
                root=t;
            return t;
        }
        if(key<p->data)
            p->lchild=Rinsert(p->lchild,key);
        else if(key>p->data)
            p->rchild=Rinsert(p->rchild,key);

        return p;
    };  
};

int main()
{
    BST<int> myBST=BST<int>();
    myBST.Rinsert(myBST.root,30);
    myBST.Rinsert(myBST.root,10);
    myBST.Rinsert(myBST.root,20);
    myBST.Rinsert(myBST.root,40);
    myBST.Rinsert(myBST.root,50);
    myBST.Rinsert(myBST.root,60);

    myBST.inOrder(myBST.root);
    cout<<endl;
    int x = 40;
    if(myBST.Rsearch(myBST.root,x)==NULL)
        cout<<"element not found"<<endl;
    else    
        cout<<"element found - "<<x<<endl;
        

    return 0;
}