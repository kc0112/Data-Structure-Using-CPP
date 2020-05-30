#include<iostream>
#include<cstdlib>
using namespace std;

struct node
{
    int data;
    node*next;
}*newnode{nullptr},*temp{nullptr},*rear{nullptr},*FRONT{nullptr};

node* create (int value)
{
    newnode=new node;
    newnode->data=value;
    newnode->next=nullptr;
    return newnode;
}

void display()
{
    cout<<"===================PRINTING ELEMENTS IN QUEUE============================"<<endl;
    temp=FRONT;
    if(FRONT==nullptr)
    {
        cout<<"EMPTY QUEUE";
    }
    while(temp!=nullptr)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
     cout<<endl<<"========================================================================="<<endl;
}

void enqueue (int value)
{
    newnode=create(value);
    if(rear==nullptr)
    {
        FRONT=newnode;
        rear=newnode;
    }
    else
    {
       rear->next=newnode;
       rear=newnode;

    }
        display();
}

void dequeue ()
{
    if(rear==nullptr)
    {
        cout<<"UNDERFLOW!! NO ITEM LEFT TO DELETE"<<endl;
    }
    else
    {
        cout<<"DELETED "<<FRONT->data<<endl;
        temp=FRONT;
        FRONT=FRONT->next;
        delete temp;
        display();
    }
}

int main()
{
    enqueue(72);
    enqueue(36);
    enqueue(53);
    enqueue(36);
    enqueue(63);
    dequeue();
    dequeue();
    enqueue(67);
    dequeue();
}
