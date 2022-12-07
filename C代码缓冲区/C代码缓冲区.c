#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct list
{
	int num;
	struct list* next;
}LIST;
int main()
{
	LIST* node, * head;
	node = (LIST*)malloc(sizeof(LIST));
	node->next = NULL;
	head = node;
	int n;
	scanf("%d", &n);
	while (1)
	{
		if (n <= 0)
		{
			node->next = NULL;
			break;
		}
		scanf("%d", &node->num);
		node->next= (LIST*)malloc(sizeof(LIST));
		n--;
		if (n <= 0)
		{
			node->next = NULL;
			break;
		}
		node = node->next;
		
	}
	node = head;


	int key;
	scanf("%d", &key);
	LIST* now = head->next;
	node = head;
	while (1)
	{
		if (head->num == key)
		{
			head = head->next;
			free(node);
			node = head;
			now = now->next;
			continue;
		}
		if (now->num == key)
		{
			node->next = now->next;
			free(now);
			now = node->next;
			if (now == NULL)
				break;
			continue;
		}
		if (now->next == NULL)
			break;
		now = now->next;
		node = node->next;
	}
	node = head;
	while (1)
	{
		printf("%d ", node->num);
		if (node->next == NULL)
			break;
		node = node->next;
	}
	node = head;
	now = node->next;
	while (1)
	{
		free(node);
		if (now == NULL)
			break;
		node = now;
		now = node->next;
		if (now == NULL)
			break;
	}
	return 0;
}