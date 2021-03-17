#include <stdio.h>
#include <complex.h>

int main(void) {
    complex double complex1 = 1.0 + 2.0 * I;
    complex double complex2 = 3.0 + I * 3.0;

    complex double compl3 = complex1 + complex2;

    printf("Complex 1 = %f + %fi\n", creal(complex1), cimag(complex1));
    printf("Complex 2 = %f + %fi\n", creal(complex2), cimag(complex2));
    printf("fkofkfokf: %f, i * %fi\n", creal(compl3), cimag(compl3));
    return 0;
}