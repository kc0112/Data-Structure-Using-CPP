#include<iostream>
#include<cstdlib>
using namespace std;

struct vertex
{
    int id;
    vertex *edge[10];
}node[10];


void display(int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        cout<<"EDGE FROM NODE "<<i+1<<" ARE : ";
        for(j=0;j<n;j++)
        {
            if(node[i].edge[j]!=nullptr)
            {
                cout<<"\t"<<node[i].edge[j]->id+1;
            }
        }
        cout<<endl;
    }
}

int main()
{
    int n;
    char ch;
    cout<<"ENTER THE NUMBER OF VERTICES : ";
    cin>>n;

    for(int i{0};i<n;i++)
        {
            node[i].id=i;
            for(int j{0};j<n;j++)
                {
                    cout<<"EDGE BETWEEN "<<i+1<<" AND "<<j+1<<" (y/n) : ";
                    cin>>ch;
                    if(ch=='y')
                    {
                        node[i].edge[j]=&node[j];
                    }
                    else
                        node[i].edge[j]=nullptr;

                }
                cout<<endl;
         }

  display(n);
}


