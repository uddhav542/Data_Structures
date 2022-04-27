#include<iostream>
using namespace std;
class Node
{
	public:
		int cust_id;
		int cust_item;
		Node *next,*prev;  
		Node()
		{
			next=NULL;	
			prev=NULL;
		}	
};
class DLL
{
	Node *start;
	public:
		int count=0;  //used to get count of items in list
		DLL()
		{
			start=NULL;
		}
		void insert_at_end() //used to create list adding 						//element at end
		{
			
			Node *temp=new Node();
			Node *p;
			cout<<endl<<"Enter customer ID:";
			cin>>temp->cust_id;
			cout<<"Enter ID of ice-cream:";
			cin>>temp->cust_item;
			if(start==NULL)
			{
				temp->next = NULL;  
           		temp->prev = NULL;  
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
				temp->prev=p;  
          		temp->next = NULL;  
			}
			count++;   //it will increament count when new 
						//node is created
		}
		
		Node* swap(Node *p1,Node *p2) //swap fuction required 								//for sorting
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
		
		void sort()   //sort elements after creating list
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
					if(p1->cust_id>p2->cust_id)
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
		
		int search(int ID)    //search element with specific 						//id
		{
			Node *p=start;
			if(start==NULL)
			{
				cout<<"list is empty.";
				return 0;
			}
			while(p!=NULL)
			{
				if(p->cust_id==ID)
				{
					cout<<"Found successfully.\n";
					cout<<p->cust_id<<"|"<<p->cust_item;
					return 0;
				}
				p=p->next;
			}
			cout<<"Not found";
		}
		
		int del(int ID) //to delete element with specific id
		{
			Node *prv,*p;
			if(start==NULL)
			{
				cout<<"list is empty.";
				return 0;
			}
		
			
			if(start->cust_id==ID)
			{
				p=start;
				start=start->next;
				start->prev=NULL;
				delete(p);
				count--;
				return 0;
			}
			p=start;
		
			while(p!=NULL)
			{
				if(p->cust_id==ID)
				{
					prv->next=p->next;
					delete(p);
					count--;
					return 0;
				}
				prv=p;
				p=p->next;
			}
			cout<<"not found.";
		}
		
		void display()   //to display list 
		{
			Node *p;
			if(start==NULL)
			{
				printf("List is empty.");
			}
			else
			{
				p=start;
				cout<<"-------------WELCOME TO ICE CREAM PARLOUR-------------";
				cout<<"\nTotal number of customers:"<<count;
				cout<<endl<<"Customer details with customer id and ice-cream id in sorted:"<<endl;
				cout<<"Head-->";
				while(p!=NULL)
				{
					cout<<p->cust_id<<"|"<<p->cust_item<<"--->";
					p=p->next;
				
				}
				cout<<"NULL";
			}		
		}
};
int main()
{
	DLL d;
	int ch;
	while(1)
	{
		cout<<"\n\n1.insert at end\n2.Search.\n3.Delete.\n4.display.\n5.exit.\n";
		cin>>ch;
		switch(ch)
		{
			case 1:
				d.insert_at_end();
				d.sort();
				break;
			case 2:
				int id;
				cout<<"Enter customer id to search:";
				cin>>id;
				d.search(id);
				break;
			case 3:
				int i;
				cout<<"Enter customer id to delete:";
				cin>>i;
				d.del(i);
				cout<<"Deleted successfully.";
				break;
			case 4:
				d.display();
				break;
			case 5:
				exit(0);
				break;
		}	
	}
}
