//============================================================================
// Name        : polynomiallinked.cpp
// Author      : Pooja Patel
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
class node
{

	friend class poly;
	node *next;
			int coef,exp;
public:


	node()
	{
		next=NULL;

	}
	node(int d1,int d2)
	{

		next=NULL;
		coef=d1;
		exp=d2;
	}

};
class poly
{

	int x,y;

	node *head,*ptr,*temp;
public:

	void accept();
	void display();
	void add(poly,poly);
	poly()
	{
		head=NULL;
	}


};
void poly::accept()
{
	int no;
	head=NULL;
	do
	{
	ptr=new node();
cout<<"\n Enter coefficient:";
	cin>>x;
	cout<<"\n Enter Exponent: ";
	cin>>y;
	temp=new node(x,y);
	if(head==NULL)
	{

		head=temp;

	}
	else
	{
		ptr=head;
		while(ptr->next!=NULL)
		{
			ptr=ptr->next;
		}

		ptr->next=temp;




	}
	cout<<"\n Do you want another Node? Press 1 for yes:";
	cin>>no;
	}while(no==1);

}
void poly::display()
{
	node *ptr=head;
	while(ptr->next!=NULL)
	{
		cout<<ptr->coef<<"x^"<<ptr->exp<<"+"<<" ";
		ptr=ptr->next;
	}
	cout<<ptr->coef<<"x^"<<ptr->exp<<"\n";
}
void poly::add(poly p1,poly p2)
{

poly p3;
	p1.ptr=p1.head;
	p2.ptr=p2.head;

	p3.ptr=p3.head;
	while((p1.ptr!=NULL)&&(p2.ptr!=NULL))
	{
		if(p1.ptr->exp>p2.ptr->exp)
		{
			p3.ptr->exp=p1.ptr->exp;;
			p3.ptr->coef=p1.ptr->coef;
			p1.ptr=p1.ptr->next;
		}

		else if(p1.ptr->exp<p2.ptr->exp)
			{
				p3.ptr->exp=p2.ptr->exp;;
				p3.ptr->coef=p2.ptr->coef;
				p2.ptr=p2.ptr->next;
			}
		else
		{
			p3.ptr->coef=p1.ptr->coef+p2.ptr->coef;
			p3.ptr->exp=p1.ptr->exp;
			p1.ptr=p1.ptr->next;
			p2.ptr=p2.ptr->next;
		}
		p3.ptr=p3.ptr->next;
		node *ptr3=new node();
		if(p1.ptr!=NULL)
			ptr3=p1.ptr;
		else if(p2.ptr!=NULL)
			ptr3=p2.ptr;
		while(ptr3!=NULL)
		{
			p3.ptr->coef=ptr3->coef;
			p3.ptr->exp=ptr3->exp;
			cout<<"+"<<p3.ptr->coef<<"x^"<<p3.ptr->exp;
		}


	}
	p3.display();

}
int main() {
	int no1,no2;
	poly p1,p2;
	poly p,p3;
	do
	{
		cout<<"\nMENU:\n1.Accept Poly 1\n2.Display Poly 1\n3.Accept Poly 2\n4.Display Poly 2\n5.Add\nChoose:";
		cin>>no1;
		switch(no1)
		{
		case 1:

				p1.accept();


		break;
		case 2:p1.display();
		break;
		case 3:

						p2.accept();


				break;
				case 4:p2.display();
				break;
				case 5:p3.add(p1,p2);
				p3.display();

				break;
		}
		cout<<"\n Do you wish to continue?Enter 1 to continue:";
		cin>>no2;
	}while(no2==1);

	return 0;
}
