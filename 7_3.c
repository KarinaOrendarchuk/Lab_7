#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int Low=-100, High=100; 
int n = 5;
int m = 5;

int min(int n, int m, int a[][m])
{
    int min = a[0][0];
for (int i=0; i < n; i++){
for (int j=0; j < m; j++)
    if (i+j < n-1 && a[i][j] < min)
    {
        min = a[i][j];
    }
}
return min;
}

int mas_a_rand(int n, int m, int a[][m])
{
    srand(time(0));
    for (int i=0; i<n; i++)
        for (int j=0; j < m; j++)
        {
            a[i][j]=Low + rand() % (High - Low + 1);
        }
}

int mas_a_printf(int n, int m, int a[][m])
{
    printf("\n");
        for (int i=0; i<n; i++)
        {
            for (int j=0; j < m; j++)
                printf("[%d][%d] %d\t", i, j, a[i][j]);printf("\n");
        }
}


int main(void)
{

int a[n][m];

mas_a_rand(n,m,a);
mas_a_printf(n,m,a);

printf("\r\nмінімальний елемент серед елементiв,\nякi знаходяться вище бокової дiагоналi: %d\r\n", min(n, m, a));

    return 0;
}