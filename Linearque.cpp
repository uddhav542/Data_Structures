#include<iostream>
#include<conio.h>
#define size 4
using namespace std;
class Node
{
	public:
	int data;
	char name[20];
	Node *next;
	Node()
	{
		next=NULL;		
	}
};
class queue
{
	Node *front,*rear;
	public:
		queue()
		{
			front=NULL;
			rear=NULL;
		}
		void enqueue();
		void dequeue();
		void show();
};
void queue::enqueue()
{
	do{
		Node *temp=new Node();
		cout<<"Enter ID:";
		cin>>temp->data;
		cout<<"Enter Food name:";
		cin>>temp->name;
		if(front==NULL)
		{
			temp->next=NULL;
			front=rear=temp;
		}
		else
		{
			rear->next=temp;
			rear=temp;
		}
		cout<<"Add more?(y/n)";	
		cout<<"\n";
	}while(getch()!='n');
	
}
void queue::dequeue()
{
	Node *temp;
	if(front==NULL)
	{
		cout<<"Queue is empty.";
	}
	else
	{
		temp=front;
		front=front->next;
		delete(temp);
	}
}
void queue::show()
{
	Node *p;
	p=front;
	if(p==NULL)
	{
		cout<<"Queue is empty.";
	}
	while(p!=NULL)
	{
		cout<<p->data<<"\t"<<p->name<<"-->";
		p=p->next;
	}
}

class ArrayQ
{
	public:
		int no;
		int rear=-1;
		int front=-1;
		int que[size];
		void add();
		void del();
		void display();
};
void ArrayQ::add()
{
	if(rear==size-1)
	{
		cout<<"Queue is overflow.";
	}
	else
	{
		if(front==-1)
		front=0;
		cout<<"Enter number:";
		cin>>no;
		rear=rear+1;
		que[rear]=no;
	}
}
void ArrayQ::del()
{
	if(front==-1||front>rear)
	{
		cout<<"Queue is underflow.";
	}
	else
	{
		cout<<"Deleted no:"<<que[front];
		if(front==rear)
		{
			front=-1;
		}
		else
		{
			front=front+1;
		}
		
	}
}
void  ArrayQ::display()
{
	int i;
	if(front==-1)
	{
		cout<<"Queue is empty.";
	}
	else
	{
		cout<<"Elements are:\n";
		for(i=front;i<=rear;i++)
		{
			cout<<que[i]<<endl;
		}
	}
}
int main()
{
	queue q;
	ArrayQ a;
	int ch,ch1;
	cout<<"-----------Linear QUEUE---------";
	cout<<"\n1.using array\n2.using linked list\n";
	cin>>ch;
	cout<<"-----------Food Ordering System-------------";
	switch(ch)
	{
		case 1:
			while(1)
			{
				cout<<"\n1-Add\n2-Delete\n3-display";
				cout<<"\nEnter your choice:";
				cin>>ch1;
				switch(ch1)
				{
					case 1:	a.add();
					break;
					case 2: a.del();
					break;
					case 3: a.display();
					break;
				}
			}
			break;
		case 2:
			while(1)
			{
				cout<<"\n1-Add\n2-Delete\n3-display";
				cout<<"\nEnter your choice:";
				cin>>ch1;
				switch(ch1)
				{
					case 1: q.enqueue();
					break;
					case 2: q.dequeue();
					break;
					case 3: q.show();
					break;
				}
			}
			break;
	}
	
	return 0;
}

