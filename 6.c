/*
ASSIGNMENT NO: 1
Batch: SA-1
Roll No:-04
Problem Statement:-
In Second year Computer Engineering class of M students, set A of students play cricket and
set B of students play badminton. Write C/C++ program to find and display-
i.
Set of students who play either cricket or badminton or both
ii.
Set of students who play both cricket and badminton
iii. Set of students who play only cricket
iv.
Set of students who play only badminton
v.
Number of students who play neither cricket nor badminton
*/

#include<stdio.h>				//including header files
#include<stdlib.h>				//including header files
int main()					//initializing main function
{
	int *students,*cricket,*badminton;	
	int noStudents,noCricket,nobadminton;
	int i,j,flag,sam,a,c,k,d; 		//declaration of variables 
	printf(" enter no of students in the class ");	
	scanf("%d",&noStudents); 
	students=(int*)malloc(noStudents*sizeof(int)); //declaration of size of array
	for(i=0;i<noStudents;i++)
											
	{
	students[i]=i+1;
	}

	printf("\n enter no of students who play cricket");	//accepting input
	scanf("%d",&noCricket); 
	cricket=(int*)malloc(noCricket*sizeof(int));
	
	for(i=0;i<noCricket;i++)
{								
	printf("\n enter roll no of student playing cricket");	//accepting cricket input
	scanf("%d",&cricket[i]);
}
	printf("\n enter no of students who play badminton");	
	scanf("%d",&nobadminton); 
	badminton=(int*)malloc(nobadminton*sizeof(int));


	for(i=0;i<nobadminton;i++)

	{
	printf("\n enter roll no of student playing badminton");	//accepting input
	scanf("%d",&badminton[i]);
	}

		//students who are only playing cricket
	for(i=0;i<noCricket;i++)
		//check cricket[i] presnt in badminton or not
{
flag=0;
	for(j=0;j<nobadminton;j++)
	{
	if(cricket[i]==badminton[j])
		{
		flag=1;
		}
	}


	if(flag==0)
{
printf("\n %d is only plays cricket",cricket[i]);
}
}
		//students who are only playing badminton
for(i=0;i<nobadminton;i++)
		//check badminton[i] present in cricket or not
{
sam=0;
	for(j=0;j<noCricket;j++)
	{
	if(badminton[i]==cricket[j])
		{
		sam=1;
		}
	}


	if(sam==0)
	{
	printf("\n %d is only plays badminton",badminton[i]);
	}
}
	//students who are playing both cricket and badminton

for(i=0;i<noCricket;i++)
	//check cricket and badminton are equal		
{
a=0;
	for(j=0;j<nobadminton;j++)
	{
	if(cricket[i]==badminton[j])
		{
		a=1;
		}
	}


	if(a==1)
{
printf("\n %d plays both cricket and badminton",cricket[i]);
}
}

	//students who are playing neither cricket nor badminton
	for(i=0;i<noStudents;i++)
	{
		
		c=0;
		
		for(j=0;j<noCricket;j++)
		{

	
			if(cricket[j]==students[i])
				{
	  				 c=1;
				}
		}

		for(k=0;k<nobadminton;k++)
		{
		
			if(badminton[k]==students[i])
				{
					c=1;
				}
		}
		if(c==0)
		{
		printf("\n students who play neither cricket nor badminton are: %d",students[i]);
		}
		else			//students who play either cricket or badminton or both
			{
				printf("\n students who play either cricket or badminton or both are: %d",students[i]);
			}
	}

	


return 0;
}

/*
output:

gescoe@gescoe-OptiPlex-3020:~/Desktop/TanmayN$ gcc Assignment1.c
gescoe@gescoe-OptiPlex-3020:~/Desktop/TanmayN$ ./a.out
 enter no of students in the class 10

 enter no of students who play cricket4

 enter roll no of student playing cricket1

 enter roll no of student playing cricket2

 enter roll no of student playing cricket3

 enter roll no of student playing cricket4

 enter no of students who play badminton3

 enter roll no of student playing badminton1

 enter roll no of student playing badminton6

 enter roll no of student playing badminton7

 2 is only plays cricket
 3 is only plays cricket
 4 is only plays cricket
 6 is only plays badminton
 7 is only plays badminton
 1 plays both cricket and badminton
 students who play either cricket or badminton or both are: 1
 students who play either cricket or badminton or both are: 2
 students who play either cricket or badminton or both are: 3
 students who play either cricket or badminton or both are: 4
 students who play neither cricket nor badminton are: 5
 students who play either cricket or badminton or both are: 6
 students who play either cricket or badminton or both are: 7
 students who play neither cricket nor badminton are: 8
 students who play neither cricket nor badminton are: 9
 students who play neither cricket nor badminton are: 10
*/
