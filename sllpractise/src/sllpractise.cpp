//============================================================================
// Name        : sllpractise.cpp
// Author      : Pooja Patel
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<string.h>
using namespace std;
class node
{
	int year;
	int rno;
	char name[20];
	node *next;
public:
	node()
	{
		year=0;
		rno=0;
		int i=0;
		while(i!=19)
		{
			name[i]='\0';
			i++;
		}
		next=NULL;
	}
	node(int y,int r,char n[])
	{
		year=y;
		rno=r;
		strcpy(name,n);
		next=NULL;
	}
	friend class list;
};
class list
{
	int y,r;
	char n[20];
	node *head;
	int p=0;
	node *ptr,*temp=new node();
public:
	list()
	{
		head=NULL;
	}
	void create();
	void display();
	void  insert();
	void deletes();
	void searchp();
	void search_rno();
	void count();
};
void list::create()
{

	int n1;
	do
	{
		node *ptr=new node();
		cout<<"\n Enter the name of the student:";
		cin>>n;
		cout<<"\n Enter the roll no of the student:";
		cin>>r;
		cout<<"\n Enter the year of the student:";
		cin>>y;
		ptr=head;
		while(ptr!=NULL)
		{

			if(ptr->rno==r&&ptr->year==y)
			{
				cout<<"\n This student is already a memeber,Re-Enter your roll no & year:";
				cin>>r;
				cin>>y;
			}
			ptr=ptr->next;
		}
		if(y<2||y>4)
		{
			cout<<"\n Students from 3rd,4th and 5th year can only be a memeber";

		}
		else
		{
			node *temp=new node(y,r,n);
			p++;
			ptr=head;
			if(head==NULL)
			{
				head=temp;

			}
			else
			{
				while(ptr->next!=NULL)
				{
					ptr=ptr->next;
				}
				ptr->next=temp;
			}
		}
		cout<<"\n Enter 1 to add new member:";
		cin>>n1;
	}while(n1==1);
}
void list::insert()
{
	node *ptr=new node();
	int pos;
	cout<<"\n Enter the position at which you want to enter a new node:";
		cin>>pos;
	if(pos>p+1)
	{
		cout<<"\n The list only has "<<p<<" members,you cant enter a member at pos:"<<pos;
	}
	else
	{

	cout<<"\n Enter name of student:";
	cin>>n;
	cout<<"\n Enter year of study:";
	cin>>y;
	cout<<"\n Enter roll no:";
	cin>>r;
	ptr=head;
			while(ptr!=NULL)
			{

				if(ptr->rno==r&&ptr->year==y)
				{
					cout<<"\n This student is already a memeber,Re-Enter your roll no & year:";
					cin>>r;
					cin>>y;
				}
				ptr=ptr->next;
			}
			if(y<2||y>4)
			{
				cout<<"\n Students from 3rd,4th and 5th year can only be a memeber";

			}
			else
			{
				node *temp=new node(y,r,n);
				p++;
				if(pos==1)
				{
					temp->next=head;
					temp=head;
				}
				else
				{
					ptr=head;

					for(int i=2;i<=pos-1;i++)
					{
						ptr=ptr->next;
					}
					if(ptr->next!=NULL)
					{
						temp->next=ptr->next;
						ptr->next=temp;
					}
					else
					{
						ptr->next=temp;
						temp->next=NULL;
					}
				}
			}
}
}
void list::deletes()
{
	 int r;
	          int j=0;
	           int ye;
	           if(head!=NULL)
	           {

	                        cout<<endl<<"Enter the roll no. of the student whose data you want to delete: ";

	                           cin>>r;
	                           cout<<endl<<"Enter the year of the student whose data you want to delete:";
	                           cin>>ye;

	                           node *ptr, *temp= new node();

	                           ptr=head;

	                           if(ptr->rno==r&&ptr->year==ye)

	                           {

	                                 temp=head;

	                                 head=head->next;

	                                 delete temp;
	p--;


	                           }

	                           else

	                           {


	                           while(ptr!=NULL)
	                           {
	                               if(ptr->rno==r&&ptr->year==ye)
	                            	   j++;
	                           ptr=ptr->next;

	                           }
	                           if(j==1)
	                           {
	                        	   ptr=head;
	                        	   while(ptr->next->rno!=r||ptr->next->year!=ye)
	                        	   {
	                        		   ptr=ptr->next;
	                        	   }
	                        	   if(ptr->next!=NULL)
	                        	                              {

	                        	                               temp=ptr->next;

	                        	                                  ptr->next=ptr->next->next;

	                        	                                  delete temp;
	                        	                                  p--;

	                        	                              }
	                        	                              else
	                        	                              {
	                        	                           	   temp=ptr->next;
	                        	                           	   ptr->next=NULL;
	                        	                           	   delete temp;
	                        	                           	   p--;
	                        	                              }
	                           }
	                           else
	                               cout<<"\n Member not found!";



	           display();

	                      }
	           }
	           else
	           {
	        	   cout<<"\n List is Empty!";
	           }
}
void list::display()
{
	node *ptr=new node();
	ptr=head;
	while(ptr!=NULL)
	{
		cout<<"\n Student name:"<<ptr->name;
		cout<<"\n Student Roll No.:"<<ptr->rno;
		cout<<"\n Student  Year of Study:"<<ptr->year;
		cout<<endl;
		ptr=ptr->next;
	}
}
void list::searchp()
{
	node  *ptr=new node();
	int pos;
	int cnt=1;
	int flag=0;
	cout<<"\n Enter position at which you want to see info:";
	cin>>pos;
	if(pos>p+1)
	{
		cout<<"\n The members are only "<<p<<" Re-Enter:";
	cin>>pos;
	}
	else
	{
	ptr=head;

while(ptr!=NULL)
{
	if(pos==cnt)
	{
		cout<<"\n Student name:"<<ptr->name;


	cout<<"\n Student Roll No.:"<<ptr->rno;
	cout<<"\n Student  Year of Study:"<<ptr->year;
	cout<<endl;
	flag=1;
	break;
	}
	else
	{
		cnt++;
		flag=0;
		ptr=ptr->next;
	}

	}
if(flag==0)
{
	cout<<"\n Data not found";

}
}
}
void list::search_rno()
{
	int rn,ye;
	int k=0;
	node *ptr=new node();
	cout<<"\n Enter the roll no you want to search for:";
	cin>>rn;
	cout<<"\n Enter the year you want to search for:";
	cin>>ye;
	ptr=head;
	if(ptr->rno==rn&&ptr->year==ye)
	{
		cout<<"\n Data found at first node:";
		cout<<"\n Student name:"<<ptr->name;
					cout<<"\n Student Roll No.:"<<ptr->rno;
					cout<<"\n Student  Year of Study:"<<ptr->year;
					cout<<endl;

	}
	else
	{
		ptr=head;
		while(ptr!=NULL)
		{
			if(ptr->rno==rn&&ptr->year==ye)
				k++;
			ptr=ptr->next;

			}
		if(k==1)
		{
			ptr=head;
			while(ptr->year!=ye||ptr->rno!=rn)
			{
				ptr=ptr->next;
			}
			cout<<"\n Data found:";
			cout<<"\n Student name:"<<ptr->name;
								cout<<"\n Student Roll No.:"<<ptr->rno;
								cout<<"\n Student  Year of Study:"<<ptr->year;
								cout<<endl;



		}
		else
			cout<<"\n No such member found";
	}

}
void list::count()
{
	cout<<"\n The total members are:"<<p;
}
int main() {
	int no1,n2;
	list l;

	do
	{
		cout<<"\n1.Create a list\n2.Display List\n3.Insert new member\n4.Search by position\n5.Search by rno and year\n6.Dlete by position \n7.Count \n8.delete by rno:";
		cin>>no1;
		switch(no1)
		{
		case 1:l.create();
		break;
		case 2:l.display();
		break;
		case 3:l.insert();
		break;
		case 4:l.searchp();
		break;
		case 5:l.search_rno();
		break;
		case 6:l.deletes();
		break;
		case 7:l.count();
		break;
		}
		cout<<"\n Enter 1 to continue:";
		cin>>n2;
	}while(n2==1);

	return 0;
}
