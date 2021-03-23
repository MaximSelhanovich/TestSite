#include "functions.c"

int main()
{
    unsigned int number, year, cost, value,distance;
    while(1)
    {
        Menu();
        printf("Enter the number of the function: ");
        switch(EnterTheNumber(number))
        {
            case 1: 
                clrscr();
                printf("The cost of the car (€): ");
                scanf("%u", &cost);
                clrscr();
                break;
            case 2: 
                clrscr();
                printf("The year of the car: ");
                scanf("%u", &year);
                clrscr();
                break;
            case 3:
                clrscr();
                printf("The engine value of the car (cc):  ");
                scanf("%u", &value);
                clrscr();
                break;
            case 4:
                clrscr();
                printf("The run distance of the car (km): ");
                scanf("%u", &distance);
                clrscr();
                break;
            case 5:
            clrscr();
                PresentData(distance, year, value, cost);
                break;
            case 6:
                clrscr();
                Information();
                break;
            case 7:
                clrscr();
                exit(0);
                break;
        }
    }
}

