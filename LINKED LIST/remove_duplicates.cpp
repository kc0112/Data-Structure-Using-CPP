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
        }
}

void display()
{
    temp=head;
     while(temp!=nullptr)
     {
         std::cout<<temp->data<<" ";
         temp=temp->next;
     }
     std::cout<<std::endl;
}

void duplicates(node* head)
{
   node* curr=head;
  while(curr!=nullptr){
         node* temp=curr;
    while(temp->next!=nullptr)
   {
       if(temp->next->data==curr->data)
       {
           node*c =temp->next;
           temp->next=temp->next->next;
          delete(c);
       }
       else
       temp=temp->next;
   }
   curr=curr->next;
 }
 display();
}

int main()
{
        insertion(2);
        insertion(3);
        insertion(4);
        insertion(5);
        insertion(2);
        insertion(5);
        std::cout<<"Inserting elements...."<<std::endl;
        display();
        std::cout<<std::endl<<"Removing Duplicates...."<<std::endl;
        duplicates(head);
}

