/*
    Roll No:-             243
	Name:- 	              Atharva Joshi
	Reg id:-              220200078
	Exam Seat no:-        S208077
	Email:-               atharva.joshi@mitaoe.ac.in
	Class:-               DSE IT
	Problem Statement:-   Poker Hand - Where 'Straight'  is Winner
*/

#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
using namespace std;

void checkforStraightHand(int data[],int player)
{
    int R[5],S[5],i;
    for(i=0;i<5;i++)
    {
        R[i]=data[i]%13; //rank
    }
    if(R[1]==R[0]+1 && R[2]==R[1]+1 && R[3]==R[2]+1 && R[4]==R[3]+1)
    {
        cout<<"\n****Straight Hand*****\n";
        cout<<"Player "<<player<<" is the Winner";
        exit(0);
    }
}
void combination(int a[],int data[],int start,int end,int index,int r,int player)
{
    int i;
    if(index==r)
    {
        for(int j=0;j<r;j++)
        {
            cout<<data[j]<<" ";
        }
        checkforStraightHand(data,player);
        cout<<"\n";
        return;
    }
    for(i=start;i<=end &&end-i+1>=r-index;i++)
    {
        data[index]=a[i];
        combination(a,data,i+1,end,index+1,r,player);
    }
}

int main()
{
    int deak[52],i,j,a[7],b[7];
    int f,temp;
    f=0;
    string snames[4]={"-Spade","-Heart","-Club","-Diamond"};
    string rnames[13]={"2","3","4","5","6","7","8","9","10","Jack of","Queen of","King of","Ace of"};
    for(i=0;i<52;i++)
    {
        deak[i]=i;
    }
     srand(time(NULL));
    for(i=0;i<52;i++)
    {
        j=rand()%52;
        temp=deak[i];
        deak[i]=deak[j];
        deak[j]=temp;
    }
    for(i=0;i<52;i++)
    {
        int snum=deak[i]/13;
        int rank=deak[i]%13;
        cout<<rnames[rank]<<snames[snum]<<"\n";
    }
    f=0;

    cout<<"\n\n Deal:";
    i=0,j=0;
    while(f<9)
    {
        if(f==0 || f==2 || f==4)
        {
            cout<<"{";
        }
            int snum=deak[f]/13;
            int rank=deak[f]%13;
            cout<<rnames[rank]<<snames[snum]<<" ";
            if(f!=2 && f!=3)
                a[i++]=deak[f];
            if(f>1)
                b[j++]=deak[f];
            if(f==1 || f==3 || f==8)
                cout<<"}";
            f++;
    }
 a[0] = 1;a[1] = 2; a[2] = 3; a[3] = 4; a[4] = 5; a[5] = 6; a[6] = 7;
    cout<<"\n\n Player 1 Cards: ";
    f=0;
    while(f<7)
    {
        int snum=a[f]/13;
        int rank=a[f]%13;
        cout<<rnames[rank]<<snames[snum]<<"  ";
        f++;
    }

    cout<<"\n\n Player 2 Cards: ";
    f=0;
    while(f<7)
    {
        int snum=b[f]/13;
        int rank=b[f]%13;
        cout<<rnames[rank]<<snames[snum]<<"  ";
        f++;
    }

    cout<<"\n\n check deal of player 1: ";
        for(i=0;i<6;i++)
        {
            for(j=0;j<6-i;j++)
            {
                if(a[j]>a[j+1])
                {
                    temp=a[j];
                    a[j]=a[j+1];
                    a[j+1]=temp;
                }
            }
        }
    for(i=0;i<7;i++)
    {
         int snum=a[i]/13;
        int rank=a[i]%13;
        cout<<rnames[rank]<<snames[snum]<<"  ";
    }

    cout<<"\n\n check deal of player 2: ";
        for(i=0;i<6;i++)
        {
            for(j=0;j<6-i;j++)
            {
                if(b[j]>b[j+1])
                {
                    temp=b[j];
                    b[j]=b[j+1];
                    b[j+1]=temp;
                }
            }
        }
    for(i=0;i<7;i++)
    {
         int snum=b[i]/13;
        int rank=b[i]%13;
        cout<<rnames[rank]<<snames[snum]<<"  ";
    }
    cout<<"\n\n";

    int data[7];
    int player;
    cout<<"Combinations for Player 1:\n";
    player=1;
    combination(a,data,0,6,0,5,player);
    cout<<"Combinations for Player 2:\n";
    player=2;
    combination(b,data,0,6,0,5,player);
    cout<<"Match Draw!!";
    return 0;
}
/*
----------------------------------------------------Output--------------------------------------------------------------

  Winning Conditions either for Player 1 or 2
    a[0] = 1;a[1] = 2; a[2] = 3; a[3] = 4; a[4] = 5; a[5] = 6; a[6] = 7;
    b[0] = 4;b[1] = 5; b[2] = 6; b[3] = 7; b[4] = 8; b[5] = 9; b[6] = 10;

    Any Sequential Rank of Card order is valid for the winning Condition;

------------------------------------------------------------Player 1 Winning Case---------------------------------------
     Deal:{King of-Club Jack of-Heart }{King of-Spade 10-Club }{6-Diamond 4-Spade Queen of-Diamond 6-Spade Jack of-Spade }

 Player 1 Cards: 3-Spade  4-Spade  5-Spade  6-Spade  7-Spade  8-Spade  9-Spade

 Player 2 Cards: King of-Spade  10-Club  6-Diamond  4-Spade  Queen of-Diamond  6-Spade  Jack of-Spade

 check deal of player 1: 3-Spade  4-Spade  5-Spade  6-Spade  7-Spade  8-Spade  9-Spade

 check deal of player 2: 4-Spade  6-Spade  Jack of-Spade  King of-Spade  10-Club  6-Diamond  Queen of-Diamond

Combinations for Player 1:
1 2 3 4 5
****Straight Hand*****
Player 1 is the Winner
-------------------------------------------------------------------------------------------------------------------------


*/

