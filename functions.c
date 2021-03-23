#include <stdio.h>
#include <math.h>
#include "functions.h"

uint64_t CountFactorialRec(uint64_t n)
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

uint64_t CountFactorialIter(uint64_t n) 
{
    if (n == 1 || n == 0)
    {
        return 1;    
    }
    else
    {
        int i, result = 1;
        for (i = 1; i <= n; i++)
        {
            result *= (2*i - 1);
        }
        return result;
    }
}

float CountRightRec(uint64_t n, float angle)
{
    if (n == 0)
    {
        return 0;
    }
    else
    {
        float result = 0.;
        result += pow(-1, n - 1) * powf(angle, (2 * n) - 1) / CountFactorialRec(n);
        return (result + CountRightRec(n - 1, angle));
    }
}

float CountRightIter(uint64_t n, float angle) 
{
    if (n == 0)
    {
        return 0;
    }
    else
    {
        float i, right = 0.;
        for (i = 1.; i <= n; i++)
        {
            right += pow(-1, (i - 1)) * powf(angle, ((2 * i) - 1)) / CountFactorialIter(i);
        }
        return right;
    }
}
