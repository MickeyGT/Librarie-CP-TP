#ifndef Library
#define Library
struct node
{
	int data;
	struct note *right;
	struct node *left;
};

typedef struct Nod 
{
	int data;                                   //ce va retine fiecare nod
	struct Nod * next;                          //pointeri catre elementul urmator
}Nod;

int getMax(int arr[], int n);

void swapp(int* a, int* b);

int rucsac(int n, int g);

void print_list(Nod *head);

void push_first(Nod *head, int val);

void push_last(Nod *head, int val);

void push_poz(Nod *head, int poz, int val);

int pop_first(Nod * head);

int pop_last(Nod * head);

int pop_poz(Nod *head, int poz);

void heapsort(struct node* root);

void constructheap(int n, struct node *root);

void addtoheap(struct node *root, int value);

void mergesort(float vector[100000], int beg, int end,float B[100000]);

void mergeparts(float A[100000], int beg, int mid, int end, float B[100000]);

void readarray(int n, float vector[100000]);

void printarray(int n, float vector[100000]);
#endif
