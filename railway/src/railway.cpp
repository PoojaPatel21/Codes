



//============================================================================
// Name        : Queue.cpp
// Author      : Pooja Patel
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<string>
using namespace std;
class Pass
{
public:
    char name[20];
    int age;
    int sno;
    int bno;
   unsigned long long adhar;
    Pass()
    {
        int  i=0;
        while(name[i]!='\0')
        {
            name[i]='\0';
            i++;
        }
        sno=0;
        age=0;
        bno=0;


    }

};
class node
{
    node *next;
   int age,bno,sno;
   char name[20];
  unsigned long long adhar;

public:
    node()
{
        next=NULL;

}
    friend class Queue;
    node(int a,int s,int b1,char n[20],unsigned long long ad)
        {
          age=a;
            int i=0;
            while(n[i]!='\0')
            {
                name[i]=n[i];
                i++;
            }
            sno=s;
            bno=b1;
            next=NULL;
            adhar=ad;
        }



};
class Queue
{
    Pass p[100];

   int wait=1;
    node *temp,*ptr,*head;
    node *front;

        node *rear;
public:
    Queue()
{
      head=NULL;
      front=head;
      rear=NULL;
}
    void create();
    void enqueue();
    void dequeue();
    void display();
    int isEmpty();
};
int Queue::isEmpty()
{
    if(front==NULL)
        return 1;
    else return 0;
}
void Queue::display()
{



  ptr=head;
int cnt=wait-1;
    while(ptr!=rear->next)
    {

        cout<<"\n Waiting list number:"<<cnt;
        cout<<"\n Ticket Bookings for:"<<ptr->name;
        cout<<"\n Adhar card Number:"<<ptr->adhar;
        cout<<"\n Age:"<<ptr->age;
        cout<<"\n Boogie Number:"<<ptr->bno;
        cout<<"\n Ticket Number:"<<ptr->sno;
cnt++;
        ptr=ptr->next;


    }

}
void Queue::create()
{

    int n1=1;



    do
    {

    cout<<"\n Enter boggie number:";
        cin>>p[wait].bno;
    cout<<"\n Enter seat number:";
    cin>>p[wait].sno;
    for(int i=1;i<wait;i++)
                       {
                           if(p[wait].bno==p[i].bno&&p[wait].sno==p[i].sno)
                           {
                           cout<<"\n That seat is already reserved,book another seat:";
                           cout<<"\n Enter new Boggie:";
                           cin>>p[wait].bno;
                           cout<<"\n Enter new Seat:";
                           cin>>p[wait].sno;
                       }
                       }
    cout<<"\n Enter name of passenger:";
        cin>>p[wait].name;
        cout<<"\n Enter your 12 digit adhar number:";
       cin>>p[wait].adhar;
      unsigned long long k=p[wait].adhar;

       int cnt=0;
       do{


           k=k/10;

           cnt++;

       }  while(k>0);
       if(cnt!=12)
       {
           cout<<"\n Enter a valid adhar card number..";
           cout<<"\n Enter your 12 digit adhar number:";
           cin>>p[wait].adhar;
       }



cout<<"\n Enter age of the passenger:";
cin>>p[wait].age;
        temp=new node(p[wait].age,p[wait].sno,p[wait].bno,p[wait].name,p[wait].adhar);
        cout<<"\n The waiting number is:"<<wait;
        wait++;
        front=head;
        if(head==NULL)
        {

           // head->next=temp;
            head=temp;
            temp->next=NULL;
rear=temp;
        }
        else
        {

            rear->next=temp;

            temp->next=NULL;
            rear=temp;

        }
        cout<<"\n Enter 1 to add new data:";
                    cin>>n1;
    }while(n1==1);
    display();



}
void Queue::enqueue()
{
cout<<"\n Waiting is for "<<wait-1<<" no. of Passengers";
    cout<<"\n Enter boggie number:";
            cin>>p[wait].bno;

        cout<<"\n Enter seat number:";
        cin>>p[wait].sno;
        for(int i=1;i<wait;i++)
                    {
                        if(p[wait].bno==p[i].bno&&p[wait].sno==p[i].sno)
                        {
                        cout<<"\n That seat is already reserved,book another seat:";
                        cout<<"\n Enter new Boggie:";
                        cin>>p[wait].bno;
                        cout<<"\n Enter new Seat:";
                        cin>>p[wait].sno;
                    }
                    }
        cout<<"\n Enter name of passenger:";
            cin>>p[wait].name;
            cout<<"\n Enter your 12 digit adhar number:";
                  cin>>p[wait].adhar;
                   unsigned long long k=p[wait].adhar;

                  int cnt=0;
                  do{


                      k=k/10;

                      cnt++;

                  }  while(k>0);
                  if(cnt!=12)
                  {
                      cout<<"\n Enter a valid adhar card number..";
                      cout<<"\n Enter your 12 digit adhar number:";
                      cin>>p[wait].adhar;
                  }

            cout<<"\n Enter age:";
            cin>>p[wait].age;

            temp=new node(p[wait].age,p[wait].sno,p[wait].bno,p[wait].name,p[wait].adhar);
            wait++;
            front=head;
            if(front==NULL)
                    {

                       // head->next=temp;
head=temp;
                        temp->next=NULL;
            rear=temp;
                    }
            else
            {
            rear->next=temp;
            temp->next=NULL;
            rear=temp;
            }
            cout<<"\n The Bookings are:";
            display();

}
void Queue::dequeue()
{
    if(isEmpty()!=1)
    {
    ptr=front;
    cout<<"\n Your Booking has been confirmed!:";

    cout<<"\n Name of Passenger:"<<ptr->name;
    cout<<"\n Adhar card Number:"<<ptr->adhar;
    cout<<"\n Passengers age:"<<ptr->age;
    cout<<"\n Seat Number:"<<ptr->sno;
    cout<<"\n Boggie Number:"<<ptr->bno;
    cout<<"\n Kindly print the above Ticket.Thank You!"<<endl;

    front=front->next;
    ptr->next=NULL;
    delete ptr;

wait--;
    display();
    }
    else
        cout<<"\n There is no waiting list to confirm!";
}

int main() {
    int n1,n2;
    Queue q;
    do
    {
        cout<<"\n Menu\n1.Book for many people\n2.Add New Booking to waiting List \n3.Confirm Booking \nChoose:";
        cin>>n2;
        switch(n2)
        {
        case 1:q.create();
        break;
        case 2:q.enqueue();
        break;
        case 3:q.dequeue();
        break;
        }
        cout<<"\n Enter 1 to continue:";
        cin>>n1;
    }while(n1==1);
    return 0;
    }





