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
		print_nodes(n->next);
		printf("Number is: %d\n",n->number);
	}
}
int main(){
	int i;
	node *head= (node*) malloc(sizeof(node));
	node *curr;//= (node*) malloc(sizeof(node));
	head=NULL;

   head = NULL;

   for(i=1;i<=10;i++) {
      curr = new_node(i);
      curr->next=head;
      head=curr;
   }


	
	print_nodes(head);
	

node_free_all(head);
// node_free_all(list);
return 0;
}