#include<iostream>
using namespace std;

int mini(int x,int y)
{
    if(x>=y)
        return y;
    else
        return x;
}

int main()
{
    int P[5][5],SP[5][5];
    int i,j,k;

    for(i=0;i<5;i++)
        for(j=0;j<5;j++)
           P[i][j]=0;

    P[0][0]=8;
    P[0][1]=3;
    P[0][3]=4;
    P[1][2]=7;
    P[2][0]=4;
    P[2][4]=5;
    P[3][2]=2;
    P[4][3]=1;

    cout<<"==================PATH MATRIX======================"<<endl;

    for(i=0;i<5;i++)
       {
           for(j=0;j<5;j++)
            {
                cout<<P[i][j]<<"\t";
                if(P[i][j]==0)
                    SP[i][j]=999;
                else
                    SP[i][j]=P[i][j];
            }
                 cout<<endl;
        }

        for(k=0;k<5;k++)
            for(i=0;i<5;i++)
                for(j=0;j<5;j++)
                    SP[i][j]=mini(SP[i][j],SP[i][k]+SP[k][j]);


    cout<<endl<<"==================SHORTEST PATH MATRIX======================"<<endl;
     for(i=0;i<5;i++)
       {
           for(j=0;j<5;j++)
            {
                cout<<SP[i][j]<<"\t";
            }
                 cout<<endl;
        }
}

