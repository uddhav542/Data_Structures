#include<iostream>
#include<conio.h>
using namespace std;
class shop
{
	public:
	int cake[40][40];       //declaration of 2D array to store sales values
	void Read()
	{	
		cout<<"Enter the sales values as of March, April, May ,June 2020 Respectively."<<endl;
		cout<<"Enter sales values of pineapple cake:";
		for(int i=0;i<4;i++)
		{
			cin>>cake[i][0];      //Read and store sales value of pineapple
		}
		cout<<"Enter sales values of Black forest cake:";
		for(int i=0;i<4;i++)
		{
			cin>>cake[i][1];	//Read and store sales value of Black forest
		}
		cout<<"Enter sales values of Red velvet cake:";
		for(int i=0;i<4;i++)
		{
			cin>>cake[i][2];     //Read and store sales value of Red velvet
		}
		cout<<"Enter sales values of Caramel Apple cake:";
		for(int i=0;i<4;i++)
		{
			cin>>cake[i][3];     //Read and store sales value of Caramel Apple
		}
		
	}
	void display()  //function used to display sales values
	{
		cout<<"\t\tMarch 2020"<<"\t\t"<<"April 2020"<<"\t\t"<<"May 2020"<<"\t\t"<<"June 2020"<<endl;
		cout<<"\t\t---------------------------------------------------------------------------------"<<endl;
		cout<<"pineapple:";
		for(int i=0;i<4;i++)
		{
			cout<<"\t"<<cake[i][0]<<"\t\t"; //display Pineapple sales
		}
		cout<<endl<<"black forest:";
		for(int i=0;i<4;i++)
		{
			cout<<"\t"<<cake[i][1]<<"\t\t"; //display black forest sales
		}
		cout<<endl<<"Red velvet:";
		for(int i=0;i<4;i++)
		{
			cout<<"\t"<<cake[i][2]<<"\t\t"; //display Red velvet sales
		}
		cout<<endl<<"caramel Apple:";
		for(int i=0;i<4;i++)
		{
			cout<<"\t"<<cake[i][3]<<"\t\t"; //display caramel Apple sales
		}
		
	}
	salesmonth()   //function used to display total sales of cae by month
	{
		int sum=0;
		for(int i=0;i<4;i++)
		{
			sum=sum+cake[0][i];  //calculation of total sales of march 2020
		}
		cout<<endl<<"Total sales of March 2020:"<<sum;
		sum=0;
		for(int i=0;i<4;i++)
		{
			sum=sum+cake[1][i];  //calculation of total sales of april 2020
		}
		cout<<endl<<"Total sales of April 2020:"<<sum;
		sum=0;	
		for(int i=0;i<4;i++)
		{
			sum=sum+cake[2][i];  //calculation of total sales of may 2020
		}
		cout<<endl<<"Total sales of May 2020:"<<sum;
		sum=0;
		for(int i=0;i<4;i++)
		{
			sum=sum+cake[3][i];  //calculation of total sales of june 2020
		}
		cout<<endl<<"Total sales of June 2020:"<<sum;
	}
	salesflavor()   //function used to display total sales of cae by flavor
	{
		int sum=0;
		for(int i=0;i<4;i++)
		{
			sum=sum+cake[i][0]; //calculation of total sales of Pineapple
		}
		cout<<endl<<"Total sales of Pineapple cake:"<<sum;
		sum=0;
		for(int i=0;i<4;i++)
		{
			sum=sum+cake[i][1]; //calculation of total sales of black forest
		}
		cout<<endl<<"Total sales of Black forest cake:"<<sum;
		sum=0;	
		for(int i=0;i<4;i++)
		{
			sum=sum+cake[i][2]; //calculation of total sales of Red velvet
		}
		cout<<endl<<"Total sales of Red velvet cake:"<<sum;
		sum=0;
		for(int i=0;i<4;i++)
		{
			sum=sum+cake[i][3]; //calculation of total sales of caremel apple
		}
		cout<<endl<<"Total sales of Caramel Apple cake:"<<sum;
	}
};

int main()
{
	shop s;
	int choice;
	do
	{
		cout<<endl<<"choose."<<endl;
		cout<<"1.Read the values:"<<endl<<"2.Display sales of cake"<<endl<<"3.Total sales of cake for each month"
		<<endl<<"4.Total sales of cake as flavor."<<endl;
		cout<<"Enter choice.";
		cin>>choice;
		switch(choice)
		{
			case 1:
				s.Read();
				break;
			case 2:
				s.display();
				break;
			case 3:
				s.salesmonth();
				break;
			case 4:
				s.salesflavor();
				break;
		}
		cout<<endl<<"Do you want to continue:(y/n)";
	}while(getch()!='n');
	getch();
	return 0;
}
