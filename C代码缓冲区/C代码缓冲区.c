#include<stdio.h>
#include<string.h>
#include<stdlib.h>


typedef struct point
{
	int num;
	struct nearpoint* head,*tail;
}POINT;
typedef struct nearpoint
{
	int point;
	struct nearpoint* next,*last;
}NEARPOINT;

POINT *pp[5001];
int main()
{
	int n, m,x1,x2;
	NEARPOINT* node;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d %d", &x2, &x1);
		if (pp[x1] == NULL)
		{
			pp[x1] = (POINT*)malloc(sizeof(POINT));
			pp[x1]->num = x1;
			pp[x1]->head = NULL;
			pp[x1]->tail = NULL;
		}
		if (pp[x2] == NULL)
		{
			pp[x2] = (POINT*)malloc(sizeof(POINT));
			pp[x2]->num = x2;
			pp[x2]->head = NULL;
			pp[x2]->tail = NULL;
		}
		if (pp[x1]->head == NULL)
		{
			pp[x1]->head = (NEARPOINT*)malloc(sizeof(NEARPOINT));
			pp[x1]->head->point = pp[x2]->num;
			pp[x1]->head->next = NULL;
			pp[x1]->head->last = NULL;
			pp[x1]->tail = pp[x1]->head->next;
		}
		else
		{
			node = pp[x1]->head;
			while (node->next != NULL)
			{
				node = node->next;
			}
			node->next = (NEARPOINT*)malloc(sizeof(NEARPOINT));
			node->next->point = pp[x2]->num;
			node->next->next = NULL;
			node->next->last = node;
			pp[x1]->tail = node->next;
		}
		if (pp[x2]->head == NULL)
		{
			pp[x2]->head = (NEARPOINT*)malloc(sizeof(NEARPOINT));
			pp[x2]->head->point = pp[x1]->num;
			pp[x2]->head->next = NULL;
			pp[x2]->head->last = NULL;
			pp[x1]->tail = pp[x1]->head->next;
		}
		else
		{
			node = pp[x2]->head;
			while (node->next != NULL)
			{
				node = node->next;
			}
			node->next = (NEARPOINT*)malloc(sizeof(NEARPOINT));
			node->next->point = pp[x1]->num;
			node->next->next = NULL;
			node->next->last = node;
			pp[x2]->tail = node->next;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		int points = 1;
		node = pp[i]->head;
		while (node->next != NULL)
		{
			node = node->next;
			points++;
		}
		printf("%d ", points);
		node = pp[i]->tail;
		while (node->last != NULL)
		{
			printf("%d ", node->point);
			node = node->last;
		}
		printf("%d", node->point);
		printf("\n");
	}
	return 0;
}