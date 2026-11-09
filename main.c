#include <stdio.h>
#include <string.h>

struct Student {
    int roll;
    char name[50];
    int mark1, mark2, mark3, mark4, mark5;
    int total;
    float average;
    char grade;
};

struct Student s[100];
int count = 0;

void addStudent();
void displayStudents();
void searchStudent();

int main() {
    int choice;

    do {
        printf("\n=====================================\n");
        printf("   STUDENT GRADE MANAGEMENT SYSTEM\n");
        printf("=====================================\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Exit\n");
        printf("-------------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addStudent();
                break;

            case 2:
                displayStudents();
                break;

            case 3:
                searchStudent();
                break;

            case 4:
                printf("\nThank you!\n");
                break;

            default:
                printf("\nInvalid Choice!\n");
        }

    } while(choice != 4);

    return 0;
}

void addStudent() {

    printf("\nEnter Roll Number: ");
    scanf("%d", &s[count].roll);

    printf("Enter Name: ");
    scanf(" %[^\n]", s[count].name);

    printf("Enter Marks in 5 Subjects:\n");

    printf("Subject 1: ");
    scanf("%d", &s[count].mark1);

    printf("Subject 2: ");
    scanf("%d", &s[count].mark2);

    printf("Subject 3: ");
    scanf("%d", &s[count].mark3);

    printf("Subject 4: ");
    scanf("%d", &s[count].mark4);

    printf("Subject 5: ");
    scanf("%d", &s[count].mark5);

    s[count].total = s[count].mark1 + s[count].mark2 +
                     s[count].mark3 + s[count].mark4 +
                     s[count].mark5;

    s[count].average = s[count].total / 5.0;

    if(s[count].average >= 90)
        s[count].grade = 'A';
    else if(s[count].average >= 80)
        s[count].grade = 'B';
    else if(s[count].average >= 70)
        s[count].grade = 'C';
    else if(s[count].average >= 60)
        s[count].grade = 'D';
    else
        s[count].grade = 'F';

    printf("\nStudent Added Successfully!\n");

    count++;
}

void displayStudents() {

    int i;

    if(count == 0) {
        printf("\nNo Student Records Found!\n");
        return;
    }

    printf("\n=========== STUDENT RECORDS ===========\n");

    for(i = 0; i < count; i++) {

        printf("\nStudent %d\n", i + 1);
        printf("-----------------------------\n");
        printf("Roll Number : %d\n", s[i].roll);
        printf("Name        : %s\n", s[i].name);
        printf("Marks       : %d %d %d %d %d\n",
               s[i].mark1,
               s[i].mark2,
               s[i].mark3,
               s[i].mark4,
               s[i].mark5);

        printf("Total       : %d\n", s[i].total);
        printf("Average     : %.2f\n", s[i].average);
        printf("Grade       : %c\n", s[i].grade);
    }
}

void searchStudent() {

    int roll, i, found = 0;

    printf("\nEnter Roll Number to Search: ");
    scanf("%d", &roll);

    for(i = 0; i < count; i++) {

        if(s[i].roll == roll) {

            printf("\nStudent Found!\n");
            printf("-----------------------------\n");
            printf("Roll Number : %d\n", s[i].roll);
            printf("Name        : %s\n", s[i].name);
            printf("Total       : %d\n", s[i].total);
            printf("Average     : %.2f\n", s[i].average);
            printf("Grade       : %c\n", s[i].grade);

            found = 1;
            break;
        }
    }

    if(found == 0) {
        printf("\nStudent Not Found!\n");
    }
}
