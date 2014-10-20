#include <stdio.h>//for printing
#include <stdlib>//for alloc calloc malloc realoc and free

typedef struct node node;
struct node{
	/* data */
	int number;
	node *left;
	node *right;
};

void delete_tree(node *leaf){
	if(leaf!=NULL){
		delete_tree(leaf->left);
		delete_tree(leaf->right);
		free(leaf);
	}
}

void insert_node(node **leaf, int num){
	if(leaf == NULL) {
		*leaf = (node*)malloc(sizeof(node));
		(*leaf)->number=num;
		(*leaf)->left=NULL;
		(*leaf)->right=NULL;
	}	
	else if((*leaf)->number < num) 
			insert_node(&(*leaf)->left,num);
	else if((*leaf)->number > num) 
			insert_node(&(*leaf)->right,num);	
}
