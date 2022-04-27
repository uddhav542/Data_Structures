#include <iostream> 
#include <cstring>
#include<conio.h>
using namespace std; 

class Node
{
	public:
		int roll;
		Node *next;
		Node()
		{
			next=NULL;	
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
		    }while(getch()!='n');
		}
		void del(int rn)
		{
			int count=0;
			Node *prev,*temp;
			if(start==NULL)
			{
				cout<<"list is empty.";
				return;
			}
			if(start->roll==rn)
			{
				temp=start;
				start=start->next;
				delete(temp);
				return;
			}
			while(start!=NULL)
			{
				if(start->roll==rn)
				{
					count++;
				}
				start=start->next;
			}
			for(int i=0;i<count;i++)
			{
				temp=start;
			
				while(temp->next!=NULL)
				{
					if(temp->roll==rn)
					{
					prev->next=temp->next;
					delete(temp);
					return;
					}                                                  
					prev=temp;
					temp=temp->next;
				}
				}
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
				cout<<endl<<"student details:"<<endl;
				while(t!=NULL)
				{
					cout<<"Roll no:"<<t->roll<<endl;
					t=t->next;
				}
				cout<<endl;
			}	
		}
};
int main()
{
	linked_list l,l1;
	int ch;
	
		do{
			cout<<endl<<"Choose."<<endl<<"1.create"<<endl<<"2.delete\n"<<"3.display";
			cin>>ch;
		switch(ch){
			case 1:
				l.create();
				break;
			case 2:
				int n;
				cout<<"Enter roll no to delete:";
				cin>>n;
				l.del(n);
				break;
			case 3:
				l.display();
				break;
			}
			cout<<endl<<"Do you want to continue.(y/n)";
	}while(getch()!='n');
		return 0;
}
