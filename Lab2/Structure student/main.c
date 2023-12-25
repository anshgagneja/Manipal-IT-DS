#include <stdio.h>
#include <stdlib.h>

typedef struct student{
char name[50];
int rollno;
int marks;
}student;

int main(){
     student data[20];
     int n;
     printf("Enter the number of students: ");
     scanf("%d",&n);
     int i;
     for(i=0;i<n;i++)
     {
        printf("\n\nEnter data for student %d\n", i + 1);

        printf("Enter name : ");
        fflush(stdin);
        gets(data[i].name);


        printf("\nEnter roll no : ");
        scanf("%d", &data[i].rollno);


        printf("Enter marks : ");
        scanf("%d", &data[i].marks);
     }
    student temp[100];
    for (int i = 0; i <n-1; i++)
    {
        for (int j = 0; j < (n-i-1); j++)
        {
            if (data[j].rollno >data[j + 1].rollno)
            {
                temp[j] = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp[j];
            }
        }
    }

     printf("\n\nRollno\tName\tMarks\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%s\t%d\n", data[i].rollno, data[i].name, data[i].marks);
    }

    return 0;
}
