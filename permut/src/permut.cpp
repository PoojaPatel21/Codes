




#include <iostream>

using namespace std;

class Party

{

private:

           int n;

           char name[100];

public:

           void accept();

           void display();

           int perm();

           double fact(int);

};

double Party::fact(int n)

{

           double fact=1;

           for(int i=n;i>0;i--)

           {

                      fact=fact*i;

           }

           return fact;

}

int Party::perm()

{

           int p;

           p=fact(n)/(2*fact(n-2));

           return p;

}

void Party::accept()

{

           cout<<"\n Enter the number of Guests Exchanging Handshakes:";

           cin>>n;

           cout<<"\n Enter the Initials of the Guests:";

           for(int i=0;i<n;i++)

           {

                      cin>>name[i];
                      for(int k=0;k<i;k++)
                      {
                    	  if(name[k]==name[i])
                    	  {
                    		  cout<<"\n This name is already entered,so Re-Enter:";
                    		  cin>>name[i];
                    	  }
                      }

           }



}

void Party::display()

{

           for(int i=0;i<n;i++)

           {

                      for(int j=i+1;j<n;j++)

                      {

                                 cout<<"\n"<<name[i]<<"&"<<name[j];

                      }

           }

}

int main() {

           Party p;

           p.accept();

           double a=p.perm();

           cout<<"\n The total Number of Handshakes are:"<<a;

           p.display();

           return 0;

}
/*
*
Enter the number of Guests Exchanging Handshakes:5

Enter the Initials of the Guests:a
b
c
d
e

The total Number of Handshakes are:10
a&b
a&c
a&d
a&e
b&c
b&d
b&e
c&d
c&e
d&e
*
*/
