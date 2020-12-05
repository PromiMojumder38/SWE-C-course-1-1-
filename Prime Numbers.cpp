/* Write a code to print the prime numbers within a given of 1 to n.
Input:
10
Output:
2
3
5
7 */

#include<stdio.h>

int prime(int n)
{
	int i;
	if(n != 2 && n % 2 == 0) return 0;
	for(i = 3; i*i <= n; i++)
	{
		if(n % i == 0) return 0;
	}
	return 1;
}

int main()
{
	int n, i;
	scanf("%d", &n);
	
	for(i = 2; i <= n; i++)
	{
		if(prime(i)) 
		{
			printf("%d\n", i);
		}
	}
}
