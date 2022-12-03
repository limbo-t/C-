#include<stdio.h>
#include<math.h>
extern double data[24];
extern int n;
void fun1(double data[])
{
	double sum,max,min;
	double average;
	sum = max = min = data[0];
	for (int i = 1; i < n; i++)
	{
		if (data[i] < min)
			min = data[i];
		if (data[i] > max)
			max = data[i];
		sum += data[i];
	}
	average = sum / n;
	for (int i = 0; i < n; i++)
		data[i] = (data[i] - average) / (max - min);
	return;
}
void fun2(double data[])
{
	double sum=0;
	double average,biaozhuncha=0;
	for (int i = 0; i < n; i++)
	{
		sum += data[i];
	}
	average = sum / n;
	for (int i = 0; i < n; i++)
	{
		biaozhuncha += pow(average - data[i], 2);
	}
	biaozhuncha /= n;
	biaozhuncha = sqrt(biaozhuncha);
	for (int i = 0; i < n; i++)
	{
		data[i] = (data[i] - average) / biaozhuncha;
	}
}
int main()
{
	int par;
	scanf("%d", &par);
	if (par == 1)
		fun1(data);
	else if (par == 2)
		fun2(data);
	for (int i = 0; i < n; i++)
		printf("%+.16lf\n", data[i]);
	return 0;
}