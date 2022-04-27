#include<stdio.h>
#define max 3
int top=0;
int stk[max];
void push();
void pop();
void display();

int main()
{
	int s;
	
	while(1)
	{
		printf("\nOperations on the stack:");
		printf("\n1.Push element\n2.pop element\n3.display stack");
		printf("\nEnter your choice:");
		scanf("%d",&s);
		switch(s)
		{
			case 1:
			{
				push();
				break;
			}
			case 2:
			{
				pop();
				break;
			}
			case 3:
			{
				display();
				break;
			}
			default:
			{
				printf("invalid choice.");
				break;
			}
		}
	}

	return 0;
}
void push()
{
	int no;
	if(top==max)
	{
		printf("\nStack overflow!!");
	}
	else
	{
		printf("Enter no for push operation:");
		scanf("%d",&no);
		top=top+1;
		stk[top]=no;
	}
}
void pop()
{
	if(top==0)
	{
		printf("\nStack underflow");
	}
	else
	{
		printf("\nPopped no. is %d",stk[top]);
		top=top-1;
	}
}
void display()
{
	int i;
	if(top==0)
	{
		printf("\nStack is empty");
	}
	else
	{
		printf("\nStack elements are:");
		for(i=top;i>0;i--)
		{
			printf("\n%d",stk[i]);
		}
	}
}


