

#include <iostream>
#include <string.h>
using namespace std;

class node
{

    unsigned long long aadhar_no;
    char name[25];
    int dd,mm,yyyy;
    friend class list;
    node *next;
 public:
    node(unsigned long long a,char n[],int d,int m,int y)
    {
        next=NULL;
        aadhar_no=a;
        strcpy(name,n);
        dd=d;
        mm=m;
        yyyy=y;
    }
};

class list
{
    node *head;
    public:
    friend class consti;
public:
    list()
    {
        head=NULL;
    }
    void print();                               //print list of registered voters.
    void insert();                              //insert newly registered citizens.
    void remove(unsigned long long);            //Remove the details of already voted people.
    unsigned long long search();
};

void list::insert()                            //Class for insertion of details of voters.
{
    int n1;
    int d,m,y,i;
    int flag;
    unsigned long long a,t;
    char n[25];
    do
    {
        cout<<"\nEnter your first name:"<<endl;
        cin>>n;
        cout<<"Enter your 12-digit Aadhar Number: "<<endl;
        cin>>a;
        t=a;
        do
        {
            flag=0;
            i=0;
            while(t!=0)
            {
                t=t/10;
                i++;
            }
            if(i!=12)
            {
                cout<<"ENTERED AADHAR NUMBER NOT VALID! Please Re-Enter: "<<endl;
                cin>>a;
                t=a;
            }
        }
        while(i!=12);
        cout<<"Enter your Date of Birth.\nDD: "<<endl;
        cin>>d;
        while(d<=0 || d>31)
        {
            cout<<"INVALID DATE! Re-Enter\nDD: "<<endl;
            cin>>d;
        }
        cout<<"MM: "<<endl;
        cin>>m;
        while(m<=0 || m>12)
        {
            cout<<"INVALID MONTH! Re-Enter\nMM: "<<endl;
            cin>>m;
        }
        cout<<"YYYY: "<<endl;
        cin>>y;
        if(y>2000 || y<1900)
        {
            cout<<"\n YOU ARE NOT ELIGIBLE TO VOTE!"<<endl;
            flag=1;
        }
        if(flag==0)
        {
            node *temp,*ptr;
            temp=new node(a,n,d,m,y);
            if(head==NULL)
            {
                head=temp;
               temp->next=NULL;
            }
           else
           {
                ptr=head;
                while(ptr->next!=NULL)
                {
                    ptr=ptr->next;
                }
                ptr->next=temp;
                ptr=temp;
                temp->next=NULL;
            }
        }
        cout<<"\n Enter 1 if you want to insert new Aadhar card details:"<<endl;
        cin>>n1;
    }
    while(n1==1);
}

void list::print()                                       //Class for displaying list of registered voters.
{
    node *ptr;
    ptr=head;
    if (ptr==NULL)
    {
        cout<<"\nLIST IS EMPTY."<<endl;
    }
    else
    {
        ptr=head;
        while(ptr!=NULL)
        {
            cout<<"\nNAME: "<<ptr->name<<"\nAADHAR NUMBER: "<<ptr->aadhar_no<<"\nBIRTH DATE: "<<ptr->dd<<"/"<<ptr->mm<<"/"<<ptr->yyyy<<endl;
            ptr=ptr->next;
        }
    }
}

void list::remove(unsigned long long ad)                   //Class for removing particular Aadhar numbers from the list.
{
    node *ptr, *temp;
    ptr=head;
    if(ptr->aadhar_no==ad)
    {
        temp=head;
        head=head->next;
        delete temp;
    }
    else
    {
        while(ptr->next->aadhar_no!=ad)
        {
            ptr=ptr->next;
        }
        temp=ptr->next;
        ptr->next=ptr->next->next;
        delete temp;
    }
    cout<<"\n Your name has been removed from the current voters list."<<endl;
}

unsigned long long list::search()                                //Class for searching a particular Aadhar number in the list.
{
    int flag,i;
    unsigned long long k,t;
    cout<<"\n Enter the Aadhar card Number that you wish to search:"<<endl;
    cin>>k;
    t=k;
    do
    {
        flag=0;
        i=0;
        while(t!=0)
        {
            t=t/10;
            i++;
        }
        if(i!=12)
        {
            cout<<"ENTERED AADHAR NUMBER NOT VALID! Please Re-Enter: "<<endl;
            cin>>k;
            t=k;
        }
    }
    while(i!=12);
    node *ptr;
    ptr=head;
    while(ptr!=NULL)
    {
        if(ptr->aadhar_no==k)
        {
            flag=1;
            break;
        }
        else
        {
            flag=0;
            ptr=ptr->next;
        }
    }
    if(flag==1)
    {
        cout<<"\n You are eligible to vote,proceed."<<endl;
        return k;
    }
    else
    {
        cout<<"\n YOU ARE NOT ELIGIBLE TO VOTE!"<<endl;
        return 0;
    }
}

class consti                                                   //Constituency class
{
    list l[5];
    int abc=0,xyz=0,def=0;
public:
    void accept()
    {
        for(int i=0;i<5;i++)
        {
            cout<<"\n Accepting voters list of Constituency no. "<<i+1<<": "<<endl;
            l[i].insert();
        }
    }

    void search(int n)                          //Class for searching name of voters in the list and proceeding for vote.
    {
        cout<<"\n Searching for you name in voters list of Constituency."<<n<<endl;
        unsigned long long  p=l[n-1].search();
        if(p!=0)
        {
            int x;
            cout<<"\nTHE CANDIDATES FOR ELECTION ARE AS FOLLOWS:\n1.  ABC Party - abc candidate\n2.  XYZ  Party -xyz Candidate\n3. DEF Party -def Candidate\n Whom do you want to vote? "<<endl;
            cin>>x;
            switch(x)
            {
            case 1:
                abc++;
                l[n-1].remove(p);
                cout<<"Thank You for your vote."<<endl;
                break;
            case 2:
                xyz++;
                l[n-1].remove(p);
                cout<<"Thank You for your vote."<<endl;
                break;
            case 3:
                def++;
                l[n-1].remove(p);
                cout<<"Thank You for your vote."<<endl;
                break;
            default:
                cout<<"INVALID INPUT!!"<<endl;
                break;
            }
        }
    }
    void winner()                                    //Winner class for declaration of winner.
    {
        if(abc>xyz&&abc>def)
        {
            cout<<"\n Congratulations to ABC Party,their candidate abc won the elections!"<<endl;
        }
        else if(xyz>abc&&xyz>def)
        {
            cout<<"\n Congratulations to XYZ party, their candidate xyz won the elections!"<<endl;
        }
        else if((xyz==def)&&(def==abc))
        {
        	cout<<"\n NO PARTY COULD WIN THIS ELECTION DUE TO A TIE,RECONDUCT ELECTIONS!";
        }
        else if(abc==def)
        {
        	cout<<"\n ABC Party and DEF Party are having a tie!";
        }
        else if(xyz==def)
        {
        	cout<<"\n XYZ Party and DEF Party are having a tie!";
        }
        else if(abc==xyz)
        {
        	cout<<"\n ABC Party and XYZ Party are having a tie!";

        }
        else
        {

            cout<<"\n Congratulations to DEF party, their candidate def won the elections!"<<endl;
        }
    }
};

int main()
{
    int n2,n1;
    consti c;
    c.accept();
    do
    {
        cout<<"\n Enter 1 to cast vote:"<<endl;
        cin>>n1;
        switch(n1)
        {
        case 1:
        cout<<"\n Select your constituency name:\n1.Pune\n2.Latur\n3.Aurangabad\n4.Raigad\n5.Mumbai \nChoose: "<<endl;
            cin>>n2;
            if(n2<=0 && n2>5)
            {
                cout<<"INVALID INPUT!"<<endl;
                break;
            }
            else
            {
                c.search(n2);
                break;
            }
        case 999:
        c.winner();
            break;

        default:
        cout<<"INVALID INPUT!"<<endl;
        cin>>n1;
        break;
        }
    }
    while(n1==1);
    return 0;
}
