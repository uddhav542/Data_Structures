#include<iostream>
#include<string.h>
using namespace std;
char temp[20];
void permutations(char *str,int r,int index)
{
	for(int i=0;i<strlen(str);i++)
	{
		temp[index]=str[i];
		if(index==r-1)
		{
			cout<<"\t"<<temp;
		}
		else
		{
			permutations(str,r,index+1);
		}
	}
	
}
int main()
{
	char str[10];
	cout<<"Enter string:";
	cin>>str;
	for(int r=1;r<=strlen(str);r++)
	{
		permutations(str,r,0);
	}
	return 0;
}
