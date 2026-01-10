/*
Define a structure called Time containing 3 integer members (Hour, Minute, Second).Develop a menu driven
program to perform the following by writing separate function for each operation.
a) Read (T) :To read time b) Display (T):To display time c) update(T):To Update time d) Add(T1, T2) : Add two
time variables.
Update function increments the time by one second and returns the new time (if the increment results in 60
seconds, then the second member is set to zero and minute member is incrementedby one. If the result is 60
minutes, the minute member is set to zero and the hour member isincremented by one. Finally, when the hour
becomes 24, Time should be reset to zero. While adding two time variables, normalize the resultant time value as in
the case of update function. Note: Illustrate the use of pointer to pass time variable to different functions.
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int hr, min, sec;

} Time;

void read(Time *t);
void display(Time *t);
void update(Time *t);
Time *add(Time *t1, Time *t2);
void normalize(Time *);

int main()
{
    int ch;
    Time *t = (Time *)malloc(sizeof(Time));
    system("cls");

    printf("Menu: \n1. Read Time\n2. Display Time.\n3. Update time.\n4. Add Time.\n5. Exit.\n");

    while (1)
    {
        printf("Enter choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            read(t);
            break;
        case 2:
            display(t);
            break;
        case 3:
            update(t);
            break;
        case 4:
            Time *t1, *t2;
            t1 = (Time *)malloc(sizeof(Time));
            t2 = (Time *)malloc(sizeof(Time));
            printf("\nTime 1: \n");
            read(t1);
            printf("\nTime 2: \n");
            read(t2);
            t = add(t1, t2);
            free(t1);
            free(t2);
            break;
        case 5:
            free(t);
            return 0;
        default:
            printf("Invalid Choice....\n");
        }
    }
}

void read(Time *t)
{
    printf("Enter Time(hh mm ss): ");
    scanf("%d %d %d", &t->hr, &t->min, &t->sec);
    normalize(t);
}
void display(Time *t)
{
    printf("Time: %d:%d:%d\n", t->hr, t->min, t->sec);
}
void update(Time *t)
{
    t->sec += 1;
    normalize(t);
}
void normalize(Time *t)
{
    if (t->sec >= 60)
    {
        t->min += t->sec / 60;
        t->sec %= 60;
    }
    if (t->min >= 60)
    {
        t->hr += t->min / 60;
        t->min %= 60;
    }
    if (t->hr >= 24)
    {
        t->hr %= 24;
    }
}
Time *add(Time *t1, Time *t2)
{
    Time *t = (Time *)malloc(sizeof(Time));
    t->hr = t1->hr + t2->hr;
    t->min = t1->min + t2->min;
    t->sec = t1->sec + t2->sec;
    normalize(t);
    return t;
}