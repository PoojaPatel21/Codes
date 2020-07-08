//============================================================================
// Name        : matrixoperations.cpp
// Author      : Pooja Patel
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
class matrix
{
private:
	int a[10][10];
	int row,col;
public:
	void accept();
	void display();
    void square();
    void transpose();
    void triangle();
    void add(matrix);
    void multi(matrix);



};
void matrix::accept()
{

	cout<<"\n Enter number of rows:";
	cin>>row;
	cout<<"\n Enter number of columns:";
	cin>>col;
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			cout<<"\n Enter element:";
			cin>>a[i][j];

		}
	}
}

void matrix::display()
{
	cout<<"\n Displaying the matrix:\n";
	for(int i=0;i<row;i++)
		{
			for(int j=0;j<col;j++)
			{
				cout<<"\t"<<a[i][j];

			}
			cout<<"\n";
		}
}
void matrix::square()
{
	if(row==col)
	{
		cout<<"\n It is a square Matrix.";
	}
	else
	{
		cout<<"\n It is not a square Matrix.";
	}
}
void matrix::transpose()
{
matrix m;
(m.row)=col;
(m.col)=row;
for(int i=0;i<m.row;i++)
{
	for(int j=0;j<m.col;j++)
	{
		(m.a[i][j])=a[j][i];
	}
}


m.display();
}
void matrix::triangle()
{
	if(row==col)
	{
	int flag=1;
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			if((j<i)&&(a[i][j]==0))
			{
				flag++;
             break;
			}
		}

	}

	if(flag==row)
				{
					cout<<"\n It is an UpperTriangular Matrix.";
				}
				else
				{
					cout<<"\n It is not an UpperTriangular Matrix.";
				}
	}
	else
		cout<<"\n Upper triangular matrices exist only for Square matrices!";

}
void matrix::add(matrix m)
{
	matrix ad;
	ad.row=row;
	ad.col=col;
	if((row==m.row)&&(col==m.col))
	{
		for(int i=0;i<row;i++)
			{
				for(int j=0;j<col;j++)
				{
					ad.a[i][j]=a[i][j]+m.a[i][j];

				}

			}
ad.display();


	}
	else
	{
		cout<<"\n Since both matrix have different order,they cannot be added!";
	}

}
void matrix::multi(matrix m)
{


	matrix multi;
	multi.row=row;
	multi.col=m.col;

	if(col==m.row)
	{
		for(int i=0;i<row;i++)
		{
			for(int j=0;j<col;j++)
			{
				multi.a[i][j]=0;
				for(int k=0;k<col;k++)
				{
					multi.a[i][j]+=(a[i][k]*m.a[k][j]);

				}



				}
}

multi.display();

		}
	else
	{
		cout<<"\n Multiplication not possible because column of 1st matrix is not equal to row of 2nd.";
	}


}
int main()
{
int n,no;
matrix m1;
matrix m2;

	do
		{
	cout<<"\n ****MENU**** \n";
	cout<<"\n Make a choice:\n1.Accept both matrices \n2.Display both matrices \n3.Check if 1st Matrix is a square Matrix\n4.Check if 2nd Matrix is a square Matrix\n5.Check if Matrix 1 is UpperTriangular\n6.Check if Matrix 2 is UpperTriangular\n7.Transpose of 1st Matrix\n8.Transpose of 2nd Matrix\n9.Add\n10.Multiply";
	cin>>n;

	switch(n)
	{

	case 1: m1.accept();
            m2.accept();
            break;
	case 2:m1.display();
	m2.display();
	break;
	case 3: m1.square();
	break;
	case 4: m2.square();
	break;
	case 5: m1.triangle();
	break;
	case 6: m2.triangle();
	break;
	case 7: m1.transpose();
	break;
	case 8: m2.transpose();
	break;
	case 9: m1.add(m2);
	break;
	case 10:m1.multi(m2);
	}
	cout<<"\n Enter 1 if you want to continue else enter 0:";
	cin>>no;
	}
	while(no==1);










	return 0;
}
/*
 *
 ****MENU****

 Make a choice:
1.Accept both matrices
2.Display both matrices
3.Check if 1st Matrix is a square Matrix
4.Check if 2nd Matrix is a square Matrix
5.Check if Matrix 1 is UpperTriangular
6.Check if Matrix 2 is UpperTriangular
7.Transpose of 1st Matrix
8.Transpose of 2nd Matrix
9.Add
10.Multiply1

 Enter number of rows:3

 Enter number of columns:3

 Enter element:1

 Enter element:2

 Enter element:3

 Enter element:0

 Enter element:4

 Enter element:5

 Enter element:0

 Enter element:0

 Enter element:6

 Enter number of rows:2

 Enter number of columns:3

 Enter element:1

 Enter element:2

 Enter element:1

 Enter element:3

 Enter element:1

 Enter element:4

 Enter 1 if you want to continue else enter 0:1

 ****MENU****

 Make a choice:
1.Accept both matrices
2.Display both matrices
3.Check if 1st Matrix is a square Matrix
4.Check if 2nd Matrix is a square Matrix
5.Check if Matrix 1 is UpperTriangular
6.Check if Matrix 2 is UpperTriangular
7.Transpose of 1st Matrix
8.Transpose of 2nd Matrix
9.Add
10.Multiply2

 Displaying the matrix:
	1	2	3
	0	4	5
	0	0	6

 Displaying the matrix:
	1	2	1
	3	1	4

 Enter 1 if you want to continue else enter 0:1

 ****MENU****

 Make a choice:
1.Accept both matrices
2.Display both matrices
3.Check if 1st Matrix is a square Matrix
4.Check if 2nd Matrix is a square Matrix
5.Check if Matrix 1 is UpperTriangular
6.Check if Matrix 2 is UpperTriangular
7.Transpose of 1st Matrix
8.Transpose of 2nd Matrix
9.Add
10.Multiply3

 It is a square Matrix.
 Enter 1 if you want to continue else enter 0:1

 ****MENU****

 Make a choice:
1.Accept both matrices
2.Display both matrices
3.Check if 1st Matrix is a square Matrix
4.Check if 2nd Matrix is a square Matrix
5.Check if Matrix 1 is UpperTriangular
6.Check if Matrix 2 is UpperTriangular
7.Transpose of 1st Matrix
8.Transpose of 2nd Matrix
9.Add
10.Multiply4

 It is not a square Matrix.
 Enter 1 if you want to continue else enter 0:1

 ****MENU****

 Make a choice:
1.Accept both matrices
2.Display both matrices
3.Check if 1st Matrix is a square Matrix
4.Check if 2nd Matrix is a square Matrix
5.Check if Matrix 1 is UpperTriangular
6.Check if Matrix 2 is UpperTriangular
7.Transpose of 1st Matrix
8.Transpose of 2nd Matrix
9.Add
10.Multiply5

 It is an UpperTriangular Matrix.
 Enter 1 if you want to continue else enter 0:1

 ****MENU****

 Make a choice:
1.Accept both matrices
2.Display both matrices
3.Check if 1st Matrix is a square Matrix
4.Check if 2nd Matrix is a square Matrix
5.Check if Matrix 1 is UpperTriangular
6.Check if Matrix 2 is UpperTriangular
7.Transpose of 1st Matrix
8.Transpose of 2nd Matrix
9.Add
10.Multiply6

 It is not an UpperTriangular Matrix.
 Enter 1 if you want to continue else enter 0:1

 ****MENU****

 Make a choice:
1.Accept both matrices
2.Display both matrices
3.Check if 1st Matrix is a square Matrix
4.Check if 2nd Matrix is a square Matrix
5.Check if Matrix 1 is UpperTriangular
6.Check if Matrix 2 is UpperTriangular
7.Transpose of 1st Matrix
8.Transpose of 2nd Matrix
9.Add
10.Multiply7

 Transpose is:
	1	0	0
	2	4	0
	3	5	6

 Enter 1 if you want to continue else enter 0:1

 ****MENU****

 Make a choice:
1.Accept both matrices
2.Display both matrices
3.Check if 1st Matrix is a square Matrix
4.Check if 2nd Matrix is a square Matrix
5.Check if Matrix 1 is UpperTriangular
6.Check if Matrix 2 is UpperTriangular
7.Transpose of 1st Matrix
8.Transpose of 2nd Matrix
9.Add
10.Multiply8
	1	3
	2	1
	1	4

 Enter 1 if you want to continue else enter 0:1

 ****MENU****

 Make a choice:
1.Accept both matrices
2.Display both matrices
3.Check if 1st Matrix is a square Matrix
4.Check if 2nd Matrix is a square Matrix
5.Check if Matrix 1 is UpperTriangular
6.Check if Matrix 2 is UpperTriangular
7.Transpose of 1st Matrix
8.Transpose of 2nd Matrix
9.Add
10.Multiply9

 Since both matrix have different order,they cannot be added!
 Enter 1 if you want to continue else enter 0:1

 ****MENU****

 Make a choice:
1.Accept both matrices
2.Display both matrices
3.Check if 1st Matrix is a square Matrix
4.Check if 2nd Matrix is a square Matrix
5.Check if Matrix 1 is UpperTriangular
6.Check if Matrix 2 is UpperTriangular
7.Transpose of 1st Matrix
8.Transpose of 2nd Matrix
9.Add
10.Multiply10

 Multiplication not possible because column of 1st matrix is not equal to row of 2nd.
 Enter 1 if you want to continue else enter 0:1

 ****MENU****

 Make a choice:
1.Accept both matrices
2.Display both matrices
3.Check if 1st Matrix is a square Matrix
4.Check if 2nd Matrix is a square Matrix
5.Check if Matrix 1 is UpperTriangular
6.Check if Matrix 2 is UpperTriangular
7.Transpose of 1st Matrix
8.Transpose of 2nd Matrix
9.Add
10.Multiply1

 Enter number of rows:2

 Enter number of columns:2

 Enter element:1

 Enter element:2

 Enter element:3

 Enter element:4

 Enter number of rows:2

 Enter number of columns:2

 Enter element:1

 Enter element:2

 Enter element:1

 Enter element:3

 Enter 1 if you want to continue else enter 0:1

 ****MENU****

 Make a choice:
1.Accept both matrices
2.Display both matrices
3.Check if 1st Matrix is a square Matrix
4.Check if 2nd Matrix is a square Matrix
5.Check if Matrix 1 is UpperTriangular
6.Check if Matrix 2 is UpperTriangular
7.Transpose of 1st Matrix
8.Transpose of 2nd Matrix
9.Add
10.Multiply9

 Displaying the matrix:
	2	4
	4	7

 Enter 1 if you want to continue else enter 0:1

 ****MENU****

 Make a choice:
1.Accept both matrices
2.Display both matrices
3.Check if 1st Matrix is a square Matrix
4.Check if 2nd Matrix is a square Matrix
5.Check if Matrix 1 is UpperTriangular
6.Check if Matrix 2 is UpperTriangular
7.Transpose of 1st Matrix
8.Transpose of 2nd Matrix
9.Add
10.Multiply10

 Displaying the matrix:
	3	8
	7	18

 Enter 1 if you want to continue else enter 0:0
 */

