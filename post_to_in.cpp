//Roll No: 236 
//Name: Uddhav patil
#include<iostream>
using namespace std;
class Node
{
	public:
		string name;
		Node *next;
		Node()
		{
			next=NULL;	
		}	
};
class Stack
{
	public:
		Node *top;
		Stack()
		{
			top=NULL;
		}
		void push(string s)
		{
			Node* temp;
    		temp = new Node();
    		temp->name=s;
    		temp->next = top;
    		top = temp;
		}
		string pop()
		{
			Node* temp;
 			string str;
    		if (top == NULL)
   		 	{
       			cout << "\nStack Underflow" << endl;
        		exit(1);
    		}
    		else
    		{
        		temp = top;
        		str=temp->name;
        		top = top->next;
    			//temp->next = NULL;
        		delete(temp);
			}
			return str;
	}
};
Stack str1;
bool isOperand(char x)
{
   return (x >= 'a' && x <= 'z') ||
          (x >= 'A' && x <= 'Z');
}
void getInfix(char t)
{ 
    if (isOperand(t))
        {
           str1.push(string(1,t));
        }
        else
        {
            string op1 = str1.pop();
            string op2 = str1.pop();
            str1.push("(" + op2 + t +
                   op1 + ")");
        }
}
void get()
{
	string infix=str1.pop();
	cout<<"infix expression:"<<infix;
}
int main()
{
	cout<<"Enter length:";
	int l;
	cin>>l;
	char exp;
	cout<<"Enter expression:\n";
	for(int i=0;i<l;i++)
	{
		cin>>exp;
		getInfix(exp);
	}
	get();
    return 0;
}


/*output:
Enter length:5
Enter expression:
a
b
+
c
*
infix expression:((a+b)*c)
*/

