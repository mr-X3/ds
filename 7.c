/*
ASSIGNMENT NO: 2
Batch: SA-1
Roll No:-04
Problem Statement:-
Write C/C++ program to store marks scored for first test of subject 'Data Structures and
Algorithms' for N students. Compute
I. The average score of class
ii. Highest score and lowest score of class
iii. Marks scored by most of the students
iv. list of students who were absent for the test
*/

#include<stdio.h>				//including header files
#include<stdlib.h>				//including header files
int main()					//initializing main function
{
int *students,*marks;
int i,nostudents,sum=0,max=0,min=100,j,abs;
int scorebymost,maxscore,counter; 
float avg;
	
	printf("\n enter number of students in the class");	//accepting number of students
	scanf("%d",&nostudents);
	students=(int*)malloc(nostudents*sizeof(int)); //declaration of size of array
	
	printf("\n Enter marks of students for DS");	//accepting marks
	marks=(int*)malloc(nostudents*sizeof(int));  //declaration of size of array
	for(i=0;i<nostudents;i++)
	{
	scanf("%d",&marks[i]);
	}
	
	//average score of the class

	for(i=0;i<nostudents;i++)
	{
	sum=sum+marks[i];
	}
	
	for(i=0;i<nostudents;i++)
	{
		if(marks[i]==-1)
		{
		abs=abs+1; 
		}		
	}
	avg=sum/(nostudents-abs);
		
	printf("Average score of the class %f",avg);

	//highest & lowest score
	
	for(i=0;i<nostudents;i++)
	{
		if(max<marks[i])
		{
			max=marks[i];	//Comparing with Max
		}
		
	}	printf("\n Highest score is %d",max);
		
	

	for(i=0;i<nostudents;i++)
	{
		if(min>marks[i] && marks[i]!=-1)
		{
			min=marks[i];	//Comparing with Min
		}
		
	}	
		printf("\n Lowest score is %d",min);

	//marks	scored by most of the students
	
	scorebymost=0;
	maxscore=0;
	for(i=0;i<nostudents;i++)
	{
		counter=0;
		
		for(j=0;j<nostudents;j++)
		{
			if(marks[i]==marks[j] && marks[i]!=-1)
			{
				counter++;
			}
		}
		if(counter>scorebymost)
		{
			scorebymost=counter;
		maxscore=marks[i];
		}
	}
printf("\n Marks scored by %d of the students is %d",scorebymost,maxscore);


	//list of students who were absent for the test
	
		printf("\n Absent number of students are %d",abs);

return 0; 
}


/*
OUTPUT:-

gescoe@gescoe-OptiPlex-3020:~/Desktop/TanmayN$ gcc Assignment2.c
gescoe@gescoe-OptiPlex-3020:~/Desktop/TanmayN$ ./a.out

 enter number of students in the class10

 Enter marks of students for DS
45
50
48
46
-1
36
-1
35
48
-1
Average score of the class 43.000000
 Highest score is 50
 Lowest score is 35
 Marks scored by most of the students is 48
 Absent number of students are 3 gescoe@gescoe-OptiPlex-3020:~/Desktop/TanmayN$

*/
