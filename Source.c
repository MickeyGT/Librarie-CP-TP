#include "Library.h"
#include<stdio.h>
#include<stdlib.h>
float v[100000], v1[100000];
int n, el;
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
	///////////////////////////////////////////////
	/*
	printf("N=");
	scanf("%i", &n);
	readarray(n, v);
	MergeSort(v, 1, n+1,v1);
	printarray(n, v1);
	*/
	int aux;

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
	system("pause");
	return 0;
}
