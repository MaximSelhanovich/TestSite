#include <stdio.h>
#include <stdlib.h>

/*Does not include '\n' and '\0' when counting*/
unsigned int lineLength(char *line) {
    unsigned int counter = 0;

    if (!line) return 0;

    while (line[counter] != '\0' && line[counter] != '\n') ++counter;
    return counter;
}

void swapStrings (char **firstLine, char **secondLine) {
    char *temp = *firstLine;
    *firstLine = *secondLine;
    *secondLine = temp;
}

int compareStrings (char *firstLine, char *secondLine) {
    unsigned int i = 0;

    if (lineLength(firstLine) < lineLength(secondLine)) return -1;
    else if (lineLength(firstLine) > lineLength(secondLine)) return 1;

    for (i = 0; i < lineLength(firstLine); ++i) {
        if (firstLine[i] < secondLine[i]) return -1;
        else if (firstLine[i] > secondLine[i]) return 1;
    }

    return 0;
}

int checkNULL(void *ptr) {
    if (!ptr) {
        printf("\nMemory (re)allocation error!\n");
        return 1;
    }
    return 0;
}

char **getTwoDimensionalArray(unsigned int linesNumber) {
    char **text = NULL;
    unsigned int i = 0, j = 0;

    if (linesNumber <= 0) return NULL;

    text = (char **)malloc(linesNumber * sizeof(char *));
    if (checkNULL(text)) return NULL;

    for (i = 0; i < linesNumber; ++i) {
        text[i] = (char *)malloc(255 * sizeof(char));

        if (checkNULL(text[i])) {
            for (j = 0; j < i; ++j) free(text[j]);

            free(text);
            return NULL;
        }
    }
    return text;
}

char **freeArray(char **text, unsigned int linesNumber) {
    unsigned int i = 0;

    if (!text) return NULL;

    for (i = 0; i < linesNumber; ++i) {
        if (!text[i]) continue;
        free(text[i]);
    }

    free(text);
    return NULL;
}


char **expendText(char **text, unsigned int *linesNumber) {
    char** tempText = NULL;
    unsigned int i = 0, j = 0;

    tempText = (char **)realloc(text,
                                (*linesNumber + 3) * sizeof(char *));

    if (checkNULL(tempText)) {
        freeArray(text, *linesNumber);
        return NULL;
    }

    for (i = *linesNumber; i < *linesNumber + 3; ++i) {
        tempText[i] = (char *)malloc(255 * sizeof(char));

        if (checkNULL(tempText[i])) {
            for (j = 0; j < i; ++j) free(tempText[j]);

            free(tempText);
            return NULL;
        }
    }

    *linesNumber += 3;
    return tempText;
}

char *resizeLine(char *line) {
    char *tempLine = NULL;
    unsigned int length = lineLength(line);

    /*on "length" position '\n' is located*/
    line[length + 1] = '\0';

    tempLine = (char *)realloc(line, (length + 2) * sizeof(char));

    if (!tempLine) return line;

    return tempLine;
}

char **resizeText(char **text, unsigned int linesNumber) {
    char** tempText = NULL;
    unsigned int i = 0;

    tempText = (char **)realloc(text, linesNumber * sizeof(char *));

    if (!tempText) return text;

    for (i = 0; i < linesNumber; ++i) tempText[i] = resizeLine(tempText[i]);

    return tempText;

}

void getText(char ***text, unsigned int *linesNumber) {
    int i = -1;

    if (!*text) return;

    do {
        ++i;

        if (i >= *linesNumber) {
            *text = expendText(*text, linesNumber);

            if (checkNULL(text)) return;
        }

        fgets((*text)[i], 254, stdin);

    }
    while ((*text)[i][0] != '\n');
    free((*text)[i]);

    *linesNumber = i;

    /**text = resizeText(*text, *linesNumber);*/
}

int main() {
    char **text = NULL;
    unsigned int linesNumber = 5;

    text = getTwoDimensionalArray(linesNumber);
    getText(&text, &linesNumber);
    if (!text) return 1;

    text = freeArray(text, linesNumber);
    return 0;
}
