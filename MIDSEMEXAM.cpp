#include<iostream>
using namespace std;
void duplicate_element(int arr[], int n)
{
int i, j;
int count = 0;
printf("Duplicate customer ID:");
for(i = 0;i < n;i++)
{
	for(j = i+1;j < n;j++)
	{
		if(arr[i] == arr[j])
		{
		printf("%d ", arr[j]);
		}
	}
}
}
int main()
{
int n;
cin>>n;
int arr[n];
int i;
for(i = 0; i < n; i++)
{
	cin>>arr[i];
}
	duplicate_element(arr,n);
	return 0;
}

