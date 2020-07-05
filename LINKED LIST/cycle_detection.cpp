#include<iostream>
#include<cstdlib>

struct node
{
    int data;
    node*next;
}*temp{nullptr},*newnode{nullptr},*head{nullptr},*tail{nullptr};

node* create (int value)
{
  newnode=new node;
  newnode->data=value;
  newnode->next=nullptr;
  return newnode;
}

void insertion(int value)
{
    newnode=create(value);
    if(head==nullptr)
        {
            head=newnode;
            tail=newnode;
        }
        else
        {
            tail->next=newnode;
            tail=newnode;
            tail->next=head;
        }
}

void display()
{
    temp=head;
     while(temp->next!=head)
     {
         std::cout<<temp->data<<" ";
         temp=temp->next;
     }
          std::cout<<temp->data<<" ";
     std::cout<<std::endl;
}

bool cycle(node* head)
{
    node* slow=head;
    node* fast=head;
    while(fast->next!=nullptr&&fast!=nullptr)
    {
        if(fast==slow)
            return true;
        fast=fast->next->next;
        slow=slow->next;
    }
    return false;
}

int main()
{
        insertion(2);
        insertion(3);
        insertion(4);
        std::cout<<"Inserting elements in Circular LL...."<<std::endl;
        display();
        std::cout<<std::boolalpha;
        std::cout<<std::endl<<"Cycle Present : "<<cycle(head);
}
