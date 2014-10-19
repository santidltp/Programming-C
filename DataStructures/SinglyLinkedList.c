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
		printf("Number is: %d\n",n->number);
		print_nodes(n->next);
	}
}
int main(){
	int i;
	node *head=NULL;

	for(i=0; i<5;i++){
		head = new_node(i); 
	}
	print_nodes(head);

	

node_free_all(head);

return 0;
}