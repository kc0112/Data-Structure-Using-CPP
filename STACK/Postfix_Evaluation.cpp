#include<iostream>
#include<vector>
#include<cctype>
#define siz 30
using namespace std;
char Stack[siz],top{-1};

void push(int value)
{
    top++;
    Stack[top]=value;
}

char pop()
{
    int value=Stack[top];
    top--;
   return value;
}

int main()
{
  vector<char>POSTFIX;
  cout<<"ENTER POSTFIX EXPRESSION : "<<endl;
  string s{"abc*+"};

  for(auto c:s)
        POSTFIX.push_back(c);
  auto it=POSTFIX.begin();
  while(it!=POSTFIX.end())
  {
      if(isalpha(*it))
      {
          int m;
          cout<<"Enter the value of "<<*it<<":";
          cin>>m;
          push(m);
      }
      else
      {
          int b=pop();
          int a=pop();
          switch(*it)
          {
              case '+':{int res=a+b;push(res);break;}
              case '-':{int res=a-b;push(res);break;}
              case '*':{int res=a*b;push(res);break;}
              case '/':{int res=a/b;push(res);break;}
          }
      }
      it++;
  }
  int result=pop();
  cout<<"Result : "<<result;
}
