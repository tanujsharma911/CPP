#include <stdio.h>
#include <string.h>

int login()
{
    static int attemptsLeft = 3;

    

    char password[] = "admin123";
    char pass[7];

    while(attemptsLeft > 0)
    {
        printf("Enter the password: ");
        scanf("%s", pass);
        
        if (strcmp(pass, password) == 0)
        {
            printf("Login successful!\n");
            return 1;
        }
        else
        {
            attemptsLeft--;
            printf("Incorrect password. Attempts left: %d\n", attemptsLeft);
        }
    }

    if (attemptsLeft <= 0)
    {
        printf("Account locked. Too many attempts.\n");
    }

    return 0;
}

int main()
{
    login();

    return 0;
}