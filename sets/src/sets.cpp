//============================================================================
// Name        : sets.cpp
// Author      : Pooja Patel
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream.h>
using namespace std;
class set
{
	int size,size1;
	int a[20],b[20]; //declaring variables
	public:
	void accept();
	void display();
	void intersect();
	void unionset();
	void contains();
	void remove();
};

void set::accept()
{
	cout<<"\n Enter the number of people in this set:";
	cin>>size;
	for(int i=0;i<size;i++)
	{
		cout<<"\n Enter the id:"; cin>>a[i];
}

	cout<<"\n Enter the number of people in this set:";
	cin>>size1;
	for(int j=0;j<size1;j++)
	{
		cout<<"\n Enter the id:";
		cin>>b[j];
}
}

void set::display()
{
cout<<"\n Displaying the set elements:"; for(int i=0;i<size;i++) {
cout<<" "<<a[i];
}
cout<<"\n Displaying the set elements:"; for(int j=0;j<size1;j++)
{
cout<<" "<<b[j];
}
} void set::intersect() { for(int i=0;i<size;i++) { for(int j=0;j<size1;j++) { if(a[i]==b[j]) { cout<<" "<<a[i];
}
}
}
} void set::unionset()
{
int u[40]; int i,j,k;
for( i=0,k=0;i<size;i++,k++)
{
	u[k]=a[i];
	cout<<" "<<u[k];
}
int v=size;
int flag=1;
for(int j=0;j<size1;j++)
{

	for(int p=0;p<size;p++)
	{
		if(u[p]==b[j]) {flag=0;break;}
		else flag=1;
	}
if(flag!=0)
{
u[v]=b[j];
cout<<" "<<u[v]; v++;
}
}
} void set::contains() { int s,id; cout<<"\n Enter '1' if you want to search for english speaking person or '2' for french speaking person:"; cin>>s; int flag;
switch(s) { case 1:cout<<"\n Enter the id:"; cin>>id; for(int i=0;i<size;i++) { if(a[i]==id) { cout<<"\n The person is present at position:"<<i+1; break; } else { cout<<"\n The person is not present at position:"<<i+1; }
}
break; case 2:cout<<"\n Enter the id:"; cin>>id; for(int i=0;i<size1;i++) { if(b[i]==id) { cout<<"\n The person is present at position:"<<i+1; break; } else { cout<<"\n The person is not present at position:"<<i+1; } } break; default:cout<<"\n Enter valid number:";
}
}
int  main()
{
	set s;
	s.accept();
	s.display();
	cout<<"\n Intersection is:";
	s.intersect();
	cout<<"\n Union is:";
	s.unionset();
	s.contains();
	return 0;
}
