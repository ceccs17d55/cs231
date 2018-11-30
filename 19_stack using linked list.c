// Visakh Sebastian
// s3 d
// 55


#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
}*TOP;

int deleteAll() {
	struct node *ptr = TOP, *prevPtr;
	while (ptr != NULL) {
		prevPtr = ptr;
		ptr = ptr->next;
		free(prevPtr);
	}
	TOP->next = NULL;
	return (0);
}
struct node *newNode() {
	struct node *newptr = malloc(sizeof(struct node));
	if (newptr == NULL) {
		printf("Memory overflow");
		deleteAll();
		exit(0);
	}
	return (newptr);
}
int deleteFirstNode() {
	struct node *currentNode = TOP->next;
	if (currentNode == NULL) {
		printf("Empty stack.\nDeletion failed.\n");
	} else {
		TOP->next = currentNode->next;
		free(currentNode);
	}
	return (0);
}
int insertNodeFront(int data) {
	struct node *newptr = newNode();
	newptr->next = TOP->next;
	newptr->data = data;
	TOP->next = newptr;
	return (0);
}
int printLinkedList() {
	struct node *currentNode = TOP->next;
	printf("\nLinked List\nTOP->");
	while (currentNode != NULL) {
		printf("%d\n", currentNode->data);
		currentNode = currentNode->next;
	}
	printf("\n");
	return (0);
}
int showMenu() {
	char choice='1';
	int data, previousData, nextData;
	do {
		printf("\n\tLINKED LIST\n");
		printf("1. Push\n");
		printf("2. Pop\n");
		printf("3. Print\n");
		printf("4. Exit\n");
		printf("Enter your choice : ");
		scanf(" %c", &choice);
		printf("\n");
		switch (choice) {
			case '1':
				printf("Enter new data : ");
				scanf("%d", &data);
				insertNodeFront(data);
				break;
			case '2':
				deleteFirstNode();
				break;
			case '3':
				printLinkedList();
				break;
			case '4':
				deleteAll();
				exit(0);
				break;
			default:
                printf("Invalid choice\n");
				break;
		}
	} while(choice != '4');
	return (0);
}
int main() {
	
	TOP = malloc(sizeof(struct node));
	TOP->data = 0;
	TOP->next = NULL;
	

	showMenu();
	deleteAll();
	
	return (0);
}
/*
Output
[?1h=$ ./19_stack_using_linked_list 
[?1l>
	STACK USING LINKED LIST
1. Push
2. Pop
3. Print
4. Exit
Enter your choice : 1

Enter new data : 1

	STACK USING LINKED LIST
1. Push
2. Pop
3. Print
4. Exit
Enter your choice : 1

Enter new data : 2

	STACK USING LINKED LIST
1. Push
2. Pop
3. Print
4. Exit
Enter your choice : 1

Enter new data : 3

	STACK USING LINKED LIST
1. Push
2. Pop
3. Print
4. Exit
Enter your choice : 3


Linked List
TOP->3
2
1


	STACK USING LINKED LIST
1. Push
2. Pop
3. Print
4. Exit
Enter your choice : 2


	STACK USING LINKED LIST
1. Push
2. Pop
3. Print
4. Exit
Enter your choice : 3


Linked List
TOP->2
1


	STACK USING LINKED LIST
1. Push
2. Pop
3. Print
4. Exit
Enter your choice : 4
*/
