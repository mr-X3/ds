/*
Department of Computer Engineering has student's club named 'Pinnacle Club'. Students of Second, third and final year of department can be granted membership on request. Similarly one may cancel the membership of club. First node is reserved for president of club and last node is reserved for secretary of club. Write C++ program to maintain club member‘s information using singly linked list. Store student PRN and Name. Write functions to 
a) Add and delete the members as well as president or even secretary. 
b) Compute total number of members of club 
c) Display members 
d) Display list in reverse order using recursion 
e) Two linked lists exists for two divisions. Concatenate two lists. 
BATCH:SE-B
CLASS:SB-2
Roll No:
DATE:  /  /2016
*/
#include<iostream>
#include<stdlib.h>
using namespace std;

//DECLARE CLASS FOR SINGLY LINKED LIST
struct node
{
      char name[10];
      int roll;
      int mtype;
      node *next;
}*head;

class sll
{
   //private data members
   
  

   //public member functions
   public:sll()            // constructor
          {
             
          }
          void create(int n);
          void display();
          void insert();
          void count();
          void remove();
          struct node* reverse(struct node*);
};

void sll::create(int n)
{
   struct node *p,*q;
   int i=0;
                while(i<n)
                {
                   if(i==0)
                   {
                      p=new(struct node);
                      head=p;
                      p->mtype=1;            //president
                      //printf("Got In");
                   }
                   else if(i==(n-1))
                   {
                      p->next=new(struct node);
                      p=p->next;
                      p->mtype=3;           //secretrary
                   }
                   else
                   {
                      p->next=new(struct node);
                      p=p->next;
                      p->mtype=2;           //ordinary member
                    
                   }
                   cout<<"\n-----Enter the data of "<<i+1<<" student-----\n";
                   cout<<"\nEnter roll number:";
                   cin>>p->roll;
 		   cout<<"\nEnter name:";
                   cin>>p->name;
                   
                   p->next=NULL;
                   i++;
 		 
                }

                cout<<"\nAll "<<n<<" students are successfully created in sll format";
}

void sll::display()
{
 struct node *p;int i=0;
 if(head==NULL)
    cout<<"Nothing to Display!";
 else
 {
    p=head;
    while(p!=NULL)
    {
      cout<<"\nThe Data of Student "<<i+1<<" is:";
      cout<<"Roll= "<<p->roll;
      cout<<" and Name= "<<p->name;
      cout<<" and Membership Type= "<<p->mtype;
      p=p->next;i++;
    }
 }

}


void sll::insert()
{
      struct node *p,*q;
      p=new(struct node);
      cout<<"\n-----Enter the data of new student-----\n";
      cout<<"\nEnter roll number:";
      cin>>p->roll;
      cout<<"\nEnter name:";
      cin>>p->name;
      cout<<"\nEnter m_type for following choices \n1.President 2. Ordinary Member 3.Secretrary:";
      cin>>p->mtype;
      if(p->mtype==1)
      {
          p->next=head;
          head->mtype=2;
          head=p;
      }
      else if(p->mtype==2)
      {
          q=head;
          while(((q->next)->next)!=NULL)  // Take q at second last node
          {
                q=q->next;
          }
          p->next=q->next;
          q->next=p;
      }
      else
      {
          p->next=NULL;
          q=head;
          while(q->next!=NULL) // Take q at last node
          {
                  q=q->next;
          }
          q->next=p;
          q->mtype=2;
      }

}


void sll::remove()
{
  struct node *p,*q;
  int temp;int flag=0;
  cout<<"Enter roll number of student to be removed:";
  cin>>temp;
  //search it
  p=head;
  while(p!=NULL)
  {
     if(p->roll==temp)
     {
        flag=1;
        break;
     }
     q=p;
     p=p->next;
  }
  if(flag==1)
  {
    cout<<"Student found";
    if(p->mtype==1)
    {
       head=p->next;
       head->mtype=1;
       delete(p); 
    }
    else if(p->mtype==2)
    {
       q->next=p->next;
       delete(p);
    }
    else
    {
       q->next=p->next;
       q->mtype=3;
       delete(p);

    }
  }
  else
    cout<<"No such student found";

}

void sll::count()
{
  struct node *p;
  int counter=0;p=head;
  while(p!=NULL)
  {
        counter++;
        p=p->next;
  }
  cout<<"Total students that are members of club are: "<<counter;
}


struct node* sll::reverse(struct node* head1)
{
        struct node *temp;
	if(head1==NULL || head1->next==NULL)
	{
		return head1;
	}
	temp=reverse(head1->next);
	head1->next->next=head1;
	head1->next=NULL;
	return temp;

}

int main()
{
    sll s;int n,ch;
    cout<<"\nEnter how many students you have initially (min 0):";
    cin>>n;
    if(n>0)
    {
         cout<<"\nValid value of number of students";
    	 s.create(n);
         while(1)
         {
            cout<<"\n1.Display \n2.Insert \n3.Delete \n4.Count Members \n5.Reverse \n6.Exit";
            cout<<"\nEnter your choice:";
            cin>>ch;
            switch(ch)
            {
               case 1: cout<<"\nThis is Display Case";
                       s.display();
                       break;  
               case 2: cout<<"\nThis is insertion Case";
                       s.insert();
                       break;
               case 3: cout<<"\nThis is Deletion Case";
                       s.remove();
                       break;
               case 4: cout<<"\nThis is counting Case";
                       s.count();
                       break;
               case 5: cout<<"\nThis is Reverse Case";
                       head=s.reverse(head);
                       break;
               case 6: exit(0);
            }
         }
    }
    else
      cout<<"\nInvalid value of number of students";
    
    return 0;
}


