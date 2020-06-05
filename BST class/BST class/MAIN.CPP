#include<iostream>
#include<cstdlib>
#include"BST.h"
using namespace std;
int main()
{
    int Treekeys[16]={50,76,21,4,32,64,15,52,14,100,83,2,3,70,87,80};

    BST myTree;

    cout<<"Printing tree in order"<<endl;

    for(int i{0};i<16;i++)
        {
            myTree.AddLeaf(Treekeys[i]);
        }

    myTree.PrintInOrder();
    cout<<endl<<"done";
    return 0;
}
