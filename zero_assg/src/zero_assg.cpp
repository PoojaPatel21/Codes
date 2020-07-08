//============================================================================
// Name        : zero_assg.cpp
// Author      : Pooja Patel
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class zero
{
private:
	int arr[100];
	int i,j;
	int n;
public:
	void accept();
	void display();
	void res();
};
void zero::accept()
{
	cout<<"\n Enter the number of Array Elements you want:";
	cin>>n;
	for(i=0;i<n;i++)
	{
		cout<<"\n Enter an element:";
		cin>>arr[i];

	}
}
void zero::display()
{
	cout<<"\n Displaying array elements:";
	for(j=0;j<n;j++)
	{
		cout<<" "<<arr[j];
	}
}
void zero::res()
{

	int temp=0;
	for(i=0;i<n;i++)
	{
for(j=0;j<n-1;j++)
{
			if(arr[j]==0)
			{

			temp=arr[j];
			arr[j]=arr[j+1];
			arr[j+1]=temp;

			}

	}

	}

	for(i=0;i<n;i++)
	{
		cout<<" "<<arr[i];
	}
}
int main()
{
	int n1,no;
	zero p;
	do
	{
		cout<<"\n1.Accept\n2.Display\n3.Result\nEnter your choice:";
		cin>>n1;
		switch(n1)
		{
		case 1:p.accept();
		break;
		case 2:	p.display();
		break;
		case 3:p.res();
		break;


		}
		cout<<"\n Enter 1 to continue:";
		cin>>no;
	}while(no==1);




	return 0;

}
