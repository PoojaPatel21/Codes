//============================================================================
// Name        : stacklink.cpp
// Author      : Pooja Patel
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<stdlib.h>
using namespace std;
class node
{
	float d;
	char c;
	node *next;
public:
	node()
	{
		d=0;
		next=NULL;
		c='\0';
	}
	node(float data,char ch)
	{
		d=data;
		c=ch;
		next=NULL;
	}
	friend class stack;
};
class stack
{
char exp[10];
char rev[10];
node *top1=new node();
node *top2=new node();
public:
stack()
{
	top1=NULL;
top2=NULL;
	for(int i=0;i<10;i++)
	{
		exp[i]='\0';
	}
	for(int i=0;i<10;i++)
	{
		rev[i]='\0';
	}
}
void push1(float d);
float pop1();
void push2(char c);
char pop2();
void isOperator(char d);
void exp_eval();
void revString();
int isEmpty1();
int isEmpty2();
};
int stack::isEmpty1()
{
	if(top1==NULL)
	{
		return 1;
	}
	else
		 return 0;
}
int stack::isEmpty2()
{
	if(top2==NULL)
		return 1;
	return 0;
}
void stack::push1(float d)
{
	node *temp=new node(d,'\0');

	if(top1==NULL)
	{
		top1=temp;
	}
	else
	{
		temp->next=top1;
		top1=temp;
	}

}
float stack::pop1()
{
	node *temp=new node();
	if(isEmpty1()!=1)
	{

		temp=top1;
		float t=temp->d;
		top1=top1->next;
		delete temp;
		return t;
	}
	else
		cout<<"\n The stack is Empty!";
	}

void stack::push2(char c)
{
	node *temp=new node(0,c);
	if(top2==NULL)
	{

		top2=temp;

	}
	else
	{
		temp->next=top2;
		top2=temp;
	}

}
char stack::pop2()
{
	node *temp=new node();
	if(isEmpty2()!=1)
	{
		temp=top2;
		char ch=top2->c;
		top2=top2->next;

		delete temp;
		return ch;
	}
}

void stack::isOperator(char k)
{
	if(k=='+'||k=='-'||k=='*'||k=='/'||k=='^')
	{
	int j=0;
	switch(k)
	{
	case '+':j=1;
	break;
	case '-':j=2;
	break;
	case '*':j=3;
	break;
	case '/':j=4;
	break;
	case '%':j=5;
	break;
	case '^':j=6;
    break;
	}
	float v1=pop1();
	float v2=pop1();
	float v3;
	switch(j)
	{
	case 1:v3=v1+v2;
	push1(v3);
	break;
	case 2:v3=v2-v1;
	push1(v3);
	break;
	case 3:v3=v1*v2;
	push1(v3);
	break;
	case 4:v3=v2/v1;
	push1(v3);
	break;
	case 6:while(v1!=1)
	{
		v2*=v2;
		v1--;
	}
	v3=v2;
	push1(v3);
	}
	}
}
void stack::exp_eval()
{
	cout<<"\n Enter expression:";
	cin>>exp;
	int i=0;
	float val;
	while(exp[i]!='\0')
	{
		if(isalpha(exp[i]))
		{
			cout<<"\n Enter value of "<<exp[i];
			cin>>val;
			push1(val);
		}
		isOperator(exp[i]);
		i++;


	}
	float k=pop1();
	cout<<"\n The solution is:"<<k;
}

int main() {
	stack s;
	s.exp_eval();
}
