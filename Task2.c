#include <stdio.h>
#include <malloc.h>

int main() {
    int i = 0, success = 1, rowsNumber = 10, columnsNumber =10;
    int **array = NULL;

    array = (int **)malloc(rowsNumber * sizeof(int *));
    if(!array) {
        printf("Poshel nafig\n");
        free(array);
        array = NULL;/*This may be nesessary if programm contiue working*/
        return 1;
    }

    for(; i < rowsNumber; ++i) {
        array[i] = (int *)malloc(columnsNumber * sizeof(int));
        if(!array[i]) {
            printf("Poshel nafig x2\n\n%d\n\n", i);
            success = 0;
            break;
        }
    }

    if (success == 0) {
        for (; i >= 0; i--) { 
            free(array[i]);
            printf("\n\n%d\n\n", i);
        }
        free(array);
        printf("\n\n%d\n\n", i);
        array = NULL;/*This may be nesessary if programm contiue working*/
        return 1;
    }



    for(i = 0; i < rowsNumber; ++i) free(array[i]);
    free(array);
    return 0;
}
