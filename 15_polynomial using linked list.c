// Visakh Sebastian
// s3 d
// 55


#include <stdio.h>
#include <stdlib.h>
struct node {
	int exponent;
	int coefficient;
	struct node *next;
}*Polynomial;
int deleteAll() {
	struct node *ptr = Polynomial, *prevPtr;
	while (ptr != NULL) {
		prevPtr = ptr;
		ptr = ptr->next;
		free(prevPtr);
	}
	Polynomial->next = NULL;
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
int insertNodeEnd(int exponent, int coefficient) {
	struct node *newptr = newNode(), *currentNode = Polynomial;

	while (currentNode->next != NULL) {
		currentNode = currentNode->next;
	}

	newptr->next = currentNode->next;
	newptr->exponent = exponent;
	newptr->coefficient = coefficient;
	currentNode->next = newptr;
	return (0);
}

int printPolynomial() {
	struct node *currentNode = Polynomial->next;
	printf("\nF(p) = ");
	while (currentNode != NULL) {
		if (currentNode->coefficient != 0) {
			if (currentNode->coefficient != 1) {
				printf("%d", currentNode->coefficient);
			}
			if (currentNode->exponent != 0) {
				printf("p^%d", currentNode->exponent);
			}
			if (currentNode->next != NULL) {
				if (currentNode->next->coefficient != 0)
					printf(" + ");
			}
		}
		currentNode = currentNode->next;
	}
	printf("\n");
	return (0);
}
int showMenu() {
	char choice;
	int coefficient, exponent;
	do {
		printf("Enter coefficient : ");
		scanf("%d", &coefficient);
		printf("Enter exponent : ");
		scanf("%d", &exponent);
		insertNodeEnd(exponent, coefficient);
		printf("\n1. Add more terms\n");
		printf("2. Print and exit\n");
		printf("Enter your choice : ");
		scanf(" %c", &choice);
		printf("\n");
	} while (choice != '2');
	return(0);
}
int main() {
	Polynomial = malloc(sizeof(struct node));
	Polynomial->coefficient = 0;
	Polynomial->exponent = 0;
	Polynomial->next = NULL;
	showMenu();
	printPolynomial();
	deleteAll();
	return (0);
}

/*
Output
[?1h=$ ./14_circular_doubly_linked_list 
[?1l>

	Circular Doubly Linked List
1. Insert at Front
2. Insert before
3. Insert after
4. Insert at End
5. Print Linked List
6. Delete first node
7. Delete node
8. Delete last node
9. Delete all
0. Exit
Enter your choice : 1

Enter new data : 1


	Circular Doubly Linked List
1. Insert at Front
2. Insert before
3. Insert after
4. Insert at End
5. Print Linked List
6. Delete first node
7. Delete node
8. Delete last node
9. Delete all
0. Exit
Enter your choice : 4

Enter new data : 4


	Circular Doubly Linked List
1. Insert at Front
2. Insert before
3. Insert after
4. Insert at End
5. Print Linked List
6. Delete first node
7. Delete node
8. Delete last node
9. Delete all
0. Exit
Enter your choice : 2

Enter new data : 4 3
Enter data of the node before which new node is to be created : 4


	Circular Doubly Linked List
1. Insert at Front
2. Insert before
3. Insert after
4. Insert at End
5. Print Linked List
6. Delete first node
7. Delete node
8. Delete last node
9. Delete all
0. Exit
Enter your choice : 3

Enter new data : 2
Enter data of the node after which new node is to be created : 1


	Circular Doubly Linked List
1. Insert at Front
2. Insert before
3. Insert after
4. Insert at End
5. Print Linked List
6. Delete first node
7. Delete node
8. Delete last node
9. Delete all
0. Exit
Enter your choice : 5

HEADER<->1<->2<->3<->4->HEADER


	Circular Doubly Linked List
1. Insert at Front
2. Insert before
3. Insert after
4. Insert at End
5. Print Linked List
6. Delete first node
7. Delete node
8. Delete last node
9. Delete all
0. Exit
Enter your choice : 6



	Circular Doubly Linked List
1. Insert at Front
2. Insert before
3. Insert after
4. Insert at End
5. Print Linked List
6. Delete first node
7. Delete node
8. Delete last node
9. Delete all
0. Exit
Enter your choice : 7

Enter data of the node to be deleted : 3


	Circular Doubly Linked List
1. Insert at Front
2. Insert before
3. Insert after
4. Insert at End
5. Print Linked List
6. Delete first node
7. Delete node
8. Delete last node
9. Delete all
0. Exit
Enter your choice : 8



	Circular Doubly Linked List
1. Insert at Front
2. Insert before
3. Insert after
4. Insert at End
5. Print Linked List
6. Delete first node
7. Delete node
8. Delete last node
9. Delete all
0. Exit
Enter your choice : 5

HEADER<->2->HEADER


	Circular Doubly Linked List
1. Insert at Front
2. Insert before
3. Insert after
4. Insert at End
5. Print Linked List
6. Delete first node
7. Delete node
8. Delete last node
9. Delete all
0. Exit
Enter your choice : 0
*/
