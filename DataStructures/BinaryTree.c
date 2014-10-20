#include <stdio.h>//for printing
#include <stdlib>//for alloc calloc malloc realoc and free

typedef struct node node;
struct node{
	/* data */
	int number;
	node *left;
	node *right;
};


