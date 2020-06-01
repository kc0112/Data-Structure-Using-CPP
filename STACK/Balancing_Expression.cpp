#include<iostream>
#include<vector>
#include<string>
#include<cctype>
#define siz 30
int Stack[siz],top{-1};
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

int evaluate (char temp,char item)
{
    if(temp=='{'&&item=='}')
        return 1;
    else if(temp=='['&&item==']')
        return 1;
        else if  (temp=='('&&item==')')
        return 1;
        else return 0;
}

int main()
{
    vector<char>INFIX;
    string l;
    cout<<"ENTER THE EXPRESSION: ";
    cin>>l;
    char temp;
    int res;
    for(char c:l)
    {
        INFIX.push_back(c);
    }

auto it=INFIX.begin();
   while(it!=INFIX.end())
   {
       if(*it=='('||*it=='['||*it=='{')
            {
                push(*it);
            }

    else if(*it==')'||*it=='}'||*it==']')
    {
        temp=pop();
        res=evaluate(temp,*it);
        if(res==0)
        {
            printf("IMBALANCED EXPRESSION\n");
            break;
        }
    }
       it++;
   }
   if(res==1)
  cout<<"EXPRESSION BALANCED";
}
