#include<iostream>
using namespace std;
#define siz 10
int top{-1},Stack[siz];


void display()
{
    cout<<"=========PRINTING ELEMENTS IN STACK==============="<<endl;

    if(top==-1)
    {
        cout<<"EMPTY STACK";
    }
    else{
        for(int i{top};i>=0;i--)
        {
            cout<<Stack[i]<<" ";
        }}
    cout<<endl<<"================================================="<<endl;
}

void pop()
{
    if(top==-1)
    {
        cout<<"UNDERFLOW!! : NO ELEMENT LEFT TO DELETE"<<endl;
    }
    else
    {
        int ele=Stack[top];
        cout<<ele<<" is deleted"<<endl;
        top--;
        display();
    }
}

void push(int value)
{
    if(top==siz-1)
    {
        cout<<"OVERFLOW!! : CAN,T ADD ELEMENTS IN STACK"<<endl;
    }
    else
  {
     top++;
     Stack[top]=value;
     display();
  }
}


int main()
{
   push(10);
   push(56);
   push(59);
   pop();
   push(78);
   pop();
   pop();
   pop();
}
