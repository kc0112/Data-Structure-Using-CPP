#include<iostream>
#include<cstdlib>
#include"Trie.h"

Trie::Trie()
:root{nullptr}
{
}


void Trie::create_root()
{
    root=create("*");
}

node*Trie::create(char* value)
{
    node* n=new node;
    n->data=*value;
    for(int j{0};j<26;j++)
       n->child[j]=nullptr;
    return n;
}

void Trie::add(char *value)
{
  add_p(value,root);
}

void Trie::add_p(char *value,node*root)
{
    node* ptr=root;

    while(*value!='\0')
    {
        if(ptr->child[*value-'a']==nullptr)
        {
            ptr->child[*value-'a']=create(value);
        }
         ptr=ptr->child[*value-'a'];
         value++;
    }
    ++ptr->c;
}

bool Trie::searching_p(char*value,node*root)
{
    node*p=root;
    while(*value!='\0')
    {
        if(p->child[*value-'a']!=nullptr)
        {
            p=p->child[*value-'a'];
            value++;
        }
        else
            return false;
    }
    if(p->c>0)
        return true;
    else
        return false;
}

bool Trie::searching(char * value)
{
    return searching_p(value,root);
}
