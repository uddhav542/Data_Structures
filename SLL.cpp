#include <iostream> 
#include <cstring>
#include<conio.h>
using namespace std; 
class Node
{
	public:
		int roll;
		char name[20];
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
				cout<<"Enter name:";
				cin>>temp->name;
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

		void insert_beg()
		{
			Node *temp=new Node();
			cout<<endl<<"Enter roll no:";
			cin>>temp->roll;
			cout<<"Enter name:";
			cin>>temp->name;
			if(start==NULL)
			{
				start=temp;
				temp->next=NULL;
			}
			else
			{
				temp->next=start;
				start=temp;
			}
		}

		void insert_end()
		{
			Node *temp=new Node();
			Node *p;
			cout<<endl<<"Enter roll no:";
			cin>>temp->roll;
			cout<<"Enter name:";
			cin>>temp->name;
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
			cout<<"Enter name:";
			cin>>temp->name;
			temp->next=p->next;
			p->next=temp;	
		}
	
		void update(int rn)
		{
			Node *p=start;
			if(start==NULL)
			{
				cout<<"list is empty.";
				return;
			}
			while(p!=NULL)
			{
				if(p->roll==rn)
				{
					cout<<endl<<"Enter new roll no:";
		 			cin>>p->roll;
		  			cout<<"Enter new name:";
					cin>>p->name;
					return;
				}
				p=p->next;
			}
			cout<<"not present";
		}

		int search(int rn)
		{
			Node *p=start;
			if(start==NULL)
			{
				cout<<"list is empty.";
				return 0;
			}
			while(p!=NULL)
			{
				if(p->roll==rn)
				{
					cout<<"found.";
					return 0;
				}
				p=p->next;
			}
			cout<<"Not found";
		}
		
		void del(int rn)
		{
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
			temp=start;
			while(temp!=NULL)
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
			cout<<"not found.";
			return;
		}

		void sort()
		{
			if(start==NULL)
			{
				cout<<"list is empty.";
				return;
			}
			Node *ptr1,*ptr2;
			int swapped;
			do
			{
				ptr1=start;
				ptr2=start->next;
				swapped=0;
				while(ptr1->next!=NULL)
				{
					if((ptr1->roll)>(ptr2->roll))
					{
						int temp=ptr1->roll;
						ptr1->roll=ptr2->roll;
						ptr2->roll=temp;
				
						char temp1[20];
						strcpy(temp1,ptr1->name);
						strcpy(ptr1->name,ptr2->name);
						strcpy(ptr2->name,temp1);
						swapped=1;
					}
					ptr1=ptr2;
					ptr2=ptr2->next;
				}
			}while(swapped!=0);
		}

		linked_list merge()
		{
			linked_list l2,l3;
			l2.create();
			l2.sort();
			Node *ptr1,*ptr2,*ptr3;
			ptr1=start;
			ptr2=l2.start;
			if(ptr1 == NULL && ptr2 == NULL)
			{
				l3.start = NULL;
				return l3;
	    	}

	      	if(ptr2 == NULL){
			l3.start = start;
			return l3;
	      	}
	      	if(ptr1 == NULL){
				return l2;
	      	}
	
			if(ptr1->roll< ptr2->roll){
			l3.start = ptr1;
			ptr3 = l3.start;
			ptr1=ptr1->next;
	      }
	      else{
			l3.start = ptr2;
			ptr3  =l3.start;
			ptr2 = ptr2->next;
	      }

	      if(ptr1->roll== ptr2->roll){
			l3.start = ptr1;
			ptr3 = l3.start;

	      }

	      while(ptr1!=NULL && ptr2!= NULL){
			if(ptr1->roll <= ptr2->roll){
				ptr3->next = ptr1;
				ptr1 = ptr1->next;
				ptr3 = ptr3->next;
			}
			else{
				ptr3->next = ptr2;
				ptr2 = ptr2->next;
				ptr3 = ptr3->next;
			}
	      }

	      if(ptr1 == NULL){
			ptr3->next = ptr2;
	      }
	      if(ptr2 == NULL){
			ptr3->next = ptr1;
	      }
	      return l3;
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
					cout<<"name:"<<t->name<<endl;
					t=t->next;
				}
				cout<<endl;
			}	
		}
};
int main()
{
	linked_list l,l1,l2;
	int ch;
	do{
	cout<<endl<<"Choose."<<endl<<"1.create"<<endl<<"2.insert at beginning"<<endl<<"3.insert at end"
	<<endl<<"4.insert in between"<<endl<<"5.update"<<endl<<"6.search"<<endl<<"7.delete"
	<<endl<<"8.sort"<<endl<<"9.merge"<<endl<<"10.display"<<endl;
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
				int r;
				cout<<"Enter roll no to update:";
				cin>>r;
				l.update(r);
				break;
			case 6:
				int s;
				cout<<"Enter roll no to search:";
				cin>>s;
				l.search(s);
				break;
			case 7:
				int n;
				cout<<"Enter roll no to delete:";
				cin>>n;
				l.del(n);
				break;
			case 8:
				l.sort();
				break;
			case 9:
				l.sort();
				cout<<"create another list to merge.";
				l2 = l.merge();
				l2.display();
				break;
			case 10:
				l.display();
				break;
		}
	cout<<endl<<"Do you want to continue.(y/n)";
	}while(getch()!='n');
	getch();
	return 0;
}
