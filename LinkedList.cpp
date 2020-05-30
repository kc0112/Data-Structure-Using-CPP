#include<iostream>
#include<cstdlib>

struct node
{
    int data;
    node*next;
}*temp=nullptr,*newnode=nullptr,*head=nullptr,*tail=nullptr;

int main()
{
    char  ch;
    do
    {
        int value;
        newnode=new node;
        std::cout<<"Enter data:";
        std::cin>>value;
        newnode->data=value;
        newnode->next=nullptr;

        if(head==nullptr)
        {
            head=newnode;
            tail=newnode;
        }
        else
        {
            tail->next=newnode;
            tail=newnode;
        }

        std::cout<<"Press Y to continue :";
        std::cin>>ch;
    }
    while(ch=='Y');

    //display
     temp=head;
     while(temp!=nullptr)
     {
         std::cout<<temp->data<<" ";
         temp=temp->next;
     }
}
