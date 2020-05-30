#include<iostream>
using namespace std;
#define siz 4
int Queue[siz],rear{-1},FRONT{-1};

void display()
{
    cout<<"===================PRINTING ELEMENTS IN QUEUE============================"<<endl;
    if(rear==-1||FRONT>rear)
    {
        cout<<"EMPTY QUEUE";
    }
    else
    {
        for(int i{FRONT};i<=rear;i++)
            {
                cout<<Queue[i]<<" ";
            }
    }
    cout<<endl<<"========================================================================="<<endl;
}

void enqueue(int value)
{
   if(rear==siz-1)
   {
       cout<<"OVERFLOW!! CAN'T ADD ELEMENT "<<endl;
   }
   else
   {
       if(FRONT==-1)
       {
          FRONT=0;
       }
       rear++;
       Queue[rear]=value;
       display();
   }
}

void dequeue()
{
    if(rear==-1||FRONT>rear)
    {
        cout<<"UNDERFLOW!! NO ITEM LEFT TO DELETE"<<endl;
    }
    else
    {
        cout<<"DELETED "<<Queue[FRONT]<<endl;
        FRONT++;
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
