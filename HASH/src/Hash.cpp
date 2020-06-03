#include "Hash.h"
#include<iostream>
#include<cstdlib>
#include<string>
using namespace std;

Hash::Hash()
{
    for(int i{0};i<tableSize;i++)
        {
            HashTable[i]= new item;
            HashTable[i]->name="empty";
            HashTable[i]->drink="empty";
            HashTable[i]->next=nullptr;
        }
}


 void Hash::RemoveItem(string name)
 {
     int index=hash_func(name);
     if(HashTable[index]->name=="empty"&&HashTable[index]->drink=="empty")
        cout<<"Item to be removed is not in Hash table"<<endl;

     else if(HashTable[index]->name==name&&HashTable[index]->next==nullptr)
         {
           HashTable[index]->name="empty";
           HashTable[index]->drink="empty";
           cout<<"Item "<<name<<" is removed"<<endl;
         }
     else if(HashTable[index]->name==name)
        {
            item*ptr=HashTable[index];
            HashTable[index]=HashTable[index]->next;
            delete ptr;
            cout<<"Item "<<name<<" is removed"<<endl;
        }
      else
        {
            item *ptr=HashTable[index];
             while(ptr->next!=nullptr&&ptr->next->name!=name)
            {
             ptr=ptr->next;
            }
            if(ptr->next==nullptr)
            {
                cout<<"Item to be removed is not in Hash table"<<endl;
            }
            else{
            item *temp=ptr->next;
            ptr->next=ptr->next->next;
            delete temp;
            cout<<"Item "<<name<<" is removed"<<endl;
            }
        }
 }

void Hash::AddItem(string name,string drink)
{
   int index =hash_func(name);
   if(HashTable[index]->name=="empty")
   {
       HashTable[index]->name=name;
       HashTable[index]->drink=drink;
   }
   else
   {
       item *ptr=HashTable[index];
      item* n=new item;
       n->name=name;
       n->drink=drink;
       n->next=nullptr;
       while(ptr->next!=nullptr)
       {
           ptr=ptr->next;
       }
       ptr->next=n;
   }
}

int Hash:: NumberOfItemsInIndex(int index)
{
    int c=0;
    if(HashTable[index]->name=="empty")
        return c;

    else
    {
         c++;
         item *ptr=HashTable[index];
    while(ptr->next!=nullptr)
    {
        c++;
        ptr=ptr->next;
    }
    return c;
    }
}

void Hash:: PrintTable()
{
    int n;
    for(int i{0};i<tableSize;i++)
        {
            n=NumberOfItemsInIndex(i);
            cout<<"-----------------------"<<endl;
            cout<<"Index = "<<i<<endl;
            cout<<HashTable[i]->name<<endl;
            cout<<HashTable[i]->drink<<endl;
            cout<<"No. of items = "<<n<<endl;
            cout<<"-----------------------"<<endl;
        }
}

void Hash::PrintItemInIndex(int index)
{
    item *ptr=HashTable[index];

    if(ptr->name=="empty")
    {
        cout<<"Index "<<index<<" is empty"<<endl;
    }

    else{
    cout<<endl<<endl<<"Printing Items In Index "<<index<<endl;
    while(ptr!=nullptr)
    {
        cout<<"-----------------------"<<endl;
        cout<<ptr->name<<endl;
        cout<<ptr->drink<<endl;
        ptr=ptr->next;
        cout<<"-----------------------"<<endl;
    }
    }
}

void Hash::FindDrink(string name)
{
    int index=hash_func(name);
    bool foundName=false;
    string drink;

    item *ptr=HashTable[index];

    while(ptr!=nullptr)
  {
    if(ptr->name==name)
    {
        foundName=true;
        drink=ptr->drink;
        break;
    }
        ptr=ptr->next;
  }
  if(foundName==true)
  {
      cout<<"Favorite drink = "<<drink<<endl;
  }
  else
    cout<<name <<"'s info was not found in the Hash Table"<<endl;
}


int Hash::hash_func (string key)
{
    int hash_key=0;
    int index;

    for(int i{0};i<key.length();i++)
        {
            hash_key+=int(key[i]);
        }

        index=hash_key%tableSize;
        return index;
}
