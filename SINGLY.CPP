#include <conio.h>
#include <iostream>
#include<string.h>

using namespace std;

class node{
	public:
		char name[20];
		float percentage;
		node *next;
		node(){
			next = NULL;
		}
};
class singly{
    public:
	node *start;
	node *temp;
	node *p;
	singly(){
		start = NULL;
	}

	void create(){
	   p = start;
	   char ch;
	   do{
		temp = new node();
		cout<<"\nEnter the name and percentage : ";
		cin>>temp->name>>temp->percentage;

		if(start ==NULL)
			start = temp;
		else{
            p = start;
            while(p->next != NULL){
                p = p->next;
            }
            p->next = temp;

	    }
       cout<<"Do you want to add one more record : ";
       cin>>ch;
    }while(ch == 'y' || ch == 'Y');

	}

	void display(){
	       p = start;
		while(p != NULL ){
			cout<<"\nName : "<<p->name;
			cout<<"   percentage : "<<p->percentage;
			p=p->next;
		}
	}
	void insert_at_begning(){
		temp = new node();
		cout<<"Enter the name : ";
		cin>>temp->name;
		cout<<"Enter the percentage : ";
		cin>>temp->percentage;
		if(start == NULL){
			start = temp;
		}
		else{
			temp->next = start;
			start = temp;
		}
	}
	int insert_at_position(int pos){
		temp = new node();
		p=start;
		cout<<"Enter the name : ";
		cin>>temp->name;
		cout<<"Enter the percentage : ";
		cin>>temp->percentage;
		if(start == NULL && pos == 1){
			start = temp;
			return 1;
		}
		else if(start == NULL && pos != 1){
			cout<<"Set is Empty !";
			return 0;
		}
		else{
			p =start;
			for(int i =1;i<pos-1;i++){
				if(p==NULL){
					break;
					return 0;
				}
				p=p->next;
			}
			temp->next = p->next;
			p->next = temp;
			return 1;
		}
	}
	void insert_at_end(){
		temp = new node();
		p = start;
		if(start == NULL){
			start = temp;
		}
		else{
			while(p->next != NULL){
				p = p->next;
			}
			p->next = temp;
		}
		cout<<"Enter the name : ";
		cin>>temp->name;
		cout<<"Enter the percentage : ";
		cin>>temp->percentage;
	}

	int search(){
		char n[20];
		cout<<"\n Enter the name you want to search : ";
		cin>>n;
		p = start;
		if(start == NULL){
			cout<<"List is empty ! ";
			return 0;
		}
		while(p!= NULL){
			if(strcmp(p->name,n) ==0){
                cout<<"Record Found !!!\nName :"<<p->name<<" percentage :"<<p->percentage;
				return 1;
			}
			p = p->next;
		}
		return 0;
	}
	int update(char n[20]){
		p = start;
		if(start == NULL){
			cout<<"List is empty ! ";
			return 0;
		}
		while(p!= NULL){
			if(strcmp(p->name,n)==0){
				cout<<"Enter the Name and the percentage to update it with : ";
				cin>>p->name;
				cin>>p->percentage;
				return 1;
			}
			p=p->next;
		}
		return 0;
	}
	int del(){
		char n[20];
		cout<<"Enter the name : ";
		cin>>n;
		p = start;
		if(start == NULL){
			cout<<"List is empty !";
			return 0;
		}
		if(strcmp(p->name,n)==0){
			start = p->next;
			delete(p);
			return 1;
		}
		p = start;
		node *prev = new node();
		while(p!= NULL){
			if(p->name == n){
				prev->next = p->next;
				p->next = NULL;
				delete(p);
				return(1);
			}
			prev = p;
			p=p->next;
		}
		return (0);
	}
	void sort(){
		float g;
		char n[20];
	       node *prev = new node();
	       prev = start;
	       p = prev->next;
	       while(p != NULL){
			prev = start;
			while(prev != NULL){
				if(p->percentage < prev->percentage){
					g = p->percentage;
					strcpy(n ,p->name);
					p->percentage = prev->percentage;
					strcpy(p->name,prev->name);
					strcpy(prev->name,n);
					prev->percentage = g;
				}
				prev=prev->next;
			}
			p = p->next;
	       }
	}
	singly merge(){
	      singly s3,s2;
	      s2.create();
	      s2.sort();
	      cout<<"\n Second List\n";
	      s2.display();

	      cout<<"\n First List\n";
	      display();

	      node *ptr1;
	      node *ptr2;
	      node *ptr3;

	      ptr1 = start;
	      ptr2 = s2.start;

	      if(ptr1 == NULL && ptr2 == NULL){
			s3.start = NULL;
			return s3;
	      }

	      if(ptr2 == NULL){
			s3.start = start;
			return s3;
	      }

	      if(ptr1 == NULL){
			return s2;
	      }

	      if(ptr1->percentage < ptr2->percentage){
			s3.start = ptr1;
			ptr3 = s3.start;
			ptr1=ptr1->next;
	      }
	      else{
			s3.start = ptr2;
			ptr3  =s3.start;
			ptr2 = ptr2->next;
	      }

	      if(ptr1->percentage == ptr2->percentage){
			s3.start = ptr1;
			ptr3 = s3.start;

	      }

	      while(ptr1!=NULL && ptr2!= NULL){
			if(ptr1->percentage <= ptr2->percentage){
				ptr3->next = ptr1;
				ptr1 = ptr1->next;
				ptr3 = ptr3->next;
			}
			else{
				ptr3->next = ptr2;
				ptr2 = ptr2->next;
				ptr3 = ptr3->next;
			}
	      }

	      if(ptr1 == NULL){
			ptr3->next = ptr2;
	      }
	      if(ptr2 == NULL){
			ptr3->next = ptr1;
	      }
	      return s3;
	}


};
int main(){

	singly s,s2,s3;
	int n,ch,chi;
	while(1){
		cout<<"\n\nEnter your Choice\n1. Create\n2. Display\n3. Insert \n4. Search \n5. Update \n6. Delete\n7. Sort\n8. Merge \n9. Exit\n";
		cin>>ch;
		switch(ch){
		case 1:
			s.create();
			break;
		case 2:
			s.display();
			break;
		case 3:
			cout<<"\n Where you want to insert the element \n1. Insert at start\n2. Insert at position\n3. Insert at end\n";
			cin>>chi;
			switch(chi){
				case 1:
					s.insert_at_begning();
					break;
				case 2:
					int pos;
					cout<<"Enter the Position : ";
					cin>>pos;
					if(s.insert_at_position(pos)==1){
						cout<<"Element Added !";
					}
					else{
						cout<<"Invalid postion ";
					}
					break;
				case 3:
					s.insert_at_end();
					break;
			}
			break;
		case 4:
			if(s.search() ==0){
				cout<<"Record not found ";
			}
			break;
		case 5:
			int i;
			char n[20];
			cout<<"Enter the name to update ";
			cin>>n;
			if( s.update(n) ==1){
				cout<<"Updated !!";
			}
			else{
				cout<<"Record not found to update";
			}
			break;

		case 6:
			if(s.del()==1){
				cout<<"Record Deleted";
			}
			else{
				cout<<"Record not found ";
			}
			break;
		case 7:
			s.sort();
			break;
		case 8:

			s.sort();
			s3 = s.merge();
			cout<<"\nMerge Elements : ";
			s3.display();
			break;

		case 9:
			return 0;
		}
	}
}
