//=====//============================================================================
// Name        : stackslinked.cpp
// Author      : Pooja Patel
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class node
{
    int data;
    node *next;
    friend class stack;
public:
    node()
{
        next=NULL;
        data=0;
}
    node(int d)
    {
        data=d;
        next=NULL;
    }

};
class stack
{
    node *top=NULL;

    int max;
public:
    void push();
    void pop();
    int isEmpty();

    void display_top();


};
int stack::isEmpty()
{
    if(top==NULL)
    return 1;
    else
        return 0;

    }


void stack::push()

{

	int j=1;
	 int d;
	do
	{

    cout<<"\n Enter new data:";
    cin>>d;
        node *temp=new node(d);
    if(top==NULL)
        top=temp;
    else
    {

    temp->next=top;
    top=temp;
    }
    cout<<"\n Enter 1 to add new node:";
    cin>>j;
	}  while(j==1);

}
void stack::pop()
{
    if(isEmpty()==1)
        cout<<"\n Stack is empty so no element can be popped!";
    else
    {
        node *temp=new node();
        temp=top;
        top=top->next;
        delete temp;

    }
}
void stack::display_top()
{

    node *ptr;
    ptr=top;

    while(ptr!=NULL)
    {
        cout<<" "<<ptr->data;
        ptr=ptr->next;
    }

}

int main() {
    stack s;
    int no1,no2;
    do
    {
        cout<<"\n ***MENU***\n1.Push\n2.Pop\nChoose:";
        cin>>no1;
        switch(no1)
        {
        case 1:s.push();
        s.display_top();
        break;
        case 2:s.pop();
        s.display_top();
        break;


        }
        cout<<"\n Do you wish to continue?Press 1 to continue:";
        cin>>no2;

    }while(no2==1);

    return 0;
}



