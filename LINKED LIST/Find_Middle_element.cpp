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

int middle (node* head)
{
  node* curr1 =head;
  node* curr2 =head;
  while(curr2->next!=nullptr&&curr2->next->next!=nullptr)
  {
      curr1=curr1->next;
      curr2=curr2->next->next;
  }
  return curr1->data;
}

int main()
{
        insertion(2);
        insertion(3);
        insertion(4);
        insertion(5);
        insertion(6);
        insertion(5);
        std::cout<<"Inserting elements...."<<std::endl;
        display();
        std::cout<<std::endl<<"Middle node is : "<<middle(head);
}
