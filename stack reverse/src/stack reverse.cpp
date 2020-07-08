/*
 * Title:Implement Stack as n ADT using linked list or array.Use ADT to evaluate expression.
Rollno:2956
*/
#include <iostream>

#include<string.h>

#include<stdlib.h>

using namespace std;

class stacks
{
public:
	int check=0;

    int max=0;

    int cnt;

    float st[100];

    char ch[100];

    float exp[100];



             int top;

             int top1;

             int top3;



    void push(int d);

    int pop();

    void display_top(int);

    int isempty();

    int isfull();



    void revchar();

    char pop1();

    float pop2();

    void push1(float);

    void ex_eval();

    void isOperator(char);

    stacks()

    {



        top=0;

        top1=0;

        top3=0;

    }





};

void stacks::isOperator(char c)

{


           if((c=='*')||(c=='+')||(c=='-')||(c=='/')||(c=='^'))

                           {
               int k;

                  if(c=='^')

                   k=0;

                  else if(c=='*')

                       k=1;

                   else if(c=='/')

                       k=2;

                   else if(c=='+')

                       k=3;

                   else if(c=='-')

                       k=4;

                   float c4=pop2();

                           float c5=pop2();

                           float a;

                   switch(k)

                   {

                   case 0:
                       while(c4!=1)
                       {
                           c5*=c5;
                           c4--;
                       }
                       a=c5;
                   push1(a);
                   break;
                   case 1:a=(c4)*(c5);

                   push1(a);

                   break;

                   case 2:a=(c5)/(c4);

                   push1(a);

                           break;

                   case 3:a=c4+c5;

                   push1(a);

                           break;

                   case 4:a=c5-c4;

                   push1(a);

                           break;



                   }



}
}
int stacks::isempty()

{

    if(top==0)

        return 1;

    else

        return 0;

}

int stacks::isfull()

{

    if(top==max)

        return 1;

    else

        return 0;



}

void stacks::push(int d)

{



    if(isfull()==1)

        cout<<"\n The stack is full,so we cannot add more data!";

    else

    {



     st[top]=d;



     cout<<"\n After pushing data:";

             display_top(top+1);

    }



}

void stacks::push1(float d)

{



    if(isfull()==1)

        cout<<"\n The stack is full,so we cannot add more data!";

    else

    {

top3++;

     exp[top3]=d;





       }



}

int stacks::pop()

{

    int data;



    if(isempty()==1)

        cout<<"\n Stack is empty,so cannot delete any Element! ";

    else

    {

        data=st[top];

        top--;

        return top;







    }

}

char stacks::pop1()

{

    char c;





        c=ch[top1];

        top1--;

        return c;



}

float stacks::pop2()

{

    float co5;





        co5=exp[top3];

        top3--;

        return co5;



}

void stacks::display_top(int cnt)

{



    top=cnt;

    cout<<"\n Displaying Stack:";



    for(int i=0;i<cnt;i++)

        cout<<" "<<st[i];

}



void stacks::revchar()

{



    int i=0;



    cout<<"\n Enter String:";

    cin>>ch;



    while(ch[i]!='\0')

    {

           i++;

    }

    top1=i-1;

while(top1!=-1)

{

char c1=pop1();

cout<<c1;

}



}

void stacks::ex_eval()

{

           char c[10];

           cout<<"\n Enter expression:";

           cin>>c;

           int i=0;

           int d;

           while(c[i]!='\0')

           {

                      if(isalpha(c[i])!=0)

                      {

                                 cout<<"\n Enter digit:";

                                 cin>>d;

                                 push1(d);
                                 check++;

                      }




                      else

                      {

                                 if(isdigit(c[i])!=0)

                                 {

                                            push1(c[i]-'0');

                                 }

                      }



                                 isOperator(c[i]);

i++;

           }

           float k=pop2();

           cout<<k;

}

int main() {



int no1,no2;

stacks s;



int d,a,n1;

int cnt=0;

cout<<"\n Enter max limit of the stack:";

cin>>s.max;

do

{

cout<<"\n Enter data:";

    cin>>s.st[cnt];



cout<<"\n Enter 1 to add new element:";

cin>>n1;



    cnt++;



}while(n1==1&&cnt<s.max);

s.display_top(cnt);

do

{

    cout<<"\n ***MENU***\n1.Push\n2.Pop\n3.Reverse String\n4.Expression Evaluation\nChoose:";

    cin>>no1;

    switch(no1)

    {



    case 1:

        cout<<"\n Enter data to add to the stack:";

        cin>>d;

        s.push(d);



        break;

    case 2:

        a=s.pop();

        if(s.isempty()==0)

        s.display_top(a);

        break;



    case 3:

        s.revchar();

        break;

    case 4:

           s.ex_eval();

           break;

    }

    cout<<"\n Do you wish to continue?Press 1 to continue.";

    cin>>no2;

}while(no2==1);

    return 0;

}
/*
 Enter max limit of the stack:5

 Enter data:1

 Enter 1 to add new element:1

 Enter data:2

 Enter 1 to add new element:1

 Enter data:3

 Enter 1 to add new element:0

 Displaying Stack: 1 2 3
 ***MENU***
1.Push
2.Pop
3.Reverse String
4.Expression Evaluation
Choose:1

 Enter data to add to the stack:4

 After pushing data:
 Displaying Stack: 1 2 3 4
 Do you wish to continue?Press 1 to continue.1

 ***MENU***
1.Push
2.Pop
3.Reverse String
4.Expression Evaluation
Choose:2

 Displaying Stack: 1 2 3
 Do you wish to continue?Press 1 to continue.1

 ***MENU***
1.Push
2.Pop
3.Reverse String
4.Expression Evaluation
Choose:2

 Displaying Stack: 1 2
 Do you wish to continue?Press 1 to continue.1

 ***MENU***
1.Push
2.Pop
3.Reverse String
4.Expression Evaluation
Choose:2

 Displaying Stack: 1
 Do you wish to continue?Press 1 to continue.1

 ***MENU***
1.Push
2.Pop
3.Reverse String
4.Expression Evaluation
Choose:2

 Do you wish to continue?Press 1 to continue.1

 ***MENU***
1.Push
2.Pop
3.Reverse String
4.Expression Evaluation
Choose:2

 Stack is empty,so cannot delete any Element!
 Do you wish to continue?Press 1 to continue.1

 ***MENU***
1.Push
2.Pop
3.Reverse String
4.Expression Evaluation
Choose:3

 Enter String:India
aidnI
 Do you wish to continue?Press 1 to continue.1

 ***MENU***
1.Push
2.Pop
3.Reverse String
4.Expression Evaluation
Choose:4

 Enter expression:ab+cd*-

 Enter digit:10

 Enter digit:20

 Enter digit:3

 Enter digit:2
24
 Do you wish to continue?Press 1 to continue.1

 ***MENU***
1.Push
2.Pop
3.Reverse String
4.Expression Evaluation
Choose:2

 Stack is empty,so cannot delete any Element!
 Do you wish to continue?Press 1 to continue.0
 *
 */
