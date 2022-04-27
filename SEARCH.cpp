#include <bits/stdc++.h>
using namespace std;
int sentinel_search(int arr[],int n,int key)
{
	int i;
	arr[n]=key;
	for(i=0;arr[i]!=key;i++)
	{
	
	}
	if(i<n)
	{
		return i+1;
	}
	else
	{
		return 0;
	}
}
int binary_search(int arr[],int l,int r,int key)
{
	if(r>=l)
	{
		int mid;
		mid=(l+r)/2;
		if(arr[mid]==key)
			return mid+1;
		if(arr[mid]>key)
			return(binary_search(arr,l, mid-1, key));
		if(arr[mid]<key)
			return(binary_search(arr,mid+1, r, key));
	}
	
}
int main()
{

	cout<<"Enter total students:";
	int n;
	cin>>n;
    int arr[n];
    cout<<"enter marks:";
   	for(int i=0;i<n;i++)
   	{
   		cin>>arr[i];	
	}
	cout<<"1.sentinel search\t2.binary seach\n";
	int ch;
	cin>>ch;
	int k;
	cout<<"Enter key:";
	cin>>k; 
	int b;
	switch(ch)
	{
		case 1: 
		b=sentinel_search(arr,n,k);
		cout<<"Element found at:"<<b;
		break;
		case 2:
		int s=binary_search(arr,0,n-1,k);
		cout<<"Element found at:"<<s;
	}	
    return 0;
}
 
