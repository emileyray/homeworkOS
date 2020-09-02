#include <stdio.h>

struct node{
	int value;
	struct node *next;
};

struct list{
	struct node *head;
};

void insert_node(struct list* myList, int index, int value){
	struct node* newNode = (struct node*)malloc(sizeof(struct node));
	newNode->value = value;

	if (index == 0){
		struct node* temp = myList->head;
		myList->head = newNode;
		newNode->next = temp;
	} else {
		struct node* prev = (struct node*)malloc(sizeof(struct node));
		struct node* temp = myList->head;
		for (int i = 0; i < index; i++){
			prev = temp;
			temp = temp->next;
		}
		prev->next = newNode;
		newNode->next = temp;
	}
}

void delete_node(struct list* myList, int index){
	struct node* curr = myList->head;
	struct node* prev = (struct node*)malloc(sizeof(struct node));

	if (index == 0){
		myList->head = myList->head->next;
	} else {
		for (int i = 0; i < index; i++){
			prev = curr;
			curr = curr->next;
		}
		prev->next = curr->next;
	}


}

void print_list(struct list* myList){
	struct node* curr = myList->head;
	while (curr != NULL){
		printf("%d ", curr->value);
		curr = curr->next;
	}
}

int main(){
	struct list* myList = (struct list*)malloc(sizeof(struct list));
	myList->head = NULL;

	insert_node(myList, 0, 0);
	printf("inserting 0 to position 0: ");
	print_list(myList);
	printf("\n");
	insert_node(myList, 1, 1);
	printf("inserting 1 to position 1: ");
	print_list(myList);
	printf("\n");
	insert_node(myList, 2, 2);
	printf("inserting 2 to position 2: ");
	print_list(myList);
	printf("\n");
	insert_node(myList, 0, 3);
	printf("inserting 3 to position 0: ");
	print_list(myList);
	printf("\n");

	delete_node(myList, 2);
	printf("Deleting a value on position 2: ");
	print_list(myList);
	printf("\n");
	delete_node(myList, 0);
	printf("Deleting a value on position 0: ");
	print_list(myList);
	printf("\n");

	//system("Pause");

	return 0;
}
