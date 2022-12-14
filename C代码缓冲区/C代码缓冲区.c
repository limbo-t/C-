#include<stdio.h>
#include<stdlib.h>

int total = 0;

int fibonacci(int num,int *f)
{
	total += 1;
	if (num == 1 || num == 2)
		return f[num] = 1;
	if (f[num] == 0)
		return f[num] = fibonacci(num - 1,f) + fibonacci(num - 2,f);
	else
		return f[num];
}

int main()
{
	int num;
	scanf("%d", &num);
	int* f=(int*)malloc((num+1) * 4);
	memset(f, 0, (num+1) * 4);
	fibonacci(num,f);
	for (int i = 1; i <= num; i++)
		printf("%d ", f[i]);
	printf("\ntotal=%d\n", total);
	free(f);
	return 0;
}