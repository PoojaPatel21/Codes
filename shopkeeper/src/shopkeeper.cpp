
#include<iostream>
#include<string.h>
using namespace std;
class Item
{
	int price;
	int stock;
	char name[10];
	int best[10];
public:
	void accept()
	{
		cout<<"\n Accepting product details:";
		cout<<"\n Enter name of the product:";
		cin>>name;
		cout<<"\n Enter number of stock:";
		cin>>stock;
		cout<<"\n Enter the price of the commodity:";
		cin>>price;

	}
	void display()
	{
		cout<<"\n Item details:";
		cout<<"\n Item Name:"<<name;
		cout<<"\n Item Price:"<<price;
		cout<<"\n Item Stock Available:"<<stock;
	}
	friend class customer;
};
class customer
{
	Item it[10];
	int buy[10][10];
	float bill[10];
    int id;
    int n1;
    int c;

public:
    void accept_item()
    {
    	cout<<"\n Enter number of items available in the Market:";
    	cin>>n1;
    	for(int i=0;i<n1;i++)
    	{
    		it[i].accept();
    	}
    	cout<<"\n Displaying item details:";
    	for(int j=0;j<n1;j++)
    		{
    		it[j].display();
    		}
    }
	void accept()
	{
		cout<<"\n Enter the number of customers in a day:";
		cin>>c;
		for(int p=0;p<c;p++)
		{
			for(int q=0;q<n1;q++)
			{
				buy[p][q]=0;
			}
		}
		for(int k=0;k<c;k++)
		{
		int n2,n3;
		cout<<"\n Enter customer details for customer no."<<k+1;

		cout<<"\n You can buy stuff from the following list:\n";
		for(int j=0;j<n1;j++)
		    		{
			cout<<"\n Item No:"<<j+1;
		    		it[j].display();
		    		}
		do
		{
			cout<<"\n For customer No."<<k+1;
		cout<<"\n Enter the Item No. you want to purchase:";
		cin>>n2;
		if(n2>n1)
		{
			cout<<"\n The available items are only "<<n1<<" kindly re-enter the item no.";
		cin>>n2;
		}
		cout<<"\n Enter the quantity you want to buy:";
		cin>>buy[k][n2-1];

int f;
		do
		{
			f=0;
		if(buy[k][n2-1]>it[n2-1].stock)
		{
			cout<<"\n The currently available stock is:"<<it[n2-1].stock<<" kindly replace your order:";
			cin>>buy[k][n2-1];
			f=1;
		}
		else

			it[n2-1].stock-=buy[k][n2-1];
		}while(f!=0);
		if(it[n2-1].stock==0)
				{
					cout<<"\n The stock of Item No."<<n2-1<<" has been exhausted,kindly re-order:";
					cin>>it[n2-1].stock;
				}
		cout<<"\n Do you want to buy another product?Press 1:";
		cin>>n3;
		}while(n3==1);

	}
	}
		void display()
		{
				for(int j=0;j<c;j++)
			{
					cout<<"\n Customer no."<<j+1<<" cart :";
				for(int k=0;k<n1;k++)
				{
				cout<<"\n Item No."<<k+1<<" :"<<buy[j][k];
				}
			}
		}
		void bill_calc()
		{
			for(int k=0;k<c;k++)
			{
				bill[k]=0;
			}
			for(int i=0;i<c;i++)
			{
				cout<<"\n For customer no."<<i+1;
				for(int j=0;j<n1;j++)
				{
					cout<<"\n Item No."<<j+1<<"("<<buy[i][j]<<")"<<" x "<<it[j].price;
					bill[i]+=(buy[i][j]*it[j].price);
				}
				cout<<"\n Customer no."<<i+1<<"'s Bill is Rs: "<<bill[i];
			}

		}
		void cust_bill()
		{
			int s;

			cout<<"\n Enter the customer whose BILL you wish to see:";
			cin>>s;
		if(s>n1)
		{
			cout<<"\n Invalid customer ID,Re eneter:";
		cin>>s;
		}
		else
		{

			for(int j=0;j<n1;j++)
							{
								cout<<"\n Item No."<<j+1<<"("<<buy[s-1][j]<<")"<<" x "<<it[j].price;

							}
							cout<<"\n Customer no."<<s<<"'s Bill is Rs: "<<bill[s-1];
		}
		}
		void top_cust()
		{
			int max=bill[0];
			int max1=0;
			for(int i=0;i<c;i++)
			{
				if(bill[i]>max)
				{
					max1=i;
					max=bill[i];
				}
			}
			cout<<"\n Top Customer is customer no."<<max1+1<<" whose bill amount is Rs. "<<max;
		}
		void best_sold()
		{
			int best[10];
			for(int k=0;k<n1;k++)
			{
				best[k]=0;
			}
			for(int i=0;i<n1;i++)
			{
				for(int j=0;j<c;j++)
				{
					best[i]+=buy[j][i];
				}
			}
			int max=best[0];
			int max1=0;
			for(int g=0;g<n1;g++)
			{
				if(max<best[g])
				{
					max=best[g];
					max1=g;
				}
			}
			cout<<"\n The Best Sold Item is Item No."<<max1+1<<" with max sold "<<best[max1]<<" items!";

		}

};
	int main()
	{
		int n1,n2;
		customer d;
		do
		{
			cout<<"\n Menu:\n1.Accept Item details \n2.Shop for items \n3.Display today's customer and item details \n4.Bills \n5.Show bill of particular customer\n6.Top Customer\n.7.Best Sold Items:";
			cin>>n1;
			switch(n1)
			{
			case 1:d.accept_item();
			break;
			case 2:
			d.accept();
			break;
			case 3:
			d.display();
			break;
			case 4:d.bill_calc();
			break;
			case 5:d.cust_bill();
			break;
			case 6:d.top_cust();
			break;
			case 7:d.best_sold();
			break;
					}
			cout<<"\n Do you wish to  continue?Press 1:";
			cin>>n2;
		}while(n2==1);
		return 0;
	}
