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
void delete_node(node *n, int num){

	node *rmNode = (node*) malloc(sizeof(node));


	while(n != NULL){
	
		if(n->next != NULL && n->next->number == num){
			rmNode= n->next;
			n->next = n->next->next;
			break;
		}
		n=n->next;
	}	
	free(rmNode);
	// return
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

   	printf("Everything:\n");
	print_nodes(head);
	printf("Deleting 1:\n");
	delete_node(head,1);
	print_nodes(head);
	printf("Deleting 5:\n");
	delete_node(head,5);
	print_nodes(head);
	printf("Deleting 2:\n");
	delete_node(head,2);
	print_nodes(head);
	printf("Deleting 3:\n");
	delete_node(head,3);
	print_nodes(head);


node_free_all(head);
// node_free_all(list);
return 0;
}