#include<iostream>
using namespace std;
int n=4;
void Number_Occurence(int a[4][4],int r,int c,int num)
{
	int count=0;
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			if(a[i][j]==num)
			{
				count++;
			}
		}
	}
	cout<<count<<"\n";
}
int main()
{
	int a[4][4];
	
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			cin>>a[i][j];
		}
	}
	cout<<a[0][0]<<":";Number_Occurence(a,4,4,a[0][0]);
	cout<<a[0][1]<<":";Number_Occurence(a,4,4,a[0][1]);
	cout<<a[0][2]<<":";Number_Occurence(a,4,4,a[0][2]);
	cout<<a[0][3]<<":";Number_Occurence(a,4,4,a[0][3]);
	return 0;
}
