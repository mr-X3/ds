/* Problem Statement:
Write C++ program for string operations copy, concatenate, check substring,equal, reverse and length 
Class – SE B
Batch - SB- 2
Roll No. –
Date -   /09/2016
*/

#include <stdio.h>
#include <stdlib.h>
int main()
{
int n,i,j,flag,ch;
char str1[50],str2[50],str3[50],str4[50];
//scanning data of N students
printf("\n-----Enter the Two Input Strings-----\n");
printf("\nEnter String1:");
scanf("%s",str1);
printf("Enter String2:");
scanf("%s",str2);
//displaying data of N students
printf("\n-----Your Entered Input Strings Are-----\n");
printf("\nString1: %s",str1);
printf("\nString2: %s",str2);
while(1)
{
printf("\n\n ****************** Menu *******************\n");
printf("\n1. Copy \n2. Concate \n3. Check Substring \n4. Equal \n5. Reverse \n6. length
of String \n7. Exit");
printf("\nEnter your choice:");
scanf("%d",&ch);
switch(ch)
{
case 1: printf("\nThis is Copy Case");
i=0;
while(str1[i]!='\0')
{
str3[i]=str1[i];
i++;
}
str3[i]='\0';
printf("\nAfter Coping String1 into String3");
printf("\nString3: %s",str3);
break;
case 2: printf("\nThis is Concate Case");
i=0;j=0;
while(str3[i]!='\0')
i++;
while(str2[j]!='\0')
{
str3[i]=str2[j];
i++;j++;
}
str3[i]='\0';
printf("\nAfter Concanating String1 and String2 into String3");
printf("\nString3: %s",str3);
break;
case 3: printf("\nThis is Substring Case");
i=0;j=0;flag=0;
while(str1[i]!='\0')
{
if(str1[i]==str2[j])
{
j++;
if(str2[j]=='\0')
flag=1;
}
i++;
}
if(flag==1)
printf("\nString2 is found in String1!");
else
printf("\nString2 is not found in String1!");
break;
case 4: printf("\nThis is Equal Case");
i=0;flag=0;
while(str1[i]!='\0')
{
if(str1[i]!=str2[i])
{
flag=1;
break;
}
i++;
}
if(flag==1)
printf("\nString1 and String2 are not equal!");
else
printf("\nString1 and String2 are equal!");
break;
case 5: printf("\nThis is Reverse Case");
i=0;j=0;
while(str1[i]!='\0')
i++;
i=i-1;
while(i>=0)
{
str4[j]=str1[i];
i--;j++;
}
str4[j]='\0';
printf("\nAfter Reversing String1 into String4");
printf("\nString4: %s",str4);
break;
case 6: printf("\nThis is length Case");
i=0;
while(str1[i]!='\0')
i++;
printf("\nThe length of String1=%d",i);
j=0;
while(str2[j]!='\0')
j++;
printf("\nThe length of String2=%d",j);
break;
case 7: exit(0);
default : printf("\nSorry! You have enterd wrong choice.");
}
}
return 0;
}

