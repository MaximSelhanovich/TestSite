#include <stdio.h>
#include <math.h>
#include "functions.h"

unsigned int CountFactorialRec(unsigned int n)
{
    if(n == 1 ||n == 0)
    {
        return 1;
    }
    else 
    {
        return ((2 * n - 1) * CountFactorialRec(n - 1));
    }
}

unsigned int CountFactorialIter(unsigned int n) 
{
            int i, result = 1;
    if (n == 1 || n == 0)
    {
        return 1;    
    }
    else
    {
        for (i = 1; i <= n; i++)
        {
            result *= (2*i - 1);
        }
        return result;
    }
}

float CountRightRec(unsigned int n, float angle)
{
            float result = 0.;
    if (n == 0)
    {
        return 0;
    }
    else
    {
        result += pow(-1, n - 1) * pow(angle, (2 * n) - 1) / CountFactorialRec(n);
        return (result + CountRightRec(n - 1, angle));
    }
}

float CountRightIter(unsigned int n, float angle) 
{
            float i, right = 0.;
    if (n == 0)
    {
        return 0;
    }
    else
    {
        for (i = 1.; i <= n; i++)
        {
            right += pow(-1, (i - 1)) * pow(angle, ((2 * i) - 1)) / CountFactorialIter(i);
        }
        return right;
    }
}
