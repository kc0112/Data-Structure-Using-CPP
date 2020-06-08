#include<iostream>
#include<vector>
#include<string>
#include<cctype>
#define siz 30
char Stack[siz],top{-1};
using namespace std;

char pop()
    {
        char ele=Stack[top];
        top--;
        return ele;
    }


void push(char value)
{
     top++;
     Stack[top]=value;
}

int sign(char sym)
{
    if(sym=='*'||sym=='/'||sym=='+'||sym=='-')
        return 1;
    else
        return 0;
}

int precedence(char sym)
{
    if(sym=='*'||sym=='/')
        return 2;
    else
        return 1;
}

int main()
{
    vector<char>INFIX;
    vector<char>POSTFIX;
    char temp;
    string l;
    cout<<"ENTER THE EXPRESSION: ";
    cin>>l;
    for(char c:l)
    {
        INFIX.push_back(c);
    }

auto it=INFIX.begin();
   while(it!=INFIX.end())
   {
       if(*it=='(')
       {
           push(*it);
       }
      else if(isalpha(*it))
       {
           POSTFIX.push_back(*it);
       }
       else if(sign(*it)==1)
       {
               temp=pop();
           while(sign(temp)==1&&precedence(temp)>=precedence(*it))
           {
               POSTFIX.push_back(temp);
               temp=pop();
           }
           push(temp);
           push(*it);
       }
       else if(*it==')')
       {
           temp=pop();
           while(temp!='(')
           {
               POSTFIX.push_back(temp);
               temp=pop();
           }
       }
       else
        cout<<"INVALID EXPRESSION !"<<endl;

       it++;
   }
   while(top>-1)
   {
       POSTFIX.push_back(pop());
   }
   cout<<endl<<"PRINTING POSTFIX EXPRESSION:";
   for(char c:POSTFIX)
   {
       cout<<c;
   }
}
