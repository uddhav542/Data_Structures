#include<iostream>
#include<conio.h>
#define size 4
using namespace std;
class ArrayQ
{
	public:
		int rear=-1;
		int front=-1;
		int que[size];
		int no;
		void insert_rear();
		void insert_front();
		void del_front();
		void del_rear();
		void display();
};
void ArrayQ::insert_rear()
{
	
	if(rear==size-1)
	{
		cout<<"Queue is overflow.";
	}
	else
	{
		if(front==-1)
		front=0;
		cout<<"Enter number for add operation:";
		cin>>no;
		rear=rear+1;
		que[rear]=no;
	}
}
void ArrayQ::del_front()
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
void ArrayQ::del_rear()
{
	if(front==-1||front>rear)
	{
		cout<<"Queue is underflow.";
	}
	else
	{
		cout<<"Deleted no:"<<que[rear];
		if(front==rear)
		{
			front=-1;
		}
		else
		{
			rear=rear-1;
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
		cout<<"Elements are:\t";
		for(i=front;i<=rear;i++)
		{
			cout<<que[i]<<"\t";
		}
	}
}
void ArrayQ::insert_front()
{
	front=front-1;
	if(front==-1)
	{
		cout<<"Insertion not possible.";
	}
	else
	{
		cout<<"Enter number for add operation:";
		cin>>no;
		que[front]=no;
	}

	
}
int main()
{
	ArrayQ a;
	int ch;
	cout<<"-----------Double Ended QUEUE---------";
	while(1)
	{
		cout<<"\n1-Insert at rear\n2-insert at front\n3-delete at front\n4-delete at rear\n5-display";
			cout<<"\nEnter your choice:";
		cin>>ch;
		switch(ch)
		{
			case 1: a.insert_rear();
			break;
			case 2: a.insert_front();
			break;
			case 3: a.del_front();
			break;
			case 4: a.del_rear();
			break;
			case 5: a.display();
			break;
		}
	}
	
	return 0;
}


/*
#include<iostream>
#include<conio.h>
using namespace std;
class ArrayQ
{
	public:
		int rear=-1;
		int front=-1;
		int que[100];
		int no;
		void insert_front();
};
void ArrayQ::insert_front()
{
	front=front-1;
	if(front==-1)
	{
		cout<<"Insertion not possible.";
	}
	else
	{
		cout<<"Enter number for add operation:";
		cin>>no;
		que[front]=no;
	}	
}
*/
