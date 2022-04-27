#include<iostream>
#include<stdlib.h>
#include<string>
using namespace std;

int bsort(int a[],int n)
{
	int i,j,temp;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
	return 0;
}
int checkforRoyalFlush(int data[],int player)
{
	int *sdata;
	int R[5];
	int S[5];
	for(int i=0;i<5;i++)
	{
		R[i]=sdata[i]%13;
		S[i]=sdata[i]/13;
	}
	if(S[0]==S[1] && S[1]==S[2] && S[2]==S[3] && S[3]==S[4]) 
	{
		if(R[1]==R[0]+1 && R[2]==R[1]+1 && R[3]==R[2]+1 && R[4]==R[3]+1 &&R[0]==8)
		{
			cout<<"ROYAL FLUSH"<<S[0]<<R[0];
			cout<<"Winner is player"<<player;
			exit(0);
		}
	}
	return 0;
}
void combination(int arr[],int data[],int start,int end,int index,int r,int player)
{
	int flag=0;
	if(flag==1)
		return;
	if(index==r)
	{
		for(int j=0;j<r;j++)
		{
			cout<<data[j]<<" ";
		}
		flag=checkforRoyalFlush(data,player);
		cout<<"\n";
	}
	for(int i=start;i<=end && end-i+1>=r-index;i++)
	{
		data[index]=arr[i];
		combination(arr,data,i+1,end,index+1,r,player);
	}
}


int checkdeal(int a[],int player)
{
	int d[7];
	combination(a,d,0,6,0,5,player);
	return 1;
}



int main()
{
	int deck[52];
	string snames[4]={"S","H","C","D"};
	string rnames[13]={"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
	for(int i=0;i<52;i++)
	{
		deck[i]=i;
	}
	for(int i=0;i<52;i++)
	{
		int j=(rand()%52);
		int temp=deck[i];
		deck[i]=deck[j];
		deck[j]=temp;
	}
	for(int i=0;i<52;i++)
	{
		int snum=deck[i]/13;
		int rank=deck[i]%13;
		cout<<rnames[rank]<<snames[snum]<<"\t";
	}
	int f;
	cout<<"\nDeal is ";
	f=0;
	
	int i=0,j=0;
	int a[7],b[7];
	while(f<9)
	{
		if(f==0||f==2||f==4)
			cout<<"{";
		int suitnumber=deck[f]/13;
		int rank=deck[f]%13;
		cout<<rnames[rank]<<snames[suitnumber]<<" ";
		if(f==2||f==3)
		{
			
		}
		else
		{
			a[i++]=deck[f];
		}
		if(f>1)
		{
			b[j++]=deck[f];
		}
		if(f==1||f==3||f==8)
			cout<<"}";
		f++;
	}
	cout<<"\nPlayer 1 cards:\n";
	f=0;
	while(f<7)
	{
		int suitnumber=a[f]/13;
		int rank=a[f]%13;
		cout/*<<a[f]<<":"*/<<rnames[rank]<<snames[suitnumber]<<" ";
		f++;
	}
	bsort(a,7);
	cout<<"\nAfter sorting:\n";
	for(int f=0;f<7;f++)
	{
		int suitnumber=a[f]/13;
		int rank=a[f]%13;
		cout/*<<a[f]<<":"*/<<rnames[rank]<<snames[suitnumber]<<" ";
		
	}
	
	cout<<"\nPlayer 2 cards:\n";
	f=0;
	while(f<7)
	{
		int suitnumber=b[f]/13;
		int rank=b[f]%13;
		cout/*<<b[f]<<":"*/<<rnames[rank]<<snames[suitnumber]<<" ";
		f++;
	}
	bsort(b,7);
	cout<<"\nAfter sorting:\n";
	for(int f=0;f<7;f++)
	{
		int suitnumber=b[f]/13;
		int rank=b[f]%13;
		cout/*<<a[f]<<":"*/<<rnames[rank]<<snames[suitnumber]<<" ";
		
	}
	cout<<"\n";
	i=checkdeal(a,1);
	j=checkdeal(b,2);
	cout<<"Match Draw";
	return 0;
}
