/* Problem Statement:
Department library has N books. Write C/C++ program to store the cost of books in array in ascending order. Books are to be arranged in descending order of their cost. Write function  for:
a) Reverse the contents of array without using temporary array.
b) Copy costs of books those with cost less than 500 in new array
c) Delete the duplicate entries using temporary array
d) Delete duplicate entries without using temporary array
e) Count number of books with cost more than 500.
Class – SE B
Batch - SB- 2
Roll No. –
Date -   /09/2016
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct book
{
int id;
float price;
char name[30];
char author[30];
}b[50];
int main()
{
int n,i,j,k,ch,flag;
float tempprice;
int counter[50],temp1[50],tempid;
char tempname[30],tempauthor[30];
printf("Enter how many books you have (max 50):");
scanf("%d",&n);
if(n>0 && n<51)
{
//scanning data of N books
for(i=0;i<n;i++)
{
printf("\n-----Enter the data of %d book-----\n",i+1);
printf("Enter Book ID:");
scanf("%d",&b[i].id);
printf("Enter Book Price:");
scanf("%f",&b[i].price);
printf("Enter Book Name:");
scanf("%s",b[i].name);
printf("Enter Author Name:");
scanf("%s",b[i].author);
}
//displaying data of N books
for(i=0;i<n;i++)
{
printf("\n\n-----The data of %d book-----\n",i+1);
printf("\n Book ID: %d",b[i].id);
printf("\n Book Price: %f",b[i].price);
printf("\n Book Name: %s",b[i].name);
printf("\n Author Name: %s",b[i].author);
}
while(1)
{
printf("\n\n ****************** Menu *******************\n");
printf("\n1. Reverse the contents of array without using temporary array");
printf("\n2. Copy costs of books those with cost less than 500 in new array");
printf("\n3. Delete the duplicate entries using temporary array");
printf("\n4. Delete duplicate entries without using temporary array");
printf("\n5. Count number of books with cost more than 500");
printf("\n6. Exit");
printf("\nEnter your choice:");
scanf("%d",&ch);
switch(ch)
{
case 1: printf("\nThis is Reverse the contents of array without using temporary array
Case");
j=n-1;i=0;
while(i<j)
{
tempid=b[i].id;
b[i].id=b[j].id;
b[j].id=tempid;
tempprice=b[i].price;
b[i].price=b[j].price;
b[j].price=tempprice;
strcpy(tempname,b[i].name);
strcpy(b[i].name,b[j].name);
strcpy(b[j].name,tempname);
strcpy(tempauthor,b[i].author);
strcpy(b[i].author,b[j].author);
strcpy(b[j].author,tempauthor);
i++;j--;
}
printf("\n\n-----After Reversing -----");
for(i=0;i<n;i++)
{
printf("\n\n-----The data of %d book-----\n",i+1);
printf("\n Book ID: %d",b[i].id);
printf("\n Book Price: %f",b[i].price);
printf("\n Book Name: %s",b[i].name);
printf("\n Author Name: %s",b[i].author);
}
break;
case 2: printf("\nThis is Copy costs of books those with cost less than 500 in new
array Case");
j=0;
for(i=0;i<n;i++)
{
if(b[i].price<500)
{
temp1[j]=i;
j++;
}
}
printf("\nThe number of books with cost less than 500 : %d",j);
printf("\nThe required list of books with details is as given below");
for(i=0;i<j;i++)
{
k=temp1[i];
printf("\n--------------------------");
printf("\n Book ID: %d",b[k].id);
printf("\n Book Price: %f",b[k].price);
printf("\n Book Name: %s",b[k].name);
printf("\n Author Name: %s",b[k].author);
}
break;
case 3: printf("This is Delete the duplicate entries using temporary array
Case");
for(i=0;i<n;i++)
{
for(j=i+1;j<n;j++)
{
if(b[i].id==b[j].id)
{
}
}
}
break;
case 4: printf("This is Delete duplicate entries without using temporary array Case");
flag=0;
for(i=0;i<n;i++)
{
for(j=i+1;j<n;j++)
{
//if duplicate entry found start shifting of books
if(b[i].id==b[j].id)
{
for(k=j;k<n-1;k++)
{
b[k].id=b[k+1].id;
b[k].price=b[k+1].price;
strcpy(b[k].name,b[k+1].name);
strcpy(b[k].author,b[k+1].author);
}
n=n-1; //one entry reduced
}
}
}
printf("\nThe new list of library books is as follows");
for(i=0;i<n;i++)
{
printf("\n--------------------------");
printf("\n Book ID: %d",b[i].id);
printf("\n Book Price: %f",b[i].price);
printf("\n Book Name: %s",b[i].name);
printf("\n Author Name: %s",b[i].author);
}
break;
case 5: printf("This is Count number of books with cost more than 500 Case");
j=0;
for(i=0;i<n;i++)
{
if(b[i].price>500)
{
temp1[j]=i;
j++;
}
}
printf("\nThe number of books with cost more than 500 : %d",j);
printf("\nThe required list of books with details is as given below");
for(i=0;i<j;i++)
{
k=temp1[i];
printf("\n--------------------------");
printf("\n Book ID: %d",b[k].id);
printf("\n Book Price: %f",b[k].price);
printf("\n Book Name: %s",b[k].name);
printf("\n Author Name: %s",b[k].author);
}
break;
case 6: exit(0);
default : printf("\nSorry! You have enterd wrong choice.");
}
}
} else
printf("\nSorry! You have entered invalind number of books.\nYou can enter Min=1
and Max=50 books\n\n");
return 0;
}

