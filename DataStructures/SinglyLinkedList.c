#include <stdio.h>//prinf
#include <stdlib.h>//alloc mallco callo
typedef struct node node;
 struct node{
	int number;
	node *next;
};
node *new_node(int num){
	node *n= (node*) malloc(sizeof(node));
	n->number=num;
	n->next=NULL;
	return n;
}
void node_free_all(node *n){
	if(n != NULL){
		node_free_all(n->next);
		free(n);
	}
}
void print_nodes(node *n){
	if(n != NULL){
		printf("%d\n"n->number);
		print_nodes(n->next);
		printf("Number is: %d\n",n->number);
	}
}
int main(){
	int i;
	node *head= (node*) malloc(sizeof(node));
	node *list;//= (node*) malloc(sizeof(node));
	//head=NULL;
	list=head;
	for(i=0; i<5;i++){
		head = new_node(i+1);
	}
	print_nodes(list);
	print_nodes(head);
	

node_free_all(head);
node_free_all(list);
return 0;
}