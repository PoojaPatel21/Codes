//============================================================================
// Name        : linedlistss.cpp
// Author      : Pooja Patel
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>
using namespace std;

class node
{
public:
	int data;
	node *link;
	node()
	{
		link=NULL;
	}
	node(int d)
	{
		data=d;
		link=NULL;
	}
};
class linked
{
	node *head,*ptr,*temp;

	int d;
	int cnt=1;
	int no1;
public:
	void create()
	{

		temp=new node();
		head=temp;
		do
		{
			cout<<"\n Enter data:";
			cin>>d;
			temp=new node(d);
			temp=temp->link;
			cout<<"\n Enter 1 to create new node:";
			cin>>no1;
			cnt++;
		}while(no1==1);

		if(no1!=1)
			temp->link=NULL;


	}
	 void display()
	{
		 for(int i=0;i<cnt;i++)
		 {
		cout<<" "<<temp->data<<" "<<temp->link;
	cnt--;
		 }
	}


};


int main() {
	linked l;
	l.create();
	l.display();
}
