#include <cstring>
#include <iostream>
using namespace std;

class car
{

  public:  string model;
  int no;
    void read()
    {
    		cout << "Enter car no.:" ;
    		cin>>no;
    		cout << "Enter car model name:" ;
    		cin>>model;
	}
    void displayInfo()
    {
    
      cout << "Car no. : " << no << endl;
    cout << "Model : " << model << endl;
    }
    
};
	
int main()
{
	int choice;int n=4;
	int p=0;
	int pos=0;
	car st[n];	int flag=0;string name;
	while(1){
	cout<<"1.Read\n2.display\n3.insert\n4.delete\n5.update\nChoose:";
	cin>>choice;
	switch(choice)
	{
		case 1:
  		for( int i=0; i<n; i++ )
  		{	cout << "car detalis: " << i + 1 << endl;
    		st[i].read();
  		}
  		break;
  		
		case 2:
  		for( int i=0; i<n; i++ )
  		{
    		cout << "car details:" << endl;
    		st[i].displayInfo();
  		}
  		break;
  		
  		case 3:
  			int x,pos;
  		cout<<"enter position to insert:";
  		cin>>pos;
  		for(x=n-1;x>=pos;x--)
  		{
  			st[x]=st[x-1];
		}
		st[pos].read();
		
		break;
		
		case 4:	
		cout<<"enter the model name to delete:";
		cin>>name;
		int i;
		for(i=0;i<n;i++)
		{
			if(name==st[i].model)
			{
				flag=1;
				break;
			}
	  
		}
		if(flag==1)
		{
			for(int j=i;j<n-1;j++)
			{
				st[i]=st[i+1];
			}	
		}
		break;
		
		case 5:
		cout<<"Enter position to update:";
		 cin>>p;
	   	st[p].read();
		 	
  }
}
  return 0;
}

