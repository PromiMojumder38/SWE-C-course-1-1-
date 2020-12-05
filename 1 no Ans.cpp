#include<stdio.h>

typedef struct {
	int regNo;
	int solvedPrb;
	double cgpa;
} info;

int main()
{
	int n, i, j, k;
	scanf("%d", &n);
	info student[n];

	for(i = 0; i < n; i++) scanf("%d %d %lf", &student[i].regNo, &student[i].solvedPrb, &student[i].cgpa);

	for(i = 0; i < n; i++)
	{
		for(j = i + 1; j < n; j++)
		{
			if(student[i].solvedPrb < student[j].solvedPrb )
			{
				info temp = student[i];
				student[i] = student[j];
				student[j] = temp;
			}
		}
	}

	for(i = 0; i < n; i++)
	{
		for(j = i + 1; j < n; j++)
		{
			if(student[i].solvedPrb == student[j].solvedPrb)
			{
				if(student[i].cgpa < student[j].cgpa)
				{
					info temp = student[i];
					student[i] = student[j];
					student[j] = temp;
				}
			}
		}
	}
	
	for(i = 0; i < n; i++)
	{
		for(j = i + 1; j < n; j++)
		{
			if(student[i].cgpa == student[j].cgpa)
			{
				if(student[i].regNo > student[j].regNo)
				{
					info temp = student[i];
					student[i] = student[j];
					student[j] = temp;
				}
			}
		}
	}
	printf("\n");
	for(int i = 0; i < n; i++) printf("%d %d %.2lf\n", student[i].regNo, student[i].solvedPrb, student[i].cgpa);
}

