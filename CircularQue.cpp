#include<iostream>
#include<conio.h>
#define size 4
using namespace std;
//implementation for array
class ArrayQ
{
	public:
		int rear=-1;
		int front=-1;
		int que[size];
		void add();
		void del();
		void display();
};

void ArrayQ::add()
{
	int no;
	if((front==0&&rear==size-1)||front==rear+1)
	{
		printf("Queue is overflow.");
	}
	else
	{
		if(front==-1)
		{
			front=0;
		}
		cout<<"Enter number for add operation:";
		cin>>no;
		rear=(rear+1)%size;
		que[rear]=no;
	}
}

void ArrayQ::del()
{
	if(front==-1)
	{
		cout<<"Queue is empty.";
	}
	else
	{
		int element=que[front];
		if(front==rear)
		{
			front=rear=-1;
		}
		else
		{
			front=(front+1)%size;
		}
		cout<<"Deleted Element:"<<element;
	}
}

void ArrayQ::display()
{
	if(front==-1)
	{
		cout<<"Queue is empty.";
	}
	else
	{
		cout<<"Elements are:\t";
		for(int i=front;i!=rear;i=(i+1)%size)
		{
			cout<<que[i]<<"\t";
		}
		cout<<que[rear];
	}
}


//implementation for linked list
class Node
{
	public:
	int data;
	char name[20];
	Node *next;
	Node()
	{
		next=this;		
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
		cout<<"Enter Name:";
		cin>>temp->name;
		temp->next=temp;
		if(front==NULL && rear==NULL)
		{
			front=rear=temp;
		}
		else
		{
			rear->next=temp;
			temp->next=front;
			rear=temp;
		}
		cout<<"Add more?(y/n)";
		cout<<"\n";	
	}while(getch()!='n');
	
}
void queue::dequeue()
{
	Node *temp;
	if(front==NULL  && rear==NULL)
	{
		cout<<"Queue is empty.";
	}
	else
	{
		if(front==rear)
		{
			front=rear=NULL;
		}
		else
		{
			temp=front;
			front=front->next;
			rear->next=front;
			delete(temp);
		}
		
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
	else
	{
		while(p!=rear)
		{
			cout<<p->data<<"\t"<<p->name<<"-->";
			p=p->next;
		}
		cout<<p->data<<"\t"<<p->name;
	}	
}

int main()
{
	queue q;
	ArrayQ a;
	int ch,ch1;
	cout<<"-----------Circular QUEUE---------";
	cout<<"\n1.using array\n2.using linked list\n";
	cin>>ch;
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
					case 1: a.add();
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
