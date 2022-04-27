#include<iostream>
using namespace std;
class loan
{
	float rate;
	int year;
	public:
		int a0,a1;
	void getdata();
	void display();
		
};
void loan::getdata()
{
	cout<<"Enter amount:";
	cin>>a0;
	cout<<"Enter interest rate(in %):";
	cin>>rate;
	cout<<"Enter number of years do you want to check amount:";
	cin>>year;
}
void loan::display()
{
	for(int i=0;i<year;i++)
	{
		a1=a0+((rate/100)*a0);
		a0=a1;	
	}
	cout<<"After "<<year<<" years it becomes:"<<a1;
	
}
int main()
{
	loan l;
	int ch;
	cout<<"Choose. 1.Home Loan\n2.Car Loan\n3.Personal Loan\n";
	cin>>ch;
	switch(ch)
	{
		case 1:
			cout<<"Enter details of Home loan:\n";
			l.getdata();
			l.display();
			break;
		case 2:
			cout<<"Enter details of Car loan:\n";
			l.getdata();
			l.display();
			break;
		case 3:
			cout<<"Enter details of Personal loan:\n";
			l.getdata();
			l.display();
			break;
	}
	
	return 0;
}
