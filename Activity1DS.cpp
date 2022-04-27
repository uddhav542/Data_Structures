#include <iostream> 
#include <cstring>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
using namespace std; 

class Node
{
	public:
		int roll;
		Node *next;
		Node()
		{
			next=this;	
		}	
};
class linked_list
{
	Node *start;
	public:
		linked_list()
		{
			start=NULL;
		}
		void create()
		{
		
		do
			{
				Node *temp=new Node();
				Node *p;
				cout<<endl<<"Enter roll no:";
				cin>>temp->roll;
				if(start==NULL)
				{
					start=temp;
					temp->next=start;
				}
				else
				{
					p=start;
					while(p->next!=start)
					{
						p=p->next;
					}
					p->next=temp;
					temp->next=start;
				}
				cout<<"do you want to add more? y/n";
		    }while(getch()!='n');
		}

		void insert_beg()
		{
			Node *temp=new Node();
			Node* p;
			cout<<endl<<"Enter roll no:";
			cin>>temp->roll;
			if(start==NULL)
			{
				start=temp;
				temp->next=start;
			}
			else
			{
				p=start;
				while(p->next!=start)
				{
					p=p->next;
				}
				temp->next=start;
				p->next=temp;
				start=temp;
			}
		}

		void insert_end()
		{
			Node *temp=new Node();
			Node *p;
			cout<<endl<<"Enter roll no:";
			cin>>temp->roll;
			if(start==NULL)
			{
				start=temp;
			}
			else
			{
				p=start;
				while(p->next!=start)
				{
					p=p->next;
				}
				p->next=temp;
				temp->next=start;
			}
		}

		insert_bet(int pos)
		{
			Node *p;
			p=start;
			for(int i=1;i<pos;i++)
			{
				p=p->next;
			}
			Node *temp=new Node();
			cout<<endl<<"Enter roll no:";
			cin>>temp->roll;
			temp->next=p->next;
			p->next=temp;	
		}
		
		void del_beg()
		{
			Node *temp;
			if(start==NULL)
			{
				cout<<"List is empty.";
			}
			else
			{
				temp=start;
				while(temp->next!=start)
				{
					temp=temp->next;
				}
				temp->next=start->next;
				start=temp->next;
				delete(temp);
			}
		}
		
		void del_last()
		{
			Node *temp,*prev;
			if(start==NULL)
			{
				cout<<"List is empty.";
			}
			else
			{
				temp=start;
				while(temp->next!=start)
				{
					prev=temp;
					temp=temp->next;
				}
				prev->next=temp->next;
				delete(temp);
			}
		}
		void display()
		{
			Node *t;
			if(start==NULL)
			{
				printf("List is empty.");
			}
			else
			{
				t=start;
				cout<<"head--->";
				do
				{
					cout<<t->roll<<"--->";
					t=t->next;
					
				}while(t->next!=start);
				cout<<t->roll<<"--->";
				cout<<"head";
			}	
		}
};
int main()
{
	linked_list l;
	int ch;
	do{
	cout<<endl<<"Choose."<<endl<<"1.create"<<endl<<"2.insert at beginning"<<endl<<"3.insert at end"
	<<endl<<"4.insert in between"<<endl<<"5.delete at start"<<endl<<"6.delete at last"<<endl<<"7.display"<<endl;
	cin>>ch;
	switch(ch){
			case 1:
				l.create();
				break;
			case 2:
				l.insert_beg();
				break;
			case 3:
				l.insert_end();
				break;
			case 4:
				int p;
				cout<<"Enter position:";
				cin>>p;
				l.insert_bet(p);
				break;	
			case 5:
				l.del_beg();
				break;
			case 6:
				l.del_last();
				break;
			case 7:
				l.display();
				break;
		}
	cout<<endl<<"Do you want to continue.(y/n)";
	}while(getch()!='n');
	getch();
	return 0;
}
