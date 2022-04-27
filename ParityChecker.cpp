#include<iostream>
#include<string>
#include<bits/stdc++.h>
using namespace std;
class parityChecker
{
	int counter=0;
	string s;
	int b[100];
	public:
		void input()
		{
			cout<<"Enter String:";
			cin>>s;
		}
		void FindParity()
		{
			for(int i=0;i<s.length();i++)
			{
				int value=int(s[i]);
				int j=0;
				while(value>0)
				{
					int p=value%2;
					b[j]=p;
					value=value/2;
					j++;
				}
				reverse(b,b+j);
				cout<<"  ";
				for(int i=0;i<j;i++)
				{
					cout<<b[i];
					if(b[i]==1)
					{
						counter++;
					}
				}
			}
			if(counter%2==0)
			{
				cout<<"\nEven parity.";
			}
			else
			{
				cout<<"\nOdd parity.";
			}
		}
};
int main()
{
	parityChecker p;
	p.input();
	p.FindParity();
	return 0;
}
