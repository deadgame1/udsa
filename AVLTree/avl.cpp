#include <iostream>

using namespace std;

template <class T1>
class TreeNode
{
public:
    TreeNode<T1>* lchild;
    int height;
    T1 data;
    TreeNode<T1>* rchild;
};

template <class T>
class AVL
{
public:
    TreeNode<T>* root=NULL;
    int NodeHeight(TreeNode<T>* p)
    {
        int hl, hr;
        hl=p && p->lchild ? p->lchild->height : 0;
        hr=p && p->rchild ? p->rchild->height : 0;

        return hl > hr ? hl+1:hr+1;
    };
    int BalanceFactor(TreeNode<T>* p)
    {
        int hl, hr;
        hl=p && p->lchild ? p->lchild->height : 0;
        hr=p && p->rchild ? p->rchild->height : 0;

        return hl - hr;
    };
    TreeNode<T>* LLRotation(TreeNode<T>* p)
    {
        TreeNode<T>* pl=p->lchild;
        TreeNode<T>* plr=pl->rchild;

        pl->rchild=p;
        p->lchild=plr;

        p->height=NodeHeight(p);
        pl->height=NodeHeight(pl);

        if(root==p)
            root=pl;

        return pl;
    };
    TreeNode<T>* LRRotation(TreeNode<T>* p)
    {
        TreeNode<T>* pl=p->lchild;
        TreeNode<T>* plr=pl->rchild;

        pl->rchild=plr->lchild;
        p->lchild=plr->rchild;
        plr->rchild=p;
        plr->lchild=pl;

        p->height=NodeHeight(p);
        pl->height=NodeHeight(pl);
        plr->height=NodeHeight(plr);

        if(root==p)
            root=plr;

        return plr;
    };
    TreeNode<T>* RRRotation(TreeNode<T>* p)
    {
        TreeNode<T>* pr=p->rchild;
        TreeNode<T>* prr=pr->rchild;

        pr->lchild=p;
        pr->rchild=prr;

        p->height=NodeHeight(p);
        pr->height=NodeHeight(pr);

        if(root==p)
            root=pr;

        return pr;
    };
    TreeNode<T>* RLRotation(TreeNode<T>* p)
    {
        TreeNode<T>* pr=p->rchild;
        TreeNode<T>* prl=pr->lchild;

        pr->lchild=prl->rchild;
        p->rchild=prl->lchild;
        prl->rchild=pr;
        prl->lchild=p;

        p->height=NodeHeight(p);
        pr->height=NodeHeight(pr);
        prl->height=NodeHeight(prl);

        if(root==p)
            root=prl;

        return prl;
    };
    TreeNode<T>* insert(T key, TreeNode<T>* p)
    {
        TreeNode<T>* q;
        if(p==NULL)
        {
            q=new TreeNode<T>();
            q->lchild=q->rchild=NULL;
            q->data=key;
            q->height=1;
            return q;
        }

        if(key<p->data)
            p->lchild=insert(key, p->lchild);
        else if(key>p->data)
            p->rchild=insert(key, p->rchild);

        p->height=NodeHeight(p);

        if(BalanceFactor(p)==2 &&  BalanceFactor(p->lchild)==1)
            return LLRotation(p);
        else if(BalanceFactor(p)==2 &&  BalanceFactor(p->lchild)==-1)
            return LRRotation(p);
        else if(BalanceFactor(p)==-2 &&  BalanceFactor(p->rchild)==-1)
            return RRRotation(p);
        else if(BalanceFactor(p)==-2 &&  BalanceFactor(p->rchild)==1)
            return RLRotation(p);
        return p;
    };
    TreeNode<T>* InPredecessor(TreeNode<T>* p)
    {
        while(p && p->rchild)
            p=p->rchild;
        return p;
    };
    TreeNode<T>* InSuccessor(TreeNode<T>* p)
    {
        while(p && p->lchild)
            p=p->lchild;
        return p;
    };
    TreeNode<T>* Delete(TreeNode<T>* p, T key) 
    {
        TreeNode<T>* t=NULL;
        
        if(!p)
            return NULL;
        if(!p->lchild && !p->rchild && p->data==key)
        {
            if(p==root)
                root=NULL;
            delete p;
            return NULL;
        }
        if(key<p->data)
            p->lchild=Delete(p->lchild,key);
        else if(key>p->data)
            p->rchild=Delete(p->rchild,key);
        else
        {
            if(NodeHeight(p->lchild) > NodeHeight(p->rchild))
            {
                t=InPredecessor(p->lchild);
                p->data=t->data;
                p->lchild=Delete(p->lchild,t->data);
            }
            else
            {
                t=InSuccessor(p->rchild);
                p->data=t->data;
                p->rchild=Delete(p->rchild,t->data);
            }
        }

        //new Height after deleteion
        p->height=NodeHeight(p);
        if(BalanceFactor(p)==2 &&  BalanceFactor(p->lchild)==1) //L1
            return LLRotation(p);
        else if(BalanceFactor(p)==2 &&  BalanceFactor(p->lchild)==-1) //L-1
            return LRRotation(p);
        else if(BalanceFactor(p)==-2 &&  BalanceFactor(p->rchild)==-1) //R-1
            return RRRotation(p);
        else if(BalanceFactor(p)==-2 &&  BalanceFactor(p->rchild)==1) //R1
            return RLRotation(p);
        else if(BalanceFactor(p)==2 &&  BalanceFactor(p->rchild)==0) //L0 rotation
            return LLRotation(p);
        else if(BalanceFactor(p)==-2 &&  BalanceFactor(p->rchild)==0) //RO rotation
            return RRRotation(p);

        return p;
    };
};

int main()
{
    AVL<int> myAvl=AVL<int>();
    myAvl.root = myAvl.insert(30,myAvl.root);
    myAvl.insert(20, myAvl.root);
    myAvl.insert(10, myAvl.root);
    myAvl.insert(40, myAvl.root);

    myAvl.Delete(myAvl.root,40);

    return 0;
}