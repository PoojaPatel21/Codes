/* Title:
Department of computer engineering has a Student Branch.Students of 2nd,3rd and final year can subscribe to membership.
Design a System to manage the CSI Student branch information.Choose appropriate ds,write the following cpp operations:
1.Add new member
2.Display member information
3.Display total number of members
Roll No:2956
*/
#include<iostream>

#include<string.h>

using namespace std;

class node

{

           friend class list;

           char name[20];

                      int rno;

                      int year;



                      node *next;

public:







           node(char n[],int r,int y)

           {

                      strcpy(name,n);

                      rno=r;

                      year=y;

                      next=NULL;

           }

           node()

           {

                      next=NULL;

           }

};

class list

{

private:

           int r,y;
           int p=0;

                      char n[20];

                      int no1;

                      node *temp,*ptr,*head;

public:

                      list()

                      {

                                 head=NULL;

                      }

           void create();

           void display();

           void insertnode();

           void deletenode();

           void search();

           void searchp();

           void count();
           int isEmpty();



};
int list::isEmpty()
{
	if(head==NULL)
	return 1;
	return 0;
}
void list::count()
{
    int cnt=0;
    ptr=head;
    if(isEmpty()==0)
    {
    while(ptr->next!=NULL)
    {
        cnt++;
        ptr=ptr->next;

    }

    cnt++;
    cout<<"\n Number of CSI Branch members are :"<<cnt;
    }
    else
    	cout<<"\n There are no CSI Members!";
}

void list::searchp()

{

	node *ptr=new node();
           int pos,cnt;

           cnt=1;

           cout<<"\n Enter position whose data you want to see:";

           cin>>pos;


           ptr=head;

           int flag=0;

           while(ptr!=NULL)

           {

                      if(pos==cnt)

                      {

                          cout<<"\n Name:"<<ptr->name<<"\n RollNo:"<<ptr->rno<<"\n Year:"<<ptr->year;
                          flag=1;

                                 break;

                      }

                      else

                                 cnt++;

                      ptr=ptr->next;

           }
           if(flag==0)
               cout<<"\n Member not found at such a position";

}

void list::search()

{


           int q;
           int t;
           int l=0;
           cout<<"\n Enter the year:";
            cin>>t;

           cout<<"\n Enter the roll no:";

           cin>>q;


           ptr=head;

           if(ptr->rno==q&&ptr->year==t)

           {

                      cout<<"\n Name:"<<ptr->name<<"\n RollNo:"<<ptr->rno<<"\n Year:"<<ptr->year;

           }

           else

           {

           while(ptr!=NULL)

           {
        	   if(ptr->rno==q&&ptr->year==t)
        		   l++;

                      ptr=ptr->next;

           }
           if(l==1)
           {
        	   ptr=head;
        	   while(ptr->rno!=q||ptr->year!=t)
        	   {
        		   ptr=ptr->next;
        	   }
        	   if(ptr->next!=NULL)
        	   {
        		   cout<<"\n Data found :";

        		              cout<<"\n Name:"<<ptr->name<<"\n RollNo:"<<ptr->rno<<"\n Year:"<<ptr->year;

        	   }
        	   else
        	   {
        		   cout<<"\n Data found :";

               cout<<"\n Name:"<<ptr->name<<"\n RollNo:"<<ptr->rno<<"\n Year:"<<ptr->year;
        	   }

}
else
    cout<<"\n Member not found!";

}
}

void list::create()

{



           do

{

                      node *ptr=new node();

           cout<<"\n Enter  name of the member:";

           cin>>n;

           cout<<"\n Enter RollNo:";

           cin>>r;



           cout<<"\n Enter Year:";

           cin>>y;
           ptr=head;
                   	                       while(ptr!=NULL)
                   	                       {
                   	                    	   if(ptr->rno==r&&ptr->year==y)
                   	                    	   {
                   	                    		   cout<<"\n This member already exists,Re-Enter ";
                   	                    		   cout<<"\n enter rno:";
                   	                    		   cin>>r;
                   	                    		   cout<<"\n enter year:";
                   	                    		   cin>>y;
                   	                    		   break;
                   	                    	   }
                   	                    	   ptr=ptr->next;
                   	                       }
           if(y<2||y>4)
                      {
                          cout<<"\n Students from 2nd,3rd,and 4th year can only be the member!";

                      }

           else
           {

p++;
           temp=new node(n,r,y);

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

                                 cout<<"\n\n\t\t\tName:"<<ptr->name<<"\n\t\t\tRollNo:"<<ptr->rno<<"\n\t\t\tYear:"<<ptr->year;

                                 ptr=ptr->next;

                      }

           }

}

void list::insertnode()

{


           int pos;
           cout<<"\n Enter the position at which you want to insert new data:";

                    cin>>pos;
           if (pos>p+1)
           {
        	   cout<<"\n The list of CSI members only has "<<p<<" members,you cannot add a member at pos "<<pos<<" ";
           }
           else
           {



           cout<<"\n Enter the Name for new data:";

           cin>>n;

           cout<<"\n Enter the RollNo for new data:";

           cin>>r;

           cout<<"\n Enter the  Year for new data:";

           cin>>y;

           if(y<2||y>4)
           {
               cout<<"\n  Students from either 2nd,3rd,or 4th year can become a member!";

           }
           else
           {

           node *temp=new node(n,r,y);

           if(pos==1)

           {

                      temp->next=head;

                      head=temp;
p++;


           }

           else

           {

p++;                      node *ptr=new node();

                      ptr=head;



                      for(int i=2;i<=pos-1;i++)

                      {

                      ptr=ptr->next;

                      }

                      temp->next=ptr->next;

                      ptr->next=temp;







           }
           }
           }

           display();

}

void list::deletenode()

                      {


          int r;
          int j=0;
           int ye;
           if(isEmpty()!=1)
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





int main()

{

           int n1,n2;

           list l;

           cout<<"\n Creating Data of Members of the CSI Branch for CCOEW :\n";

                                            l.create();

           do

           {

                      cout<<"\n\t\tMENU:\n1.Display Data\n2.Insert new Member\n3.Delete Member\n4.Search by Rollno\n5.Search by position\n6.Total Members\nChoose by Number:";

                      cin>>n1;

                      switch(n1)

                      {

                      case 1:cout<<"\n Displaying Member Data:";

                          l.display();

                      break;

                      case 2:

                             l.insertnode();

                      break;

                      case 3:cout<<"\n Deleting Data of the member you want:";

                      l.deletenode();

                      break;

                      case 4:l.search();

                      break;

                      case 5:l.searchp();

                      break;

                      case 6:l.count();

                      break;

                      }

                      cout<<"\n Enter 1 to continue:";

                      cin>>n2;

           }while(n2==1);











return 0;

}

/*
 *
 Creating Data of Members of the CSI Branch for CCOEW :

 Enter  name of the member:Andy

 Enter RollNo:12

 Enter Year:2

 Enter 1 to accept data of another member:1

 Enter  name of the member:Aamy

 Enter RollNo:13

 Enter Year:2

 Enter 1 to accept data of another member:1

 Enter  name of the member:GIna

 Enter RollNo:13

 Enter Year:3

 Enter 1 to accept data of another member:1

 Enter  name of the member:Jake

 Enter RollNo:44

 Enter Year:4

 Enter 1 to accept data of another member:1

 Enter  name of the member:Terry

 Enter RollNo:45

 Enter Year:6

 Students from 2nd,3rd,and 4th year can only be the member,re-enter the year!4

 Enter 1 to accept data of another member:0

        MENU:
1.Display Data
2.Insert new Member
3.Delete Member
4.Search by Rollno
5.Search by position
6.Total Members
Choose by Number:1

 Displaying Member Data:

            Name:Andy
            RollNo:12
            Year:2

            Name:Aamy
            RollNo:13
            Year:2

            Name:GIna
            RollNo:13
            Year:3

            Name:Jake
            RollNo:44
            Year:4

            Name:Terry
            RollNo:45
            Year:4
 Enter 1 to continue:1

        MENU:
1.Display Data
2.Insert new Member
3.Delete Member
4.Search by Rollno
5.Search by position
6.Total Members
Choose by Number:2

 Enter the position at which you want to insert new data:5

 Enter the Name for new data:Hina

 Enter the RollNo for new data:7

 Enter the  Year for new data:3


            Name:Andy
            RollNo:12
            Year:2

            Name:Aamy
            RollNo:13
            Year:2

            Name:GIna
            RollNo:13
            Year:3

            Name:Jake
            RollNo:44
            Year:4

            Name:Hina
            RollNo:7
            Year:3

            Name:Terry
            RollNo:45
            Year:4
 Enter 1 to continue:1

        MENU:
1.Display Data
2.Insert new Member
3.Delete Member
4.Search by Rollno
5.Search by position
6.Total Members
Choose by Number:3

 Deleting Data of the member you want:
Enter the roll no. of the student whose data you want to delete: 13

Enter the year of the student whose data you want to delete:3


            Name:Andy
            RollNo:12
            Year:2

            Name:Aamy
            RollNo:13
            Year:2

            Name:Jake
            RollNo:44
            Year:4

            Name:Hina
            RollNo:7
            Year:3

            Name:Terry
            RollNo:45
            Year:4
 Enter 1 to continue:1

        MENU:
1.Display Data
2.Insert new Member
3.Delete Member
4.Search by Rollno
5.Search by position
6.Total Members
Choose by Number:4

 Enter the year:3

 Enter the roll no:7

 Data found :
 Name:Hina
 RollNo:7
 Year:3
 Enter 1 to continue:1

        MENU:
1.Display Data
2.Insert new Member
3.Delete Member
4.Search by Rollno
5.Search by position
6.Total Members
Choose by Number:5

 Enter position whose data you want to see:4

 Name:Hina
 RollNo:7
 Year:3
 Enter 1 to continue:1

        MENU:
1.Display Data
2.Insert new Member
3.Delete Member
4.Search by Rollno
5.Search by position
6.Total Members
Choose by Number:2

 Enter the position at which you want to insert new data:3

 Enter the Name for new data:Katy

 Enter the RollNo for new data:44

 Enter the  Year for new data:2


            Name:Andy
            RollNo:12
            Year:2

            Name:Aamy
            RollNo:13
            Year:2

            Name:Katy
            RollNo:44
            Year:2

            Name:Jake
            RollNo:44
            Year:4

            Name:Hina
            RollNo:7
            Year:3

            Name:Terry
            RollNo:45
            Year:4
 Enter 1 to continue:1

        MENU:
1.Display Data
2.Insert new Member
3.Delete Member
4.Search by Rollno
5.Search by position
6.Total Members
Choose by Number:4

 Enter the year:2

 Enter the roll no:44

 Data found :
 Name:Katy
 RollNo:44
 Year:2
 Enter 1 to continue:1

        MENU:
1.Display Data
2.Insert new Member
3.Delete Member
4.Search by Rollno
5.Search by position
6.Total Members
Choose by Number:6

 Number of CSI Branch members are :6
 Enter 1 to continue:0
 *
 */
