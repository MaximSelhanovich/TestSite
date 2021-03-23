#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
#include <math.h>

void clrscr()
{
    system("@cls || clear");
}

float CostOfTheDistillation(unsigned int distance)
{
    float distillation = 3.11 * 0.5 * distance;
    float result = roundf(distillation * 10000) / 10000;
    return result;
}

float CostOfTheCustoms(unsigned int year, unsigned int value)
{
    float customs, result;
    if(year < 3)
    {
        customs = 0.6 * 3.11 * value;
    }
    if (year >= 3 && year < 10)
    {
        if (value > 2500)
        {
            customs = 0.3 * 3.11 *value;
        }
        else
        {
            customs = 0.6 * 3.11 * value;    
        }
    }
    if (year >= 10 && year < 14)
    {
        customs = 0.6 * 3.11 * value;
    }
    if (year >= 14)
    {
        customs = 2.0 * 3.11 * value;
    }
    result = roundf(customs * 10000) / 10000;
    return result;
}

float TotalCostInByn(unsigned int cost, unsigned int distance, unsigned int year, unsigned int value)
{
    float total = 3.11 * cost + CostOfTheDistillation(distance) + CostOfTheCustoms(year, value);
    float result = roundf(total * 10000) / 10000;
    return result;
}

void PresentData(unsigned int distance, unsigned int year,  unsigned int value,  unsigned int cost)
{
    printf("The cost of the distillation of the car: %.2f", CostOfTheDistillation(distance));
    printf("\nThe cost of the customs of the car: %.2f", CostOfTheCustoms(year, value));
    printf("\nThe total cost of the car (in byn): %.2f\n", TotalCostInByn(cost, distance, year, value));
}

void Menu()
{
    printf("1. Enter the cost of the car\n");
    printf("2. Enter the year of issue of the car\n");
    printf("3. Enter the engine volume of the car\n");
    printf("4. Enter the run distance of the car\n");
    printf("5. Calculation of the cost of the service\n");
    printf("6. Information about the version and the author of the program\n");
    printf("7. Exit the program\n");
}

unsigned int EnterTheNumber(unsigned int number)
{
    scanf("%u", &number);
    while(number > 7)
    {
        printf("Sorry, there is no function with this number, please re-enter\n");
        printf("Enter the number of the function: ");
        scanf("%u", &number); 
    }
    return number;
}

void Information() 
{
    printf("The author: Mary Zyryanova\nThe version of the program: C98\n");
}
