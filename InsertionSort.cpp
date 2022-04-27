#include <bits/stdc++.h>
using namespace std;
class student
{
	public:
	void insertion_sort(int arr[],int n);
	int partition(int arr[],int low,int high);
	void quick_sort(int arr[],int low,int high);
};
void student:: insertion_sort(int arr[],int n)
{
	int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
 
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
    for (i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}
int student:: partition(int arr[],int low,int high)
{
	int pivot=low;
	int i,j;
	i=low;
	j=high;
	while(i<j)
	{
		while(arr[i]<=arr[pivot] && i<high)
		{
			i++;
		}
		while(arr[j]>arr[pivot])
		{
			j--;
		}
		if(i<j)
		{
			int temp=arr[i];
			arr[i]=arr[j];
			arr[j]=temp;
		}
	}
	int temp1=arr[pivot];
	arr[pivot]=arr[j];
	arr[j]=temp1;
	return j;
}
void student:: quick_sort(int arr[],int low,int high)
{
	if(low<high)
	{
		int p=partition(arr,low,high);
		quick_sort(arr,low,p-1);
		quick_sort(arr,p+1,high);
	}
}
int main()
{
	student s;
	cout<<"Enter pupulation of town:";
	int n;
	cin>>n;
    int arr[n];
    cout<<"enter age of people:";
   	for(int i=0;i<n;i++)
   	{
   		cin>>arr[i];	
	}
	cout<<"1.Insertion sort\t2.Quick sort\n";
	int ch;
	cin>>ch;
	switch(ch)
	{
		case 1: s.insertion_sort(arr,n);
		break;
		case 2: s.quick_sort(arr,0,n-1);
		for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    	cout << endl;
		break;
	}	
    return 0;
}
 
