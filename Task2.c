#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <malloc.h>

int surround(int x, int y, int verticalFlaf, int type, int** field) {   
    int  i, j;
    if (verticalFlaf == 1) {
        for (i = x - 1; i <= x + 1; i++) {
            if (i >= 0 && i < 10) {
                for (j = y - 1; j <= y + type; j++) {
                    if (j >= 0 && j < 10 && field[i][j] == 0) {
                        field[i][j] = 8;
                    }
                }
            }
        }
    }
    else {
        for (i = x - 1; i <= x + type; i++) {
            if (i >= 0 && i < 10) {
                for (j = y - 1; j <= y + 1; j++) {
                    if (j >= 0 && j < 10 && field[i][j] == 0)
                        field[i][j] = 8;
                }
            }
        }
    }
    return 0;
}

void fill(int** field) {
    int i, j;
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            field[i][j] = 0;
        }
    }
}

void clear(int** field) {
    int i, j;
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            if(field[i][j] == 8) field[i][j] = 0;
        }
    }
}

void printField(int** field) {
    int i, j;
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            printf("%d  ", field[i][j]);
        }
        printf("\n");
    }
}

int horizontalCheck (int** field, int y, int x, int size) {
    int i = 0;
    if (x + size - 1 > 9) return 0;
    
    for (i = 0; i < size; ++i) {
        if (field[y][x + i] != 0) return 0;
    }
    return 1;
}

int horizontalFill (int** field, int y, int x, int size) {
    int i = 0;
    
    for (i = 0; i < size; ++i) {
        field[y][x + i] = size;
    }
    return 1;
}

int verticalFill (int** field, int y, int x, int size) {
    int i = 0;
    
    for (i = 0; i < size; ++i) {
        field[y + i][x] = size;
    }
    return 1;
}

int verticalCheck (int** field, int y, int x, int size) {
    int i = 0;
    if (y + size - 1 > 9) return 0;
    
    for (i = 0; i < size; ++i) {
        if (field[y + i][x] != 0) return 0;
    }
    return 1;
}

void place(int** field) {
    int type = 4, fillIndex = 0, y, x, amount = 1, verticalFlaf;

    for (type = 4; type > 0; --type) {
        amount = 4 - type + 1;
        for (amount = 4 - type + 1; amount > 0; --amount) {
            fillIndex = 0;
            while (fillIndex == 0) {
                do {
                    y = rand() % 10;
                    x = rand() % 10;
                } while (field[y][x] != 0);
                
                if (horizontalCheck(field, y, x, type) == 1) {
                    fillIndex = horizontalFill(field, y, x, type);
                    verticalFlaf = 1;
                }
                else {
                    if (verticalCheck(field, y, x, type) == 1) {
                        fillIndex = verticalFill(field, y, x, type);
                        verticalFlaf = 0;
                    }
                }
            }
            surround(y, x, verticalFlaf, type , field);
        }
    }
}

int checkShips(int** field) {
    int i, j, countSh = 0;
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            if (field[i][j] > 0 && field[i][j] < 5) {
                countSh += field[i][j];
            }
        }
    }
    return countSh;
}
int main(void) {
    int n = 10, m = 10, i, amount;
    int** field = (int**)malloc(n * sizeof(int*));
    
    for (i = 0; i < n; i++) {
        field[i] = (int*)malloc(m * sizeof(int));
    }

    srand(time(NULL));

    printf("Autoplacement of ships\n");
    fill(field);
    place(field);
    clear(field);
    printf("final version:\n");
    printField(field);
    amount = checkShips(field);
    printf("am = %d", amount);

    for (i = 0; i < n; i++) {
        free(field[i]);
    }
    free(field);

    return 0;
}
