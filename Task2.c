#include "functions.c"

int main()
{
    uint64_t n;
    int choice, x;
    float right, left, angle;
    char answer = 'y';
    while (answer == 'y')
    {
        printf("Enter n: ");
        while (scanf("%lu", &n) != 1) 
        {
            if (scanf("%lu", &n) != 1) 
            {
                printf("Incorrect input, try again!");  
                printf("\nn = ");
                while(getchar() != '\n') {}
            }
        }
        printf("Enter x: ");
        while (scanf("%d", &x) != 1) 
        {
            if (scanf("%d", &x) != 1) 
            {
                printf("Incorrect input, try again!");  
                printf("\nx = ");
                while(getchar() != '\n') {}
            }
        }
        printf("How do you want to count?\n     1.Using recursion\n     2.Using iterating\n     Answer: ");
        while (scanf("%d", &choice) != 1) 
        {
            if (scanf("%d", &choice) != 1) 
            {
                printf("Incorrect input, try again!");  
                printf("\nyour choice = ");
                while(getchar() != '\n') {}
            }
        }
        angle = x * 3.14 / 180;
        left = sin(angle);
        switch (choice)
        {
            case 1:
            {
                right = CountRightRec(n, angle);
                printf("The result in the left: %f\n", left);
                printf("The result in the right %f\n", right);
                break;
            }
            case 2:
            {
                right = CountRightIter(n, angle);
                printf("The result in the left: %f\n", left);
                printf("The result in the right %f\n", right);
                break;
            }
        }
        printf("Do you want to try again?\nAnswer: ");
        scanf("%s", &answer);
        while(1)
        {
            if(answer == 'y' || answer == 'n')
            {
                break;
            } else {
                printf("Incorrect input, try again!");
                scanf("%s", &answer);
            }
        }
    }
}
