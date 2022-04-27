#include<iostream>
using namespace std;
class sparsematrix
{
	int matrix[100][100];
	int row,col;
	int sparse[100][3];	
	public:
		void accept();
		void createsparse();
		void addition(sparsematrix &matrix2);
};
void sparsematrix::accept()
{
	cout<<"Enter number of rows:";
	cin>>row;
	cout<<"Enter number of columns:";
	cin>>col;
	cout<<"Enter matrix :\n";
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			cin>>matrix[i][j];
		}
	}
}

void sparsematrix::createsparse()
{
	cout<<"Triplet of matrix :\n";
	int n=0;
	sparse[0][0]=row;
	sparse[0][1]=col;
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			if(matrix[i][j]!=0)
			{
				sparse[n+1][0]=i;
				sparse[n+1][1]=j;
				sparse[n+1][2]=matrix[i][j];
				n++;
			}
		}
	}
	sparse[0][2]=n;
	for(int i=0;i<n+1;i++)
	{
		for(int j=0;j<3;j++)
		{
			cout<<sparse[i][j]<<"   ";
		}
		cout<<"\n";
	}
}
void sparsematrix::addition(sparsematrix &matrix2)
{
	int s1,s2,i=1,j=1,k=1;
	int result[40][3];
	s1=sparse[0][2];
	s2=matrix2.sparse[0][2];
	result[0][0]=sparse[0][0];
	result[0][1]=sparse[0][1];
	
	if(row!=matrix2.row && col!=matrix2.col)
	{
		cout<<"row and column not matching.";
		return;
	}
	else
	while(i<=s1&&j<=s2)
	{
		if(sparse[i][0]==matrix2.sparse[j][0])
		{
			if(sparse[i][1]==matrix2.sparse[j][1])
			{
				result[k][0]=sparse[i][0];
				result[k][1]=sparse[i][1];
			result[k][2]=sparse[i][2]+matrix2.sparse[j][2];
				i++;
				j++;
				k++;
			}
			else
			{
				if(sparse[i][1]<matrix2.sparse[j][1])
				{
					result[k][0]=sparse[i][0];
					result[k][1]=sparse[i][1];
					result[k][2]=sparse[i][2];
					i++;	
					k++;
				}
				else
				{
					if(sparse[i][1]>matrix2.sparse[j][1])
					{
					result[k][0]=matrix2.sparse[j][0];
					result[k][1]=matrix2.sparse[j][1];
					result[k][2]=matrix2.sparse[j][2];
						j++;	
						k++;
					}
				}
			}
		}
		else
		{
			if(sparse[i][0]>matrix2.sparse[j][0])
			{
				result[k][0]=matrix2.sparse[j][0];
				result[k][1]=matrix2.sparse[j][1];
				result[k][2]=matrix2.sparse[j][2];
				j++;	
				k++;
			}
			else
			{
				if(sparse[i][0]<matrix2.sparse[j][0])
				{
					result[k][0]=sparse[i][0];
					result[k][1]=sparse[i][1];
					result[k][2]=sparse[i][2];
					i++;	
					k++;
				}
			}
		}
	}
	while((j<=s2))
	{
		result[k][0]=matrix2.sparse[j][0];
		result[k][1]=matrix2.sparse[j][1];
		result[k][2]=matrix2.sparse[j][2];
		j++;	
		k++;
	}
	while((i<=s1))
	{
		result[k][0]=sparse[i][0];
		result[k][1]=sparse[i][1];
		result[k][2]=sparse[i][2];
		i++;	
		k++;
	}
	result[0][2]=k-1;
	
	cout<<"Addition:";
	for(int i=0;i<=result[0][2];i++)
	{
		cout<<"\n";
		for(int j=0;j<3;j++)
		{
			cout<<result[i][j]<<"   ";
		}
	}
}

int main()
{

	sparsematrix sp1,sp2;
	sp1.accept();
	sp1.createsparse();
	sp2.accept();
	sp2.createsparse();
	sp1.addition(sp2);
	return 0;
}

