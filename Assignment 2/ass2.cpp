#include <iostream> 
#include <cstring>
#include<conio.h>
#include <bits/stdc++.h>
using namespace std; 
class Node
{
	public:
		char name;
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
		void create()
		{
			do
			{
				
				Node *temp=new Node();
				Node *p;
				cout<<"\nEnter name:";
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
				count++;
		    }while(getch()!='n');
		}
		void getmiddle()
		{
			Node *p;
			p=start;
			int middle=0;         //used to get index of middle node 
			
			if(count%2==0)         //count variable stores the 
									//total number of nodes
									 
			{
				middle=(count/2)-1;
			}
			else
			{
				middle=count/2;
			}
			for(int i=0;i<middle;i++)
			{
				p=p->next;
			}
			cout<<"Middle of list:"<<p->name;
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
				cout<<"name:";
				while(t!=NULL)
				{
					cout<<t->name;
					t=t->next;
				
				}
			}
		}
		
		string findKWordString(Node* head, int k)
		{
    		// Stores the final string
    		string ans = "";
 
    		// Keep track of the number of
    		// nodes traversed
    		int cnt = 0;
 
    		// Stores the word formed by k consecutive
    		// nodes of the linked list
    		string word = "";
 
    		while (head) {
 
        		// Check if k nodes are traversed
        		// If yes then add the word obtained
       			 // to the result string
        		if (cnt == k)
				{
            		if (ans != "") 
					{
                		ans = ans + " ";
            		}
            		ans = ans + word;
            		word = "";
            		cnt = 0;
        		}
 
        		// Add the current character to the word
        		// formed so far and increase the count
        		word = word + string(1, head->name);
        		cnt++;
        		head = head->next;
    		}
 
    		// Add the final word to the result
    		// Length of the final word can be less than k
    		if (ans != " ") 
			{
        		ans = ans + " ";
    		}
    		ans = ans + word;
 
    		return ans;
		}
};
int main()
{
	linked_list l,l1;
	int ch;
	do{
	cout<<endl<<"Choose.\n1.create";//\n2.middle of list.
	cout<<"\n2.display.\n";
	cin>>ch;
	switch(ch){
			case 1:
				l.create();
				break;
			//case 2:
			//	l.getmiddle();
			//	break;
			case 2:
				int n;
				cout<<"enter number for string seperation:";
				cin>>n;
    			cout<<l.findKWordString(l.start, n);
				break;
		}
	cout<<endl<<"Do you want to continue.(y/n)";
	}while(getch()!='n');
	getch();
	return 0;
}
