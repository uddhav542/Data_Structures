#include <iostream> 
#include <cstring>
#include<stdio.h>
#include<conio.h>
using namespace std; 

class Node
{
	public:
		int num;
		Node *next;
		Node()
		{
			next=NULL;	
		}	
};
class linked_list
{

	public:
		Node *start;
		int count=0;
		linked_list()
		{
			start=NULL;
		}
	
		void create1()
		{
			do
			{
				
				Node *temp=new Node();
				Node *p;
				cout<<"\nEnter numbers:";
				cin>>temp->num;
				if(start==NULL)
				{
					start=temp;
				}
				else
				{
					p=start;
					while(p->next!=NULL)
					{
						p=p->next;
					}
					p->next=temp;
				}
				cout<<"do you want to add more? y/n";
				count++;
		    }while(getch()!='n');
		}
		void rearrange()
		{
			Node *p,*q,*t;
			int temp;
			if(!start)
			{
				return;
			}
			p=start;
			q=start->next;
			while(q)
			{
				temp=p->num;
				p->num=q->num;
				q->num=temp;
				p=q->next;
				q=p?p->next:0;
			}
			t=start;
			cout<<endl;
			while(t->next!=NULL)
			{
				cout<<t->num<<" ";
				t=t->next;
			}
			cout<<t->num<<" ";
			return;
		}
		void display()
		{
			Node *t;
			if(start==NULL)
			{
				printf("List is empty.");
			}
			t=start;
			cout<<endl;
			while(t->next!=NULL)
			{
				cout<<t->num<<" ";
				t=t->next;
			}
			cout<<t->num<<" ";
			return;
		}
		void fun(Node *tmp)
		{
			if(tmp==NULL)
			{
				return;
			}
			
			cout<<tmp->num<<" ";
			fun(tmp->next);
		}
		
		void fun1(Node *tmp)
		{
			if(tmp ->next== NULL)
			 return; 
			printf("%d ", tmp->num); 
			if(tmp->next != NULL ) 
			fun1(tmp->next->next);
			printf("%d ", tmp->num); 
		}
		
};
int main()
{
	linked_list l;

	l.create1();
	//l.rearrange();
	cout<<"\nBefore fun() executes:";
	l.display();
	cout<<"\nAfter fun1() executes:\n";
	l.fun(l.start);
	return 0;
}
