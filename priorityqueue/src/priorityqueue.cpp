

//============================================================================
// Name        : PriorityQueue.cpp
// Roll No     : 2956
// Title       : Job Scheduling
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
class node
{


public:
    int d;
        int p;
        node *next;
    node()
{
        d=0;

        next=NULL;
        p=0;
}
    node(int data,int prior)
    {
        d=data;
        p=prior;
    }
    friend class Queue;
};
class Queue
{
    int data,pr;
    node *temp;
    node *ptr;
    node *front;
    node *rear;
public:
    Queue()
{
        data=0;
        pr=0;
        temp=NULL;
        front=NULL;
        rear=NULL;
        ptr=NULL;
}
    void enqueue();
    void display();
    void dequeue();
    void prior();
    int isEmpty();
};
int Queue::isEmpty()
{
    if(front==NULL)
return 1;
    return 0;
}
void Queue::dequeue()
{
    if(isEmpty()!=1)
    {
    temp=new node();
    temp=front;
    front=front->next;
    delete temp;
    display();


    }else
        cout<<"\n List is Empty,no Job to delete.";


}
void Queue::enqueue()
{
    int n;
    do
    {
    cout<<"\n Enter job ID:";
    cin>>data;
    cout<<"\n Enter job priority:";
    cin>>pr;
    temp=new node(data,pr);
    if(front==NULL)
    {
        front=temp;
        rear=temp;
    }
    else
    {
        ptr=front;
        rear->next=temp;
        rear=temp;

    }
    cout<<"\n Enter 1 to add another job:";
    cin>>n;
    }
    while(n==1);
}
void Queue::prior()
{
    node *ptr,*temp,*min;
    temp=front;
    while(temp->next!=NULL)
    {
        ptr=temp;
        min=ptr;
        while(ptr!=NULL)
        {
            if(ptr->p<min->p)
            {
                min=ptr;
            }
            ptr=ptr->next;
        }
        if(min!=temp)
        {
            int t;
            t=temp->d;
            temp->d=min->d;
            min->d=t;
            t=temp->p;
            temp->p=min->p;
            min->p=t;
        }
        temp=temp->next;
    }
    display();

}
void Queue::display()
{
    ptr=front;
    while(ptr!=rear)
    {
        cout<<"\n Job ID no."<<ptr->d<<" has priority no."<<ptr->p<<"\n";
        ptr=ptr->next;
    }
    cout<<"\n Job  IDno."<<ptr->d<<" has priority no."<<ptr->p<<"\n";

}

int main() {
    int n1,n2;
    Queue q;
    do
    {
    cout<<"\n1.Enter list of jobs\n2.Show by Priority\n3.Delete a job from the list\n4.Display the list:";
    cin>>n1;
    switch(n1)
    {
    case 1:q.enqueue();
    break;
    case 2:q.prior();
    break;
    case 3:q.dequeue();
    break;
    case 4:q.display();
    break;
    }
    cout<<"\n Enter 1 to continue:";
    cin>>n2;
    }while(n2==1);
    return 0;
}
/*
1.Enter list of jobs
2.Show by Priority
3.Delete a job from the list
4.Display the list:1

 Enter job ID:7

 Enter job priority:3

 Enter 1 to add another job:1

 Enter job ID:4

 Enter job priority:5


 Enter 1 to add another job:1

 Enter job ID:6

 Enter job priority:3

 Enter 1 to add another job:1

 Enter job ID:2

 Enter job priority:1

 Enter 1 to add another job:1

 Enter job ID:1

 Enter job priority:8

 Enter 1 to add another job:0

 Enter 1 to continue:1

1.Enter list of jobs
2.Show by Priority
3.Delete a job from the list
4.Display the list:4

 Job ID no.7 has priority no.3

 Job ID no.4 has priority no.5

 Job ID no.6 has priority no.3

 Job ID no.2 has priority no.1

 Job  IDno.1 has priority no.8

 Enter 1 to continue:1

1.Enter list of jobs
2.Show by Priority
3.Delete a job from the list
4.Display the list:2

 Job ID no.2 has priority no.1

 Job ID no.6 has priority no.3

 Job ID no.7 has priority no.3

 Job ID no.4 has priority no.5

 Job  IDno.1 has priority no.8

 Enter 1 to continue:1

1.Enter list of jobs
2.Show by Priority
3.Delete a job from the list
4.Display the list:3

 Job ID no.6 has priority no.3

 Job ID no.7 has priority no.3

 Job ID no.4 has priority no.5

 Job  IDno.1 has priority no.8

 Enter 1 to continue:0
 *
 */
