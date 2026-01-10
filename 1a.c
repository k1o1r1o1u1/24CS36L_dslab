/*
Define a structure called Student with the members: Name, Reg_no, marks in 3 tests and average_ marks.
Develop a menu driven program to perform the following by writing separate function for each operation: a) read
information of N students b) display student’s information c) to calculate the average of best two test marks of each
student.
Note: Allocate memory dynamically and illustrate the use of pointer to an array of structure.
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char name[50];
    int reg_no;
    float marks[3], avg;
} Student;
void getData(Student *);
void display(Student *);
void calc(Student *);

int main()
{
    int ch, n;
    system("cls");
    printf("Enter the no. of students: ");
    scanf("%d", &n);
    Student *sptr = (Student *)malloc(n * sizeof(Student));
    printf("Mennu: \n1. Enter Details.\n2. Calculate.\n3. Display the details.\n4. Exit\n");

    while (1)
    {
        printf("Enter choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the details of %d students: \n", n);
            for (int i = 0; i < n; i++)
            {
                printf("\nStudent %d: \n", i + 1);
                getData(sptr + i);
            }
            break;
        case 2:
            for (int i = 0; i < n; i++)
                calc(sptr + i);
            printf("\nCalculation done successfully.....\n");
            break;
        case 3:
            printf("The student details are: \n");
            for (int i = 0; i < n; i++)
            {
                printf("\nStudent %d: \n", i + 1);
                display(sptr + i);
            }

            break;
        case 4:
            exit(0);
        default:
            printf("Invalid Choice...\n");
        }
    }
    return 0;
}
void getData(Student *s)
{
    printf("Name: ");
    scanf("%s", s->name);
    printf("Reg. No.: ");
    scanf("%d", &s->reg_no);
    printf("Marks in 3 subjects: ");
    scanf("%f %f %f", &s->marks[0], &s->marks[1], &s->marks[2]);
}

void display(Student *s)
{
    printf("Name: %s\n", s->name);
    printf("Reg. No.: %d\n", s->reg_no);
    printf("Marks in 3 subjects: %f %f %f\n", s->marks[0], s->marks[1], s->marks[2]);
    printf("Average of the best 2 test marks: %f\n", s->avg);
}

void calc(Student *s)
{
    float small;
    float m1 = s->marks[0], m2 = s->marks[1], m3 = s->marks[2];

    small = (m1 < m2) ? (m1 < m3 ? m1 : m3) : (m2 < m3 ? m2 : m3);
    s->avg = (m1 + m2 + m3 - small) / 2;
}
