#include<iostream>
using namespace std;
class sparse 
{ 
    const static int MAX = 40; 
    int **matrix; 
    int row, col;  
    int n; 
  
public: 
    sparse(int r, int c) 
    { 
  
        row = r; 
        col = c; 
        n = 0; 
        matrix = new int *[MAX]; 
        
       for (int i = 0; i < MAX; i++) // Array representation of sparse matrix 
            matrix[i] = new int[3]; //[0] represents row [1] represents col [2] represents value 
    } 
    
    void insert(int r, int c, int val) 
    { 
            matrix[n][0] = r; // insert row value
  			matrix[n][1] = c; // insert col value 
            matrix[n][2] = val; // insert element's value 
            n++; 					// increment number of data in matrix   
       
    } 
  
    sparse transpose() 
    { 
  
        sparse result(col, row);  // new matrix with inversed row X col 
        result.n = n; 
        int *count = new int[col]; // to count number of elements in each column 
  
        for (int i = 1; i <= col; i++)  // initialize all to 0 
            count[i] = 0; 
  
        for (int i = 0; i < n; i++) 
            count[matrix[i][1]]++; 
  
        int *index = new int[col]; 
  
        // to count number of elements having  
        // col smaller than particular i 
        index[0] = 0; 
  
        for (int i = 1; i <= col; i++)  // initialize rest of the indices 
  
            index[i] = index[i - 1] + count[i - 1]; 
  
        for (int i = 0; i < n; i++) 
        { 
  
            // insert a data at k and  
            // increment its value 
            int k = index[matrix[i][1]]++; 
            result.matrix[k][0] = matrix[i][1]; // transpose row=col 
  			result.matrix[k][1] = matrix[i][0]; // transpose col=row 
            result.matrix[k][2] = matrix[i][2]; // same value 
        } 

        return result; 
    } 
  
    void display() 
    { 
        cout << "\nSparse Matrix: \nRow\tColumn\tValue\n"; 
        for (int i = 0; i < n; i++) 
        { 
            cout << matrix[i][0] << "\t " << matrix[i][1]  
                 << "\t " << matrix[i][2] << endl; 
        } 
    } 
}; 
int main()
{
	int a[4][4],b[8][3];
	
	int n=0;
	cout<<"Enter matrix elements:\n";
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			cin>>a[i][j];
		}
	}
	b[0][0]=4;
	b[0][1]=4;;
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
		if(a[i][j]!=0)
		{
			b[n+1][0]=i;
			b[n+1][1]=j;
			b[n+1][2]=a[i][j];
			n++;	
		}
		}
	}
	b[0][2]=n;
	cout<<endl;
	cout<<"Triplet of matrix:"<<endl;
	for(int i=0;i<n+1;i++)
	{
		for(int j=0;j<3;j++)
		{
			cout<<b[i][j]<<" ";
		}
		cout<<endl;
	}
	sparse c(5,5);
	for(int i=1;i<n+1;i++)
	{
		c.insert(b[i][0],b[i][1],b[i][2]);
	}
	cout << "\nTranspose: "; 
    sparse trans = c.transpose(); 
    trans.display(); 
	return 0;
}
