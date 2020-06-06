#include<iostream>
#include<cstdlib>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
}*root=NULL;

 node* LL(node*);
 node* RR(node*);
 node*insertion (node*,int);
 int height(node*);
 void display(node*);
 int m(int,int);
 int balancefact(node*);


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

void display(node*root)
{
 if(root==NULL)
        return ;
 display (root->left);
  cout<<root->data<<" ";
 display (root->right);
}

int height(node*root)
 {
     if(root==NULL)
         return (-1);
    int left,right;
    left = height(root->left);
    right=height (root->right);
    return (m(left,right)+1);
 }

 int m(int L,int R)
 {
     if(L>R)
    return L;
    else
        return R;
 }

 int balancefact(node*root)
{
    int b=height(root->left)-height(root->right);
    return (b);
}

node* RR(node* root)
{
    node* newroot=root->right;
    root->right=newroot->left;
    newroot->left=root;
    return (newroot);
}

node* LL(node* root)
{
    node* newroot=root->left;
    root->left=newroot->right;
    newroot->right=root;
    return (newroot);
}

int main()
{
    int value;
    do{
   cout<<"ENTER THE KEY TO INSERT IN TREE (-1 to exit) : ";
   cin>>value;
   if(value==-1)
    break;
   root=insertion(root,value);
   display(root);
   int BF=balancefact(root);
   cout<<endl<<BF<<endl;

   if(BF>1||BF<-1)
   {
       if(BF>1)
       {
            if(height(root->left->left)>height(root->left->right))
            {
                root=LL(root);
            }
            else
            {
                root->left=RR(root->left);
                root=LL(root);
            }
       }
        else
        {
            if(height(root->right->right)>height(root->right->left))
               {
                   root=RR(root);
               }
            else
               {
                root->right=LL(root->right);
                root=RR(root);
               }
        }

         cout<<"UNBALANCED,CHANGIN TO BALANCED:\n";
           display(root);
            BF=balancefact(root);
           cout<<endl<<BF<<endl;
   }

    }while(value!=-1);

   cout<<"\nDisplaying Final Tree........................."<<endl;
   display(root);
}



