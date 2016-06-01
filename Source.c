#include "Library.h"
#include<stdio.h>
#include<stdlib.h>
int v1[100000],v2[100000],v3[100000];
int n, el,i,nr, vizitat[100],matrice[100][100],j,q,ok,v[100000];
#define min(a,b) (((a)<(b)) ? (a) : (b))
void matrixchainmultiplication()
{
	for (i = 3;i <= n;i++)
	{
		for (j = 1;j + i - 1 <= n;j++)
		{
			el = j + i - 1;
			matrice[j][el] = 100000000;
			for (q = j + 1;q <= el - 1;q++)
			{
				matrice[j][el] = min(matrice[j][el], matrice[j][q] + matrice[q][el] + v[j]*v[q]*v[el]);
			}
		}
	}
	printf("%d \n", matrice[1][n]);
}

void queens(int k) 
{
	if (k == n + 1) {
		if (!nr) {
			for (i = 1;i <= n;i++)
				printf("%d ",v[i]);
		}
		nr++;
		return;
	}

	for (i = 1;i <= n;i++)
		if (!v1[i] && !v2[k + i - n] && !v3[k - i + n]) {
			v1[i] = v2[k + i - n] = v3[k - i + n] = 1;
			v[k] = i;
			queens(k + 1);
			v1[i] = v2[k + i - n] = v3[k - i + n] = 0;
		}
}

void inline init(int k)
{
	vizitat[k] = 0;
}

int succesor(int k)
{
	if (vizitat[k]<n)
	{
		++vizitat[k];
		return 1;
	}
	return 0;
}

int solution(int k)
{
	return k == n;
}
void printSolution(int k)
{
	for (j = 1;j <= k;j++)
		printf("%d ", vizitat[j]);
	printf("%c", '\n');
}
int valid(int k)
{
	for (j = 1;j<k;j++)
		if (vizitat[j] == vizitat[k])
			return 0;
	return 1;
}
void bkt(int k)
{
	init(k);
	while (succesor(k))
	{
		if (valid(k))
		{
			if (solution(k))
				printSolution(k);
			else
				bkt(k + 1);
		}
	}
}

void back(int k)
{
	int i;
	for (i = vizitat[k - 1] + 1;i <= n;i++)
	{
		vizitat[k] = i;
		if (k == q)
			printSolution(k);
		if (k<q)
			back(k + 1);
	}

}

int count_coin(int S[], int m, int n) {
	int i, j, x, y;
	memset(matrice, 0, sizeof(matrice));
	for (i = 0; i<m; i++)
		matrice[0][i] = 1;

	for (i = 1; i < n + 1; i++)
	{
		for (j = 0; j < m; j++)
		{
			x = (i - S[j] >= 0) ? matrice[i - S[j]][j] : 0;
			y = (j >= 1) ? matrice[i][j - 1] : 0;
			matrice[i][j] = x + y;
		}
	}
	return matrice[n][m - 1];
}

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
	constructheap(n,root);
	printf("The sorted elements from Heap:\n");
	heapsort(root);
	*/

	//////////////////////////////////////////////////

	/*
	printf("N=");
	scanf("%i", &n);
	readarray(n, v);
	mergesort(v, 1, n+1,v1);
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

	/*
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
	*/

	/////////////////////////////////////////////////

	//printf("%d",rucsac(5, 15));

	/////////////////////////////////////////////////

	/*
	printf("n=");
	scanf("%d", &n);
	for (j = 0;j < n;j++)
		scanf("%d", &vizitat[j]);
	printf("%d", count_coin(vizitat, n, 26));
	*/

	/////////////////////////////////////////////////

	/*
	//Permutari
	printf("n=");
	scanf("%d", &n);
	bkt(1);
	*/

	//////////////////////////////////////////////////

	/*
	//Combinari
	printf("n=");
	scanf("%d", &n);
	printf("q=");
	scanf("%d", &q);
	back(1);
	*/

	/////////////////////////////////////////////////

	/*
	printf("n=");
	scanf("%d", &n);
	queens(1);
	printf("\n%d", nr);
	*/

	//////////////////////////////////////////////////

	/*
	printf("n=");
	scanf("%d", &n);
	n++;
	for (j = 1;j <= n;j++)
		scanf("%d", &v[j]);
	matrixchainmultiplication();
	*/

	system("pause");
	return 0;
}
