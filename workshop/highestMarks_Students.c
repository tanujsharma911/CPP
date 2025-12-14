#include <stdio.h>

struct Student
{
    int roll;
    char name[30];
    float maths, science, english;
    float total;
    int percent;
};

void inputStudent(struct Student *s, int n);
void displayStudents(struct Student *s, int n);

int main()
{
    int n;

    printf("Number of students: ");
    scanf("%d", &n);

    struct Student s[n];

    inputStudent(s, n);

    displayStudents(s, n);

    return 0;
}

void inputStudent(struct Student *s, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("\nEnter details for student %d\n", i + 1);
        printf("Roll: ");
        scanf("%d", &s->roll);

        printf("Name: ");
        scanf(" %29[^\n]", s->name);

        printf("Enter marks in Maths, Science, English: ");
        scanf("%f %f %f", &s->maths, &s->science, &s->english);

        s->total = s->english + s->maths + s->science;
        s->percent = s->total / 300 * 100;

        s++;
    }
}

void displayStudents(struct Student *s, int n)
{
    struct Student *highest = s;

    for (int i = 0; i < n; i++)
    {
        if (highest->total < s[i].total)
        {
            highest = &s[i];
        }

        printf("\nStudents details of %d:\n", i + 1);
        printf("name: %s\n", s[i].name);

        printf("roll: %d\n", s[i].roll);

        printf("Maths: %.2f science: %.2f english: %.2f\n", s[i].maths, s[i].science, s[i].english);

        printf("total: %.2f\n", s[i].total);

        printf("percentage: %d\n", s[i].percent);
    }

    printf("\nStudent with highest marks:\n");
    printf("name: %s\n", highest->name);

    printf("roll: %d\n", highest->roll);

    printf("Maths: %.2f science: %.2f english: %.2f\n", highest->maths, highest->science, highest->english);

    printf("total: %.2f\n", highest->total);

    printf("percentage: %d\n", highest->percent);
}