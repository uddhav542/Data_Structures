//do this with class and array of objects having marks and roll no
#include <bits/stdc++.h>
using namespace std;
class student
{
	public:
	int marks;
	int roll;
	void read()
    {
    	cout << "Roll no.:" ;
    	cin>>roll;
    	cout << "Marks:" ;
    	cin>>marks;
	}
	void displayInfo()
    {
    
      cout << "ROll no. : " << roll << endl;
      cout << "MArks: " << marks << endl;
    }
	void insertion_sort(student s,int n);
	int partition(student s,int low,int high);
	void quick_sort(student s,int low,int high);
};
void student:: insertion_sort(student s,int n)
{
	int i, key, j;
    for (i = 1; i <n; i++)
    {
        key = s[i].marks;
        s[j] = s[i - 1];
 
        /* Move elements of arr[0..i-1], that are
        greater than key, to one position ahead
        of their current position */
        while (j >= 0 && s[j] > key)
        {
            s[j + 1] = s[j];
            j = j - 1;
        }
        s[j + 1] = key;
    }
    for (i = 0; i < n; i++)
        cout << s[i].displayInfo() << " ";
    cout << endl;
}

int main()
{
	cout<<"Enter size:";
	int n;
	cin>>n;
   	student s[n];
   	student s1;
    cout<<"enter elements:";
	for( int i=0; i<n; i++ )
  	{	cout << "student detalis: " << i + 1 << endl;
    	s[i].read();
  	}
	cout<<"1.Insertion sort\t2.Quick sort\n";
	int ch;
	cin>>ch;
	switch(ch)
	{
		case 1: s1.insertion_sort(s[],n);
		break;
		case 2: 
		
		break;
	}	
    return 0;
}
 
