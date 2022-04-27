#include<iostream>
using namespace std;
int main()
{
	int a[4][4],b[8][3];
	
	int n=0;
	cout<<"Enter matrix elements:\n";
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			cin>>a[i][j];
		}
	}
	b[0][0]=4;
	b[0][1]=4;;
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
		if(a[i][j]!=0)
		{
			b[n+1][0]=i;
			b[n+1][1]=j;
			b[n+1][2]=a[i][j];
			n++;	
		}
		}
	}
	b[0][2]=n;
	cout<<endl;
	cout<<"Triplet of matrix:"<<endl;
	for(int i=0;i<n+1;i++)
	{
		for(int j=0;j<3;j++)
		{
			cout<<b[i][j]<<" ";
		}
		cout<<endl;
	}
	
	return 0;
}
