#include <iostream> 
#include<conio.h>
using namespace std; 

class Node
{
	public:
		int roll;
		int marks;
		
		Node *next,*prev;
		Node()
		{
			next=NULL;	
			prev=NULL;
		}	
};
class MarkList
{
	Node *start;
	int count;
	public:
		MarkList()
		{
			start=NULL;
		}
		void create()
		{
			count=0;
			do
			{
				Node *temp=new Node();
				cout<<endl<<"Enter roll no:";
				cin>>temp->roll;
				cout<<"Enter marks:";
				cin>>temp->marks;
				if(start==NULL)
				{
					start=temp;
				}
				else
				{
					temp->next=start;
					start->prev=temp;
					start=temp;
				}
				count++;	
				cout<<"Do you want to add more?(y/n)";
			}
			while(getch()!='n');
		}
		Node* swap(Node *p1,Node *p2)
		{
			Node *temp;
            temp = p2->next;
            p2->next = p1;
            p2->prev = p1->prev;
            p1->next = temp;
            p1->prev = p2;
            if(p1->next != NULL)
			{
                temp->prev = p1;
            }
            if(p2->prev != NULL)
			{
                p2->prev->next = p2;
            }
            else
			{
            	start = p2;
            }
            return p2;  
			
		}
		
		void sort()
		{
			Node **h;
			int i,j,swapped;
			for(i=0;i<count-1;i++)
			{
				h=&start;
				swapped=0;
				for(j=0;j<count-1-i;j++)
				{
					Node *p1=*h;
					Node *p2=p1->next;
					if(p1->marks>p2->marks)
					{
						*h=swap(p1,p2);
						swapped=1;
					}
					h=&(*h)->next;
				}	
				if(swapped==0)
				{
					break;
				}
			}
			
		}
		
		
		
		void merge(MarkList l1,MarkList l2)                                      
		{
			Node *p=l1.start;
			Node *q=l2.start;
			Node *r;
			if(p==NULL&&q==NULL)
			{
				cout<<"Lists are empty.";
				start=NULL;
				return;
			}
			if(p==NULL)
			{
				start=q;
				return;
			}
			if(q==NULL)
			{
				start=p;
				return;
			}
		
			if(p->marks<=q->marks)
			{
				start=p;
				r=p;
				p=p->next;
			}
			else
			{
				start=q;
				r=q;
				q=q->next;
			}	
			while(p!=NULL && q!=NULL)
			{
				if(p->marks<=q->marks)
				{
					r->next=p;
					p->prev=r;
					p=p->next;
				}
				else if(q->marks<=p->marks)
				{
					r->next=q;
					q->prev=r;
					q=q->next;
				}
				r=r->next;
			}
	
			if(p==NULL)
			{
				r->next=q;
				q->prev=r;
			}
			else
			{
				r->next=p;
				p->prev=r;
			}
		}
		void display()
		{
			
			Node *p;
			if(start==NULL)
			{
				printf("List is empty.");
			}
			else
			{
				p=start;
				cout<<endl<<"student details:"<<endl;
				while(p!=NULL)
				{
					cout<<"Roll no:"<<p->roll<<endl;
					cout<<"Marks:"<<p->marks<<endl;
					p=p->next;
				
				}
			cout<<endl;
			}		
		}
};
int main()
{
	MarkList m,m1,m2;
	int ch;
	while(1)
	{
		cout<<"\n1.create\n2.sort\n3.Merge.\n4.display.\n5.exit.\n";
		cin>>ch;
		switch(ch)
		{
			case 1:
				m.create();
				break;
			case 2:
				m.sort();
				break;
			case 3:
				cout<<"\nEnter list 2:";
				m.sort();
				m1.create();
				m1.sort();
				m2.merge(m,m1);
				m2.display();
				break;
			case 4:
				m.display();
				break;
			case 5:
				exit(0);
				break;
		}	
	}
	getch();
}
	
	
			
