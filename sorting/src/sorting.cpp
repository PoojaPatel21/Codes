

//===============================================================================================
// Name        : CGPA.cpp
// Author      : Roll No:2956
// Title       : Write a Cpp program to store first year CGPA of students in array.Write
//               function for sorting array of floating point numbers in an ascending/descending
//               order using:
//               1.Bubble sort/Selection sort 2.Insertion sort 3.Quick Sort or Merge Sort
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//================================================================================================

#include <iostream>
#include<string>
using namespace std;

class CGPA
{
public:
	float s[100];
    int n ;
    int i=0;
    int cnt=0;

    void accept();
    void display();
    void sorts();
    void sorti();
    void quick(int first,int last);
    void quicksort();
};
void CGPA::quick(int first, int last)
{
	int i, j, pivot;
float temp;
	   if(first<last){
	      pivot=first;
	      i=first;
	      j=last;

	      while(i<j){
	         while(s[i]<=s[pivot]&&i<last)
	            i++;
	         while(s[j]>s[pivot])
	            j--;
	         if(i<j){
	            temp=s[i];
	            s[i]=s[j];
	            s[j]=temp;
	         }
	      }

	      temp=s[pivot];
	      s[pivot]=s[j];
	      s[j]=temp;

	      //cout<<"\n Showing the swapping:";
	      //for(i=first;i<last;i++)
	      //cout<<s[i];

	      quick(first,j-1);
	      quick(j+1,last);

	   }
}
void CGPA::quicksort()
{
	quick(0,n-1);
	display();
}


void CGPA::sorti()
{
    float value;
    for(int i=0;i<n;i++)
    {
    value=s[i];
    int j=i-1;
    while(j>=0&&s[j]>value)
    {
        s[j+1]=s[j];
        j--;
    }
    s[j+1]=value;
    }
display();

}
void CGPA::accept()
{


int n1;
do{
    cout<<"\n Enter CGPA of student :"<<i+1;
    cin>>s[i];
    cout<<"\n Press 1 if you wish to add CGPA of another student?";
    cin>>n1;
    i++;
}while(n1==1);
n=i;
}
void CGPA::sorts()
{


    int min;
    for(int i=0;i<n;i++)
    {
        min=i;

    for(int j=i+1;j<n;j++)
    {
        if(s[j]<s[min])
        {
            min=j;

        }
    }
    if(min!=i)
    {
        float temp=s[i];
        s[i]=s[min];
        s[min]=temp;
    }
    }
    display();

}
void CGPA::display()
{
    for(int i=0;i<n;i++)
    {
        cout<<"\n CGPA:"<<s[i];
    }
}
int main() {
    CGPA c;
    int n1,n2;
    do
    {
    cout<<"\n MENU\n1.Accept\n2.Selection Sort \n3.Insertion Sort\n4.QuickSort\nChoose:";
    cin>>n1;
    switch(n1)
    {
    case 1:c.accept();
    break;
    case 2:c.sorts();
    break;
    case 3:c.sorti();
    break;
    case 4:cout<<"\n Sorting the CGPA using quicksort algorithm:";
    	c.quicksort();
    break;
    }
    cout<<"\n Enter 1 to continue:";
    cin>>n2;
    }while(n2==1);



}
/*
 MENU
1.Accept
2.Selection Sort
3.Insertion Sort
4.QuickSort
Choose:1

 Enter CGPA of student :19.24

 Press 1 if you wish to add CGPA of another student?1

 Enter CGPA of student :26.67

 Press 1 if you wish to add CGPA of another student?1

 Enter CGPA of student :39.05

 Press 1 if you wish to add CGPA of another student?1

 Enter CGPA of student :47.89

 Press 1 if you wish to add CGPA of another student?0

 Enter 1 to continue:1

 MENU
1.Accept
2.Selection Sort
3.Insertion Sort
4.QuickSort
Choose:2

 CGPA:6.67
 CGPA:7.89
 CGPA:9.05
 CGPA:9.24
 Enter 1 to continue:1

 MENU
1.Accept
2.Selection Sort
3.Insertion Sort
4.QuickSort
Choose:1

 Enter CGPA of student :58.87

 Press 1 if you wish to add CGPA of another student?1

 Enter CGPA of student :66.79

 Press 1 if you wish to add CGPA of another student?1

 Enter CGPA of student :79.09

 Press 1 if you wish to add CGPA of another student?0

 Enter 1 to continue:1

 MENU
1.Accept
2.Selection Sort
3.Insertion Sort
4.QuickSort
Choose:3

 CGPA:6.67
 CGPA:6.79
 CGPA:7.89
 CGPA:8.87
 CGPA:9.05
 CGPA:9.09
 CGPA:9.24
 Enter 1 to continue:1

 MENU
1.Accept
2.Selection Sort
3.Insertion Sort
4.QuickSort
Choose:1

 Enter CGPA of student :84.45

 Press 1 if you wish to add CGPA of another student?1

 Enter CGPA of student :92.29

 Press 1 if you wish to add CGPA of another student?1

 Enter CGPA of student :109.67

 Press 1 if you wish to add CGPA of another student?1

 Enter CGPA of student :116.86

 Press 1 if you wish to add CGPA of another student?0

 Enter 1 to continue:1

 MENU
1.Accept
2.Selection Sort
3.Insertion Sort
4.QuickSort
Choose:4

 Sorting the CGPA using quicksort algorithm:
 CGPA:2.29
 CGPA:4.45
 CGPA:6.67
 CGPA:6.79
 CGPA:6.86
 CGPA:7.89
 CGPA:8.87
 CGPA:9.05
 CGPA:9.09
 CGPA:9.24
 CGPA:9.67
 Enter 1 to continue:0
 *
 */
