#include <stdio.h>

struct Course
{
    int code;
    char courseName[20];
    char credits[20];
};

void inputCourses(struct Course *c, int n);
void displayCourses(struct Course *c, int n);

int main()
{
    int n;

    printf("Number of courses: ");
    scanf("%d", &n);

    struct Course c[n];

    inputCourses(c, n);
    displayCourses(c, n);

    return 0;
}

void inputCourses(struct Course *c, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("\nEnter the details of %d course:\n", n);

        printf("Name: ");
        scanf(" %19[^\n]", c->courseName);

        printf("Code: ");
        scanf("%d", &c->code);

        printf("Credits: ");
        scanf(" %19[^\n]", c->credits);

        c++;
    }
}
void displayCourses(struct Course *c, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("\nDetails of %d course:\n", n);

        printf("Name: %s\n", c[i].courseName);
        printf("Code: %d\n", c[i].code);
        printf("Credits: %s\n", c[i].credits);
    }
}