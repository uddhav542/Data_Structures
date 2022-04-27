#include<iostream>
#include<stdlib.h>
#include<string>
using namespace std;

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
int main()
{
	int deck[52];
	string snames[4]={"S","H","C","D"};
	string rnames[13]={"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
	for(int i=0;i<52;i++)
	{
		deck[i]=i;
	}
	for(int i=0;i<52;i++)
	{
		int j=(rand()%52);
		int temp=deck[i];
		deck[i]=deck[j];
		deck[j]=temp;
	}
	for(int i=0;i<52;i++)
	{
		int snum=deck[i]/13;
		int rank=deck[i]%13;
		cout<<rnames[rank]<<snames[snum]<<"\t";
	}

	int f=0, i=0, j=0,temp;
	int user1[7];
	int user2[7];
	while(f<9){
        if(f!=2 && f!=3){
            user1[i]=deck[f];
            i++;
        }
        if(f!=0 && f!=1){
            user2[j]=deck[f];
            j++;
        }
         f++;
	}
	cout<<"\n";
	cout<<"user1\n\n";
    for(i=0; i<7; i++){
        int snum=user1[i]/13;
		int rank=user1[i]%13;
		cout<<rnames[rank]<<snames[snum]<<"\t";
    }
    cout<<"\n\n";
    cout<<"user2\n\n";
    for(i=0; i<7; i++){
        int snum=user2[i]/13;
		int rank=user2[i]%13;
		cout<<rnames[rank]<<snames[snum]<<"\t";
    }

    for (i = 0; i < 7-1; i++)
        for (j = 0; j < 7-i-1; j++){
            if(user1[j] > user1[j+1])
                swap(&user1[j], &user1[j+1]);
            if(user2[j] > user2[j+1])
                swap(&user2[j], &user2[j+1]);
        }
    cout<<"\n\nuser1\n\n";
    for(i=0; i<7; i++){
        int snum=user1[i]/13;
		int rank=user1[i]%13;
		cout<<rnames[rank]<<snames[snum]<<"\t";
    }
    cout<<"\n";
    cout<<"\nuser2\n\n";
    for(i=0; i<7; i++){
        int snum=user2[i]/13;
		int rank=user2[i]%13;
		cout<<rnames[rank]<<snames[snum]<<"\t";
    }
	return 0;
}
