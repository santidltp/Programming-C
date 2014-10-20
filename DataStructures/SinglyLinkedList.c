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
void delete_node(node **n, int num){

	node *rmNode;
	node *current = (*n);

	//delete first
	if( current!= NULL && current->number==num){
		rmNode = current;
		current= current->next;
		free(rmNode);
		(*n)=current;
	}
		//all but first
		while(current != NULL){
			if(current->next != NULL && current->next->number == num){
				rmNode= current->next;
				current->next = rmNode->next;
				free(rmNode);
				break;
			}
			current=current->next;
		}	
}
int main(){
	int i;
	node *head= (node*) malloc(sizeof(node));
	node *current;
	head=NULL;
	current=new_node(1);
	current->next=head;
	head=current;
   for(i=1;i<=10;i++) {
      current = new_node(i);
      current->next =head;
      head=current;
	}



   	printf("Everything:\n");
	print_nodes(head);
	printf("Deleting 1:\n");
	delete_node(&head,1);
	print_nodes(head);
	printf("Deleting 5:\n");
	delete_node(&head,5);
	print_nodes(head);
	printf("Deleting 2:\n");
	delete_node(&head,2);
	print_nodes(head);
	printf("Deleting 3:\n");
	delete_node(&head,3);
	print_nodes(head);
	printf("Deleting 10:\n");
	delete_node(&head,10);
	print_nodes(head);
	printf("Deleting 9:\n");
	delete_node(&head,9);
	print_nodes(head);

node_free_all(head);
// node_free_all(list);
return 0;
}