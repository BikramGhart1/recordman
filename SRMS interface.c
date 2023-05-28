#include<stdio.h>
#include<stdlib.h>
//structure
struct student{
char name[30];
int roll;
float marks;
char address[20];
};

//functions declaration
void info();
void menuWindow();
void addStudent(struct student *stds,FILE *fadd);
//main function it contains opening window and switch case
int main()
{
       int firstChoice;
       struct student stds[100];
       FILE *fadd;

    printf("\nStudent Record Management System\n");
    printf("      SRMS\n");
    printf("\n\t^");
    printf("\n'Press 1 to enter the Menu window'\n");
    printf("'Press 2 to Quit the program'\n");
    printf("'press 3 to open program info'\n");
    printf("\tv\n");
    printf("\nenter your key here: ");
    scanf("%d",&firstChoice);


//switch case
    switch (firstChoice)
{
case 1:
    menuWindow(stds);
    break ;
case 2:
    printf("\nQuiting.....");
        return 0;
case 3:
    info();
    break;
default:
    system("cls");
    printf("Invalid");
}

return 0;
}


//menu function
void menuWindow(struct student *stds)
{
    system("cls");
     while(1){
    int secondChoice;
printf("\nSRMS\n");
printf("Menu\n\n");
printf("\t^\n");
printf("<1> Add a new student\n");
printf("<2> Display Student records\n");
printf("<3> Search Students\n");
printf("<4> Delete a record\n");
printf("<5> Exit\n");
printf("\tv\n");
printf("\nYour key here: ");
scanf("%d",&secondChoice);

//switch case
switch (secondChoice)
{
case 1:
    addStudent(stds, fadd);
    break;
case 5:
    printf("Exiting");
    return 0;
}
}
}

//function to display info
void info()
{
    system("cls");
    FILE *finfo;
    finfo=fopen("info.txt","r");
    if(finfo==NULL)
    {
        printf("Unable to open the file.");
        return 0;
    }
       char buffer[100];

    while (fscanf(finfo, "%s", buffer) != EOF) {
        printf("%s ", buffer);
    }
    printf("\n\n\n");
}

//function to add Student
void addStudent(struct student *stds, FILE *fadd)
{
    int i,n;
    printf("\nAdd new records");
    printf("\nenter the number of student");
    scanf("%d",&n);
    printf("\nEnter student details:\n");
    fadd=fopen("studentrecs.txt","w");
    if(fadd==NULL)
    {
        printf("An error occured!");
        return 0;
    }

    for(i=0;i<n;i++)
    {
        printf("student %d",i+1);
        printf("\nName: ");
        scanf("%s",stds[i]->name);
        fprintf(fadd,"%s",stds[i]->name);
        printf("\nRoll No: ");
        scanf("%d",&stds[i]->roll);
        fprintf(fadd,"%s",stds[i]->roll);
        printf("\nMarks: ");
        scanf("%f",&stds[i]->marks);
          fprintf(fadd,"%.2f",stds[i]->marks);
        printf("\nAddress: ");
        scanf("%s",stds[i]->address);
          fprintf(fadd,"%s",stds[i]->address);
    }

    printf("\nRecord added succesful.");
    fclose(fadd);
}
