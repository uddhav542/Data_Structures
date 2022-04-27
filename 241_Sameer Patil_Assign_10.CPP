
/*
Name : Sameer Manik Patil
Roll no : 241
PRN : 0220200017
Seat No : S208073
Problem Statement : Design and implement a menu driven program
                    for implementing insertion sort and quick Sort
                    on population of Town
*/


#include<iostream>
#include<string>
using namespace std;

int Partition(int A[], int low, int high){
    int pivot = A[high];
    int i = (low-1);

    for (int j = low; j <= high - 1; j++)
    {
        if (A[j] < pivot)
        {
            i++;
           int temp=A[i];
           A[i]=A[j];
           A[j]=temp;
        }
    }
    int temp=A[i+1];
    A[i+1]=A[high];
    A[high]=temp;
    return (i + 1);
}
void QuickSort(int A[], int low, int high){
    if(low < high){
       int p=Partition(A,low,high);
        QuickSort(A,low,p-1);
        QuickSort(A,p+1,high);
    }
}
void InsertionSort(int A[], int n){
    for(int i=1,key=A[i],j;i<n;i++){
        key=A[i];
        for(j=i-1;j>=0 && A[j]>key ; j--)
            A[j+1]=A[j];
        A[j+1]=key;
    }
}
int main(){

    int  A[10],n,key,t;
    cout<<"Enter the Population of Town : ";
    cin>>n;
    cout<<"Enter the Age of People : ";
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    cout<<"Enter the Sorting Technique : .....1.Insertion Sort...2.Quick Sort....";
    cin>>t;
    switch(t){
        case 1 :
                    InsertionSort(A,n);
                    break;
        case 2 :
                    QuickSort(A,0,n-1);
                    break;
        defaul : cout<<"\nInvalid Choice !";
    }

    cout<<"\nSorted Age of People : \n";
    for(int i=0;i<n;i++)
        cout<<A[i]<<endl;
    return 0;
}

/*
Output :

//For Insertion Sort
Enter Population of Town : 5
Enter the Age of People :
3
76
32
89
3
Enter the Sorting Technique : .....1.Insertion Sort...2.Quick Sort....1

Sorted Age of People :
3
3
32
76
89

Process returned 0 (0x0)   execution time : 9.726 s
Press any key to continue.

---------------------------------------------------------------------------------------------------------------

//For Quick Sort
Enter the Population of Town : 5
Enter the Age of People :
32
46
70
1
24
Enter the Sorting Technique : .....1.Insertion Sort...2.Quick Sort....2

Sorted Age of People :
1
24
32
46
70

Process returned 0 (0x0)   execution time : 14.068 s
Press any key to continue.

*/
