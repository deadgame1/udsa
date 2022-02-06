#include <iostream>
#include "queue.h"

using namespace std;

template <class T1>
class BinaryTree
{
public:
    TreeNode<T1>* root;
    void createTree()
    {
        T1 input;
        root=new TreeNode<T1>();
        TreeNode<T1>** temp;
        TreeNode<T1>** p;
        QueueLL<TreeNode<T1>**> q = QueueLL<TreeNode<T1>**>();
        cout<<"Enter root data "<<endl;
        cin>>input;
        root->data=input;
        root->lchild=root->rchild=NULL;
        q.enqueue(&root);
        while (!q.isEmpty())
        {
            p=q.dequeue();
            cout<<"Enter Left child of - "<<(*p)->data<<endl;
            cin>>input;
            if(input!=-1)
            {
                temp=new TreeNode<T1>*(); //this is the address of TreeNode, Tree Node itself is a pointer. so temp becomes a double ptr
                *temp=new TreeNode<T1>(); // this is the actual tree node. //we have to store the address of this pointer type node in Queue.
                (*temp)->data=input;
                (*temp)->lchild=(*temp)->rchild=NULL;
                (*p)->lchild=(*temp);
                q.enqueue(temp);
            }
            cout<<"Enter Right child of - "<<(*p)->data<<endl;
            cin>>input;
            if(input!=-1)
            {
                temp=new TreeNode<T1>*();
                *temp=new TreeNode<T1>();
                (*temp)->data=input;
                (*temp)->lchild=(*temp)->rchild=NULL;
                (*p)->rchild=(*temp);
                q.enqueue(temp);
            }
        }
        
        return;
    };
    void preOrder(TreeNode<T1>* tr)
    {
        if(tr){
            cout<<tr->data<<" ";
            preOrder(tr->lchild);
            preOrder(tr->rchild);
        }        
    }; 
    void postOrder(TreeNode<T1>* tr)
    {
        if(tr){
            postOrder(tr->lchild);
            postOrder(tr->rchild);
            cout<<tr->data<<" ";
        }        
    }; 
    void inOrder(TreeNode<T1>* tr)
    {
        if(tr){
            inOrder(tr->lchild);
            cout<<tr->data<<" ";
            inOrder(tr->rchild);
        }        
    };    
};

int main()
{
    BinaryTree<int> myTree = BinaryTree<int>();
    myTree.createTree();

    myTree.preOrder(myTree.root);
    cout<<endl;
    myTree.postOrder(myTree.root);
    cout<<endl;
    myTree.inOrder(myTree.root);
    cout<<endl;

    return 0;
}