#include<iostream>
using namespace std;

struct node
{
  int data;
  node*next;
}*top{nullptr},*newnode{nullptr},*temp{nullptr};

void display()
{
    cout<<"==========PRINTING ELEMENTS IN STACK============================"<<endl;
    if(top==nullptr)
    {
      cout<<"EMPTY STACK";
    }
    else
    {
        temp=top;
        while(temp!=nullptr)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
    }
    cout<<endl<<"================================================================"<<endl;
}

node* create(int value)
{
    newnode=new node;
    newnode->data=value;
    newnode->next=nullptr;
    return newnode;
}

void push (int value)
{
    if(top==nullptr)
    {
        newnode=create(value);
        top=newnode;
    }
    else
    {
        newnode=create(value);
        newnode->next=top;
        top=newnode;
    }
    display();
}

void pop ()
{
    if(top==nullptr)
        cout<<"EMPTY STACK"<<endl;
    else
    {
        temp=top;
        cout<<"DELETED "<<top->data<<endl;
        top=top->next;
        delete temp;
        display();
    }
}

int main()
{
    push(78);
    push(79);
    push(33);
    pop();
    pop();
    push(87);
}
