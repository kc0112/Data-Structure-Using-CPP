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

void insertion_at_beg(int value)
{
   newnode=create(value);
   newnode->next=head;
   head=newnode;
}

void insertion_at_end(int value)
{
    newnode=create(value);
    tail->next=newnode;
    tail=newnode;
}

void insertion_at_any(int value,int pos)
{
    newnode=create(value);
    temp=head;
    for(int i{1};i<pos-1;i++)
        {
            temp=temp->next;
        }
        newnode->next=temp->next;
        temp->next=newnode;
}

void deletion_at_beg()
{
    temp=head;
    head=head->next;
    delete(temp);
}

void deletion_at_end()
{
    temp=head;
    while(temp->next!=tail)
        temp=temp->next;
    temp->next=nullptr;
    delete(tail);
    tail=temp;
}

void deletion_at_any(int pos)
{
    temp=head;
  for(int i{1};i<pos-1;i++)
  {
      temp=temp->next;
  }
  node*t=temp->next;
  temp->next=temp->next->next;
  delete(t);
}

int count_node()
{
    int c=0;
    temp=head;
    while(temp!=nullptr)
    {
        c++;
        temp=temp->next;
    }
    return c;
}

void print_reverse_list(node* temp)
{
    if(temp->next==NULL)
    {
        std::cout<<temp->data<<" ";
        return;
    }
    print_reverse_list(temp->next);
     std::cout<<temp->data<<" ";
}

void reverse_list()
{
    node* current{nullptr},*prev{nullptr},*next{nullptr};
    current=head;
    {
        while(current!=nullptr)
        {
            next=current->next;
            current->next=prev;
            prev=current;
            current=next;
        }
    }
    head=prev;
}

int main()
{
        insertion(2);
        insertion(3);
        insertion(4);
        std::cout<<"Inserting elements...."<<std::endl;
        display();
        insertion_at_beg(1);
        std::cout<<"Inserting element at beginning...."<<std::endl;
        display();
        insertion_at_end(6);
        std::cout<<"Inserting element at end...."<<std::endl;
        display();
        insertion_at_any(5,5);
        std::cout<<"Inserting element anywhere...."<<std::endl;
        display();
        deletion_at_beg();
        std::cout<<"deleting element at beginning...."<< std::endl;
        display();
        deletion_at_end();
        std::cout<<"deleting element at end...."<< std::endl;
        display();
        deletion_at_any(3);
        std::cout<<"deleting element anywhere...."<< std::endl;
        display();
        std::cout<<"Counting no. of nodes......."<<std::endl<<"TOTAL NODES : "<<count_node()<<std::endl;

        std::cout<<"Reversing the linked list........"<<std::endl;
        reverse_list();
        display();
        std::cout<<"Printing linked list in reverse order........"<<std::endl;
        node* temp2=head;
        print_reverse_list(temp2);
}




