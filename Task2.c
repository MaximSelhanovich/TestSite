#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
int checkNULL (void *ptr) {
    if (ptr == NULL) {
        printf("Allocation error!\n");
        return 1;
    }
    return 0;
}

/*Does not include '\n' and '\0' when counting*/
unsigned int lineLength(char *line) {
    unsigned int counter = 0;

    if (!line) {
        printf("\nIncorrect string!\n");
        return 0;
    }

    while (line[counter] && line[counter] != '\n') ++counter;
    return counter;
}

void *clearTwoTwoDimensionalArray(void **arrayToClean,
                                  unsigned int *linesNumber) {
    unsigned int i = 0;
    
    if (!arrayToClean) {
        printf("This array is already clean.\n");
        return NULL;
    }
    
    for (i = 0; i < *linesNumber; ++i) free(arrayToClean[i]);
    free(arrayToClean);
    *linesNumber = 0;
    printf("\nMemory cleaned\n");
    return NULL;
}

char ** getTwoDimensionalArray(unsigned int linesNumber) {
    char **text = NULL;
    unsigned int i, success = 1;

    text = (char **)malloc(linesNumber * sizeof(char *));
    if (checkNULL(text)) return NULL;

    for (i = 0; i < linesNumber; ++i) {
        text[i] = (char *)malloc(255 * sizeof(char));

        if (checkNULL(text[i])) {
            success = 0;
            break;
        }
    }

    if (!success) return clearTwoTwoDimensionalArray((void **)text, &i);

    return text;
}

char ** getText(char **text, unsigned int *linesNumber) {
    unsigned int i = 0;
    char tempChar;
    char *tempLine = NULL;
    char **tempText = NULL;

    while ((tempChar = getchar()) != '\n') {
        ungetch(tempChar);
        if (i >= *linesNumber) {
            tempText =  (char **)realloc(text, *linesNumber + 3);

            if (checkNULL(tempText)) {
                return clearTwoTwoDimensionalArray((void **)text, linesNumber);

            }
            text = tempText;
            *linesNumber += 3;
        }

        scanf(" %[^\n]254s", text[i]);
        getchar();
        printf("\n\n%u\n\n", lineLength(text[i]) + 1);
        tempLine = (char *)realloc(text[i], lineLength(text[i]) + 1);

        if (checkNULL(tempLine)) {
            return clearTwoTwoDimensionalArray((void **)text, linesNumber);
        }
        text[i] = tempLine;
        ++i;
    }
    return text;
}

int main() {
    unsigned int linesNumber = 5, i = 0, success = 1; 
    char **text = NULL;

    /*text = getTwoDimensionalArray(linesNumber);
    if(!text) return 1;*/

    text = (char **)malloc(linesNumber * sizeof(char *));

    if (!text) {
        printf("Allocation error!\n");
        free(text);
        text = NULL;
        return 1;
    }

    for (i = 0; i < linesNumber; ++i) {
        text[i] = (char *)malloc(255 * sizeof(char));

        if (!text[i]) {
            printf("Allocation error!");
            success = 0;
            break;
        }
    }

    if (success == 0) {
        for (; i >= 0; i--) free(text[i]);

        free(text);
        text = NULL;
        return 1;
    }

    text = getText(text, &linesNumber);
    printf("May be yes may be no");

    text = clearTwoTwoDimensionalArray((void **)text, &linesNumber);
    return 0;
}
