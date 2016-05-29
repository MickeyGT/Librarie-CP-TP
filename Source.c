#include "Library.h"
#include<stdio.h>
#include<stdlib.h>
float v[100000], v1[100000];
int n, el,i,nr, vizitat[100],matrice[100][100],j;

void dfs(int root, int number)
{
	int k;
	vizitat[root] = 1;
	for (k = 1;k <= number;k++)
		if (matrice[root][k] && !vizitat[k])
		{
			printf("\n%d->%d", root, k);
			dfs(k, number);
		}
}

void bfs( int number, int v)
{
    int front, rear,k;
	int que[20];
	front = rear = -1;
	for (k = 1;k <= number;k++)
		vizitat[k] = 0;

	printf("%d ", v);
	vizitat[v] = 1;
	rear++;
	front++;
	que[rear] = v;

	while (front <= rear)
	{
		v = que[front]; // delete from queue 
			front++;
			for (k = 1;k <= number;k++)
		{
			// Check for adjacent unvisited nodes 
				if (matrice[v][k] == 1 && vizitat[k] == 0)
				{
					printf("%d ", k);
					vizitat[k] = 1;
					rear++;
					que[rear] = k;
				}
		}
	}
}

int main()
{
	/*
	printf("N=");
	scanf("%i", &n);
	printf("Print %d elements:\n", n);
	struct node *root;
	root = (struct node*) malloc(sizeof(struct node));
	root->left = NULL;
	root->right = NULL;
	scanf("%d", &el);
	root->data = el;
	ConstructHeap(n,root);
	printf("The sorted elements from Heap:\n");
	HeapSort(root);
	*/

	//////////////////////////////////////////////////

	/*
	printf("N=");
	scanf("%i", &n);
	readarray(n, v);
	MergeSort(v, 1, n+1,v1);
	printarray(n, v1);
	*/

	//////////////////////////////////////////////////

	/*
	Nod * head = NULL; // creez nodul de start
	head = (Nod*)malloc(sizeof(Nod)); // aloc memorie pentru nodul de start
	head->next = NULL;

	//verific ca nodul de start sa fie alocat
	if (head->data == NULL) {
		printf("Lista este goala\n");
	}
	push_last(head, 1);
	push_last(head, 2);
	push_last(head, 3);
	push_first(head, 0);
	print_list(head);
	pop_last(head);
	pop_first(head);
	print_list(head);
	push_last(head, 3);
	push_poz(head, 1, 10);
	print_list(head);
	pop_poz(head, 3);
	print_list(head);
	*/
	/*scanf("%d", &nr);
	for (i = 1;i <= nr;i++)
		for (j = 1;j <= nr;j++)
			scanf("%d", &matrice[i][j]);
	*/

	//////////////////////////////////////////////////


	FILE *f;
	f= fopen("file.in","r");
	fscanf(f,"%d", &n);
	for (i = 1;i<=n;i++)
		vizitat[i] = 0;
	for (i = 1;i <= n;i++)
		for (j = 1;j <= n;j++)
			fscanf(f,"%d ", &matrice[i][j]);
	dfs(1, n);
	printf("\n");
	bfs(n, 1);
	system("pause");
	return 0;
}
