#include<iostream>
#include<cstdlib>
#include<vector>
#include<cctype>
#include<string>
#include<stack>
#define siz 30
using namespace std;


struct node
{
    char data;
    node* left,*right;
}*root=nullptr;

node* tree_stack [siz];
int top{-1};

node* create(char value)
{
        node* newnode=new node;
        newnode->data=value;
        newnode->left=newnode->right=NULL;
        return newnode;
}

node* pop()
{
        node* ele=tree_stack [top];
        top--;
        return ele;
}

void push(node* value)
{
     top++;
     tree_stack[top]=value;
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

void display_i(node*root)
{
 if(root==NULL)
        return ;
 display_i (root->left);
  cout<<root->data;
 display_i (root->right);
}

void display_pr(node*root)
{
 if(root==NULL)
        return ;
  cout<<root->data;
 display_pr(root->left);
 display_pr (root->right);
}

void display_po(node*root)
{
 if(root==NULL)
        return ;
 display_po (root->left);
 display_po (root->right);
   cout<<root->data;
}


int main()
{
    vector<char>INFIX;
    vector<char>POSTFIX;
    std::stack<char>s;
    char temp;
    cout<<"ENTER THE INFIX EXPRESSION : ";
    string l;
    cin>>l;

    for(char c:l)
    {
        INFIX.push_back(c);
    }

   auto it=INFIX.begin();
   while(it!=INFIX.end())
   {
       int flag=0;
       if(*it=='(')
       {
           s.push(*it);
       }
      else if(isalpha(*it))
       {
           POSTFIX.push_back(*it);
       }
       else if(sign(*it)==1)
       {
              if(s.size()!=0)
              {
               temp=s.top();
                 s.pop();
           while(sign(temp)==1&&precedence(temp)>=precedence(*it))
           {
               POSTFIX.push_back(temp);
               if(s.size()==0)
               {
                   flag++;
                  break;
               }

               temp=s.top();
           }
           if(flag==0)
             s.push(temp);
              }
           s.push(*it);
       }
       else if(*it==')')
       {
           temp=s.top();
           s.pop();
           while(temp!='(')
           {
               POSTFIX.push_back(temp);
               temp=s.top();
               s.pop();
           }
       }
       else
        cout<<"INVALID EXPRESSION !"<<endl;

       it++;
   }
   while(s.size()!=0)
   {
       POSTFIX.push_back(s.top());
       s.pop();
   }

   // tree stack
    for(char c:POSTFIX)
    {
       node* char_node=create(c);
        if(isalpha(c))
         push(char_node);
        else
        {
            root=char_node;
            root->right=pop();
            root->left=pop();
            push(root);
        }
    }
    root=pop();
    int choice;
    cout<<endl<<"FOR INFIX : PRESS 1\nFOR PREFIX : PRESS 2\nFOR POSTFIX : PRESS 3\nANY OTHER KEY TO EXIT"<<endl;
    cout<<"CONVERSION TO :";
    cin>>choice;
    switch(choice)
    {
        cout<<endl;
        case 1:{display_i(root);break;}
        case 2:{display_pr(root);break;}
        case 3:display_po(root);
        default:cout<<endl<<"THANKYOU"<<endl;
    }
}

