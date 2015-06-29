//Program to generate student marksheet based on marks entered by him/her 

//header files
#include <stdio.h>
#include <conio.h>

//functions used, prototypes
int total(int,int,int,int,int); 
int avrg(int);
float prcnt(int);
void grade(float,char[]);

int main()
{
	
	int eng,mat,c,jav,db,tot,avg,rno;
	float per; //percentage will be float,decimal
	char name[100]; //student name
	system("cls");
	printf("\n\nWelcome to student marksheet generation module!");
	printf("\n===============================================\n\n");
	//student input => name, roll number and marks
	printf("Enter your name: "); 
	fgets(name,100,stdin); //scan name
	strtok(name,"\n"); //remove the trailing \n from name(stdin) to drop the new line
	printf("\nEnter your roll number: ");
	scanf("%d",&rno);
	printf("\n\nHello, %s Please enter your subjectwise marks out of 100: \n",name);
	printf("\nEnglish: ");
	scanf("%d",&eng);
	printf("\nMath: ");
	scanf("%d",&mat);
	printf("\nC Prog: ");
	scanf("%d",&c);
	printf("\nJava Prog: ");
	scanf("%d",&jav);
	printf("\nDatabase: ");
	scanf("%d",&db);
	if(eng > 100 || mat > 100 || c > 100 || jav > 100 || db > 100) //check validity of marks
	{	//No marks can exceed 100
		printf("\n\nInvalid marks entered. Must be out of 100.");
	}
	else
	{	//proceed only if all marks are <=100
		system("cls");
		printf("\n\n\nGenerating Your Marksheet...");
		printf("\n============================");
		sleep(2);
       // freopen("marksheet.txt","w",stdout);
		printf("\n\nStudent Details:"); //Marksheet formatting
		printf("\n----------------");
		printf("\n\nStudent Name: %s\nStudent Roll No.: %d",name,rno); //print name and roll no.
		printf("\n========================================\n");
		printf("\nYour Subjectwise Marks:");
		printf("\n-----------------------\n\n");
		printf("English\tMaths\tC-Prog\tJava\tDatabase");
		printf("\n\n%d/100\t%d/100\t%d/100\t%d/100\t%d/100",eng,mat,c,jav,db);
		printf("\n========================================\n");
		tot = total(eng,mat,c,jav,db); //function call to total, returns total of all subjects
		printf("\n========================================");
		printf("\nTotal Marks = %d/500",tot); //display total
		printf("\n========================================");
		avg = avrg(tot); //function call to avrg, returns avg marks out of 100
		printf("\nAverage Marks = %d/100",avg); //Display avg marks
		printf("\n========================================");
		per = prcnt(tot); //function call to prcnt, returns a float value for percentage
		printf("\nPercentage: %.2f %%",per);//Display percent
		printf("\n========================================\n");
		printf("\nGrade: ");
		grade(per,name);//Check and display grade
		
	}
	getche();
	return 0;
}

int total(int eng, int mat, int c, int jav, int db)//Function def total, calculates and 
												   //returns the total of all subjects
{												   //Takes the int marks of 5 subjects as arguments
	return (eng + mat + c + jav + db);
}

int avrg(int tot) //Function def avg, calculates and returns the avg out of 100 
{				  //Takes the int total marks as input 
	return (tot/5);
}

float prcnt(int tot) //Function def prcnt, returns float, calculates percentage based on total marks
{
	return (((float)tot/500)*100);
}

void grade(float per, char name[])//Function def grade, takes percent as argument
								  //Used nested if-else to calculate grade based on percent and displays grade 
{
	if(per <= 100.00 && per >= 75.00) //Conditional to check if percent within range
	{
		printf("Congratulations '%s' you have passed with 'Distinction'!",name);
	}
	else if(per < 75.00 && per >= 60.00)
	{
		printf("Congratulations '%s' you have passed with 'First Class'!",name);
	}
	else if(per < 60.00 && per >= 35.00)
	{
		printf("Congratulations '%s' you have passed with Pass Class!",name);
	}
	else
	{
		printf("You have failed '%s'! Don't lose heart!",name);
	}
}