#include<iostream>
#include "Hash.h"

int main()
{
    Hash test;
    string name=" ";

    test.AddItem("Paul","Locha");
    test.AddItem("Kim","Iced Mocha");
    test.AddItem("Emma","Strawberry Smoothy");
    test.AddItem("Annie","Hot Chocolate");
    test.AddItem("Sarah","Passion Tea");
    test.AddItem("Pepper","Caramel Mocha");
    test.AddItem("Mike","Chai Tea");
    test.AddItem("Steve","Apple Cider");
    test.AddItem("Bill","Root Beer");
    test.AddItem("Marie","Skinny Latte");
    test.AddItem("Susan","Water");
    test.AddItem("Joe","Green Tea");


    cout<<"Testing function Print_Table:"<<endl;
    test.PrintTable();


     cout<<endl<<"Testing function Print_Item_In_Index:"<<endl;
    test.PrintItemInIndex(2);


   cout<<endl<<"Testing function Find_Drink:"<<endl;
    while(name!="exit")
    {
        cout<<"Search for ";
        cin>>name;
        if(name!="exit")
        {
            test.FindDrink(name);
        }
    }
   name=" ";


    cout<<endl<<"Testing function Remove_Item:"<<endl;
     while(name!="exit")
    {
        cout<<"Remove ";
        cin>>name;
        if(name!="exit")
        {
            test.RemoveItem(name);
        }
        cout<<endl<<"Refreshing HashTable......."<<endl;
        test.PrintTable();
    }
}
