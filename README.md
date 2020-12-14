# Lab_7#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void max_hos(char *S1, char *S3){
int summ = 0;
int k = 0, i = 0;
int max = 0;
int max_i = 0;
_Bool check = 0;
for (k = 0; S1[k] != '\0'; k++)
{
	if (summ > 0)
	{
		check = 1;
	}
	if (summ > max)
	{
		max = summ;
		max_i = k-1;
	} summ = 0;
	for (i = k; S1[i] != ' '; i++)
	{
		for (int j = 0; S3[j] != '\0'; j++)
		{		
			if (S1[i] == S3[j]) //якщо в масиві S1 зустрічається голосна буква (S3) збільшує суму на одиницю
			{
				summ++;
			}
		}
	}
}
if (check == 0)
{
	printf("#Відсутнє\n\n");
	return;
}
for (int m = max_i; S1[m] != '\0'; m++)
{
	printf("%c", S1[m]);
	if (S1[m] == ' ')
	{
		printf("\n\n");
		return;
	}
}
printf("\n\n");
}

void clear_spaces(char *s1){
int i = 0, ss = 0, k = 0, m = 0;
for (i = 0; s1[i] != '\0'; i++)
{
	if (s1[i] == ' ' && s1[i+1] == ' ') //залишає лише по одному пробілу
	{
		for (ss = i+1; s1[ss] != '\0'; ss++)
		{
			s1[ss] = s1[ss+1];
		}
		i = 0;
	}
	if (s1[0] == ' ') // якщо перед текстом були пробіли - видаляє їх
	{
		do{
			for (m = 0; s1[m] != '\0'; m++)
			{
				s1[m] = s1[m+1];
			}
		}while(s1[0] == ' ');
	}

	if (s1[i] == ' ' && s1[i+1] == '\0'){ // якщо в кінці текста були пробіли - видаляє їх
		for (k = i; s1[k] == ' '; k--){}
		s1[k+1] = '\0';
	}
}
}

int main()
{
char S3[] = "аеиіоуяюєї"; // Голосні букви
char S[10000];
printf("\nВведіть речення: ");
gets(S);

printf("\n\na) Cлово, що містить найбільшу кількість голосних літер: ");
max_hos(S, S3);
clear_spaces(S);

puts("б) Речення після видалення з тексту всі непотрібні пробіли:\n");
puts(S);
return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void zl(char *S1, char *S2){
char *S3 =  (char*)malloc(strlen(S1)+strlen(S2));
S3[0] = '\0';
strcat(S3, S1);
strcat(S3, S2);
puts(S3);
}

int main()
{
char S[10000];
char S2[10000];

printf("\nПерше речення: ");
gets(S);

printf("Друге речення: ");
gets(S2);

printf("\nРезультат виконання функції: ");
zl(S, S2);

return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
_Bool x = 0;

int dov(char *S, ...){
int i, k=1;
int min=9999;
int max = 0;

	for (i=0; S[i] != '\0'; i++)
	{
		if (S[i+1] !=' ' && S[i+1] != '\0')
		    k++;
		else
		{
			if(x == 0 && k<min) min=k;
			else if(x == 1 && k>max) max=k;
			k=0;
		}
	}
	if (x == 0)
	{
		return min/2;
	} else return max/2;
}

int main()
{
char S[10000];
printf("\nВведіть речення: ");
gets(S);
printf("Довжина найкоротшого слова = %d\nДовжина найдовшого слова = %d\n",dov(S, x=0), dov(S, x=1));
return 0;
}
