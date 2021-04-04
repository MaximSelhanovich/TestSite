#include <stdio.h>
#include <stdlib.h>

int checkNULL(void *ptr) {
    if (!ptr) {
        printf("\nMemory allocation error!\n");
        return 1;
    }
    return 0;
}

/*char** getTwoDemensionalArray(int linesNumber) {
    char **text = NULL;
    unsigned int i = 0;

    text = (char **)malloc(linesNumber * sizeof(char *));
    if (checkNULL(text)) {
        free(text);
        return NULL;
    }
    for (i = 0; i < linesNumber; ++i) {
        text[i] = (char *)malloc(255 * sizeof(char));
        if (checkNULL(text[i])) {
            for (--i; i >= 0; --i) free(text[i]);
            free(text);
            return NULL;
        }
    }
    return text;
}

char** freeArray(char **text, unsigned int linesNumber) {
    unsigned int i = 0;
    if (!text) return NULL;

    for (i = linesNumber - 1; i >= 0; --i) {
        free(text[i]);
    }

    free(text);
    return NULL;
}*/




int main() {
    char **text = NULL;
    unsigned int linesNumber = 5;
    /*text = getTwoDemensionalArray(linesNumber);
    if (!text) return 1;*/

    unsigned int i = 0;

    text = (char **)malloc(linesNumber * sizeof(char *));
    if (checkNULL(text)) {
        free(text);
        return 1;
    }
    for (i = 0; i < linesNumber; ++i) {
        text[i] = (char *)malloc(255 * sizeof(char));
        if (checkNULL(text[i])) {
            for (--i; i >= 0; --i) free(text[i]);
            free(text);
            return 1;
        }
    }

    for (i = linesNumber - 1; i >= 0; --i) {
        free(text[i]);
    }
    free(text);

    /*text = freeArray(text, linesNumber);*/
    return 0;
}
