#include <stdio.h>
int n;

int avg(int n, int a[n][n])
{
int sum = 0;
int p = n*n;
for (int i = 0; i < n; i++)
{
for (int j = 0; j < n; j++)
sum += a[i][j];
}
return sum/p;
}


int main(void)
{


printf("n=");
scanf("%d", &n);

int a[n][n];

for(int i = 0; i < n; i++)
{
	for (int j = 0; j < n; j++)
	{
		printf("a[%d][%d]=", i, j);
    	scanf("%d", &a[i][j]);
	}
}

printf("Avg = %d\n", avg(n,a));


    return 0;
}