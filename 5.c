/*Problem Statement:
Title:The ticket booking system of Cinemax theater has to be implemented using C++ program.
There are 10 rows and 7 seats in each row. Doubly circular linked list has to be maintained
to keep track of free seats at rows. Assume some random booking to start with. Use array to
store pointers (Head pointer) to each row. On demand
a) The list of available seats is to be displayed
b) The seats are to be booked
c) The booking can be cancelled.
Class-S.E -B
Batch-SB-
Roll No:
*/
#include<iostream>
#include<stdlib.h>
#define rows 3
#define cols 2
using namespace std;
//DECLARE CLASS FOR DOUBLY CIRCULAR LINKED LIST
struct node
{
int status;
node *next,*prev;
}*head;
struct node *xyz[10];
class dcll
{
//private data members
//public member functions
public:dcll()            // constructor
{
}
void create();
void display();
void book();
void cancel();
};
void dcll::create()
{
struct node *p,*q;int i=0,j;
for(j=0;j<rows;j++)
{
i=0;head=NULL;
while(i<cols)
{
if(i==0)
{
p=new(struct node);
head=p;
p->prev=p->next=head;
}
else
{
p->next=new(struct node);
q=p;
p=p->next;
p->prev=q;
p->next=head;
head->prev=p;
}
cout<<"\n-----Enter the avaibility of seat\n";
cout<<"\nEnter status:";
cin>>p->status;
i++;
}
xyz[j]=head;
}
cout<<"\nAll Avaibility status of Seats are successfully Recorded";
}
void dcll::display()
{
struct node *p;int i=0;int j;
for(j=0;j<rows;j++)
{
i=0;
head=xyz[j];
if(head==NULL)
cout<<"Nothing to Display!";
else
{
p=head;
while(p->next!=head)
{
if(p->status==0)
cout<<"\nRow no.="<<j<<" and Column no.= "<<i;
p=p->next;i++;
}
if(p->status==0)
cout<<"\nRow no.="<<j<<" and Column no.= "<<i;
}
}
}
void dcll::book()
{
struct node *p,*q;
int r,c,j;
cout<<"\n-----Enter the data of seat to be booked-----\n";
cout<<"\nEnter row number:";
cin>>r;
cout<<"\nEnter column number:";
cin>>c;

head=xyz[r];
if(head==NULL)
cout<<"Nothing to Display!";
else
{
p=head;j=0;
while(j<c)
{
p=p->next;j++;
}
cout<<"j="<<j;
if(p->status==0)
{
p->status=1;
cout<<"\n Your seat is successfully booked!";
}
else
cout<<"\nThe seat is already booked!";
}
}
void dcll::cancel()
{
struct node *p,*q;
int r,c,j;
cout<<"\n-----Enter the data of seat to be canceled-----\n";
cout<<"\nEnter row number:";
cin>>r;
cout<<"\nEnter column number:";
cin>>c;
head=xyz[r];
if(head==NULL)
cout<<"Nothing to Display!";
else
{
p=head;j=0;
while(j<c)
{
p=p->next;j++;
}
if(p->status==1)
{
p->status=0;
cout<<"\n Your seat is successfully canceled!";
}
else
cout<<"\nThe seat is already vacant!";
}
}
int main()
{
dcll s;int n,ch;



s.create();
while(1)
{
cout<<"\n1.Available \n2.Booking \n3.Cancelation \n4.Exit";
cout<<"\nEnter your choice:";
cin>>ch;
switch(ch)
{
case 1: cout<<"\nThis is Display Case";
s.display();
break;
case 2: cout<<"\nThis is insertion Case";
s.book();
break;
case 3: cout<<"\nThis is Deletion Case";
s.cancel();
break;
case 4: exit(0);
}
}
return 0;
}

