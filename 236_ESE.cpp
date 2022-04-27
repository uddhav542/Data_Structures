/*
Roll NO:      236
Exam seat no: S204153
Batch:        E2
Problem statement: Sparse Matrix Addition and Transpose
*/

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
		void fast_transpose();
};
void sparsematrix::accept()
{
	cout<<"\nEnter number of rows:";
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

void sparsematrix::fast_transpose()
{
	int i;
	int result[50][3];
	int *count= new int[col];
	int *index = new int[col+1]; 
	for ( i = 0; i < col; i++)  
    {
    	count[i] = 0;
	}   
	for ( i = 1; i <= sparse[0][2]; i++)
	{
		count[sparse[i][1]]++;
	}        
    index[0] = 1;
    for (int i = 1; i <= col; i++)  
  	{
  		index[i] = index[i - 1] + count[i - 1];
	}
    result[0][0]=sparse[0][1];
	result[0][1]=sparse[0][0];
	result[0][2]=sparse[0][2];  
	for (int i = 1; i <= sparse[0][2]; i++) 
    { 
            int k = index[sparse[i][1]]; 
            result[k][0] = sparse[i][1]; 
  			result[k][1] = sparse[i][0];  
            result[k][2] = sparse[i][2];
			index[sparse[i][1]]++;     
    }      
  	cout<<"fast Transpose:";
  	for(i=0;i<=result[0][2];i++)
  	{
  		cout<<"\n";
		for(int j=0;j<3;j++)
		{
			cout<<result[i][j]<<"\t";	
		}	
	}
}
int main()
{

	sparsematrix sp1,sp2;
	sp1.accept();
	sp1.createsparse();
	sp1.fast_transpose();
	sp2.accept();
	sp2.createsparse();
	sp1.addition(sp2);
	return 0;
}


/*output:
Enter number of rows:4
Enter number of columns:4
Enter matrix :
0 0 2 0
0 1 0 4
0 0 5 0
7 0 0 0
Triplet of matrix :
4   4   5
0   2   2
1   1   1
1   3   4
2   2   5
3   0   7
fast Transpose:
4       4       5
0       3       7
1       1       1
2       0       2
2       2       5
3       1       4
Enter number of rows:4
Enter number of columns:4
Enter matrix :
0 2 0 0
0 3 0 0
1 0 0 0
0 0 0 6
Triplet of matrix :
4   4   4
0   1   2
1   1   3
2   0   1
3   3   6
Addition:
4   4   8
0   1   2
0   2   2
1   1   4
1   3   4
2   0   1
2   2   5
3   0   7
3   3   6
--------------------------------
*/
