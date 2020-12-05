/*Write a code to sort the elements firstly according to num of problems solved. If number of
problems solved is equal then according to cgpa, if cgpa is equal then according to their
registration number.
Input:
The number in the first line means number of students. Then each line of input has 3 numbers. The first
number represents the registration number, the second number represents the number of solved
problems and the third number represents the cgpa of the students.
4
1 200 3.99
4 400 3.77
2 1000 3.55
33 1000 3.62
Output:
33 1000 3.62
2 1000 3.55
4 400 3.77
1 200 3.99 */

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

