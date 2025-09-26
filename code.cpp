#include<iostream>
using namespace std;
struct Node{
    int data;
    Node *next;
};
class Stack{
    public:
    long size;
    Node *top;
    Stack();
    Node *createNode(int v);
    void push(int v);
    void show();


};
Stack::Stack(){
    size=0;
    top=NULL;
}
Node* Stack::createNode(int v){
    Node *p=new Node();
    p->data=v;
    p->next=NULL;
    return p;
}
void Stack::push(int v){
    Node *p=createNode(v);
    if(top==NULL)
    top=p;
    else{
        p->next=top;
        top=p;
    }
    
}
void Stack::show(){
    for(Node *i=top;i!=NULL;i=i->next)
      cout<<i->data <<" " ;
}



int main() {
    Stack a;
    a.push(5);
    a.push(10);
    a.push(15);
    a.show();
    
}