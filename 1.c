
/* Problem Statement:
Write C/C++ program to store marks scored for first test of subject 'Data Structures and Algorithms' for N students.Compute
I.The average score of class
ii.Highest score and lowest score of class
iii.Marks scored by most of the students
iv.list of students who were absent for the test
Class-S.E -B
Batch-SB-
Roll No:
*/

#include <stdio.h>
#include <stdlib.h>
struct student
{
int roll;
int marks;
char name[20];
char mobile[20];
char email[20];
}s[50];

int main()
{
int n,i,j,ch,sum,temp,x,abcount;
float avg;
int counter[50],ab[50];
printf("Enter how many students you have (max 50):");
scanf("%d",&n);
if(n>0 && n<51)
{
//scanning data of N students
for(i=0;i<n;i++)
{
printf("\n-----Enter the data of %d student-----\n",i+1);
printf("Enter roll number:");
scanf("%d",&s[i].roll);
printf("Enter marks (Enter -1 for abscent student):");
scanf("%d",&s[i].marks);
printf("Enter name:");
scanf("%s",s[i].name);
printf("Enter mobile number:");
scanf("%s",s[i].mobile);
printf("Enter email id:");
scanf("%s",s[i].email);
}
//displaying data of N students
for(i=0;i<n;i++)
{
printf("\n\n-----The data of %d student-----\n",i+1);
printf("\n roll number:%d",s[i].roll);
printf("\n marks: %d",s[i].marks);
printf("\n name: %s",s[i].name);
printf("\n mobile: %s",s[i].mobile);
printf("\n email id: %s",s[i].email);
}
while(1)
{
printf("\n\n ****************** Menu *******************\n");
printf("\n1. Average marks\n2. Highest and lowest marks\n3. Maximum figure of marks repeated\n4. Absent students\n5. Exit");
printf("\nEnter your choice:");
scanf("%d",&ch);
switch(ch)
{
case 1: //Calculate Average Score
sum=0;
for(i=0;i<n;i++)
{
if(s[i].marks!=-1)
{
sum=sum+s[i].marks;
}
}
avg=(float)sum/n;
printf("\n The average of class : %f",avg);
break;
case 2: //Find Highest Score
printf("\n The Highest and lowest marks");
temp=s[0].marks;
for(i=0;i<n;i++)
{
if(temp<s[i].marks)
{
temp=s[i].marks;
x=i;
}
}
printf("\n\n-----The data of Highest marks achiever student-----\n");
printf("\n roll number:%d",s[x].roll);
printf("\n marks: %d",s[x].marks);
printf("\n name: %s",s[x].name);
printf("\n mobile: %s",s[x].mobile);
printf("\n email id: %s",s[x].email);

// Find Lowest Score
temp=0;x=0;
for(i=0;i<n;i++)
{
if(s[i].marks!=-1)
{
temp=s[i].marks;
break;
}
}

for(i=0;i<n;i++)
{
if(temp>s[i].marks && s[i].marks!=-1)
{
temp=s[i].marks;
x=i;
}
}
printf("\n\n-----The data of Lowest marks achiever student-----\n");
printf("\n roll number:%d",s[x].roll);
printf("\n marks: %d",s[x].marks);
printf("\n name: %s",s[x].name);
printf("\n mobile: %s",s[x].mobile);
printf("\n email id: %s",s[x].email);
break;
case 3: //Marks Scored By Most of the Students
printf("\n Marks Scored By Most of the Students");
for(i=0;i<n;i++)
{
counter[i]=0;
}
temp=0;x=0;
for(i=0;i<n;i++)
{
temp=s[i].marks;
for(j=0;j<n;j++)
{
if(temp==s[j].marks)
counter[i]++;
}
}
temp=counter[0];
for(i=0;i<n;i++)
{
if(temp<counter[i])
{
temp=counter[i];
x=i;               // save index of maximum count in x
}
}
printf("\n maximum figure repeated marks: %d",s[x].marks);
printf("\n Total : %d students have got this marks figure",temp);
break;

case 4: // List of Students Who were Absent for the Test
printf("\n Abscent student list");
abcount=0;
for(i=0;i<n;i++)
ab[abcount]=0;
for(i=0;i<n;i++)
{
if(s[i].marks==-1)
{
ab[abcount]=i; // save index of abscent student
abcount++;     // increment counter of number of abscent students
}
}
printf("\n The total abscent students: %d",abcount);
printf("\n List of abscent roll numbers:");
for(i=0;i<abcount;i++)
printf("%d ",s[ab[i]].roll);
break;
case 5: exit(0);
default : printf("\nSorry! You have enterd wrong choice.");
}
}
}
else
printf("\nSorry! You have entered invalind number of students.\nYou can enter Min=1 and Max=50 students\n\n");
return 0;
}
/*OUTPUT:

