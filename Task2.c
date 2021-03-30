#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <malloc.h>


void surround(int a, int b, int f, int size, int** field)
{   
    int  i, j;
    if (f == 1)
    {
        for (i = a - 1; i <= a + 1; i++)
        {
            if (i >= 0 && i < 10) {
                for (j = b - 1; j <= b + size; j++)
                {
                    if (j >= 0 && j < 10 && field[i][j] == 0)
                    {
                        field[i][j] = 8;
                    }
                }
            }
        }
    }
    else
    {
        for (i = a - 1; i <= a + size; i++)
        {
            if (i >= 0 && i < 10) 
            {
                for (j = b - 1; j <= b + 1; j++)
                {
                    if (j >= 0 && j < 10 && field[i][j] == 0)
                        field[i][j] = 8;
                }
            }
        }
    }
}
void fill(int** field)
{
    int i, j;
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {
            field[i][j] = 0;
        }
    }
}

void clear(int** field)
{
    int i, j;
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {
            if(field[i][j] == 8)
            field[i][j] = 0;
        }
    }

}

void printField(int** field)
{
    int i, j;
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {
            printf("%d  ", field[i][j]);
        }
        printf("\n");
    }
}

int horizontalCheck (int** field, int x, int y, int size) {
    int i = 0;
    if (x + size - 1 > 9) return 0;
    
    for (i = 0; i < size; ++i) {
        if (field[x + i][y] != 0) return 0;
    }
    return 1;
}

int horizontalFill (int** field, int x, int y, int size) {
    int i = 0;
    
    for (i = 0; i < size; ++i) {
        field[x + i][y] = size;
    }
    return 1;
}

int verticalFill (int** field, int x, int y, int size) {
    int i = 0;
    
    for (i = 0; i < size; ++i) {
        field[x][y + i] = size;
    }
    return 1;
}

int verticalCheck (int** field, int x, int y, int size) {
    int i = 0;
    if (y + size - 1 > 9) return 0;
    
    for (i = 0; i < size; ++i) {
        if (field[x][y + i] != 0) return 0;
    }
    return 1;
}

void place(int** field)
{
    int type, fillIndex = 0, x, y, amount, verticalFlaf ;

    for (type = 4; type > 0; type--)
    {
        for (amount = 4 - type + 1; amount > 0; amount--)
        {
            while (fillIndex == 0) 
            {
                do
                {
                    x = rand() % 10;
                    y = rand() % 10;
                } while (field[x][y] != 0);

                if (horizontalCheck(field, x, y, type) == 1)
                {
                    fillIndex = horizontalFill(field, x, y, type);
                    verticalFlaf = 0;
                }
                else
                {
                    if (verticalCheck(field, x, y, type) == 1)
                    {
                        fillIndex = verticalFill(field, x, y, type);
                        verticalFlaf = 1;
                    }
                }
            }
            surround(x, y, verticalFlaf, type , field);
        }
    }
}
int checkShips(int** field)
{
    int i, j, countSh = 0;
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {
            if (field[i][j] > 0 && field[i][j] < 5)
            {
                countSh += field[i][j];
            }
        }
    }
    return countSh;
}
int main(void)
{
    int n = 10, m = 10, i, amount;
    int** field = (int**)malloc(n * sizeof(int*));
    for (i = 0; i < n; i++)
    {
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

    for (i = 0; i < n; i++) 
    {
        free(field[i]);
    }
    free(field);

    return 0;
}
