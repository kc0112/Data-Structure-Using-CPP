#include<iostream>
#include<stack>
#include<cstdlib>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
}*root=NULL;


node* insertion (node* root,int n)
{
    if (root==NULL)
    {
        root=new node;
        root->data=n;
        root->left=root->right=NULL;
        return root;
    }

    else
   {
        if (n<root->data)
            root->left=insertion(root->left,n);
        else
            root->right=insertion (root->right,n);
        return (root);
    }
}

bool leaf(node* curr)
{
   if(curr->right==nullptr&&curr->left==nullptr)
        return true;
   else
    return false;
}

void display(node* root)
{
    stack<node*>s;
    s.push(root);
    while(!s.empty())
    {
        node* curr=s.top();
        if(leaf(curr))
        {
            node*temp=s.top();
            s.pop();
            cout<<temp->data<<" ";
        }
        else
        {
            if(curr->right!=nullptr)
            {
                s.push(curr->right);
                curr->right=nullptr;
            }

            if(curr->left!=nullptr)
            {
                s.push(curr->left);
                curr->left=nullptr;
            }
        }

    }
}

int main(){

    root=insertion(root,40);
    root=insertion(root,50);
    root=insertion(root,10);
    root=insertion(root,30);
    root=insertion(root,70);
    root=insertion(root,90);
    root=insertion(root,20);
    root=insertion(root,35);
    display(root);
}

