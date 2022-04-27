#include<iostream>
#include<conio.h>
using namespace std;
class Node
{
public:
    int coe;
    int exp;
    Node* next;
    Node()
    {
        next=this;
    }
};
class Polynomial
{
    public:
    Node *start;
    Polynomial()
    {
        start=NULL;
    }
    void sorted_insert(Node *temp);
    void display();
    void add(Polynomial p1,Polynomial p2);
    void mul(Polynomial p1,Polynomial p2);
};
void Polynomial::sorted_insert(Node *temp)
{
    
        Node *p,*prev;
        if(start==NULL)
        {
            start=temp;
        }
        else if(start->exp<temp->exp)
        {
            p=start;
            while(p->next!=start)
            {
                p=p->next;
            }
        	temp->next=start;
        	p->next=temp;
        	start=temp;
        }
        else if(start->exp==temp->exp)
        {
            start->coe=start->coe+temp->coe;
        }
        else{
            p=start;
            while(1)
            {
                if(p->exp==temp->exp)
                {
                    p->coe=p->coe+temp->coe;
                    break;
                }
                else if(p->exp<temp->exp ||p->next==start)
                {
                    if(p->exp<temp->exp)
                    {

                        prev->next=temp;
                        temp->next=p;
                        break;
                    }
                    else{
                            p->next=temp;
                        temp->next=start;
                        break;
                    }
                }
                else{
                    prev=p;
                    p=p->next;
                }
            }
        }

}
void Polynomial::display()
{
    Node *p;
    p=start;
    do
    {
        cout<<p->coe<<"X^"<<p->exp<<"+";
        p=p->next;
    }while(p->next!=start);
    cout<<p->coe<<"X^"<<p->exp<<"=0\n";

}
void Polynomial::add(Polynomial po1,Polynomial po2)
{
	Node *p1,*p2,*p3;
	if(po1.start==NULL&&po2.start){
		return;
	}
	p1=po1.start;
	do
	{
		Node * temp=new Node();
		temp->exp=p1->exp;
		temp->coe=p1->coe;
		temp->next=temp;
		sorted_insert(temp);
		p1=p1->next;
	}while(p1!=po1.start);
	p2=po2.start;
	do
	{
		Node * temp=new Node();
		temp->exp=p2->exp;
		temp->coe=p2->coe;
		temp->next=temp;
		sorted_insert(temp);
		p2=p2->next;
	}while(p2!=po2.start);

}
void Polynomial::mul(Polynomial po1,Polynomial po2)
{
	Node *p1,*p2;
	if(po1.start==NULL&&po2.start==NULL)
	{
		return;
	}
	p1=po1.start;
	do
	{
		p2=po2.start;
		do
		{
			Node * temp=new Node();
			temp->exp=p1->exp+p2->exp;
			temp->coe=p1->coe*p2->coe;
			temp->next=temp;
			sorted_insert(temp);
			p2=p2->next;
		}
		while(p2!=po2.start);
		p1=p1->next;
	}
	while(p1!=po1.start);
}
int main()
{
    Polynomial s,s1,s2,s3;
    cout<<"Enter equation 1:";
    do
    {
		Node *temp=new Node;
    	cout<<"\nEnter coefficient=";
        cin>>temp->coe;
        cout<<"Enter Exponent:";
        cin>>temp->exp;
    	s.sorted_insert(temp);
    	cout<<"Do you want to add more?(y/n)";
	}while(getch()!='n');
	
	cout<<"\nEnter equation 2:";
  	do
    {
		Node *temp1=new Node;
    	cout<<"\nEnter coefficient=";
        cin>>temp1->coe;
        cout<<"Enter Exponent:";
        cin>>temp1->exp;
    	s1.sorted_insert(temp1);
    	cout<<"Do you want to add more?(y/n)";
	}while(getch()!='n');
	int ch;
	do{
		cout<<"\nchoose.\n1.Display\n2.Addition\n3.Multiplication"<<endl;
		cin>>ch;
		switch(ch)
		{
			case 1:
				cout<<"equation 1:";
				s.display();
				cout<<"equation 2:";	
				s1.display();
				break;
			case 2:
				s2.add(s,s1);
				cout<<endl;
				cout<<"Addition:";
    			s2.display();
    			break;
    		case 3:
    			cout<<"Multiplication:";
    			s3.mul(s,s1);
    			s3.display();
    			break;
		} 
		cout<<"Do you want to continue.(y/n)";
	}while(getch()!='n');
    getch();
	return 0;
}
