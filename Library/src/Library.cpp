
#include <iostream>

#include<string.h>

using namespace std;

class Book

{

public:
  long isbn;

           char author[100];

           char title[100];



};

class  library

{

private:

           Book b[10];

           int n;

public:

           void accept();

           void display();

           void add_book();

           void sort();

           void search();

           void seeauthor();



};

void library::accept()

{

           cout<<"\n Enter number of Books:";

           cin>>n;
           for(int i=0;i<n;i++)
               b[i].isbn=0;

           for(int i=0;i<n;i++)

           {

                      cout<<"\n Enter Book author:";

                      cin>>b[i].author;

                      cout<<"\n Enter Title:";

                      cin>>b[i].title;

                      cout<<"\n Enter ISBN number:";

                      cin>>b[i].isbn;


int cnt;
                      do
                      {
                    	  long k=b[i].isbn;
                    	  cnt=0;
                      while(k>0)
                      {
                    	  k=k/10;
                    	  cnt++;
                      }
                      if(cnt!=10)
                      {
                    	  cout<<"\n Entered ISBN is not valid,Enter a 10 digit ISBN number:";

                    	                        cin>>b[i].isbn;
                      }

                      }while(cnt!=10);

                      if(i!=0)
                      {
                      long d=b[i].isbn;
                                for(int j=i-1;j>=0;j--)
                                {
                                if(d==b[j].isbn)

                                {
                                    cout<<"\n Book with ISBN No. "<<d<<"  already exists so enter new ISBN Number:";
                                    cin>>b[i].isbn;
                                }
                                }
                      }
           }


}

void library::display()

{

           cout<<"\n Displaying Books:\n";
           cout<<"\n ISBN \t\t\t Author\t\tTitle\n";

           for(int i=0;i<n;i++)



           {

                    cout<<"\n"<<b[i].isbn<<"\t\t"<<b[i].author<<"\t\t"<<b[i].title<<"\n";



           }

}

void library::add_book()

{




           cout<<"\n Enter the ISBN no of the new Book:";

           cin>>b[n].isbn;
           int cnt;
                                 do
                                 {
                               	  long k=b[n].isbn;
                               	  cnt=0;
                                 while(k>0)
                                 {
                               	  k=k/10;
                               	  cnt++;
                                 }
                                 if(cnt!=10)
                                 {
                               	  cout<<"\n Entered ISBN is not valid,Enter a 10 digit ISBN number:";

                               	                        cin>>b[n].isbn;
                                 }

                                 }while(cnt!=10);

                                    long d=b[n].isbn;
                                           for(int j=n-1;j>=0;j--)
                                                      {
                                                     if(d==b[j].isbn)
                                                       {
                                                      cout<<"\n Book with ISBN No. "<<d<<"  already exists so enter new ISBN Number:";
                                                           cin>>b[n].isbn;
                                                        }
                                                      }

           cout<<"\n Enter the Author name:";

           cin>>b[n].author;

           cout<<"\n Enter Title:";

           cin>>b[n].title;

           n=n+1;

           display();

}

void library::sort()

{

           int max=b[0].isbn;

           char m[100];

           char m1[100];

           char  y[100];

           char y1[100];

           for(int j=0;j<n;j++)

           {

           for(int i=j+1;i<n;i++)

           {

                      if(b[i].isbn<b[j].isbn)

                      {

                                 max=b[i].isbn;

                                 b[i].isbn=b[j].isbn;

                                 b[j].isbn=max;

                                 strcpy(m,b[i].author);

                                 strcpy(m1,b[j].author);

                                 strcpy(b[i].author,m1);

                                 strcpy(b[j].author,m);



                                 strcpy(y,b[i].title);

                                                                  strcpy(y1,b[j].title);

                                                                  strcpy(b[j].title,y);

                                                                  strcpy(b[i].title,y1);

                      }



           }

           }
cout<<"\n Sorted Books by ISBN number:";
display();




}

void library::search()

{

           int s,flag,i;

           cout<<"\n Enter the ISBN No. of the Book you want:";

           cin>>s;

           for( i=0;i<n;i++)

           {

                      if(s==b[i].isbn)

                      {

                                 flag=1;

                                 break;



                      }

                      else

                      {

                                 flag=0;

                      }

           }
           if (flag==0)
                 	   cout<<"\n No such Book found!";
           else
           {

           cout<<"\n Book  is available at position: "<<i+1;

           cout<<"\nAuthor: "<<b[i].author;

           cout<<"\nTitle : "<<b[i].title;
           }


}

void library::seeauthor()

{

           char auth[100];

           cout<<"\n Enter author:";

           cin>>auth;
int flag=0;
           for(int i=0;i<n;i++)

           {

           if(!(strcmp(auth,b[i].author)))

           {



                      cout<<"\n Isbn No.:"<<b[i].isbn;

                      cout<<"\n Author:"<<b[i].author;

                      cout<<"\n Title:"<<b[i].title;
                      cout<<"\n";
                   	flag++;

           }





}
           if(flag==0)
           {
        	   cout<<"\n No Books of such author!";
           }

}

int main() {
    library l;
int no1,no2;
do
{
cout<<"\n ***Menu***\n1.Accept\n2.Display\n3.Add new Book\n4.Sort by ISBN number\n5.Search by ISBN number\n6.Show Books of specific author:";
cin>>no1;
switch(no1)
{
case 1: l.accept();
break;
case 2:l.display();
break;
case 3:l.add_book();

break;
case 4:l.sort();
break;
case 5:l.search();
break;
case 6:l.seeauthor();
break;

}
cout<<"\n Do you wish to contnue?Press 1 to continue:";
cin>>no2;
}while(no2==1);

           return 0;

}
/*
 ***Menu***
1.Accept
2.Display
3.Add new Book
4.Sort by ISBN number
5.Search by ISBN number
6.Show Books of specific author:1

 Enter number of Books:4

 Enter Book author:WilliamS

 Enter Title:Hamlet

 Enter ISBN number:1231231231

 Enter Book author:WilliamS

 Enter Title:JuliusCesaer

 Enter ISBN number:1231231231

 Book with ISBN No. 1231231231  already exists so enter new ISBN Number:1231231234

 Enter Book author:StephenHawking

 Enter Title:TheBriefHistoryofTime

 Enter ISBN number:1231231236

 Enter Book author:RonRoy

 Enter Title:AtoZmystries

 Enter ISBN number:1231231235

 Do you wish to contnue?Press 1 to continue:1

 ***Menu***
1.Accept
2.Display
3.Add new Book
4.Sort by ISBN number
5.Search by ISBN number
6.Show Books of specific author:2

 Displaying Books:

 ISBN No.:1231231231

 Author:WilliamS

 Title:Hamlet

 ISBN No.:1231231234

 Author:WilliamS

 Title:JuliusCesaer

 ISBN No.:1231231236

 Author:StephenHawking

 Title:TheBriefHistoryofTime

 ISBN No.:1231231235

 Author:RonRoy

 Title:AtoZmystries

 Do you wish to contnue?Press 1 to continue:1

 ***Menu***
1.Accept
2.Display
3.Add new Book
4.Sort by ISBN number
5.Search by ISBN number
6.Show Books of specific author:3

 Enter the ISBN no of the new Book:1231231237

 Enter the Author name:BjarneStroutrup

 Enter Title:TheCPPCompleteBook

 Displaying Books:

 ISBN No.:1231231231

 Author:WilliamS

 Title:Hamlet

 ISBN No.:1231231234

 Author:WilliamS

 Title:JuliusCesaer

 ISBN No.:1231231236

 Author:StephenHawking

 Title:TheBriefHistoryofTime

 ISBN No.:1231231235

 Author:RonRoy

 Title:AtoZmystries

 ISBN No.:1231231237

 Author:BjarneStroutrup

 Title:TheCPPCompleteBook

 Do you wish to contnue?Press 1 to continue:1

 ***Menu***
1.Accept
2.Display
3.Add new Book
4.Sort by ISBN number
5.Search by ISBN number
6.Show Books of specific author:4

 Sorted Books by ISBN number:
 Displaying Books:

 ISBN No.:1231231231

 Author:WilliamS

 Title:Hamlet

 ISBN No.:1231231234

 Author:WilliamS

 Title:JuliusCesaer

 ISBN No.:1231231235

 Author:RonRoy

 Title:AtoZmystries

 ISBN No.:1231231236

 Author:StephenHawking

 Title:TheBriefHistoryofTime

 ISBN No.:1231231237

 Author:BjarneStroutrup

 Title:TheCPPCompleteBook

 Do you wish to contnue?Press 1 to continue:1

 ***Menu***
1.Accept
2.Display
3.Add new Book
4.Sort by ISBN number
5.Search by ISBN number
6.Show Books of specific author:5

 Enter the ISBN No. of the Book you want:1231231231

 Book  is available at position: 1
Author: WilliamS
Title : Hamlet
 Do you wish to contnue?Press 1 to continue:1

 ***Menu***
1.Accept
2.Display
3.Add new Book
4.Sort by ISBN number
5.Search by ISBN number
6.Show Books of specific author:6

 Enter author:WilliamS

 Isbn No.:1231231231
 Author:WilliamS
 Title:Hamlet
 Isbn No.:1231231234
 Author:WilliamS
 Title:JuliusCesaer
 Do you wish to contnue?Press 1 to continue:0
*/

