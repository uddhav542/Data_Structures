#include <iostream> 
using namespace std; 
int intersection2(int a[],int b[],int s1,int s2)
{
	int count=0;
	for(int j=0;j<s1;j++)
	{
		for(int k=0;k<s2;k++)
		{
			if(a[j]==b[k])
			{
				count++;
			}
		}
	}
	return count;
}
int intersection3(int a[],int b[],int c[],int s1,int s2,int s3)
{
	int count=0;
	for(int i=0;i<s1;i++)
	{
		for(int j=0;j<s2;j++)
		{
			for(int k=0;k<s3;k++)
			{
				if(a[i]==b[j]&&a[i]==c[k]&&b[j]==c[k])
				{
					count++;
				}
			}
		}
	}
	return count;
}
int main()
{
	int size1,size2,size3;
	int total;
	cout<<"Enter size of french students:";
	cin>>size1;
	int a[size1];
	cout<<"Enter Roll no of students who spoke french:";
	for(int i=0;i<size1;i++)
	{
		cin>>a[i];
	}
	cout<<"Enter size of German Students:";
	cin>>size2;
	int b[size2];
	cout<<"Enter Roll no of students who spoke German:";
	for(int i=0;i<size2;i++)
	{
		cin>>b[i];
	}
	cout<<"Enter size of German Students:";
	cin>>size3;
	int c[size3];
	cout<<"Enter Roll no of students who spoke Russian:";
	for(int i=0;i<size3;i++)
	{
		cin>>c[i];
	}
	cout<<"\nno. of students who spoke german and French"<<intersection2(a,b,size1,size2);
	cout<<"\nno. of students who spoke german and Russian"<<intersection2(b,c,size2,size3);
	cout<<"\nno. of students who spoke French and Russian"<<intersection2(a,c,size1,size3);
	cout<<"\nno. of students who spoke All:"<<intersection3(a,b,c,size1,size2,size3);
	total=size1+size2+size3-intersection2(a,b,size1,size2)-intersection2(b,c,size2,size3)-intersection2(a,c,size1,size3)+intersection3(a,b,c,size1,size2,size3);
	
	cout<<"\nTotal no. of students:"<<total;
}
