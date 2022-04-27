#include<stdio.h>
//#include<iostream>
#include<conio.h>
#define max 3
//using namespace std;
int rear=-1;
int front=-1;
int que[max];
void add()
{
	int no;
	if(rear==(max-1))
	{
		printf("Queue is overflow.");
	}
	else
	{
		if(front==-1)
		front=0;
		printf("Enter number for add operation:");
		scanf("%d",&no);
		rear=rear+1;
		que[rear]=no;
	}
}
void del()
{
	if(front==-1||front>rear)
	{
		printf("Queue is underflow.");
	}
	else
	{
		printf("Deleted no=%d",que[front]);
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
void  display()
{
	int i;
	if(front==-1)
	{
		printf("Queue is empty.");
	}
	else
	{
		printf("Elements are:\n");
		for(i=front;i<=rear;i++)
		{
			printf("%d\n",que[i]);
		}
	}
}

int main()
{
	int ch,ch1;
	printf("-----------Linear QUEUE---------");
	printf("\n1.using array\n2.using linked list");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			while(1)
			{
				printf("\n1-Add\n2-Delete\n3-display");
				printf("\nEnter your choice:");
				scanf("%d",&ch1);
				switch(ch1)
				{
					case 1: add();
					break;
					case 2: del();
					break;
					case 3: display();
					break;
				}
			}
			break;
	}
	
	return 0;
}

