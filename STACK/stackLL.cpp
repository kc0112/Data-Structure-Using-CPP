/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

class Stack{
    public:
    class Node{
        public:
        int data;
        Node* next;
        
        Node(int key){
            data = key;
            next = nullptr;
        }
    };
    
    Node* topPtr;
    
    Stack(){
        topPtr = nullptr;
    }
    
    int top(){
        return topPtr->data; 
    }
    
    void push(int key){
        Node * node = new Node(key);
        
        node->next = topPtr;
        topPtr = node;
    }
    
    void pop(){
        Node* temp = topPtr;
        topPtr = topPtr->next;
        delete temp;
    }
    
    int size(){
        Node* temp = topPtr;
        int size = 0;
        while(temp){
            temp = temp->next;
            size++;
        }
        
        return size;
    }
};

int main()
{
    Stack s;
    s.push(1);
    cout<<s.top()<<endl;
    s.push(8);
    s.push(4);
    s.pop();
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;
    s.push(5);
    s.push(7);
    s.push(6);
    s.pop();
    cout<<s.size();
}
