//============================================================================
// Name        : Queuearray.cpp
// Author      : Pooja Patel
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
class Passenger
{
	int sno,bno;
	char name[20];
	unsigned long long adhar;
public:
	void accept()
	{
		cout<<"\n Enter name:";
		cin>>name;
		cout<<"\n Enter adhar card:";
		cin>>adhar;
		unsigned long long k=adhar;
		int cnt=0;
		while(k>0)
		{
			k=k/10;
			cnt++;
		}
		if(cnt!=12)
		{
			cout<<"\n Re-Enter:";
			cin>>adhar;
		}
		cout<<"\n enter seat number:";
		cin>>sno;
		cout<<"\n enter boggie number:";
		cin>>bno;
	}
	void display()
	{
		cout<<"\n Passenger details are:";
		cout<<"\n Name:"<<name;
		cout<<"\n Seat No:"<<sno;
		cout<<"\n Boggie no."<<bno;
		cout<<"\n Adhar no.:"<<adhar;
	}
	friend class Queue;
};
class Queue
{
public:
	Passenger P[5];
	int front,rear;
	Queue()
	{
		front=-1;
		rear=-1;
	}
	int isFull();
	int isEmpty();
	void enqueue();
	void dequeue();
	void display1();
	friend class Application;
};
int Queue::isEmpty()
{
	if(front==rear)
		return 1;
	return 0;
}
int Queue::isFull()
{
	if(rear==4)
		return 1;
	return 0;
}

void Queue::enqueue()
{
	Passenger q;
	if(isFull()!=1)
	{
	q.accept();
	if(front==-1)
	{
		front=0;
	}
	rear++;
	P[rear]=q;

	}
	else
		cout<<"\n The reservation system is closed,no longer seats can be booked!";
}
void Queue::dequeue()
{
	Passenger r;
	if(isEmpty()!=1)
	{
		cout<<"\n Your Booking has been confirmed!";
		r=P[front];
		front++;
		r.display();

	}
	else
		cout<<"\n There is no waiting list to be confirmed!";
}
void Queue::display1()
{
	if(isEmpty()!=1)
	{
	for(int i=front;i<=rear;i++)
	{
		cout<<"\n  waiting list number is:"<<i+1<<endl;
		P[i].display();
	}
	}else
		cout<<"\n The linked list is Empty";
}
class Application
{
public:
	Queue q;
	void confirm_list();
	void reserve_Waiting();


};
void Application::confirm_list()
{

	cout<<"\n Print the ticket!";
	q.dequeue();
}
void Application::reserve_Waiting()
{
	q.enqueue();
	q.display1();
}
int main() {
int n1,n2;
Application a;
do
{
	cout<<"\n1.Reserve\n2.Confirm\nChoose:";
	cin>>n1;
	switch(n1)
	{
	case 1:a.reserve_Waiting();
	break;
	case 2:a.confirm_list();
	break;
	}
	cout<<"\n Enter 1 to continue:";
	cin>>n2;
}while(n2==1);

	return 0;
}
