#include"Library.h"
#include<stdio.h>
#include<stdlib.h>


void print_list(Nod *head) {
	if (head->next != NULL) {                     // daca lista nu este goala
		Nod *current = head;                    //nodul curent primeste head
		do {
			current = current->next;            //nodul curent primeste urmatorul element
			printf("%d,", current->data);       //printeaza valoarea nodului curent
		} while (current->next != NULL);
		printf("\n");
	}
	else {
		printf("Lista este goala\n");           //daca dupa nodul head nu mai avem alte elemente
	}
}

// adaugam elemente din stanga listei, ca la stiva
void push_first(Nod *head, int val) {
	Nod *new_nod;                               //creez un nod nou
	new_nod = (Nod*)malloc(sizeof(Nod));        // aloc memmorie pentru noul nod
	new_nod->data = val;                        //se da valoarea noului element
	new_nod->next = head->next;                 //noul nod va pointa catre al doilea element (ex primul)
	head->next = new_nod;                       //head-ul va pointa catre noul nod creat
}

//adaugam elemente la dreapta listei, ca la vector
void push_last(Nod *head, int val) {
	Nod *current, *new_nod;
	current = head;
	//cat timp elementul la care am ajuns mai are un nod dupa inseamna ca nu este ultimul
	while (current->next != NULL) {
		current = current->next;
	}
	//current va avea acum adresa ultimului element
	new_nod = (Nod*)malloc(sizeof(Nod));        // aloc memmorie pentru noul
	current->next = new_nod;                      //ultimul nod va pointa acum catre noul nod creat
	new_nod->data = val;                          //i se atribuie o valoare noului nod
	new_nod->next = NULL;                         //noul nod devine ultimul deci va pointa catre NULL
}

//adaugam un nou element la pozitia poz
void push_poz(Nod *head, int poz, int val) {
	int iterator;                               //declaram un iterator cu care ne vom plimba prin lista
	Nod *current;                               //declaram un nod cu care ne vom plimba prin lista
	Nod *added_node;                            //declaram nodul pe care il vom adauga
	iterator = 0;                                 //iteratoul va pleca de la inceputul listei
	current = head;                               //nodul curent pleaca de la head
												  //atat timp cat nu am ajuns la pozitia ceruta
	while (iterator<poz) {
		current = current->next;
		iterator++;
	}
	added_node = (Nod*)malloc(sizeof(Nod));      //alocam in memorie noul nod
	added_node->next = current->next;             //noul nod se va adresa la urmatorul dupa curent
	current->next = added_node;                   //nodul current va adresa noul nod adaugat
	added_node->data = val;                       //dam nodului o valoare
}

//extragem primul element din lista, ca la stiva
int pop_first(Nod * head) {
	int value;                                  //o variabila pe care o voi returna
	Nod *primul_element;                        //declar primul element
	primul_element = head->next;                  //primul element primeste adresa elementului dupa head
	value = primul_element->data;                 //in value vom retine valoarea primului element
	head->next = primul_element->next;            //head va primi adresa celui de-al doilea element
	free(primul_element);                       //dealocam din memorie primul element
	return value;                               //returnam valoarea primului element
}

//extragem ultimul element din lista
int pop_last(Nod * head) {
	Nod *current, *deleted_node;                 //declar doua noduri
	int value;                                  //o variabila pe care o voi returna
	current = head->next;                         //nodul curent devine primul element din lista
												  //cat timp nu am ajuns la penultimul element
	while (current->next->next != NULL) {
		current = current->next;
	}
	//current devine penultimul nod
	deleted_node = current->next;                 //deleted_node devine ultimul nod
	value = deleted_node->data;                   //preluam valuare in value a ultimului nod
	free(deleted_node);                         //dealocam ultimul nod
	current->next = NULL;                         //nodul curent devine ultimul deci va primi NULL la adresa urmatorului element
	return value;                               //returnam valoarea ultimului element
}

int pop_poz(Nod *head, int poz) {
	int iterator;                               //declaram un iterator cu care ne vom plimba prin lista
	int value;
	Nod *current;                               //declaram un nod cu care ne vom plimba prin lista
	Nod *deleted_node;                          //declaram nodul pe care il vom adauga
	iterator = 0;                                 //iteratoul va pleca de la inceputul listei
	current = head;                               //nodul curent pleaca de la head
												  //atat timp cat nu am ajuns la pozitia ceruta
	while (iterator<poz - 1) {
		current = current->next;
		iterator++;
	}
	deleted_node = current->next;                 //nodul ce va fi sters este urmatorul
	value = deleted_node->data;                   //in value retinem informatia din nodul ce va fi sters
	current->next = deleted_node->next;           //nodul curent va adresa
	free(deleted_node);
}

void mergesort(float vector[100000],int beg,int end,float B[100000])
{
	if (end - beg <= 1)                      
		return;                                											
	int mid = (end + beg) / 2;              
	MergeSort(vector, beg, mid,B);
	MergeSort(vector, mid, end,B);
	MergeParts(vector, beg, mid, end,B);
	for (int k = beg;k < end;k++)
		vector[k] = B[k];							          
}

void addtoheap(struct node *root, int value)
{
	if (value < root->data)
	{
		if (root->left == NULL)
		{
			struct node *n;
			n = (struct node*)malloc(sizeof(struct node));
			n->data = value;
			n->left = NULL;
			n->right = NULL;
			root->left = n;
		}
		else
			AddtoHeap(root->left, value);
	}
	else
	{
		if (root->right == NULL)
		{
			struct node *n;
			n = (struct node*)malloc(sizeof(struct node));
			n->data = value;
			n->left = NULL;
			n->right = NULL;
			root->right = n;
		}
		else
			AddtoHeap(root->right, value);
	}
}

void heapsort(struct node *root)
{
	if (root->left != NULL)
		HeapSort(root->left);
	printf("%d ", root->data);
	if (root->right != NULL)
		HeapSort(root->right);
}

void constructheap(int n,struct node *root)
{
	int el;
	for (int i = 1;i <= n-1;i++)
	{
		scanf("%d", &el);
		AddtoHeap(root, el);
	}
}

void mergeparts(float A[100000],int beg,int mid,int end,float B[100000])
{
	int ind1, ind2;
	//float B[100000];
	ind1 = beg;
	ind2 = mid;
	for (int k = beg; k < end; k++)
	{
		if ((ind1 < mid) && ((ind2 >= end)|| (A[ind1] <= A[ind2])))
		{
			B[k] = A[ind1];
			ind1 = ind1 + 1;
		}
		else 
		{
			B[k] = A[ind2];
			ind2 = ind2 + 1;
		}
	}

}

void readarray(int n, float vector[100000])
{
	int i;
	for (i = 1;i <= n;i++)
	{
		printf("Element[%d]=", i);
		scanf("%f", &vector[i]);
	}
}

void printarray(int n, float vector[100000])
{
	int i;
	for (i = 1;i <= n;i++)
		printf("%f ", vector[i]);
	printf("\n");

}

