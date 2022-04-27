#include<stdio.h>
int main()
{
	int a[3][3],b[3][3];
	int c[3][3];
	printf("Enter first matrix elements:\n");
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	
	printf("Enter second matrix elements:\n");
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			scanf("%d",&b[i][j]);
		}
	}
	
	printf("Addition is:\n");
	for(int i=0;i<3;i++)
	{
		printf("\n");
		for(int j=0;j<3;j++)
		{
			c[i][j]=a[i][j]+b[i][j];
			printf("\t%d",c[i][j]);
		}
	}
	return 0;
}
