
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

void insertion_at_beg(int value)
{
   newnode=create(value);
   newnode->next=head;
   head=newnode;
   tail->next=head;
}

void insertion_at_end(int value)
{
    newnode=create(value);
    tail->next=newnode;
    tail=newnode;
    tail->next=head;
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
    tail->next=head;
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
    tail->next=head;
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
    int c=1;
    temp=head;
    while(temp->next!=head)
    {
        c++;
        temp=temp->next;
    }
    return c;
}


int main()
{
        insertion(2);
        insertion(3);
        insertion(4);
        std::cout<<"Inserting elements in Circular LL...."<<std::endl;
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

}




