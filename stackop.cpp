#include<iostream>
#include<bits/stdc++.h>
#include<string>
#include<cstring>
#include<conio.h>
#include<sstream>
#define size 100
using namespace std;
class Stack
{
	public:
		string stack[size];
		int top;
		Stack()
		{
			top=-1;
		}
		bool IsFull()
		{
			if(top==size-1)
			{
				return true;
			}
			else
				return false;
		}
		bool IsEmpty()
		{
			if(top==-1)
			{
				return true;
			}
			else
				return false;
		}
		void push(string str)
		{
			if(IsFull())
			{
				cout<<"stack is full";
			}
			else
			{
				top++;
				stack[top]=str;
			}
			
		}
		string pop()
		{
			if(IsEmpty())
			{
				cout<<"";
			}
			else
			{
				string str=stack[top];
				top--;
				return str;
			}
			
		}
	
};
class expression
{
	public :
	string postfix;
	string infix;
	Stack str1;
	bool IsOperator(char x)
	{
		if(x=='+'||x=='-'||x=='*'||x=='/'||x=='^')
		{
			return true;
		}
		else
			return false;
	}	
	int precedence(string t)
	{
		if(t=="+"||t=="-")
			return 1;
		else if(t=="*"||t=="/")
			return 2;
		else if(t=="^")
			return 3;
		else
			return 0;		
	}
	void infix_to_postfix()
	{
		cout<<"Enter infix expression:";
		cin>>infix;
		for(int i=0;i<infix.length();i++)
		{
			if((infix[i]>='a'&&infix[i]<='z')||(infix[i]>='A'&&infix[i]<='Z'))
			{
				postfix=postfix+infix[i];
			}
			else if(infix[i]=='(')
			{
				str1.push("(");
			}
			else if(infix[i]==')')
			{
				while(str1.top!=-1 && str1.stack[str1.top]!="(")
				{
					string temp=str1.stack[str1.top];
					str1.pop();
					postfix=postfix+temp;
				}
				if(str1.stack[str1.top]=="(")
				{
					str1.pop();
				}
			}
			else
			{
				while((str1.top!=-1) && precedence(string(1,infix[i])) <= precedence(str1.stack[str1.top]))
				{
					string temp=str1.stack[str1.top];
					str1.pop();
					postfix=postfix+temp;
				}
				str1.push(string(1,infix[i]));
			}
		}
		while(str1.top!=-1)
		{
			string temp=str1.stack[str1.top];
			str1.pop();
			postfix=postfix+temp;
		}
		cout<<"postfix expression:"<<postfix;
	}
	
	void postfix_to_prefix()
	{
		cout<<"Enter postfix expression:";
		cin>>postfix;
		for(int i=0;i<postfix.length();i++)
		{
			if(IsOperator(postfix[i]))
			{
				string op1=str1.pop();
				string op2=str1.pop();
				string temp=postfix[i]+op2+op1;
				str1.push(temp);
			}
			else
			{
				str1.push(string(1,postfix[i]));
			}
		}
		string prefix=str1.pop();
		cout<<"Prefix expression:"<<prefix;
	}
	void postfix_evaluation()
	{
		cout<<"Enter postfix expression:";
		cin>>postfix;
		for(int i=0;i<postfix.length();i++)
		{
			if(IsOperator(postfix[i]))
			{
				int a,b,ans;
				string op2=str1.pop();
				string op1=str1.pop();
				stringstream st1(op1);
				stringstream st2(op2);
				st1>>a;
				st2>>b;
				if(postfix[i]=='+')
					ans=a+b;
				else if(postfix[i]=='-')
					ans=a-b;
				else if(postfix[i]=='*')
					ans=a*b;
				else if(postfix[i]=='/')
					ans=a/b;
				else if(postfix[i]=='^')
					ans=a^b;
					
				ostringstream st3;
				st3<<ans;
				string temp=st3.str();
				str1.push(temp);
			}
			else
			{
				str1.push(string(1,postfix[i]));
			}
		}
		string result=str1.pop();
		cout<<"Result:"<<result;
	}
};
int main()
{
	Stack s;
	expression e;
	int ch;
	do
	{
		cout<<"\n1.Infix to postfix.\n2.Postfix to prefix\n3.Postfix evaluation\n";
		cin>>ch;
		switch(ch)
		{
			case 1:
				e.infix_to_postfix();
				break;
			case 2:
				e.postfix_to_prefix();
				break;
			case 3:
				e.postfix_evaluation();
				break;
			
		}
		cout<<"\nDo you want to continue.(y/n)";
	}while(getch()!='n');
	
	return 0;
}
