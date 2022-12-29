#include<stdio.h>
int ans[50][50] = { 0 };
char txt[50][50];
int count = 0;
void backtrack(int n, int m, int x, int y)
{
	ans[x][y] = 1;
	if (x + 1 < m)
	{
		if (txt[x + 1][y] == '0'&&ans[x+1][y]==0)
			backtrack(n, m, x + 1, y);
	}
	if (x - 1 >= 0)
	{
		if (txt[x - 1][y] == '0' && ans[x -1][y] == 0)
			backtrack(n, m, x - 1, y);
	}
	if (y + 1 < n)
	{
		if (txt[x][y + 1] == '0' && ans[x][y+1] == 0)
			backtrack(n, m, x, y + 1);
	}
	if (y - 1 >= 0)
	{
		if (txt[x][y - 1] == '0' && ans[x][y-1] == 0)
			backtrack(n, m, x, y - 1);
	}
	return;
}
char judge(int n, int m)
{
	for (int j = 0; j < n; j++)
	{
		for (int k = 0; k < m; k++)
			if (txt[j][k] == '0')
			{
				count++;
				backtrack(n, m, j, k);
				goto A;
			}
	}
	A:
	for (int j = 0; j < n; j++)
	{
		for (int k = 0; k < m; k++)
		{
			if (ans[j][k] == 0 && txt[j][k] == '0')
			{
				count++;
				backtrack(n, m, j, k);
				goto B;
			}
		}
	}
	B:
	for (int j = 0; j < n; j++)
	{
		for (int k = 0; k < m; k++)
		{
			if (ans[j][k] == 0 && txt[j][k] == '0')
			{
				count++;
				backtrack(n, m, j, k);
				goto C;
			}
		}
	}
	C:
	if (count == 1)
		return 'C';
	else if (count == 2)
		return 'A';
	else
		return 'B';
}

int main()
{
	int t,n,m;
	scanf("%d", &t);
	for (int i = 0; i < t; i++)
	{
		scanf("%d %d", &n, &m);
		rewind(stdin);
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < m; k++)
			{
				scanf("%c", &txt[j][k]);
			}
			char c = getchar();
		}
		count = 0;
		for (int j = 0; j < 50; j++)
			for (int k = 0; k < 50; k++)
				ans[j][k] = 0;

		printf("%c\n", judge(n, m));
	}
	return 0;
}