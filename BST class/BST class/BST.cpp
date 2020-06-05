#include<iostream>
#include<cstdlib>
#include"BST.h"
using namespace std;

BST::BST()
{
    root=NULL;
}

node* BST::CreateLeaf(int value)
{
    node* newnode=new node;
    newnode->data=value;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}

void BST::AddLeaf(int value)
{
    AddLeafPrivate(value,root);
}

void BST::AddLeafPrivate(int value,node* ptr)
{
    if(this->root==NULL)
    {
        this->root=CreateLeaf(value);
    }

    else if(value<ptr->data)
    {
        if(ptr->left!=NULL)
        {
            AddLeafPrivate(value,ptr->left);
        }
        else
        {
            ptr->left=CreateLeaf(value);
        }
    }

    else
    {
        if(ptr->right!=NULL)
        {
            AddLeafPrivate(value,ptr->right);
        }
        else
        {
            ptr->right=CreateLeaf(value);
        }
     }

}

void BST::PrintInOrder()
{
  PrintInOrderPrivate(root);
}

void BST::PrintInOrderPrivate(node* root)
{
    if(root==NULL)
        { return;}
    PrintInOrderPrivate(root->left);
    cout<<root->data<<" ";
    PrintInOrderPrivate(root->right);
}
