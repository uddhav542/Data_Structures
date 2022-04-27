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
    void create();
    void display();
};
void Polynomial::create()
{
    int n,i;
    cout<<"how many nodes do you want enter";
    cin>>n;
    for(i=0;i<n;i++)
    {
        Node *temp=new Node;
        cout<<"\nEnter coefficient=";
        cin>>temp->coe;
        cout<<"\nEnter Exponent";
        cin>>temp->exp;
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
int main()
{
    Polynomial s;
    int ch;
    do
    {
    cout<<"\n1:create\n2:display";
    cout<<"\nEnter Your Choice:";
    cin>>ch;
        switch(ch)
        {
        case 1:
            s.create();
            break;
        case 2:
            s.display();
            break;
        }
    }while(ch!=0);
getch();
return 0;
}
