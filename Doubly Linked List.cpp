#include<iostream>

using namespace std;

class node{
    public:
        int marks;
        node *next;
        node *prev;
        node(){
            cout<<"\nEnter the marks of the student: ";
            cin>>marks;
            next=NULL;
            prev=NULL;
        }
};

class DLL{
    public:
        int length = 0;
        node *start;
        int ch = 1;
        DLL(){
            start=NULL;
        }

        void create_list(){
            node *temp;
            do{
                temp = new node();
                length += 1;
                if(start == NULL)
                    start = temp;
                else{
                    start->prev = temp;
                    temp->next = start;
                    start = temp;
                }
                cout<<"\nDo you want to add another element press 1 for yes 0 for no: ";
                cin>>ch;
            }while(ch==1);
        }

        void Merge(DLL d1, DLL d2){
            node *ptr1, *ptr2, *ptr3;
            ptr1 = d1.start;
            ptr2 = d2.start;

            if(ptr1 == NULL && ptr2 == NULL){
                cout<<"Both list are Empty!";
                start = NULL;
                return;
            }
            if(ptr1 == NULL){
                start = ptr2;
                return;
            }
            if(ptr2 == NULL){
                start = ptr1;
                return;
            }
            if(ptr1->marks <= ptr2->marks){
                start = ptr1;
                ptr3= ptr1;
                ptr1 = ptr1->next;
            }
            else{
                start = ptr2;
                ptr3 = ptr2;
                ptr2 = ptr2->next;
            }
            while(ptr1 != NULL && ptr2 != NULL){
                    if(ptr1->marks <= ptr2->marks){
                    ptr3->next = ptr1;
                    ptr1->prev = ptr3;
                    ptr1 = ptr1->next;
                }
                else if(ptr2->marks < ptr1->marks){
                    ptr3->next = ptr2;
                    ptr2->prev = ptr3;
                    ptr2 = ptr2->next;
                }
                ptr3 = ptr3->next;
            }
            if(ptr1 == NULL){
                ptr3->next = ptr2;
                ptr2->prev = ptr3;
            }
            else{
                ptr3->next = ptr1;
                ptr1->prev = ptr3;
            }
        }
        node *swapnode(node *p1,node *p2){
            node *temp;
            temp = p2->next;
            p2->next = p1;
            p2->prev = p1->prev;
            p1->next = temp;
            p1->prev = p2;
            if(p1->next != NULL){
                temp->prev = p1;
            }
            if(p2->prev != NULL){
                p2->prev->next = p2;
            }
            else{
            start = p2;
            }
            return p2;
            }

        void bubblesort(){
            node **h;
            int i,j,swapped;
            for(i=0;i<length;i++){
                h = &start;
                swapped =0;
                for(j=0;j<(length-1-i);j++){
                    node *p1 = *h;
                    node *p2 = p1->next;
                    if(p1->marks > p2->marks){
                        *h = swapnode(p1,p2);
                        swapped = 1;
                    }
                    h = &(*h)->next;
                }
                if(swapped == 0){
                    break;
                }
            }
        }

        void display(){
            if(start == NULL){
                cout<<"\nList is empty!!!";
            }
            node *p;
            p = start;
            while(p != NULL){
                cout<<"--->"<<p->marks;
                p = p->next;
            }
        }
};

int main(){
    DLL d1;
    int ch;

    while(1){
        cout<<"\nEnter your choice \n1. Create \n2. Display \n3. sort \n4. Merge \n5. Exit \n";
        cin>>ch;
        switch(ch){
            case 1:
                d1.create_list();
                cout<<"\nlength of linked list is "<<d1.length<<"\n";
                break;
            case 2:
                d1.display();
                break;
            case 3:
                d1.bubblesort();
                break;
            case 4:
                {
                    DLL d2, d3;
                    d2.create_list();
                    cout<<"\nlength of linked list is"<<d2.length<<"\n";
                    d2.bubblesort();
                    d3.Merge(d1,d2);
                    d3.length = d1.length + d2.length;
                    cout<<"\nlength of merged linked list is"<<d3.length<<"\n";
                    d3.display();
                    break;
                }
            case 5:
                return 0;
            }
        }
    }


