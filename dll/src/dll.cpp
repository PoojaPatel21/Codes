

//============================================================================
// Name        : dll.cpp
// Roll No     : 2956
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
/* Department of computer engineering has two divisions.Students information along
 * with their with their percentage are stores in linked list for every division.generate
 * a combine list of students which is sorted in descending order based on their percentage (doubly linked list).
 */
#include<iostream>

#include<string.h>

using namespace std;

class node

{

           friend class list;

                      int rno;


                      float per;


                      node *next;
                      node *prev;

public:







           node(int r,float perc)

           {
rno=r;



per=perc;
                      next=NULL;
                      prev=NULL;

           }

           node()

           {

                      next=NULL;
                      prev=NULL;

           }

};

class list

{

private:

           int r;


float perc;

                      int no1;

                      node *temp,*ptr,*head;

public:

                      list()

                      {

                                 head=NULL;

                      }

           void create();

           void display();

           void merge(list,list);
           void reverse();
           void sorts();

void insert();



};
void list::sorts()
{
	node *ptr=new node();
	ptr=head;
	node  *min =new node();
	node *temp=new node();
	while(ptr->next!=NULL)
	{
		temp=ptr;
		min=ptr;
		while(temp!=NULL)
		{
			if(temp->per>min->per)
			{
				min=temp;
			}
			temp=temp->next;
		}
		if(min!=ptr)
		{
		node *t=new node();
			t->per=ptr->per;
			ptr->per=min->per;
			min->per=t->per;
			t->rno=ptr->rno;
						ptr->rno=min->rno;
						min->rno=t->rno;

		}
		ptr=ptr->next;

	}

}
void list::reverse()
{
	ptr=head;
	while(ptr->next!=NULL)
		ptr=ptr->next;
node *t=new node();
t=head->prev;
	while(ptr!=t)
	{
		cout<<"\n rollno:"<<ptr->rno;
		cout<<"\n rollno :"<<ptr->per;
		ptr=ptr->prev;
	}

}
void list::insert()
{
	int pos,cnt=1;
	cout<<"\n Enter position:";
	cin>>pos;
	cout<<"\n Enter RollNo:";

	           cin>>r;

	          cout<<"\n Enter Percentage in descending order:";
	          cin>>perc;
	ptr=new node();
	temp=new node(r,perc);

	ptr=head;
	while(ptr!=NULL)
	{

		if(pos==cnt)
		{
			ptr->next=temp;
			temp->prev=ptr;
		}
		ptr=ptr->next;
	}
	display();

}

void list::create()

{



           do

{

                      node *ptr=new node();


           cout<<"\n Enter RollNo:";

           cin>>r;

          cout<<"\n Enter Percentage in descending order:";
          cin>>perc;

           node *temp=new node(r,perc);

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
           temp->prev=ptr;

           }



           cout<<"\n Enter 1 to accept data of another member:";

           cin>>no1;



}while(no1==1);



}

void list::display()

{

           node *ptr=new node();



           if(head==NULL)

           {

                      cout<<"\n List is Empty";

           }

           else

           {

                      ptr=head;

                      while(ptr!=NULL)

                      {

                                 cout<<"\n\n\t\t\tRollNo:"<<ptr->rno;

                                 cout<<"\n\t\t\t Percentage:"<<ptr->per;
                                 ptr=ptr->next;

                      }

           }

}


void list::merge(list l1,list l2)
{



    node *ptr1=new node();
    ptr1=l1.head;
    node *ptr2=new node();
    ptr2=l2.head;
    node *ptr=new node();
    ptr=head;
    while(ptr1!=NULL&&ptr2!=NULL)
    {
        if(ptr1->per>ptr2->per)
        {
    if(head==NULL)
    {
        head=ptr1;
        ptr=ptr1;
    }
    else
    {
        ptr->next=ptr1;
        ptr1->prev=ptr;
        ptr=ptr->next;
    }
    ptr1=ptr1->next;
        }
        else
        {
            if(head==NULL)
                {
                    head=ptr2;
                    ptr=ptr2;
                }
                else
                {
                    ptr->next=ptr2;
                    ptr2->prev=ptr;
                    ptr=ptr->next;
                }
                ptr2=ptr2->next;

                    }
        }
                   while(ptr1!=NULL)
                    {
                        ptr->next=ptr1;

                       ptr1->prev=ptr;

                        ptr1=ptr1->next;
                    }
                    while(ptr2!=NULL)
                    {
                        ptr->next=ptr2;

                        ptr2->prev=ptr;
                        ptr2=ptr2->next;
                    }

display();


}
int main()

{

           int n1,n2;

           list l1;
           list l2;
           list l3;
           cout<<"\n Creating Data of Students of Division A:\n";

                                            l1.create();
                                            cout<<"\n Creating Data of Students of Division B:";
                                            l2.create();

           do

           {

                      cout<<"\n\t\tMENU:\n1.Display Data\n2.Merge both Divisions\n3.Reverse\n Choose by Number:";

                      cin>>n1;

                      switch(n1)

                      {

                      case 1:
                    	  l1.sorts();
                    	  l2.sorts();
                    	  cout<<"\n Displaying Student data of Division A:";

                          l1.display();
                          cout<<"\n Displaying Student data of Division B:";
                          l2.display();

                      break;
                      case 2:
                          cout<<"\n Displaying Merged Linked List:";
                          l3.merge(l1,l2);

                   break;
                      case 3:l1.reverse();
                      }

                      cout<<"\n Enter 1 to continue:";

                      cin>>n2;

           }while(n2==1);











return 0;

}
/*
 Creating Data of Students of Division A:

 Enter RollNo:1

 Enter Percentage in descending order:90

 Enter 1 to accept data of another member:1

 Enter RollNo:3

 Enter Percentage in descending order:86

 Enter 1 to accept data of another member:1

 Enter RollNo:55

 Enter Percentage in descending order:77

 Enter 1 to accept data of another member:0

 Creating Data of Students of Division B:
 Enter RollNo:32

 Enter Percentage in descending order:92

 Enter 1 to accept data of another member:1

 Enter RollNo:52

 Enter Percentage in descending order:87

 Enter 1 to accept data of another member:1

 Enter RollNo:9

 Enter Percentage in descending order:76

 Enter 1 to accept data of another member:0

		MENU:
1.Display Data
2.Merge both Divisions
3.Reverse
 Choose by Number:1

 Displaying Student data of Division A:

			RollNo:1
			 Percentage:90

			RollNo:3
			 Percentage:86

			RollNo:55
			 Percentage:77
 Displaying Student data of Division B:

			RollNo:32
			 Percentage:92

			RollNo:52
			 Percentage:87

			RollNo:9
			 Percentage:76
 Enter 1 to continue:1

		MENU:
1.Display Data
2.Merge both Divisions
3.Reverse
 Choose by Number:2

 Displaying Merged Linked List:

			RollNo:32
			 Percentage:92

			RollNo:1
			 Percentage:90

			RollNo:52
			 Percentage:87

			RollNo:3
			 Percentage:86

			RollNo:55
			 Percentage:77

			RollNo:9
			 Percentage:76
 Enter 1 to continue:1

		MENU:
1.Display Data
2.Merge both Divisions
3.Reverse
 Choose by Number:
 */
